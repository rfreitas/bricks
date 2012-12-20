//
//  DoNothing.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 30/11/12.
//
//

#include "DoNothing.h"

DoNothing::DoNothing():Behaviour(){
    
}

DoNothing::~DoNothing(){
    
}

void DoNothing::behave(Component* componentParam, Component& collidedWith)
{
    // do nothing
}