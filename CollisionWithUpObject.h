

#ifndef __Bricks__CollisionWithUpObject__
#define __Bricks__CollisionWithUpObject__

#include <iostream>
#include "Component.h"


using namespace std;

class CollisionWithUpObject {
public:
    CollisionWithUpObject();
    ~CollisionWithUpObject();
    
    void run();
    void init();
private:
    Component* wall;
    Component* ball;
};

#endif /* defined(__Bricks__CollisionWithUpObject__) */
