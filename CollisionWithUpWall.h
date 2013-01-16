//
//  CollisionWithUpWall.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 16/01/13.
//
//

#ifndef __Bricks__CollisionWithUpWall__
#define __Bricks__CollisionWithUpWall__

#include <iostream>
#include "Component.h"


using namespace std;

class CollisionWithUpWall {
public:
    CollisionWithUpWall();
    ~CollisionWithUpWall();
    
    void run();
    void init();
private:
    Component* wall;
    Component* ball;
};


#endif /* defined(__Bricks__CollisionWithUpWall__) */
