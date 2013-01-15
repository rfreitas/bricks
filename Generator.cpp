//
//  Generator.cpp
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//
#include "Generator.h"
#include "Wall.h"
#include "Block.h"
#include "RectangleShape.h"
#include "BallShape.h"  
#include "DoNothing.h"
#include "LoseLife.h"
#include "Assassin.h"

using namespace std;

/**
 * Component Constructor
 **/
Generator::Generator(double game_x, double game_y, double game_width, double game_height):
game_x(game_x),
game_y(game_y),
game_width(game_width),
game_height(game_height)
{
}

/**
 * Destructor.
 **/
Generator::~Generator() {
    
}

void Generator::randomBlocks(ComponentGroup* components){
    // generate and add to components vector
    
    //TODO
    // left wall
    Wall* leftWall = new Wall(game_x, game_y, 0, 0, 0, NULL);
    RectangleShape* recShape = new RectangleShape(0, 0, 20, game_height, sf::Color::White);
    leftWall->setShape(recShape);
    
    // right wall
    Wall* rightWall = new Wall(game_x+game_width, game_y, 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, 20, game_height, sf::Color::White);
    rightWall->setShape(recShape);
    
    // top wall
    Wall* topWall = new Wall(game_x, game_y, 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, game_width, 20, sf::Color::White);
    topWall->setShape(recShape);
    
    // bottom wall
    Wall* bottomWall = new Wall(game_x, game_y+game_height, 0, 0, 0, NULL);
    bottomWall->setBehaviour(AssassinType);
    recShape = new RectangleShape(0, 0, game_width, 20, sf::Color::Black);
    bottomWall->setShape(recShape);
    
    
    // block 1
    Block* block1 = new Block(200, 210, 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, 120, 20, sf::Color::Yellow);
    block1->setShape(recShape);
    // block 2
    Block* block2 = new Block(500, 200, 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, 120, 20, sf::Color::Yellow);
    block2->setShape(recShape);
    // block 3
    Block* block3 = new Block(300, 300, 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, 120, 20, sf::Color::Yellow);
    block3->setShape(recShape);
    
    
    components->push_back(leftWall);
    components->push_back(rightWall);
    components->push_back(topWall);
    components->push_back(bottomWall);
    components->push_back(block1);
    components->push_back(block2);
    components->push_back(block3);
}


void Generator::randomBalls(ComponentGroup* balls, int numBalls)
{
    for(int i = 1; i <= numBalls ; i++){
        int x = 340;
        int y = 80*i;
        BallShape* ballShape = new BallShape(10, sf::Color::White);
        Component* ball = new Component(x, y, 0, 0, 0, NULL);
        ball->setShape(ballShape);
        balls->push_back(ball);
    }
}

