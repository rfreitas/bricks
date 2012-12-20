//
//  WallOfDeath.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 20/12/12.
//
//

#include "WallOfDeath.h"

WallOfDeath::WallOfDeath(double posX, double posY, double areaValue,
           double normalValue, double velocityVector, Shape* componentShape)
:Component(posX, posY, areaValue, normalValue, velocityVector, componentShape)
{
    
}

WallOfDeath::~WallOfDeath()
{
    
}


Behaviour* WallOfDeath::getBehaviour(){
    return collisionBehaviour;
}

void WallOfDeath::setBehaviour(Behaviour* behaviourParam){
    collisionBehaviour = behaviourParam;
}


void WallOfDeath::doCollisionBehaviour(Component& collidedWith){
    collisionBehaviour->behave(this, collidedWith);
}