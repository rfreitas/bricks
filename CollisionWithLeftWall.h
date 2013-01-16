
#ifndef __Bricks__CollisionWithLeftWall__
#define __Bricks__CollisionWithLeftWall__

#include <iostream>
#include "Component.h"


using namespace std;

class CollisionWithLeftWall {
public:
    CollisionWithLeftWall();
    ~CollisionWithLeftWall();
    
    void run();
    void init();
private:
    Component* wall;
    Component* ball;
};

#endif /* defined(__Bricks__CollisionWithLeftWall__) */
