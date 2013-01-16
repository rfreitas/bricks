

#include "CollisionWithUpWall.h"
#include "BallShape.h"
#include "Wall.h"
#include "RectangleShape.h"
#include "ConfigManager.h"
#include <cassert>

CollisionWithUpWall::CollisionWithUpWall(){
}

CollisionWithUpWall::~CollisionWithUpWall(){
    
}

void CollisionWithUpWall::init() {
    //parede
    wall = new Wall(0, 0, 0, 0, 0, NULL);
    RectangleShape* recShape = new RectangleShape(0, 0, 100, 20, sf::Color::White);
    wall->setShape(recShape);
    
    //bola
    Component* protoBall = new Component(0, 25, 0, 0, 0, new BallShape(5, sf::Color::White) );
    ball = protoBall->clone();
}

void CollisionWithUpWall::run() {
    bool collided = ball->collidingWith(wall);
    assert(collided == true);
}
