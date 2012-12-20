//
//  BallBehaviour.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 20/12/12.
//
//

#ifndef __Bricks__BallBehaviour__
#define __Bricks__BallBehaviour__

#include <iostream>
#include "Behaviour.h"

class BallBehaviour: public Behaviour {
private:
    
public:
    void behave(Component* component, Component& collidedWith);
    
    BallBehaviour();
    ~BallBehaviour();
};
#endif /* defined(__Bricks__BallBehaviour__) */
