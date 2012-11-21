
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "Generator.h"
#include "RectangleShape.h"
#include "BallShape.h"
#include "ColisionManager.h"

using namespace std;

#define PLATFORM_STEP 7

// Vector of Components
vector<Component*> components(3);
vector<Component*> balls(1);
Component* platform;
ColisionManager* collisionManager;

void init(){
    // Read config file...
    // ...
    // Init Colision Manager
    collisionManager = new ColisionManager();
    // Init Components Generator
    Generator* generator = new Generator();
    
    ///////////////////////////////////////////////////////////////
    // Generate Components /*@config file*/
    // if random
    //generator->randomBlocks(/*&components*/);
    // then
    // generator->notRandom(&components);
    // BUT for tests //////////////////////////////////////////////
    Component* ball = new Component(300, 300, 0, 0, 0, NULL);
    BallShape* ballShape = new BallShape(5, sf::Color::White);
    ball->setShape(ballShape);
    balls[0] = ball;
    
    // left wall
    Component* leftWall = new Component(100, 50, 0, 0, 0, NULL);
    RectangleShape* recShape = new RectangleShape(0, 0, 20, 500, sf::Color::White);
    leftWall->setShape(recShape);
    
    // right wall
    Component* rightWall = new Component(700, 50, 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, 20, 500, sf::Color::White);
    rightWall->setShape(recShape);
    
    // top wall
    Component* topWall = new Component(100, 50, 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, 620, 20, sf::Color::White);
    topWall->setShape(recShape);
    
    // platform
    platform = new Component(300, 510, 0, 0, 0, NULL);
    recShape = new RectangleShape(0, 0, 90, 10, sf::Color::Yellow);
    platform->setShape(recShape);
    
    components[0] = leftWall;
    components[1] = rightWall;
    components[2] = topWall;
    
    //////////////////////////////////////////////////////////////
}

void checkCollisions(){
    
    //uncomment when collision maths are done
    for(int i = 0; i < balls.size() ; i++){
        Component* ball = balls[i];
        for(int j = 0 ; j < components.size() ; j++){
            Component* actualComponent = components[j];
            collisionManager->evaluate(*ball, *actualComponent);
        }
    }
    
    collisionManager->evaluate(*(balls[0]), *platform);
    
}

void keyboardListenner(sf::RenderWindow &App){
    // Process events
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
            double x = platform->getX();
            x -= PLATFORM_STEP;
            platform->setX(x);
        }
        else if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Right)){
            double x = platform->getX();
            x += PLATFORM_STEP;
            platform->setX(x);
        }
    }
    
}

void draw(sf::RenderWindow &App){
    
    // Listen to keyboard inputs
    keyboardListenner(App);
    
    // Clear screen
    App.Clear();
    
    for (int i = 0; i<components.size(); i++) {
        Component* auxComponent = components[i];
        Shape* s = auxComponent->getShape();
        s->draw(App, auxComponent->getX(), auxComponent->getY());
    }
    
    for (int i = 0; i<balls.size(); i++) {
        Component* auxComponent = balls[i];
        Shape* s = auxComponent->getShape();
        s->draw(App, auxComponent->getX(), auxComponent->getY());
        
        // for tests
        balls[i]->moveMe();
    }
    
    // draw platform
    Shape* platformShape = platform->getShape();
    platformShape->draw(App, platform->getX(), platform->getY());
    
    App.Display();
}

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    // Init
    init();
    
    // Create main window
    sf::RenderWindow App(sf::VideoMode(800, 600), "Bricks" /*@config file*/);
    
    // Start game loop
    while (App.IsOpened())
    {
        checkCollisions();
        draw(App);
    }

    return EXIT_SUCCESS;
}
