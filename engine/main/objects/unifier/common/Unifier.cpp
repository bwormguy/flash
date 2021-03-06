//
// Created by roman on 09.09.2020.
//

#include "Unifier.h"

void Unite::Unifier::addBackSprite(Components::ISprite *sprite) noexcept {
    m_back_sprites.push_back(std::shared_ptr<Components::ISprite>(sprite));
}

void Unite::Unifier::addBackSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    m_back_sprites.push_back(sprite);
}

void Unite::Unifier::removeBackSprite(Components::ISprite *sprite) noexcept {
    m_back_sprites.remove_if([sprite](const std::shared_ptr<Components::ISprite> &sprt) -> bool {
        return sprt.get() == sprite;
    });
}

void Unite::Unifier::removeBackSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    m_back_sprites.remove(sprite);
}

const std::list<std::shared_ptr<Components::ISprite>> &Unite::Unifier::getBackSprites() const noexcept {
    return m_back_sprites;
}

void Unite::Unifier::addFrontSprite(Components::ISprite *sprite) noexcept {
    m_front_sprites.push_back(std::shared_ptr<Components::ISprite>(sprite));
}

void Unite::Unifier::addFrontSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    m_front_sprites.push_back(sprite);
}

void Unite::Unifier::removeFrontSprite(Components::ISprite *sprite) noexcept {
    m_front_sprites.remove_if([sprite](const std::shared_ptr<Components::ISprite> &sprt) -> bool {
        return sprt.get() == sprite;
    });
}

void Unite::Unifier::removeFrontSprite(const std::shared_ptr<Components::ISprite> &sprite) noexcept {
    m_front_sprites.remove(sprite);
}

const std::list<std::shared_ptr<Components::ISprite>> &Unite::Unifier::getFrontSprites() const noexcept {
    return m_front_sprites;
}

void Unite::Unifier::addText(Components::Text *text) noexcept {
    m_screen_text.push_back(std::shared_ptr<Components::Text>(text));
}

void Unite::Unifier::addText(const std::shared_ptr<Components::Text> &text) noexcept {
    m_screen_text.push_back(text);
}

void Unite::Unifier::removeText(Components::Text *text) noexcept {
    m_screen_text.remove_if([text](const std::shared_ptr<Components::Text> &txt) -> bool {
        return txt.get() == text;
    });
}

void Unite::Unifier::removeText(const std::shared_ptr<Components::Text> &text) noexcept {
    m_screen_text.remove(text);
}

const std::list<std::shared_ptr<Components::Text>> &Unite::Unifier::getTextAreas() const noexcept {
    return m_screen_text;
}

void Unite::Unifier::addParticle(Particles::Particle *particle) noexcept {
    m_particles.push_back(std::shared_ptr<Particles::Particle>(particle));
}

void Unite::Unifier::addParticle(const std::shared_ptr<Particles::Particle> &particle) noexcept {
    m_particles.push_back(particle);
}

void Unite::Unifier::removeParticle(Particles::Particle *particle) noexcept {
    m_particles.remove_if([particle](const std::shared_ptr<Particles::Particle> &partcl) -> bool {
        return partcl.get() == particle;
    });
}

void Unite::Unifier::removeParticle(const std::shared_ptr<Particles::Particle> &particle) noexcept {
    m_particles.remove(particle);
}

const std::list<std::shared_ptr<Particles::Particle>> &Unite::Unifier::getParticles() const noexcept {
    return m_particles;
}

void Unite::Unifier::addBullet(Particles::Bullet *bullet) noexcept {
    m_bullets.push_back(bullet);
    this->addParticle(bullet);
}

void Unite::Unifier::addBullet(const std::shared_ptr<Particles::Bullet> &bullet) noexcept {
    m_bullets.push_back(bullet.get());
    this->addParticle(bullet);
}

void Unite::Unifier::addBullet(const std::shared_ptr<Particles::Particle> &bullet) noexcept {
    if (Particles::Bullet *blt = dynamic_cast<Particles::Bullet *>(bullet.get())) {
        m_bullets.push_back(blt);
        this->addParticle(bullet);
    }
}

void Unite::Unifier::removeBullet(Particles::Bullet *bullet) noexcept {
    m_bullets.remove_if([bullet](Particles::Bullet *bllt) -> bool {
        return bllt == bullet;
    });
    this->removeParticle(bullet);
}

void Unite::Unifier::removeBullet(const std::shared_ptr<Particles::Bullet> &bullet) noexcept {
    m_bullets.remove_if([bullet](Particles::Bullet *bllt) -> bool {
        return bllt == bullet.get();
    });
    this->removeParticle(bullet);
}

const std::shared_ptr<Particles::Particle> &Unite::Unifier::getBullet(Particles::Bullet *bullet) const {
    return *std::find_if(m_particles.begin(), m_particles.end(), [bullet](const std::shared_ptr<Particles::Particle> &particle) -> bool {
        return particle.get() == bullet;
    });
}

const std::list<Particles::Bullet *> &Unite::Unifier::getBullets() const noexcept {
    return m_bullets;
}

void Unite::Unifier::addObstacle(Obstacles::Obstacle *obstacle) noexcept {
    m_obstacles.push_back(std::shared_ptr<Obstacles::Obstacle>(obstacle));
}

void Unite::Unifier::addObstacle(const std::shared_ptr<Obstacles::Obstacle> &obstacle) noexcept {
    m_obstacles.push_back(obstacle);
}

void Unite::Unifier::removeObstacle(Obstacles::Obstacle *obstacle) noexcept {
    m_obstacles.remove_if([obstacle](const std::shared_ptr<Obstacles::Obstacle> &obstcle) -> bool {
        return obstcle.get() == obstacle;
    });
}

void Unite::Unifier::removeObstacle(const std::shared_ptr<Obstacles::Obstacle> &obstacle) noexcept {
    m_obstacles.remove(obstacle);
}

const std::list<std::shared_ptr<Obstacles::Obstacle>> &Unite::Unifier::getObstacles() const noexcept {
    return m_obstacles;
}

void Unite::Unifier::addBlock(Obstacles::Block *block) noexcept {
    m_blocks.push_back(block);
    this->addObstacle(block);
}

void Unite::Unifier::addBlock(const std::shared_ptr<Obstacles::Block> &block) noexcept {
    m_blocks.push_back(block.get());
    this->addObstacle(block);
}

void Unite::Unifier::addBlock(const std::shared_ptr<Obstacles::Obstacle> &block) noexcept {
    if (Obstacles::Block *blk = dynamic_cast<Obstacles::Block *>(block.get())) {
        m_blocks.push_back(blk);
        this->addObstacle(block);
    }
}

void Unite::Unifier::removeBlock(Obstacles::Block *block) noexcept {
    m_blocks.remove_if([block](Obstacles::Block *blck) -> bool {
        return blck == block;
    });
    this->removeObstacle(block);
}

void Unite::Unifier::removeBlock(const std::shared_ptr<Obstacles::Block> &block) noexcept {
    m_blocks.remove_if([block](Obstacles::Block *blck) -> bool {
        return blck == block.get();
    });
    this->removeObstacle(block);
}

const std::shared_ptr<Obstacles::Obstacle> &Unite::Unifier::getBlock(Obstacles::Block *block) const {
    return *std::find_if(m_obstacles.begin(), m_obstacles.end(), [block](const std::shared_ptr<Obstacles::Obstacle> &obstacle) -> bool {
        return obstacle.get() == block;
    });
}

const std::list<Obstacles::Block *> &Unite::Unifier::getBlocks() const noexcept {
    return m_blocks;
}

void Unite::Unifier::addMob(Mobs::Mob *mob) noexcept {
    m_mobs.push_back(std::shared_ptr<Mobs::Mob>(mob));
}

void Unite::Unifier::addMob(const std::shared_ptr<Mobs::Mob> &mob) noexcept {
    m_mobs.push_back(mob);
}

void Unite::Unifier::removeMob(Mobs::Mob *mob) noexcept {
    m_mobs.remove_if([mob](const std::shared_ptr<Mobs::Mob> &mb) -> bool {
        return mb.get() == mob;
    });
}

void Unite::Unifier::removeMob(const std::shared_ptr<Mobs::Mob> &mob) noexcept {
    m_mobs.remove(mob);
}

const std::list<std::shared_ptr<Mobs::Mob>> &Unite::Unifier::getMobs() const noexcept {
    return m_mobs;
}

void Unite::Unifier::addStandAloneMob(Mobs::Mob *mob) noexcept {
    m_stand_alone_mobs.push_back(mob);
    this->addMob(mob);
}

void Unite::Unifier::addStandAloneMob(const std::shared_ptr<Mobs::Mob> &mob) noexcept {
    m_stand_alone_mobs.push_back(mob.get());
    this->addMob(mob);
}

void Unite::Unifier::removeStandAloneMob(Mobs::Mob *mob) noexcept {
    m_stand_alone_mobs.remove_if([mob](Mobs::Mob *mb) -> bool {
        return mb == mob;
    });
    this->removeMob(mob);
}

void Unite::Unifier::removeStandAloneMob(const std::shared_ptr<Mobs::Mob> &mob) noexcept {
    m_stand_alone_mobs.remove_if([mob](Mobs::Mob *mb) -> bool {
        return mb == mob.get();
    });
    this->removeMob(mob);
}

const std::list<Mobs::Mob *> &Unite::Unifier::getStandAloneMobs() const noexcept {
    return m_stand_alone_mobs;
}

void Unite::Unifier::addPlayer(Mobs::Player *player) noexcept {
    m_players.push_back(player);
    this->addMob(player);
}

void Unite::Unifier::addPlayer(const std::shared_ptr<Mobs::Player> &player) noexcept {
    m_players.push_back(player.get());
    this->addMob(player);
}

void Unite::Unifier::addPlayer(const std::shared_ptr<Mobs::Mob> &player) noexcept {
    if (Mobs::Player *plr = dynamic_cast<Mobs::Player *>(player.get())) {
        m_players.push_back(plr);
        this->addMob(player);
    }
}

void Unite::Unifier::removePlayer(Mobs::Player *player) noexcept {
    m_players.remove_if([player](Mobs::Player *plr) -> bool {
        return plr == player;
    });
    this->removeMob(player);
}

void Unite::Unifier::removePlayer(const std::shared_ptr<Mobs::Player> &player) noexcept {
    m_players.remove_if([player](Mobs::Player *plr) -> bool {
        return plr == player.get();
    });
    this->removeMob(player);
}

const std::shared_ptr<Mobs::Mob> &Unite::Unifier::getPlayer(Mobs::Player *player) const {
    return *std::find_if(m_mobs.begin(), m_mobs.end(), [player](const std::shared_ptr<Mobs::Mob> &mob) -> bool {
        return mob.get() == player;
    });
}

const std::list<Mobs::Player *> &Unite::Unifier::getPlayers() const noexcept {
    return m_players;
}

void Unite::Unifier::addEffect(Effects::Effect *effect) noexcept {
    m_effects.push_back(std::shared_ptr<Effects::Effect>(effect));
}

void Unite::Unifier::addEffect(const std::shared_ptr<Effects::Effect> &effect) noexcept {
    m_effects.push_back(effect);
}

void Unite::Unifier::removeEffect(Effects::Effect *effect) noexcept {
    m_effects.remove_if([effect](const std::shared_ptr<Effects::Effect> &effct) -> bool {
        return effct.get() == effect;
    });
}

void Unite::Unifier::removeEffect(const std::shared_ptr<Effects::Effect> &effect) noexcept {
    m_effects.remove(effect);
}

const std::list<std::shared_ptr<Effects::Effect>> &Unite::Unifier::getEffects() const noexcept {
    return m_effects;
}

void Unite::Unifier::addTrigger(Triggers::Trigger *trigger) noexcept {
    m_triggers.push_back(std::shared_ptr<Triggers::Trigger>(trigger));
}

void Unite::Unifier::addTrigger(const std::shared_ptr<Triggers::Trigger> &trigger) noexcept {
    m_triggers.push_back(trigger);
}

void Unite::Unifier::removeTrigger(Triggers::Trigger *trigger) noexcept {
    m_triggers.remove_if([trigger](const std::shared_ptr<Triggers::Trigger> &trgr) -> bool {
        return trgr.get() == trigger;
    });
}

void Unite::Unifier::removeTrigger(const std::shared_ptr<Triggers::Trigger> &trigger) noexcept {
    m_triggers.remove(trigger);
}

const std::list<std::shared_ptr<Triggers::Trigger>> &Unite::Unifier::getTriggers() const noexcept {
    return m_triggers;
}

void Unite::Unifier::addFrameAction(const std::function<void(Unite::Unifier *)> &action) noexcept {
    m_frame_actions.push_back(action);
}
