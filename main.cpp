
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <iostream>
#include "ConfigManager.h"
#include "CollisionWithLeftWall.h"

using namespace std;

// Game instance
Game*   game;

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    // Create, Instantiate and start a game
//    game = new Game();
//    game->run();

    CollisionWithLeftWall* c = new CollisionWithLeftWall();
    c->init();
    c->run();
    
    return EXIT_SUCCESS;
}
