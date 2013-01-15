//
//  Assassin.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 20/12/12.
//
//

#include "Assassin.h"
#include "Component.h"

Assassin::Assassin():Behaviour(){
    
}

Assassin::~Assassin(){
    
}

void Assassin::behave(Component* componentParam, Component& collidedWith)
{
    collidedWith.setLife(0);
}