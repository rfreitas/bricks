#ifndef __Bricks__Game__
#define __Bricks__Game__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "TemplateGame.h"
#include <SFML/Graphics.hpp>
#include "ComponentGroup.h"
#include "Generator.h"
#include "RectangleShape.h"
#include "Player.h"

using namespace std;

class Game : public TemplateGame{
private:
    ComponentGroup* components;
    ComponentGroup* balls;
    Player* player_one;
    Player* player_two;
    
    sf::Sprite sprite;
    sf::Image image;

    
    sf::RenderWindow App;
    
    bool leftKeyBeingPressed;
    bool rightKeyBeingPressed;
    
    
    //int loseGames;
    //int winGames;
    bool gamePaused;
    
    void checkCollisions();
    void move();
    void removeDeadObjects();
    void movePlayerTowardsClosestBall( Player* player);
    
public:
    void initializeGame();
    void draw();
    void keyboardListenner();
    bool gameIsRunning();
    bool isGamePaused();
    bool didGameFinished();
    //void displayScore();
    void clean();
    
    void iterate();
    
    Game();
	~Game();
};


#endif /* defined(__Bricks__Game__) */
