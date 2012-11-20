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
}

/**
 * Destructor.
 **/
Component::~Component() {
    
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

void Component::moveMe(){
    y += 0.03;
    x += 0.03;
}
