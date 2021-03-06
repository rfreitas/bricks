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
    return {
        .x = vector.x/mag,
        .y = vector.y/mag
    };
}

Pair vector( Pair pointStart, Pair pointEnd ){
    return {
        .x = pointEnd.x - pointStart.x,
        .y = pointEnd.y - pointStart.y
    };
}

double Shape::getWidth(){
    double* rec = getBounderyRectangle();
    return rec[2] - rec[0];
}


void Shape::setColor(sf::Color paramColor)
{
    color = paramColor;
}

sf::Color Shape::getColor()
{
    return color;
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

