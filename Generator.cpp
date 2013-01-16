#include "Generator.h"
#include "Wall.h"
#include "Block.h"
#include "RectangleShape.h"
#include "BallShape.h"  
#include "DoNothing.h"
#include "LoseLife.h"
#include "ConfigManager.h"
#include "Assassin.h"

using namespace std;

/**
 * Component Constructor
 **/
Generator::Generator()
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
    Wall* leftWall = new Wall(ConfigManager::Instance()->getGameX(), ConfigManager::Instance()->getGameY(), 0, 0, 0, NULL);
    RectangleShape* recShape = new RectangleShape(0, 0, 20, ConfigManager::Instance()->getGameHeight(), sf::Color::White);
    leftWall->setShape(recShape);
    
    // right wall
    Wall* rightWall = new Wall(ConfigManager::Instance()->getGameX()+ConfigManager::Instance()->getGameWidth(), ConfigManager::Instance()->getGameY(), 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, 20, ConfigManager::Instance()->getGameHeight(), sf::Color::White);
    rightWall->setShape(recShape);
    
    // top wall
    /*
    Wall* topWall = new Wall(ConfigManager::Instance()->getGameX(), ConfigManager::Instance()->getGameY(), 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, ConfigManager::Instance()->getGameWidth(), 20, sf::Color::White);
    topWall->setShape(recShape);
     */
    sf::Color color(0, 0, 0, 0);
    
    
    // bottom wall
    Wall* bottomWall = new Wall(ConfigManager::Instance()->getGameX(), ConfigManager::Instance()->getGameY()+ConfigManager::Instance()->getGameHeight(), 0, 0, 0, NULL);
    bottomWall->setBehaviour(AssassinType);
    recShape = new RectangleShape(0, 0, ConfigManager::Instance()->getGameWidth(), 20, color);
    bottomWall->setShape(recShape);
    
    // up wall
    Wall* upWall = new Wall(ConfigManager::Instance()->getGameX(), ConfigManager::Instance()->getGameY(), 0, 0, 0, NULL);
    upWall->setBehaviour(AssassinType);
    recShape = new RectangleShape(0, 0, ConfigManager::Instance()->getGameWidth(), 20, color);
    upWall->setShape(recShape);
    
    
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
    //components->push_back(topWall);
    components->push_back(bottomWall);
    components->push_back(upWall);
    components->push_back(block1);
    components->push_back(block2);
    components->push_back(block3);
}


void Generator::randomBalls(ComponentGroup* balls, int numBalls)
{
    Component* protoBall = new Component(400, 0, 0, 0, 0, new BallShape(10, sf::Color::White) );
    for(int i = 1; i <= numBalls ; i++){
        Component* ball = protoBall->clone();
        ball->setY(80*i + 50);
        Pair newVel = ball->getVelocity();
        newVel.x = 1.4;
        if (i%2 != 0){
            newVel.y = -1*newVel.y;
        }
        ball->setVelocity(newVel);
        balls->push_back(ball);
    }
}

