//
// Created by roman on 22.11.2020.
//

#include "Slime.h"
#include "../../../../auxiliary/components/sprite/primitive/SpriteBox.h"
#include "../../../reduction/collision/CollisionReduction.h"
#include "../../../reduction/mobs/MobsAnalysisReduction.h"
#include "../../../../../../utils/math/algorithms.h"
#include "splitter/SlimeSplitter.h"

Mobs::Slime::Slime(
        const Material::MaterialProperties &material_properties,
        const Mobs::MobProperties &properties,
        const Components::Area &area,
        const std::shared_ptr<Components::ISpriteBox> &sprite,
        const std::shared_ptr<::Material::Algorithms> &algorithms,
        const SlimeProperties &params
) : AnalyzingMob(material_properties, properties, area, sprite, algorithms), m_slime(params) {}

void Mobs::Slime::selfAction(Unite::Unifier *unifier) {
    RD::healthAnalysis(*this);
    if (this->isDead()) {
        //Verification of the possibility of splitting.
        if (((m_sprite->getArea().m_size.width / m_slime.splitCoefficient >= m_slime.minSplitSize) &&
             (m_sprite->getArea().m_size.height / m_slime.splitCoefficient >= m_slime.minSplitSize)) &&
            ((m_sprite->getArea().m_size.width / m_slime.splitCoefficient >= Components::SpriteBox::MIN_SPRITE_SIDE_SIZE) &&
             (m_sprite->getArea().m_size.height / m_slime.splitCoefficient >= Components::SpriteBox::MIN_SPRITE_SIDE_SIZE))) {

            unifier->addFrameAction([this](Unite::Unifier *unifier1) -> void {
                SlimeSplitter splitter(m_slime.splitCoefficient);

                //Slime properties.
                SlimeProperties slimeProperties = splitter.splitProperties(m_slime);

                //Spawn start speed calculating.
                float xSpeedOffset = m_slime.splitPower.first;
                float ySpeedOffset = m_slime.splitPower.second;

                int xSpeedRandomOffset = m_slime.splitPower.first / m_slime.splitCoefficient / 2;
                int ySpeedRandomOffset = m_slime.splitPower.second / m_slime.splitCoefficient / 2;

                //Health points calculations.
                int healthPointsDiv = m_properties.maxHealthPoints / m_slime.splitCoefficient;
                int healthPoints = (healthPointsDiv == 0) ? 1 : healthPointsDiv;

                for (std::size_t i = 0; i < m_slime.splitSlimesNumber; ++i) {
                    char flight_dest = ((i % 2 == 0) ? -1 : 1);
                    float xSpeed = m_material_properties.speed.xSpeed + (xSpeedOffset + Calculations::random(-xSpeedRandomOffset, xSpeedRandomOffset)) * flight_dest;
                    float ySpeed = m_material_properties.speed.ySpeed - (ySpeedOffset + Calculations::random(-ySpeedRandomOffset, ySpeedRandomOffset));
                    unifier1->addStandAloneMob(Mobs::split(splitter, *this, {
                            Material::MaterialProperties(Components::Speed(xSpeed, ySpeed)),
                            MobProperties(healthPoints, healthPoints), slimeProperties}));
                }
            });
        }
        unifier->addFrameAction([this](Unite::Unifier *unifier1) -> void {
            unifier1->removeStandAloneMob(this);
        });
        return;
    }
    //Players jumping.
    for (Mobs::Player *player : unifier->getPlayers()) {
        if ((player->getPosition().y < this->getPosition().y) && m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(player, this)) {
            this->dealDamage(static_cast<int>(player->getSpeed().ySpeed)); //Calculating damage with player's speed.
            bool sameSign = player->getSpeed().ySpeed * this->getSpeed().ySpeed >= 0;
            float ySpeed = static_cast<int>(-1 * player->getSpeed().ySpeed * m_slime.elasticCoefficient + (sameSign ? 0 : this->getSpeed().ySpeed));
            player->setYSpeed((std::abs(ySpeed) == 1) ? 0 : ySpeed);
            if (player->getSpeed().xSpeed != this->getSpeed().xSpeed) {
                player->setXSpeed(static_cast<int>(player->getSpeed().xSpeed * m_slime.frictionCoefficient));
            }
        }
    }

    //Slime punching logic.
    Mobs::Player *player;
    if ((player = m_algorithms->getCollision().getMovingCollision().abscissaMoveAble(this, unifier->getPlayers())) != nullptr) {
        player->dealDamage(m_slime.punchDamage);
        if (this->getSpeed().xSpeed * player->getSpeed().xSpeed <= 0) {
            player->setSpeed(Components::Speed((this->getSpeed().xSpeed > 0 ? 1 : -1) * m_slime.punchPower, -1 * m_slime.punchPower * 2));
        }
    }

    Obstacles::Block *block;
    if ((block = m_algorithms->getCollision().getMovingCollision().ordinateMoveAble(this, unifier->getBlocks())) != nullptr) {
        //Slime moving logic.
        if ((Calculations::random(0, m_slime.jumpRateCoefficient) == 0) && (this->getPosition().y < block->getPosition().y) &&
            (static_cast<int>(this->getSpeed().ySpeed) == 0)) {
            this->addSpeed(((Calculations::random(0, 1) == 1) ? 1 : -1) * m_slime.moveSpeed, -1 * m_slime.jumpSpeed);
        } else {
            bool sameSign = m_material_properties.speed.ySpeed * block->getSpeed().ySpeed >= 0;
            float ySpeed = static_cast<int>(-1 * m_material_properties.speed.ySpeed * block->getProperties().elasticCoefficient + (sameSign ? 0 : block->getSpeed().ySpeed));
            m_material_properties.speed.ySpeed = (std::abs(ySpeed) == 1) ? 0 : ySpeed;
            if (m_material_properties.speed.xSpeed != block->getSpeed().xSpeed) {
                m_material_properties.speed.xSpeed = static_cast<int>(m_material_properties.speed.xSpeed * block->getProperties().frictionCoefficient);
            }
        }
    }
    RD::abscissaBlocksNaturalCollision(this, *m_algorithms.get(), unifier);
}
