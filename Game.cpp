#include "Game.h"
#include <sstream>
#include <string> // this should be already included in <sstream>
#include "ConfigManager.h"


// TODO
#define GAME_LIMIT_LEFT 120
#define GAME_LIMIT_RIGHT 700

Game::Game():
App(sf::VideoMode(ConfigManager::Instance()->getWindowWidth(), ConfigManager::Instance()->getWindowHeight()), "RS Bricks"),
TemplateGame()
{
    //loseGames = 0;
    //winGames = 0;
    components = new ComponentGroup();
    balls = new ComponentGroup();
}

Game::~Game(){
}


void Game::initializeGame(){
    // Init Colision Manager & Init Components Generator
    Generator* generator = new Generator();
    
    // Game not paused
    gamePaused = false;
    
    // Generate Components
    if (random){
        generator->randomBlocks(components);
        generator->randomBalls(balls, ConfigManager::Instance()->getNumInitBalls());
    }
    
    RectangleShape* recShape = new RectangleShape(0, 0, 20, 500, sf::Color::White);
    player_one = new Player(200, 510, 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, 90, 10, sf::Color::Yellow);
    player_one->setShape(recShape);
    
    recShape = new RectangleShape(0, 0, 20, 500, sf::Color::White);
    player_two = new Player(0, 0, 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, 90, 10, sf::Color::Green);
    player_two->setShape(recShape);
}

void Game::clean()
{
//    for(int i = 0 ; i < components.size() ; i++)
//    {
//        delete components[i];
//    }
//    for(int i = 0 ; i < balls.size() ; i++)
//    {
//        delete balls[i];
//    }
}
bool Game::gameIsRunning(){
    return App.IsOpened();
}

bool Game::isGamePaused(){
    return gamePaused;
}

void Game::checkCollisions(){
    balls->evaluateCollisionWith(player_one);
    balls->evaluateCollisionWith(player_two);
    balls->evaluateCollisionWith(components);
}

void Game::draw(){
    
    // Clear screen
    App.Clear();
    
    components->draw(App);
    balls->draw(App);

    
    // draw player's platform
    player_one->draw(App);
    player_two->draw(App);
    
    //displayScore();
    
    App.Display();
}

void Game::move(){    
    balls->newFrame();
}

void Game::removeDeadObjects(){
    components->removeDeadObjects();
}

bool Game::didGameFinished()
{
    balls->removeDeadObjects();
    
    if(balls->size() == 0)
    {
//        loseGames++;
        return true;
    }
    
    return false;
}

//void Game::displayScore()
//{
//    sf::String winLabel;
//    winLabel.SetText("Win:");
//    winLabel.SetColor(sf::Color(255, 255, 255));
//    winLabel.SetPosition(10.f, 100.f);
//    winLabel.SetSize(18.f);
//    
//    ostringstream ss1;//create a stringstream
//    ss1 << winGames;//add number to the stream
//    
//    sf::String winValue;
//    winValue.SetText(ss1.str());
//    winValue.SetColor(sf::Color(255, 255, 255));
//    winValue.SetPosition(60.f, 100.f);
//    winValue.SetSize(18.f);
//    
//    sf::String lose;
//    lose.SetText("Lose:");
//    lose.SetColor(sf::Color(255, 255, 255));
//    lose.SetPosition(10.f, 120.f);
//    lose.SetSize(18.f);
//    
//    ostringstream ss;//create a stringstream
//    ss << loseGames;//add number to the stream
//
//    sf::String loseValue;
//    loseValue.SetText(ss.str());
//    loseValue.SetColor(sf::Color(255, 255, 255));
//    loseValue.SetPosition(60.f, 120.f);
//    loseValue.SetSize(18.f);
//    
//    App.Draw(winLabel);
//    App.Draw(winValue);
//    App.Draw(lose);
//    App.Draw(loseValue);
//}

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
            x -= ConfigManager::Instance()->getPlatformStep();
            if(x>=GAME_LIMIT_LEFT){
                player_one->setX(x);
            }
        }
        else if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Right)){
            double x = player_one->getX();
            x += ConfigManager::Instance()->getPlatformStep();
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

void Game::iterate()
{
    move();
    checkCollisions();
    removeDeadObjects();
}

