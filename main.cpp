
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <iostream>
#include "ConfigManager.h"
#include "CollisionWithLeftWall.h"
#include "CollisionWithUpWall.h"
#include "CollisionWithRightWall.h"
#include "CollisionWithDownWall.h"

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

    CollisionWithLeftWall* l = new CollisionWithLeftWall();
    l->init();
    l->run();
    
    CollisionWithUpWall* u = new CollisionWithUpWall();
    u->init();
    u->run();
    
    CollisionWithRightWall* r = new CollisionWithRightWall();
    r->init();
    r->run();
    
    CollisionWithDownWall* d = new CollisionWithDownWall();
    d->init();
    d->run();
    
    return EXIT_SUCCESS;
}
