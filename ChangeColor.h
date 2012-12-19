//
//  ChangeColor.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 30/11/12.
//
//

#ifndef __Bricks__ChangeColor__
#define __Bricks__ChangeColor__

#include <iostream>
#include "Behaviour.h"

class ChangeColor: public Behaviour {
private:
    
public:
    void behave(Component* component);
    
    ChangeColor();
    ~ChangeColor();
};

#endif /* defined(__Bricks__ChangeColor__) */
