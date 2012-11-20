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

#include <iostream>
#include "Shape.h"

#endif /* defined(__SFML_Graphics_based_Application__Component__) */


class Component {
private:
	double x;
	double y;
    double area;
    double normal;
    double velocity;
    
    Shape* shape;
	
public:
    Component();
    Component(double posX, double posY, double areaValue, double normalValue, double velocityVector, Shape* componentShape);
	
    ~Component();
    
    double getX();
    double getY();
    double getArea();
    double getNormal();
    double getVelocity();
    
    
    // for test
    void moveMe();
};
