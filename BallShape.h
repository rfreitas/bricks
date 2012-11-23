//
//  BallShape.h
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 21/11/12.
//
//

#ifndef __SFML_Graphics_based_Application__BallShape__
#define __SFML_Graphics_based_Application__BallShape__
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class BallShape: public Shape {
private:
    double radius;
    
public:
    BallShape(double radiusValue);
    BallShape(double radiusValue, sf::Color colorValue);
    
	~BallShape();
    
    void draw(sf::RenderWindow &App, double x, double y);
    double* getBounderyRectangle();
    Pair normalVector( Pair externalPoint, Pair topLeft);
};


#endif /* defined(__SFML_Graphics_based_Application__BallShape__) */
