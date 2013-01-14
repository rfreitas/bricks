
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <iostream>
#include "ConfigManager.h"

using namespace std;


// Game instance
Game*   game;

//void readConfiguration(char* file) {
//	ConfigFile config(file);
//    
//    config.readInto(num_init_balls, "num_init_balls" );
//	config.readInto(r_blocks, "r_blocks" );
//	config.readInto(platform_step, "platform_step" );
//    config.readInto(window_width, "window_width" );
//	config.readInto(window_height, "window_height" );
//	config.readInto(game_width, "game_width" );
//	config.readInto(game_height, "game_height" );
//	config.readInto(game_x, "game_x" );
//	config.readInto(game_y, "game_y" );
//}

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    //char config_file[] = "game.cfg";
	//readConfiguration(config_file);
    
    // Create, Instantiate and start a game
    game = new Game();
    game->run();

    return EXIT_SUCCESS;
}
