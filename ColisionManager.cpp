//
//  ColisionManager.cpp
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//

#include "ColisionManager.h"
/**
 * Component Constructor
 **/
ColisionManager::ColisionManager(){
}

/**
 * Destructor.
 **/
ColisionManager::~ColisionManager() {
    
}

bool ColisionManager::collisionHappened(Component& cA, Component& cB){
    // Maths and stuff
    if( cA.getY() > cB.getY()){
        return true;
    }
    return false;
}

void ColisionManager::evaluate(Component& componentA, Component& componentB)
{
    if(collisionHappened(componentA,componentB))
    {
        componentA.willCollideWith(componentB);
        componentB.willCollideWith(componentA);
        
        componentA.collidedWith(componentB);
        componentB.collidedWith(componentA);
    }
    else
    {
        // collision not happened
    }
}

