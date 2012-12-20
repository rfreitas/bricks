//
//  Wall.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 30/11/12.
//
//

#include "Wall.h"

Wall::Wall(double posX, double posY, double areaValue,
           double normalValue, double velocityVector, Shape* componentShape)
:Component(posX, posY, areaValue, normalValue, velocityVector, componentShape)
{
    
}

Wall::~Wall()
{
    
}


Behaviour* Wall::getBehaviour(){
    return collisionBehaviour;
}

void Wall::setBehaviour(Behaviour* behaviourParam){
    collisionBehaviour = behaviourParam;
}


void Wall::doCollisionBehaviour(Component& collidedWith){
    collisionBehaviour->behave(this, collidedWith);
}

