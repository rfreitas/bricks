//
//  Subject.h
//  Bricks
//
//  Created by Ricardo Freitas on 19/12/2012.
//
//

//#import "Observer.h"
#ifndef __Bricks__Subject__
#define __Bricks__Subject__

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Observer;

class Subject {
    protected:
    vector<Observer*> observers;
    
    public:
        Subject();
    ~Subject();
        void attach(Observer* observer);
        void deattach(Observer* observer);
        void notify();
};


class Observer {
    
public:
    virtual void update(Subject* input );
    Observer();
    ~Observer();
};

#endif /* defined(__Bricks__Subject__) */