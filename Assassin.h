//
//  Assassin.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 20/12/12.
//
//

#ifndef __Bricks__Assassin__
#define __Bricks__Assassin__

#include <iostream>
#include "Behaviour.h"

class Assassin: public Behaviour {
private:
    
public:
    void behave(Component* component, Component& collidedWith);
    
    Assassin();
    ~Assassin();
};

#endif /* defined(__Bricks__Assassin__) */
