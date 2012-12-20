//
//  Wall.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 30/11/12.
//
//

#ifndef __Bricks__Wall__
#define __Bricks__Wall__

#include <iostream>
#include "Component.h"
#include "Behaviour.h"

class Wall : public Component{
private:
    Behaviour* collisionBehaviour;
    
public:
    Wall(double posX, double posY, double areaValue,
         double normalValue, double velocityVector, Shape* componentShape);
	~Wall();
    
    void doCollisionBehaviour(Component& collidedWith);
    Behaviour* getBehaviour();
    void setBehaviour(Behaviour* behaviourParam);
};

#endif /* defined(__Bricks__Wall__) */
