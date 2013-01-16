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

vector<Behaviour*> Component::behaviours;

vector<Behaviour*> Component::getBehaviours()
{
    if (behaviours.size() == 0) {  // Only allow one instance of class to be generated.
        behaviours.assign (3, new Behaviour());
        behaviours[AssassinType] = new Assassin();
        behaviours[DoNothingType] = new DoNothing();
        behaviours[LoseLifeType] = new LoseLife();
    }
    return behaviours;
}

behavioursType Component::getBehaviour(){
    return collisionBehaviour;
}

void Component::setBehaviour(behavioursType behaviourParam){
    collisionBehaviour = behaviourParam;
}


void Component::doCollisionBehaviour(Component& collidedWith){
    getBehaviours()[collisionBehaviour]->behave(this, collidedWith);
}



Component::Component(){
    collisionBehaviour = DoNothingType;
}

/**
 * Component Constructor
 **/
Component::Component(double posX, double posY, double areaValue,
                     double normalValue, double velocityVector, Shape* componentShape)
{
    x = posX;
	y = posY;
    area    = areaValue;
    normal  = normalValue;
    shape   = componentShape;
    
    vVector.x = 0.3;
    vVector.y = 0.3;
    
    life = 20;
    
    collisionBehaviour = DoNothingType;
}

Component* Component::clone(){
    return new Component(x, y, area, normal, 0, shape);
}

/**
 * Destructor.
 **/
Component::~Component() {
    
}

void Component::willCollideWith(Component* comp){
    doCollisionBehaviour(*comp);
}

void Component::collidedWith(Component* comp){
    //printf("\ncollision %d\n",hey++);
    Pair normal = comp->normalVector( center() );
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
        .y = shapeCenter.y
    };
};

Pair Component::normalVector(Pair externalPoint){
    Pair pos;
    pos.x = x;
    pos.y = y;
    return shape->normalVector(externalPoint, pos);
};


void Component::newFrame(){
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

Pair Component::getVelocity(){
    return vVector;
}

Shape* Component::getShape(){
    return shape;
}

int Component::getLife()
{
    return life;
}

void Component::setShape(Shape* shapeObject){
    shape = shapeObject;
}

void Component::setX(double xValue){
    x = xValue;
}
void Component::setY(double yValue){
    y = yValue;
}

void Component::setLife(int newLife)
{
    life = newLife;
}

void Component::draw(sf::RenderWindow &App)
{
    shape->draw(App, x, y);
}

void Component::drawWithOrigin(sf::RenderWindow &App, double xOrigin, double yOrigin)
{
    shape->draw(App, x+xOrigin, y+yOrigin);
}

bool Component::collidingWith(Component* cB)
{
    if (cB->isGroup() ){
        return cB->collidingWith(this);
    }
    
    double* bounderiesCA = getShape()->getBounderyRectangle();
    double* bounderiesCB = cB->getShape()->getBounderyRectangle();
    
    
    double xCA1 = bounderiesCA[0] + getX();
    double yCA1 = bounderiesCA[1] + getY();
    double xCA2 = bounderiesCA[2] + getX();
    double yCA2 = bounderiesCA[3] + getY();
    
    double xCB1 = bounderiesCB[0] + cB->getX();
    double yCB1 = bounderiesCB[1] + cB->getY();
    double xCB2 = bounderiesCB[2] + cB->getX();
    double yCB2 = bounderiesCB[3] + cB->getY();
    
    
    //printf("xCA1=%.2f yCA1=%.2f xCA2=%.2f yCA2=%.2f\n",xCA1,yCA1,xCA2,yCA2);
    //printf("xCB1=%.2f yCB1=%.2f xCB2=%.2f yCB2=%.2f\n",xCB1,yCB1,xCB2,yCB2);
    
    
    if((xCA1 <= xCB1 && xCA2 >= xCB1) ||
       ((xCA1 >= xCB1 && xCA1 <= xCB2) && (xCA2 >= xCB1 && xCA2 <= xCB2)) ||
       (xCA1 <= xCB2 && xCA2 >= xCB2))
    {
        
        //printf("Horizontal\n");
        if((yCA1 <= yCB1 && yCA2 >= yCB1) ||
           ((yCA1 >= yCB1 && yCA1 <= yCB2) && (yCA2 >= yCB1 && yCA2 <= yCB2)) ||
           (yCA1 <= yCB2 && yCA2 >= yCB2)){
            
            //printf("and Vertical\n");
            return true;
        }
    }
    return false;
}

void Component::evaluateCollisionWith(Component* componentB)
{
    if (componentB->isGroup()){
        return componentB->evaluateCollisionWith(this);
    }
    
    if(collidingWith(componentB))
    {
        willCollideWith(componentB);
        componentB->willCollideWith(this);
        
        collidedWith(componentB);
        componentB->collidedWith(this);
    }
    else
    {
        // collision not happened
    }
}

bool Component::isGroup(){
    return false;
}

double distanceBetweenPairs( Pair pos, Pair pos1){
    return sqrt( pow(pos.x - pos1.x, 2) + pow(pos.y - pos1.y, 2) );
}

int Component::distance(Component* other){
    return distanceBetweenPairs( center(), other->center() );
}
