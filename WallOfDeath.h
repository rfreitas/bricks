//
//  WallOfDeath.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 20/12/12.
//
//

#ifndef __Bricks__WallOfDeath__
#define __Bricks__WallOfDeath__

#include <iostream>
#include "Component.h"
#include "Behaviour.h"

class WallOfDeath : public Component{
private:
    Behaviour* collisionBehaviour;
    
public:
    WallOfDeath(double posX, double posY, double areaValue,
         double normalValue, double velocityVector, Shape* componentShape);
	~WallOfDeath();
    
    void doCollisionBehaviour(Component& collidedWith);
    Behaviour* getBehaviour();
    void setBehaviour(Behaviour* behaviourParam);
};
#endif /* defined(__Bricks__WallOfDeath__) */
