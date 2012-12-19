//
//  Status.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 29/11/12.
//
//

#ifndef __Bricks__Status__
#define __Bricks__Status__

#include <iostream>

class Component;

class Status {
private:
    
public:
    virtual void updateStatus(Component* c){};
    
    Status();
    ~Status();
};

#endif /* defined(__Bricks__Status__) */
