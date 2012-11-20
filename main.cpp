
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "Generator.h"
#include "ColisionManager.h"

using namespace std;

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    
    // Init
    
    // Read config file...
    // ...
    // Init Colision Manager
    ColisionManager* colisionManager = new ColisionManager();
    // Init Components Generator
    Generator* generator = new Generator();
    
    // Vector of Components
    vector<Component*> components(1);
    
    // Generate Components /*@config file*/
    // if random
    generator->randomBlocks(/*&components*/);
    // then
    // generator->notRandom(&components);
    
    
    // for tests
    Component* ball = new Component(200, 200, 0, 0, 0, NULL);
    components[0] = ball;
    
    
    // Create main window
    sf::RenderWindow App(sf::VideoMode(800, 600), "Brick Pong" /*@config file*/);
    
    // Start game loop
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();
        }

        // Clear screen
        App.Clear();
        
        for (int i = 0; i<components.size(); i++) {
            // Draw apredefined shape
            App.Draw(sf::Shape::Circle(components[i]->getX(), components[i]->getY(), 6, sf::Color::Blue, 2, sf::Color::Blue));
            
            // for tests
            components[i]->moveMe();
        }
        
        // Finally, display the rendered frame on screen
        App.Display();
    }

    return EXIT_SUCCESS;
}
