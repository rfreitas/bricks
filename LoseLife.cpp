//
//  LoseLife.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 20/12/12.
//
//

#include "LoseLife.h"

LoseLife::LoseLife():Behaviour(){
    
}

LoseLife::~LoseLife(){
    
}

void LoseLife::behave(Component* componentParam, Component& collidedWith)
{
    int life = componentParam->getLife();
    life -= 10;
    componentParam->setLife(life);
}