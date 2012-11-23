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
    Pair vVector;
    
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
    
    Pair normalVector(Pair externalPoint);
    Pair center();
    
    // for test
    void newFrame(unsigned long long  currentTimeStamp, unsigned long long  previousTimeStamp);
};

#endif /* defined(__SFML_Graphics_based_Application__Component__) */

