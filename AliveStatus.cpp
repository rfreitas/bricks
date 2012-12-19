//
//  AliveStatus.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 29/11/12.
//
//

#include "AliveStatus.h"

void AliveStatus::updateStatus(Component* component)
{
    life = life - 20;
    if(life>79){
        component->getShape()->setColor(sf::Color::Red);
    }
    else if(life > 50){
        component->getShape()->setColor(sf::Color::Black);
        component->setStatus(new AliveStatus());
    }
}

AliveStatus::AliveStatus():Status()
{
    life = 100;
}

AliveStatus::~AliveStatus()
{
    
}