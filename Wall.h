//
//  Wall.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 30/11/12.
//
//

#ifndef __Bricks__Wall__
#define __Bricks__Wall__

#include <iostream>
#include "Component.h"
#include "Behaviour.h"

class Wall : public Component{
    
public:
    Wall(double posX, double posY, double areaValue,
         double normalValue, double velocityVector, Shape* componentShape);
	~Wall();
};

#endif /* defined(__Bricks__Wall__) */
