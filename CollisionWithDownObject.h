//
//  CollisionWithDownObject.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 16/01/13.
//
//

#ifndef __Bricks__CollisionWithDownObject__
#define __Bricks__CollisionWithDownObject__

#include <iostream>
#include "Component.h"


using namespace std;

class CollisionWithDownObject {
public:
    CollisionWithDownObject();
    ~CollisionWithDownObject();
    
    void run();
    void init();
private:
    Component* wall;
    Component* ball;
};

#endif /* defined(__Bricks__CollisionWithDownObject__) */
