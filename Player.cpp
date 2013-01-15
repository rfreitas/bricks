//
//  Player.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 01/12/12.
//
//

#include "Player.h"

Player::Player(double posX, double posY, double areaValue,
             double normalValue, double velocityVector, Shape* componentShape)
:Component(posX, posY, areaValue, normalValue, velocityVector, componentShape)
{
    platform_step = 10;
    winner = false;
}

Player::~Player()
{
    
}


void Player::setPlatformStep(int platform_step_param){
    platform_step = platform_step_param;
}

int Player::getPlatformStep(){
    return platform_step;
}

void Player::setAsWinner(){
    winner = true;
}
bool Player::isWinner(){
    return winner;
}