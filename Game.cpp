//
//  Game.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 01/12/12.
//
//

#include "Game.h"


// TODO
#define GAME_LIMIT_LEFT 120
#define GAME_LIMIT_RIGHT 700

Game::Game(bool randomParam, int numInitBallsParam, int game_xParam, int game_yParam,
           int window_heightParam, int window_widthParam, int game_heightParam, int game_widthParam, int platform_stepParam):
random(randomParam),
num_init_balls(numInitBallsParam),
game_x(game_xParam),
game_y(game_yParam),
game_width(game_widthParam),
game_height(game_heightParam),
platform_step(platform_stepParam),
App(sf::VideoMode(window_widthParam, window_heightParam), "RS Bricks"),
TemplateGame()
{
}

Game::~Game(){
}


void Game::initializeGame(){
    // Init Colision Manager & Init Components Generator
    collisionManager = new ColisionManager();
    Generator* generator = new Generator(game_x, game_y, game_width, game_height);
    
    // Game not paused
    gamePaused = false;
    gameEnded  = false;
    
    // Generate Components
    if (random){
        generator->randomBlocks(components);
        generator->randomBalls(balls,num_init_balls);
    }
    
    RectangleShape* recShape = new RectangleShape(0, 0, 20, 500, sf::Color::White);
    player_one = new Player(200, 510, 0, 0, 0, NULL, NULL);
    recShape = new RectangleShape(0, 0, 90, 10, sf::Color::Yellow);
    player_one->setShape(recShape);
    
    recShape = new RectangleShape(0, 0, 20, 500, sf::Color::White);
    player_two = new Player(0, 0, 0, 0, 0, NULL, NULL);
    recShape = new RectangleShape(0, 0, 90, 10, sf::Color::Green);
    player_two->setShape(recShape);
}

bool Game::gameIsRunning(){
    return App.IsOpened();
}

bool Game::isGamePaused(){
    return gamePaused;
}

void Game::checkCollisions(){
    // Iterate balls vs components
    for(int i = 0; i < balls.size() ; i++){
        Component* ball = balls[i];
        
        // Collision with player's platform
        collisionManager->evaluate(*(balls[i]), *player_one);
        collisionManager->evaluate(*(balls[i]), *player_two);
        
        // Collision with the others components
        for(int j = 0 ; j < components.size() ; j++){
            Component* actualComponent = components[j];
            collisionManager->evaluate(*ball, *actualComponent);
        }
    }
}

void Game::draw(){
    
    // Clear screen
    App.Clear();
    
    for (int i = 0; i<components.size(); i++) {
        Component* auxComponent = components[i];
        auxComponent->draw(App);
    }
    
    for (int i = 0; i<balls.size(); i++) {
        Component* auxComponent = balls[i];
        auxComponent->draw(App);
    }
    
    // draw player's platform
    player_one->draw(App);
    player_two->draw(App);
    
    App.Display();
}

void Game::move(){
//    for (int i = 0; i<components.size(); i++) {
//        Component* auxComponent = components[i];
//        
//    }
    
    for (int i = 0; i<balls.size(); i++) {
        Component* auxComponent = balls[i];
        balls[i]->newFrame(0, 0);
    }
}

void Game::keyboardListenner(){
    sf::Event Event;
    while (App.GetEvent(Event))
    {
        // Close window : exit
        if (Event.Type == sf::Event::KeyPressed && Event.Key.Code == sf::Key::Escape){
            App.Close();
        }
        
        // TODO check the game limits
        // Escape key pressed
        if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Left)){
            double x = player_one->getX();
            x -= platform_step;
            if(x>=GAME_LIMIT_LEFT){
                player_one->setX(x);
            }
        }
        else if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Right)){
            double x = player_one->getX();
            x += platform_step;
            RectangleShape* shape = dynamic_cast<RectangleShape*>(player_one->getShape());
            if(x + shape->getX2() <= GAME_LIMIT_RIGHT){
                player_one->setX(x);
            }
        }
        // Pause the game when space bar is pressed
        else if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Space)){
            gamePaused = !gamePaused;
        }
    }
    
}

