
#include "CollectionPile.h"

CollectionPile* CollectionPile::instance=0;

CollectionPile& CollectionPile::getInstance()
{
    if (instance==0)
        instance = new CollectionPile;
    return *instance;

}


void CollectionPile::addPile(Pile* p)
{
    push_back(&p->duplique());
}

void CollectionPile::releaseInstance()
{
    if (instance!=0)
        delete instance;
}

