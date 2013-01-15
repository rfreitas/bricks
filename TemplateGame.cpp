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
    initializeGame();
    
    while (gameIsRunning() && !didGameFinished())
    {
        keyboardListenner();
        
        if(!isGamePaused()){
            iterate();
            draw();
        }
    }
    
    clean();
}