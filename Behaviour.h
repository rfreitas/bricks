//
//  Behaviour.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 30/11/12.
//
//

#ifndef __Bricks__Behaviour__
#define __Bricks__Behaviour__

#include <iostream>
#include "Component.h"

class Behaviour {
private:
    
public:
    virtual void behave(Component* c){};
    
    Behaviour();
    ~Behaviour();
};



#endif /* defined(__Bricks__Behaviour__) */
