//
//  AliveStatus.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 29/11/12.
//
//

#ifndef __Bricks__AliveStatus__
#define __Bricks__AliveStatus__

#include <iostream>
#include "Component.h"

class AliveStatus: public Status {
private:
    int life;
    
public:
    void updateStatus(Component* component);
    
    AliveStatus();
    ~AliveStatus();
};

#endif /* defined(__Bricks__AliveStatus__) */
