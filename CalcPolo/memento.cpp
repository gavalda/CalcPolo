#include "Memento.h"
#include "Pile.h"


Memento::Memento()
{
    currentStack = -1;
}

Memento::~Memento()
{
    for(int i=0; i<tabPile.size(); i++){
       delete tabPile.at(i);
    }
}

void Memento::addMemoire(Pile *pile){
tabPile.push_back(&pile->clone());
currentStack++;
}

Pile* Memento::undo(){
    if(currentStack > 0)
    {
     currentStack -= 1;
     return &tabPile.at(currentStack)->clone();
    }
    return 0;
}

Pile* Memento::redo(){
    if(currentStack >= 0 && currentStack < tabPile.size()-1)
    {
     currentStack += 1;
     return &tabPile.at(currentStack)->clone();
    }
    return 0;
}

