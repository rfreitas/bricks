//
//  Component.h
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//

#ifndef __SFML_Graphics_based_Application__Component__
#define __SFML_Graphics_based_Application__Component__
#pragma once
#include "Shape.h"
#include <iostream>

#endif /* defined(__SFML_Graphics_based_Application__Component__) */

typedef enum
{
    top = 0,
    left,
    right,
    bottom
}  POSITION;



class Component {
private:
	double x;
	double y;
    double area;
    double normal;
    double velocity;
    
    Shape* shape;
    
    // test
    double test;
	
public:
    Component();
    Component(double posX, double posY, double areaValue, double normalValue, double velocityVector, Shape* componentShape);
	
    ~Component();
    
    POSITION whereRelativeTo(Component& comp);
    
    double getX();
    double getY();
    double getArea();
    double getNormal();
    double getVelocity();
    Shape* getShape();
    
    void setX(double x);
    void setShape(Shape* shapeObject);
    void willCollideWith(Component& comp);
    void collidedWith(Component& comp);
    
    void draw(sf::RenderWindow &App);
    
    // for test
    void newFrame(time_t  currentTimeStamp, time_t  previousTimeStamp);
};
