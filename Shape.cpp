//
//  Shape.cpp
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//

#include "Shape.h"




/**
 * Component Constructor
 **/
Shape::Shape()
{
}

Shape::Shape(sf::Color colorValue)
{
    color = colorValue;
}

Pair Shape::center()
{
    double* rect = getBounderyRectangle();
    //Pair center;
    return {
        .x = (rect[2] - rect[0])/2,
        .y = (rect[3] - rect[1])/2
    };
}


/**
 * Destructor.
 **/
Shape::~Shape() {
    
}

