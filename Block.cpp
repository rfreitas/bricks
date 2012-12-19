//
//  Block.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 30/11/12.
//
//

#include "Block.h"

Block::Block(double posX, double posY, double areaValue,
           double normalValue, double velocityVector, Shape* componentShape, Status* statusParam)
:Component(posX, posY, areaValue, normalValue, velocityVector, componentShape, statusParam)
{
    
}

Block::~Block()
{
    
}


Behaviour* Block::getBehaviour(){
    return collisionBehaviour;
}

void Block::setBehaviour(Behaviour* behaviourParam){
    collisionBehaviour = behaviourParam;
}


void Block::doCollisionBehaviour(){
    collisionBehaviour->behave(this);
}
