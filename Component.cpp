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
    // R = V - 2 * (V · N)   <-- formula I found online somewhere
    double d = (vector.x*normal.x) + (vector.y*normal.y);

    Pair pair;
    pair.x =  vector.x - 2 * d;
    pair.y =  vector.y - 2 * d;
    return pair;
}



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
    
    vVector.x = .2;
    vVector.y = -.1;
    
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
    //printf("\ncollision %d\n",hey++);
    test = test * -1.0;
    Pair normal = comp.normalVector( center()  );
    Pair newVel = reflect(vVector, normal);
    //printf("vel: ( %f, %f )\n",vVector.x,vVector.y);
    //printf("reflect: ( %f, %f )\n",newVel.x,newVel.y);
    vVector.x = newVel.x;
    vVector.y = newVel.y;
}

Pair Component::center(){
    Pair shapeCenter = shape->center();
    Pair pair;
    pair.x = shapeCenter.x;
    pair.y = shapeCenter.y;
};

Pair Component::normalVector(Pair externalPoint){
    Pair pos;
    pos.x = x;
    pos.y = y;
    return shape->normalVector(externalPoint, pos);
};

// Test
void Component::newFrame(unsigned long long  currentTimeStamp, unsigned long long  previousTimeStamp){
    //printf("hey");
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

void Component::setShape(Shape* shapeObject){
    shape = shapeObject;
}

void Component::setX(double xValue){
    x = xValue;
}

void Component::draw(sf::RenderWindow &App)
{
    shape->draw(App, x, y);
}
