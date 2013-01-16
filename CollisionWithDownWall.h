//
//  CollisionWithDownWall.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 16/01/13.
//
//

#ifndef __Bricks__CollisionWithDownWall__
#define __Bricks__CollisionWithDownWall__

#include <iostream>
#include "Component.h"


using namespace std;

class CollisionWithDownWall {
public:
    CollisionWithDownWall();
    ~CollisionWithDownWall();
    
    void run();
    void init();
private:
    Component* wall;
    Component* ball;
};

#endif /* defined(__Bricks__CollisionWithDownWall__) */
