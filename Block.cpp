//
//  Block.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 30/11/12.
//
//

#include "Block.h"

Block::Block(double posX, double posY, double areaValue,
           double normalValue, double velocityVector, Shape* componentShape)
:Component(posX, posY, areaValue, normalValue, velocityVector, componentShape)
{
    collisionBehaviour = LoseLifeType;
}

Block::~Block()
{
    
}
