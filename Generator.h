#ifndef __SFML_Graphics_based_Application__Generator__
#define __SFML_Graphics_based_Application__Generator__

#include <iostream>
#include "ComponentGroup.h"

using namespace std;

class Generator {
private:
public:
    Generator();
	~Generator();
    
    void randomBlocks(ComponentGroup* components);
    void randomBalls(ComponentGroup* balls, int numBalls);
};

#endif /* defined(__SFML_Graphics_based_Application__Generator__) */