//
//  ColisionManager.h
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//

#ifndef __SFML_Graphics_based_Application__ColisionManager__
#define __SFML_Graphics_based_Application__ColisionManager__
#pragma once

#include <iostream>
#include "Component.h"

#endif /* defined(__SFML_Graphics_based_Application__ColisionManager__) */

class ColisionManager {
private:
    bool collisionHappened(Component& cA, Component& cB);
public:
    ColisionManager();
	~ColisionManager();
    
    void evaluate(Component& componentA, Component& componentB);
};