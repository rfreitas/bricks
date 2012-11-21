//
//  Component.cpp
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//

#include "Component.h"

/**
 * Component Constructor
 **/
Component::Component(double posX, double posY, double areaValue, double normalValue, double velocityVector, Shape* componentShape)
{
    x = posX;
	y = posY;
    area = areaValue;
    normal = normalValue;
    velocity = velocityVector;
    shape = componentShape;
    
    // test
    test = 0.1;
}

/**
 * Destructor.
 **/
Component::~Component() {
    
}

void Component::willCollideWith(Component& comp){
    
}

void Component::collidedWith(Component& comp){
    test = test * -1.0;
}

// Test
void Component::moveMe(){
    y -= test;
}


double Component::getX(){
    return x;
}

double Component::getY(){
    return y;
}

double Component::getArea(){
    return area;
}

double Component::getNormal(){
    return normal;
}

double Component::getVelocity(){
    return velocity;
}

Shape* Component::getShape(){
    return shape;
}

void Component::setShape(Shape* shapeObject){
    shape = shapeObject;
}

void Component::setX(double xValue){
    x = xValue;
}

