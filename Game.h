//
//  Game.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 01/12/12.
//
//

#ifndef __Bricks__Game__
#define __Bricks__Game__

#include <iostream>
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
    
    bool gameEnded;
    bool gamePaused;
    
    bool random;
    double game_x;
    double game_y;
    double game_width;
    double game_height;
    double window_width;
    double window_height;
    int num_init_balls;
    int platform_step;
    
public:
    void initializeGame();
    void checkCollisions();
    void move();
    void draw();
    void keyboardListenner();
    bool gameIsRunning();
    bool isGamePaused();
    
    Game(bool random, int numInitBalls, int game_x, int game_y,
         int window_height, int window_width, int game_height, int game_width, int platform_step);
	~Game();
};


#endif /* defined(__Bricks__Game__) */
