//
//  Shape.h
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//

#ifndef __SFML_Graphics_based_Application__Shape__
#define __SFML_Graphics_based_Application__Shape__

#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>



struct Pair {
    double x;
    double y;
};

double vectorMagnitude( Pair vector);
Pair normalizeVector(Pair vector);
Pair vector( Pair pointStart, Pair pointEnd );

class Shape {
protected:
    sf::Color color;
    
public:
    virtual void draw(sf::RenderWindow &App, double x, double y){};
    virtual double* getBounderyRectangle(){};
    virtual Pair normalVector( Pair externalPoint, Pair topLeft){};
    
    Shape();
    Shape(sf::Color colorValue);
	~Shape();
    
    Pair center();
    
   
    
};

#endif /* defined(__SFML_Graphics_based_Application__Shape__) */

