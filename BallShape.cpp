//
//  BallShape.cpp
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 21/11/12.
//
//
#include "Shape.h"
#include "BallShape.h"

/**
 * Component Constructor
 **/
BallShape::BallShape(double radiusValue):Shape()
{
    radius = radiusValue;
}

BallShape::BallShape(double radiusValue, sf::Color colorValue)
:Shape(colorValue)
{
    radius = radiusValue;
}


/**
 * Destructor.
 **/
BallShape::~BallShape() {
    
}

void BallShape::draw(sf::RenderWindow &App, double x, double y)
{
    App.Draw(sf::Shape::Circle(x, y, radius, Shape::color));
}

double* BallShape::getBounderyRectangle(){
    double *bounderies = new double[4];
    bounderies[0] = 0;
    bounderies[1] = 0;
    bounderies[2] = radius;
    bounderies[3] = radius;
    return bounderies;
}