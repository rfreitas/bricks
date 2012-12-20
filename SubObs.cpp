//
//  Subject.cpp
//  Bricks
//
//  Created by Ricardo Freitas on 19/12/2012.
//
//

#include "SubObs.h"


Subject::Subject(){
    
}

Subject::~Subject()
{
    
}

void Subject::notify(){
    for (int i = 0; i< observers.size(); i++) {
        observers[i]->update(this);
    }
}


void Subject::attach(Observer* observer){
    observers.push_back(observer);
}

void Subject::deattach(Observer* observer){
    //lol
}


//Observer
Observer::Observer()
{
    
}

Observer::~Observer()
{
    
}