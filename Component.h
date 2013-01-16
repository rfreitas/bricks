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
#include <iostream>
#include "Component.h"
#include <SFML/Graphics.hpp>
#include "Assassin.h"
#include "LoseLife.h"
#include "DoNothing.h"

using namespace std;

typedef enum
{
    top = 0,
    left,
    right,
    bottom
    
}  POSITION;

typedef enum  { DoNothingType, AssassinType, LoseLifeType } behavioursType;



class Component {
private:
    static vector<Behaviour*> behaviours;
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
    vector<Behaviour*> getBehaviours();
    behavioursType collisionBehaviour;
	
public:
    Component();
    Component(double posX, double posY, double areaValue, double normalValue,
              double velocityVector, Shape* componentShape);
	
    ~Component();
    
    //PROTOTYPE
    Component* clone();
    
    POSITION whereRelativeTo(Component& comp);
    
    double  getX();
    double  getY();
    double  getArea();
    double  getNormal();
    double  getVelocity();
    Shape*  getShape();
    int getLife();
    
    //behaviour STRATEGY
    void doCollisionBehaviour(Component& collidedWith);
    behavioursType getBehaviour();
    void setBehaviour(behavioursType behaviourType);
    
    void    setX(double x);
    void    setY(double y);
    void    setShape(Shape* shapeObject);
    virtual void    willCollideWith(Component* comp);
    virtual void    collidedWith(Component* comp);
    void setLife(int newLife);
    
    void    draw(sf::RenderWindow &App);
    void    drawWithOrigin(sf::RenderWindow &App, double x, double y);
    
    Pair    normalVector(Pair externalPoint);
    Pair    center();
    
    void    newFrame();
    
    virtual bool collidingWith(Component* cB);
    virtual void evaluateCollisionWith(Component* componentB);
    virtual bool isGroup();
};


#endif /* defined(__SFML_Graphics_based_Application__Component__) */
