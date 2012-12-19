//
//  Component.cpp
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//

#include "Component.h"

int hey = 0;

// 'v' is the incoming vector, 'n' is the normalized wall vector
Pair reflect( Pair vector, Pair normal){
    // R = V - 2 * (V · N)   <-- formula I found online 
    double d = (vector.x*normal.x) + (vector.y*normal.y);
    return {
        .x =  vector.x - 2 * d * normal.x,
        .y =  vector.y - 2 * d * normal.y
    };
}


Component::Component(){
    
}

/**
 * Component Constructor
 **/
Component::Component(double posX, double posY, double areaValue,
                     double normalValue, double velocityVector, Shape* componentShape, Status* statusParam)
{
    x = posX;
	y = posY;
    area    = areaValue;
    normal  = normalValue;
    velocity = velocityVector;
    shape   = componentShape;
    status = statusParam;
    
    vVector.x = 0.5;
    vVector.y = 0.5;
}

/**
 * Destructor.
 **/
Component::~Component() {
    
}

void Component::willCollideWith(Component& comp){
    doCollisionBehaviour();
}

void Component::collidedWith(Component& comp){
    //printf("\ncollision %d\n",hey++);
    Pair normal = comp.normalVector( center()  );
    Pair newVel = reflect(vVector, normal);
    //printf("vel: ( %f, %f )\n",vVector.x,vVector.y);
    //printf("reflect: ( %f, %f )\n",newVel.x,newVel.y);
    vVector.x = newVel.x;
    vVector.y = newVel.y;
}

Pair Component::center(){
    Pair shapeCenter = shape->center();
    return {
        .x = shapeCenter.x +x,
        .y = shapeCenter.y + y
    };
};

Pair Component::normalVector(Pair externalPoint){
    Pair pos;
    pos.x = x;
    pos.y = y;
    return shape->normalVector(externalPoint, pos);
};


void Component::newFrame(unsigned long currentTimeStamp, unsigned long previousTimeStamp){
    //double elapsedTime = difftime(currentTimeStamp, previousTimeStamp)*1000;
    //printf("e:%f",elapsedTime);
    previousPosition.x = x;
    previousPosition.y = y;
    x += vVector.x;
    y += vVector.y;
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

Status* Component::getStatus(){
    return status;
}

void Component::setShape(Shape* shapeObject){
    shape = shapeObject;
}

void Component::setX(double xValue){
    x = xValue;
}

void Component::setStatus(Status* statusParam)
{
    status = statusParam;
}
void Component::draw(sf::RenderWindow &App)
{
    shape->draw(App, x, y);
}
