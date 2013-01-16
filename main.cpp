
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <iostream>
#include "ConfigManager.h"
#include "CollisionWithLeftObject.h"
#include "CollisionWithUpObject.h"
#include "CollisionWithRightObject.h"
#include "CollisionWithDownObject.h"

using namespace std;

// Game instance
Game*   game;

void runTests() {
    CollisionWithLeftObject* l = new CollisionWithLeftObject();
    l->init();
    l->run();
    
    CollisionWithUpObject* u = new CollisionWithUpObject();
    u->init();
    u->run();
    
    CollisionWithRightObject* r = new CollisionWithRightObject();
    r->init();
    r->run();
    
    CollisionWithDownObject* d = new CollisionWithDownObject();
    d->init();
    d->run();
}

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    runTests();
    // Create, Instantiate and start a game
    game = new Game();
    game->run();
    
    return EXIT_SUCCESS;
}
