//
//  ChangeColor.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 30/11/12.
//
//

#include "ChangeColor.h"

ChangeColor::ChangeColor():Behaviour(){
    
}

ChangeColor::~ChangeColor(){
    
}

void ChangeColor::behave(Component* componentParam)
{
    componentParam->getStatus()->updateStatus(componentParam);
}