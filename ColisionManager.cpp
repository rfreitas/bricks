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
    double yCA1 = bounderiesCA[1] + cA.getY();
    double xCA2 = bounderiesCA[2] + cA.getX();
    double yCA2 = bounderiesCA[3] + cA.getY();
    
    double xCB1 = bounderiesCB[0] + cB.getX();
    double yCB1 = bounderiesCB[1] + cB.getY();
    double xCB2 = bounderiesCB[2] + cB.getX();
    double yCB2 = bounderiesCB[3] + cB.getY();
    
    
//    printf("xCA1=%.2f yCA1=%.2f xCA2=%.2f yCA2=%.2f\n",xCA1,yCA1,xCA2,yCA2);
//    printf("xCB1=%.2f yCB1=%.2f xCB2=%.2f yCB2=%.2f\n",xCB1,yCB1,xCB2,yCB2);
//    
    
    if((xCA1 <= xCB1 && xCA2 >= xCB1) ||
       ((xCA1 >= xCB1 && xCA1 <= xCB2) && (xCA2 >= xCB1 && xCA2 <= xCB2)) ||
       (xCA1 <= xCB2 && xCA2 >= xCB2))
    {
        
//        printf("first\n");
        if((yCA1 <= yCB1 && yCA2 >= yCB1) ||
          ((yCA1 >= yCB1 && yCA1 <= yCB2) && (yCA2 >= yCB1 && yCA2 <= yCB2)) ||
          (yCA1 <= yCB2 && yCA2 >= yCB2)){
            
//            printf("second\n");
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

