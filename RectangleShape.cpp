//
//  RectangleShape.cpp
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//
#include "Shape.h"
#include "RectangleShape.h"



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
    //printf("extPoint: %f,%f \n", externalPoint.x, externalPoint.y);
    //printf(" topLeft: %f,%f \n", topLeft.x, topLeft.y);
    
    
    if ( externalPoint.x <= topLeft.x +3){
        outNormal.x = -1;
    }
    else if (externalPoint.x >= bottomRight.x){
        outNormal.x = 1;
    }
    else if (  externalPoint.y <= topLeft.y ){
        outNormal.y = -1;
    }
    else if ( externalPoint.y >= bottomRight.y ){
        outNormal.y = 1;
    }
    else{
        //externa point is actually internal, to compensate for that we will look for the closest side of the rectangle to the supposed external point
        int distToLeftSide = topLeft.x - externalPoint.x;
        outNormal.x = -1;
        int minDist = distToLeftSide;
        
        int distToRightSide = abs(bottomRight.x - externalPoint.x);
        if ( distToRightSide <  minDist ){
            outNormal.x = 1;
            minDist = distToRightSide;
        }
        int distToTopSide = abs(topLeft.y - externalPoint.y);
        if ( distToTopSide <  minDist ){
            outNormal.y = -1;
            outNormal.x = 0;
            minDist = distToTopSide;
        }
        int distToBottomSide = abs(bottomRight.y -externalPoint.y);
        if ( distToBottomSide <  minDist ){
            outNormal.y = 1;
            outNormal.x = 0;
        }
        
    }
    //printf("%f,%f\n", outNormal.x, outNormal.y);
    return outNormal;
}