//
//  RectangleShape.h
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//

#ifndef __SFML_Graphics_based_Application__RectangleShape__
#define __SFML_Graphics_based_Application__RectangleShape__
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#endif /* defined(__SFML_Graphics_based_Application__RectangleShape__) */

class RectangleShape: public Shape {
private:
    double x1;
    double y1;
    double x2;
    double y2;
    
public:
    RectangleShape(double px1, double py1, double px2, double py2);
    RectangleShape(double px1, double py1, double px2, double py2, sf::Color colorValue);

	~RectangleShape();
    
    void draw(sf::RenderWindow &App, double x, double y);
    double* getBounderyRectangle();
    
    double getX2();
};