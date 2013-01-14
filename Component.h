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
    double  area;
    double  normal;
    double  velocity;
    Pair    previousPosition;
    Pair    vVector;
    int life;
    
    Shape*  shape;
    
protected:
    double  x;
	double  y;
	
public:
    bool group;
    Component();
    Component(double posX, double posY, double areaValue, double normalValue,
              double velocityVector, Shape* componentShape);
	
    ~Component();
    
    virtual void doCollisionBehaviour(Component& collidedWith){};
    
    POSITION whereRelativeTo(Component& comp);
    
    double  getX();
    double  getY();
    double  getArea();
    double  getNormal();
    double  getVelocity();
    Shape*  getShape();
    int getLife();
    
    void    setX(double x);
    void    setShape(Shape* shapeObject);
    void    setStatus(Status* statusParam);
    virtual void    willCollideWith(Component* comp);
    virtual void    collidedWith(Component* comp);
    void setLife(int newLife);
    
    void    draw(sf::RenderWindow &App);
    void    drawWithOrigin(sf::RenderWindow &App, double x, double y);
    
    Pair    normalVector(Pair externalPoint);
    Pair    center();
    
    void    newFrame(unsigned long currentTimeStamp, unsigned long previousTimeStamp);
    
    virtual bool collidingWith(Component* cB);
    virtual void evaluateCollisionWith(Component* componentB);
    virtual bool isGroup();
};


#endif /* defined(__SFML_Graphics_based_Application__Component__) */
