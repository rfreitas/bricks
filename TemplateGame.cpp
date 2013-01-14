//
//  TemplateGame.cpp
//  Bricks
//
//  Created by Nuno André Fontes Vinhas on 19/12/12.
//
//

#include "TemplateGame.h"


TemplateGame::TemplateGame()
{
}

TemplateGame::~TemplateGame()
{
}

void TemplateGame::run()
{
    while(true){
        initializeGame();
        
        while (gameIsRunning())
        {
            keyboardListenner();
            
            if(!isGamePaused()){
                move();
                checkCollisions();
                removeDeadObjects();
                if(didGameFinished()) break;
                draw();
            }
        }
        
        clean();
    }
    
}