//
//  ComponentGroup.h
//  Bricks
//
//  Created by Ricardo Freitas on 20/12/2012.
//
//

#ifndef __Bricks__ComponentGroup__
#define __Bricks__ComponentGroup__

#include "Component.h"

class ComponentGroup: public Component {
    private:
         vector<Component*> components;
    
    public:
        ComponentGroup();
        ~ComponentGroup();
        int getLife();
        void    draw(sf::RenderWindow &App);
        void    drawWithOrigin(sf::RenderWindow &App, double x, double y);
        void    push_back(Component* component);
        void    removeDeadObjects();
    
        bool collidingWith(Component* cB);
        void evaluateCollisionWith(Component* componentB);
        void newFrame();
        bool isGroup();
        int size();
    
        void willCollideWith(Component* comp);
        void collidedWith(Component* comp);
    
        Component* closestComponentTo(Component* other);
};
#endif /* defined(__Bricks__ComponentGroup__) */
