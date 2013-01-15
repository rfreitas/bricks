#ifndef __Bricks__ConfigManager__
#define __Bricks__ConfigManager__

#include <iostream>
#include "Game.h"

class ConfigManager {
private:
    static ConfigManager* m_pInstance;
    ConfigManager();
    
    GLint     window_width = 800;
    GLint     window_height = 640;
    GLint     game_width = 600;
    GLint     game_height = 500;
    GLint     game_x = 100;
    GLint     game_y = 50;
    bool      r_blocks = true;
    GLint     num_init_balls = 2;
    GLint     platform_step = 10;
    
public:
    GLint getWindowWidth();
    GLint getWindowHeight();
    GLint getGameWidth();
    GLint getGameHeight();
    GLint getGameX();
    GLint getGameY();
    bool getRandomBlocks();
    int getNumInitBalls();
    int getPlatformStep();
    
    static ConfigManager* Instance();
	~ConfigManager();
};

#endif /* defined(__Bricks__ConfigManager__) */
