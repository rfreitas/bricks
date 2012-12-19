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
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "ColisionManager.h"
#include "Generator.h"
#include "RectangleShape.h"
#include "Player.h"

using namespace std;

class Game {
private:
    vector<Component*>  components;
    vector<Component*>  balls;
    Player*             player_one;
    Player*             player_two;
    
    ColisionManager*    collisionManager;
    sf::RenderWindow    App;
    
    unsigned long       previousTimeStamp;
    unsigned long       currentTimeStamp;
    
    bool    gamePaused;
    bool    gameEnded;
    
    bool    random;
    double  game_x;
    double  game_y;
    double  game_width;
    double  game_height;
    int     num_init_balls;
    int     platform_step;
    
    // Methods
    void    startGameLoop();
    void    checkCollisions();
    void    move();
    void    draw();
    void    keyboardListenner();
    
public:
    Game(bool random, int numInitBalls, int game_x, int game_y,
         int window_height, int window_width, int game_height, int game_width, int platform_step);
	~Game();
    
    void startGame();
};


#endif /* defined(__Bricks__Game__) */
