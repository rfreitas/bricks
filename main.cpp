
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <iostream>
#include "ConfigFile.h"
#include "Game.h"

using namespace std;

// values are read from "game.config"
GLint     window_width = 800;
GLint     window_height = 640;
GLint     game_width = 600;
GLint     game_height = 500;
GLint     game_x = 100;
GLint     game_y = 50;
GLint     r_blocks = 1;
GLint     num_init_balls = 1;
GLint     platform_step = 10;

// Game instance
Game*   game;

void readConfiguration(char* file) {
	ConfigFile config(file);
    
    config.readInto(num_init_balls, "num_init_balls" );
	config.readInto(r_blocks, "r_blocks" );
	config.readInto(platform_step, "platform_step" );
    config.readInto(window_width, "window_width" );
	config.readInto(window_height, "window_height" );
	config.readInto(game_width, "game_width" );
	config.readInto(game_height, "game_height" );
	config.readInto(game_x, "game_x" );
	config.readInto(game_y, "game_y" );
}

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
    game = new Game(r_blocks == 1 ? true : false, num_init_balls, game_x, game_y,
                    window_height, window_width, game_height, game_width, platform_step);
    game->run();

    return EXIT_SUCCESS;
}
