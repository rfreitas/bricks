//
//  Generator.h
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//
#ifndef __SFML_Graphics_based_Application__Generator__
#define __SFML_Graphics_based_Application__Generator__

#include <iostream>
#include "ComponentGroup.h"

using namespace std;

class Generator {
private:
	double game_x;
    double game_y;
    double game_width;
    double game_height;
public:
    Generator(double game_xParam, double game_y, double game_width, double game_height);
	~Generator();
    
    void randomBlocks(ComponentGroup* components);
    void randomBalls(ComponentGroup* balls, int numBalls);
};

#endif /* defined(__SFML_Graphics_based_Application__Generator__) */