

#ifndef __Bricks__CollisionWithLeftObject__
#define __Bricks__CollisionWithLeftObject__

#include <iostream>
#include "Component.h"


using namespace std;

class CollisionWithLeftObject {
public:
    CollisionWithLeftObject();
    ~CollisionWithLeftObject();
    
    void run();
    void init();
private:
    Component* wall;
    Component* ball;
};

#endif /* defined(__Bricks__CollisionWithLeftObject__) */
