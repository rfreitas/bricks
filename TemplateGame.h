//
//  TemplateGame.h
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 19/12/12.
//
//

#ifndef __Bricks__TemplateGame__
#define __Bricks__TemplateGame__

#include <iostream>

using namespace std;

class TemplateGame {
private:
    
public:
    virtual void initializeGame() = 0;
    virtual void checkCollisions() = 0;
    virtual void move() = 0;
    virtual void draw() = 0;
    virtual void keyboardListenner() = 0;
    virtual bool gameIsRunning() = 0;
    virtual bool isGamePaused() = 0;
    virtual void removeDeadObjects() = 0;
    virtual bool didGameFinished() = 0;
    
    TemplateGame();
	~TemplateGame();
    
    void run();
};

#endif /* defined(__Bricks__TemplateGame__) */
