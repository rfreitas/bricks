//
//  CollisionWithRightWall.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 16/01/13.
//
//

#ifndef __Bricks__CollisionWithRightWall__
#define __Bricks__CollisionWithRightWall__

#include <iostream>
#include "Component.h"


using namespace std;

class CollisionWithRightWall {
public:
    CollisionWithRightWall();
    ~CollisionWithRightWall();
    
    void run();
    void init();
private:
    Component* wall;
    Component* ball;
};


#endif /* defined(__Bricks__CollisionWithRightWall__) */
