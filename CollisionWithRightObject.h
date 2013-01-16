
#ifndef __Bricks__CollisionWithRightObject__
#define __Bricks__CollisionWithRightObject__

#include <iostream>
#include "Component.h"


using namespace std;

class CollisionWithRightObject {
public:
    CollisionWithRightObject();
    ~CollisionWithRightObject();
    
    void run();
    void init();
private:
    Component* wall;
    Component* ball;
};


#endif /* defined(__Bricks__CollisionWithRightObject__) */
