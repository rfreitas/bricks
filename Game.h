#ifndef __Bricks__Game__
#define __Bricks__Game__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "TemplateGame.h"
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "ColisionManager.h"
#include "Generator.h"
#include "RectangleShape.h"
#include "Player.h"

using namespace std;

class Game : public TemplateGame{
private:
    vector<Component*> components;
    vector<Component*> balls;
    Player* player_one;
    Player* player_two;
    
    sf::RenderWindow App;
    
    ColisionManager* collisionManager;
    
    //int loseGames;
    //int winGames;
    bool gamePaused;
    
    void checkCollisions();
    void move();
    void removeDeadObjects();
    
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
