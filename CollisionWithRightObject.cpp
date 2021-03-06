

#include "CollisionWithRightObject.h"
#include "BallShape.h"
#include "Wall.h"
#include "RectangleShape.h"
#include "ConfigManager.h"
#include <cassert>

CollisionWithRightObject::CollisionWithRightObject(){
}

CollisionWithRightObject::~CollisionWithRightObject(){
    
}

void CollisionWithRightObject::init() {
    //parede
    wall = new Wall(30, 0, 0, 0, 0, NULL);
    RectangleShape* recShape = new RectangleShape(0, 0, 20, 100, sf::Color::White);
    wall->setShape(recShape);
    
    //bola
    Component* protoBall = new Component(25, 0, 0, 0, 0, new BallShape(5, sf::Color::White) );
    ball = protoBall->clone();
}

void CollisionWithRightObject::run() {
    bool collided = ball->collidingWith(wall);
    assert(collided == true);
}
