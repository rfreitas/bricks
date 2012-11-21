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
    
    double* bounderiesCA = cA.getShape()->getBounderyRectangle();
    double* bounderiesCB = cB.getShape()->getBounderyRectangle();
    
    
    double xCA1 = bounderiesCA[0] + cA.getX();
    double xCA2 = bounderiesCA[2] + cA.getX();
    double xCB1 = bounderiesCB[0] + cB.getX();
    double xCB2 = bounderiesCB[2] + cB.getX();
    
    double yCA1 = bounderiesCA[1] + cA.getY();
    double yCA2 = bounderiesCA[3] + cA.getY();
    double yCB1 = bounderiesCB[1] + cB.getY();
    double yCB2 = bounderiesCB[3] + cB.getY();
    
    if((xCA1 <= xCB1 && xCA2 >= xCB1) ||
       ((xCA1 >= xCB1 && xCA1 <= xCB2) && (xCA2 >= xCB1 && xCA2 <= xCB2)) ||
       (xCA1 <= xCB2 && xCA2 >= xCB2))
    {
        if((yCA1 <= yCB1 && yCA2 >= yCB1) ||
          ((yCA1 >= yCB1 && yCA1 <= yCB2) && (yCA2 >= yCB1 && yCA2 <= yCB2)) ||
          (yCA1 <= yCB2 && yCA2 >= yCB2)){
            return true;
        }
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

