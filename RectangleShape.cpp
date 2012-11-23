//
//  RectangleShape.cpp
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//
#include "Shape.h"
#include "RectangleShape.h"
#include <CoreServices/CoreServices.h>



/**
 * Component Constructor
 **/
RectangleShape::RectangleShape(double px1, double py1, double px2, double py2):Shape()
{
    x1 = px1;
    x2 = px2;
    y1 = py1;
    y2 = py2;
}

RectangleShape::RectangleShape(double px1, double py1, double px2, double py2, sf::Color colorValue)
:Shape(colorValue)
{
    x1 = px1;
    x2 = px2;
    y1 = py1;
    y2 = py2;
}


/**
 * Destructor.
 **/
RectangleShape::~RectangleShape() {
    
}

void RectangleShape::draw(sf::RenderWindow &App, double x, double y)
{
    App.Draw(sf::Shape::Rectangle(x1+x, y1+y, x2+x, y2+y, Shape::color));
}

double* RectangleShape::getBounderyRectangle(){
    double *bounderies = new double[4];
    bounderies[0] = x1;
    bounderies[1] = y1;
    bounderies[2] = x2;
    bounderies[3] = y2;
    return bounderies;
}

double RectangleShape::getX2(){
    return x2;
}


Pair RectangleShape::normalVector( Pair externalPoint, Pair topLeft){
    Pair bottomRight = {
        .x = topLeft.x + x2,
        .y = topLeft.y + y2
    };
    Pair outNormal = {
      .x = 0,
        .y = 0
    };
    if ( externalPoint.x <= topLeft.x){
        outNormal.x = -1;
    }
    else if (externalPoint.x >= topLeft.x){
        outNormal.x = 1;
    }
    else if (  externalPoint.y <= topLeft.y ){
        outNormal.y = -1;
    }
    else if ( externalPoint.y >= topLeft.y ){
        outNormal.y = 1;
    }
    else{
        //error
    }
    return outNormal;
}