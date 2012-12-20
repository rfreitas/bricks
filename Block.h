//
//  Block.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 30/11/12.
//
//

#ifndef __Bricks__Block__
#define __Bricks__Block__

#include <iostream>
#include "Component.h"
#include "Behaviour.h"

class Block : public Component{
private:
    Behaviour* collisionBehaviour;
    
public:
    Block(double posX, double posY, double areaValue,
         double normalValue, double velocityVector, Shape* componentShape);
	~Block();
    
    void doCollisionBehaviour(Component& collidedWith);
    Behaviour* getBehaviour();
    void setBehaviour(Behaviour* behaviourParam);
};
#endif /* defined(__Bricks__Block__) */
