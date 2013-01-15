#include "ConfigManager.h"

ConfigManager* ConfigManager::m_pInstance = NULL;

ConfigManager* ConfigManager::Instance()
{
    if (!m_pInstance) {
        m_pInstance = new ConfigManager;
    }
    return m_pInstance;
}

GLint ConfigManager::getWindowWidth(){
    return window_width;
}

GLint ConfigManager::getWindowHeight(){
    return window_height;
}

GLint ConfigManager::getGameWidth(){
    return game_width;
}

GLint ConfigManager::getGameHeight() {
    return game_height;
}

GLint ConfigManager::getGameX() {
    return game_x;
}

GLint ConfigManager::getGameY() {
    return game_y;
}

bool ConfigManager::getRandomBlocks() {
    return r_blocks;
}

int ConfigManager::getNumInitBalls(){
    return num_init_balls;
}

int ConfigManager::getPlatformStep(){
    return platform_step;
}

ConfigManager::ConfigManager() {
    
}





