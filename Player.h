//
//  Player.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 01/12/12.
//
//

#ifndef __Bricks__Player__
#define __Bricks__Player__

#include <iostream>
#include "Component.h"
#include "Behaviour.h"

class Player : public Component{
private:
    Behaviour* collisionBehaviour;
    
    int platform_step;
    bool winner;
    
public:
    Player(double posX, double posY, double areaValue,
          double normalValue, double velocityVector, Shape* componentShape);
	~Player();
    
    void    doCollisionBehaviour(Component& collidedWith);
    Behaviour* getBehaviour();
    void    setBehaviour(Behaviour* behaviourParam);
    void    setPlatformStep(int platform_step_param);
    int     getPlatformStep();
    void    setAsWinner();
    bool    isWinner();
    
};
#endif /* defined(__Bricks__Player__) */
