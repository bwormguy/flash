//
// Created by roman on 10.09.2020.
//

#include "StartLevelFactory.h"
#include "../../unifier/GeneralUnifier.h"
#include "../../material/mobs/player/custom/BasicPlayer.h"
#include "../../material/mobs/monsters/custom/mushroom/Mushroom.h"
#include "../../auxiliary/components/sprite/common/box/SpriteBox.h"
#include "../../static/effects/GravityEffect.h"
#include "../../material/obstacles/blocks/single/DullBlock.h"
#include "../../material/shared/collision/moving-collision/ObstacleCollision.h"

#include <memory>
#include <map>

std::shared_ptr<Unite::Unifier>
LevelGenerating::StartLevelFactory::loadLevel(const sf::Vector2u &size, Screen::StateChangeable *context,
                                              Managers::DataManager *manager) const {
    using namespace Unite;
    using namespace Mobs;
    using namespace Components;
    using namespace Material;

    Unifier *unifier = new GeneralUnifier();

    std::shared_ptr<Collision> collision(new Collision(unifier, 8, 5));


    unifier->addBackSprite(new SpriteBox(Point(0, 0), Size(size.x, size.y),
                                         manager->getTextureManager()->loadTexture("background/dungeon_back_2.png")));

    Player *player = new BasicPlayer(
            std::shared_ptr<ISpriteBox>(
                    new SpriteBox(
                            Point(610, 110),
                            Size(20, 20),  //10 - min
                            manager->getTextureManager()->loadTexture("mobs/player/mush.png"))),
            collision);

    player->loadKeyMap("keys/keymap.ini", manager);
    unifier->addPlayer(player);

    //mushroom

    auto mushroom = manager->getTextureManager()->loadTexture("mobs/monsters/mushroom/mushroom.png");

    Mobs::Monster *mush = new Mobs::Mushroom(std::shared_ptr<ISpriteBox>(
            new SpriteBox(
                    Point(555, 250),
                    Size(30, 30),  //10 - min
                    mushroom)), collision);
    mush->addSpeed(-1, 0);
    unifier->addMonster(mush);

    mush = new Mobs::Mushroom(std::shared_ptr<ISpriteBox>(
            new SpriteBox(
                    Point(1060, 280),
                    Size(30, 30),  //10 - min
                    mushroom)), collision);
    mush->addSpeed(-1, 0);
    unifier->addMonster(mush);


    mush = new Mobs::Mushroom(std::shared_ptr<ISpriteBox>(
            new SpriteBox(
                    Point(1060, 220),
                    Size(30, 30),  //10 - min
                    mushroom)), collision);
    mush->addSpeed(-1, 0);
    unifier->addMonster(mush);


    mush = new Mobs::Mushroom(std::shared_ptr<ISpriteBox>(
            new SpriteBox(
                    Point(1060, 250),
                    Size(30, 30),  //10 - min
                    mushroom)), collision);
    mush->addSpeed(-1, 0);
    unifier->addMonster(mush);


    mush = new Mobs::Mushroom(std::shared_ptr<ISpriteBox>(
            new SpriteBox(
                    Point(1130, 250),
                    Size(30, 30),  //10 - min
                    mushroom)), collision);
    mush->addSpeed(1, 0);
    unifier->addMonster(mush);


    mush = new Mobs::Mushroom(std::shared_ptr<ISpriteBox>(
            new SpriteBox(
                    Point(200, 250),
                    Size(30, 30),  //10 - min
                    mushroom)), collision);
    mush->addSpeed(-1, 0);
    unifier->addMonster(mush);


    mush = new Mobs::Mushroom(std::shared_ptr<ISpriteBox>(
            new SpriteBox(
                    Point(170, 250),
                    Size(30, 30),  //10 - min
                    mushroom)), collision);
    mush->addSpeed(1, 0);
    unifier->addMonster(mush);


    //gravity
    unifier->addEffect(new Effects::GravityEffect(0, 1));

    auto wall_texture = manager->getTextureManager()->loadTexture("structure/walls/stone/stone_wall_1.jpg");

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1100, 300),
                            Size(100, 100),
                            wall_texture))));

    //
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(100, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(200, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(300, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(400, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(500, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(600, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(700, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(800, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(900, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1000, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1100, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1200, 0),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1200, 100),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1200, 200),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1200, 300),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1200, 400),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1200, 500),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1200, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1100, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(1000, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(900, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(800, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(700, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(600, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(500, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(400, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(300, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(200, 600),
                            Size(100, 100),
                            wall_texture))));
    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(100, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(0, 600),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(0, 500),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(0, 400),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(0, 300),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(0, 200),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(0, 100),
                            Size(100, 100),
                            wall_texture))));

    unifier->addObstacle(
            new Obstacles::DullBlock(
                    std::shared_ptr<SpriteBox>(new SpriteBox(
                            Point(0, 0),
                            Size(100, 100),
                            wall_texture))));

    return std::shared_ptr<Unite::Unifier>(unifier);
}