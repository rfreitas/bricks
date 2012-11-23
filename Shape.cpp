//
//  Shape.cpp
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//

#include "Shape.h"


double vectorMagnitude( Pair vector){
    return sqrt(vector.x*vector.x + vector.y*vector.y);
}

Pair normalizeVector(Pair vector){
    double mag = vectorMagnitude(vector);
    Pair pair;
    pair.x = vector.x/mag;
    pair.y = vector.y/mag;
    return pair;
}

Pair vector( Pair pointStart, Pair pointEnd ){
    Pair pair;
    pair.x = pointEnd.x - pointStart.x;
    pair.y = pointEnd.y - pointStart.y;
    return pair;
}



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
    Pair center;
    
    center.x = (rect[2] - rect[0])/2;
    center.y = (rect[3] - rect[1])/2;
    return center;
}


/**
 * Destructor.
 **/
Shape::~Shape() {
    
}

