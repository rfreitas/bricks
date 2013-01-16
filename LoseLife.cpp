//
//  LoseLife.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 20/12/12.
//
//

#include "LoseLife.h"
#include "Component.h"

LoseLife::LoseLife():Behaviour(){
    
}

LoseLife::~LoseLife(){
    
}

void LoseLife::behave(Component* componentParam, Component& collidedWith)
{
    int life = componentParam->getLife();
    life -= 30;
    componentParam->setLife(life);
    
    
    if(life == 70) {
        sf::Color color(0, 150, 0);
        componentParam->getShape()->setColor(color);
    } else if(life == 40 ){
        sf::Color color(0, 100, 0);
        componentParam->getShape()->setColor(color);
    } else if(life == 10 ){
        sf::Color color(0, 50, 0);
        componentParam->getShape()->setColor(color);
    }
}