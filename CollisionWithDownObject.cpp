

#include "CollisionWithDownObject.h"
#include "BallShape.h"
#include "Wall.h"
#include "RectangleShape.h"
#include "ConfigManager.h"
#include <cassert>

CollisionWithDownObject::CollisionWithDownObject(){
}

CollisionWithDownObject::~CollisionWithDownObject(){
    
}

void CollisionWithDownObject::init() {
    //parede
    wall = new Wall(0, 50, 0, 0, 0, NULL);
    RectangleShape* recShape = new RectangleShape(0, 0, 100, 20, sf::Color::White);
    wall->setShape(recShape);
    
    //bola
    Component* protoBall = new Component(0, 45, 0, 0, 0, new BallShape(5, sf::Color::White) );
    ball = protoBall->clone();
}

void CollisionWithDownObject::run() {
    bool collided = ball->collidingWith(wall);
    assert(collided == true);
}
