//
//  Component.h
//  SFML Graphics-based Application
//
//  Created by Nuno André Fontes Vinhas on 20/11/12.
//
//

#ifndef __SFML_Graphics_based_Application__Component__
#define __SFML_Graphics_based_Application__Component__

#include "Shape.h"
#include "Status.h"
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
	double  x;
	double  y;
    double  area;
    double  normal;
    double  velocity;
    Pair    previousPosition;
    Pair    vVector;
    
    Shape*  shape;
    Status* status;
	
public:
    Component();
    Component(double posX, double posY, double areaValue, double normalValue,
              double velocityVector, Shape* componentShape, Status* statusParam);
	
    ~Component();
    
    virtual void doCollisionBehaviour(){};
    
    POSITION whereRelativeTo(Component& comp);
    
    double  getX();
    double  getY();
    double  getArea();
    double  getNormal();
    double  getVelocity();
    Shape*  getShape();
    Status* getStatus();
    
    void    setX(double x);
    void    setShape(Shape* shapeObject);
    void    setStatus(Status* statusParam);
    void    willCollideWith(Component& comp);
    void    collidedWith(Component& comp);
    
    void    draw(sf::RenderWindow &App);
    
    Pair    normalVector(Pair externalPoint);
    Pair    center();
    
    void    newFrame(unsigned long currentTimeStamp, unsigned long previousTimeStamp);
};


#endif /* defined(__SFML_Graphics_based_Application__Component__) */
