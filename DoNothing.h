//
//  DoNothing.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 30/11/12.
//
//

#ifndef __Bricks__DoNothing__
#define __Bricks__DoNothing__

#include <iostream>
#include "Behaviour.h"

class DoNothing: public Behaviour {
private:
    
public:
    void behave(Component* component, Component& collidedWith);
    
    DoNothing();
    ~DoNothing();
};

#endif /* defined(__Bricks__DoNothing__) */
