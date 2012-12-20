//
//  LoseLife.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 20/12/12.
//
//

#ifndef __Bricks__LoseLife__
#define __Bricks__LoseLife__

#include <iostream>

#include "Behaviour.h"

class LoseLife: public Behaviour {
private:
    
public:
    void behave(Component* component, Component& collidedWith);
    
    LoseLife();
    ~LoseLife();
};


#endif /* defined(__Bricks__LoseLife__) */
