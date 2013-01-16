//
//  ComponentGroup.cpp
//  Bricks
//
//  Created by Ricardo Freitas on 20/12/2012.
//
//

#include "ComponentGroup.h"

ComponentGroup::ComponentGroup(){
}

ComponentGroup::~ComponentGroup(){
    
}



int ComponentGroup::getLife(){
    int life = 0;
    for(int i = 0; i < components.size() ; i++){
        life += components[i]->getLife();
    }
    return life;
}

void ComponentGroup::draw(sf::RenderWindow &App){
    for(int i = 0; i < components.size() ; i++){
        components[i]->drawWithOrigin(App, x, y);
    }
}

void ComponentGroup::drawWithOrigin(sf::RenderWindow &App, double xOrigin, double yOrigin)
{
    for(int i = 0; i < components.size() ; i++){
        components[i]->drawWithOrigin(App, x+xOrigin, y+yOrigin);
    }
}

void ComponentGroup::push_back(Component* component){
    components.push_back(component);
}


void ComponentGroup::removeDeadObjects(){
    for(int i = 0 ; i < components.size() ; i++)
    {
        if(components[i]->getLife() <= 0)
        {
            delete components[i];
            components.erase(components.begin()+i);
        }
    }
}

bool ComponentGroup::collidingWith(Component* cB)
{
    for(int i = 0 ; i < components.size() ; i++){
        if (components[i]->collidingWith(cB) ){
            return true;
        }
    }
    return false;
}

void ComponentGroup::evaluateCollisionWith(Component* componentB)
{
    for(int i = 0 ; i < components.size() ; i++){
        components[i]->evaluateCollisionWith(componentB);
    }
}

void ComponentGroup::willCollideWith(Component* comp){
    
}

void ComponentGroup::collidedWith(Component* comp){
    
}

void ComponentGroup::newFrame(){
    for(int i = 0 ; i < components.size() ; i++){
        components[i]->newFrame();
    }
}

bool ComponentGroup::isGroup(){
    return true;
}

int ComponentGroup::size(){
    return components.size();
}

Component* ComponentGroup::closestComponentTo(Component* other){
    int min = INT_MAX;
    Component* closest = NULL;
    for (int i=0; i< components.size(); i++){
        int dist = components[i]->distance(other);
        if ( dist < min ){
            closest = other;
            min = dist;
        }
    }
    return closest;
}