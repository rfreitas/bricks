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


class ColisionManager {
private:

public:
    ColisionManager();
	~ColisionManager();
    
    void evaluate(Component& componentA, Component& componentB);
    bool collisionHappened(Component& cA, Component& cB);

};

#endif /* defined(__SFML_Graphics_based_Application__ColisionManager__) */

