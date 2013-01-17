#ifndef __Bricks__ConfigManager__
#define __Bricks__ConfigManager__

#include <iostream>
#include "Game.h"

class ConfigManager {
private:
    static ConfigManager* m_pInstance;
    ConfigManager();
    
    GLint     window_width = 1000;
    GLint     window_height = 700;
    GLint     game_width = 800;
    GLint     game_height = 600;
    GLint     game_x = 100;
    GLint     game_y = 50;
    bool      r_blocks = true;
    GLint     num_init_balls = 3;
    double     platform_step = 1.7;
    
public:
    GLint getWindowWidth();
    GLint getWindowHeight();
    GLint getGameWidth();
    GLint getGameHeight();
    GLint getGameX();
    GLint getGameY();
    bool getRandomBlocks();
    int getNumInitBalls();
    double getPlatformStep();
    
    static ConfigManager* Instance();
	~ConfigManager();
};

#endif /* defined(__Bricks__ConfigManager__) */
