#ifndef GARDIEN_H
#define GARDIEN_H

#include <QVector>
#include <QStack>
#include "Donnee.h"


class Pile;

class gardien
{
    int currentStack;
    QVector <Pile*> tabPile;

public:

    gardien();

    Pile* undo();

    ~gardien();

    Pile* redo();

    void addMemoire(Pile* pile);
};

#endif // GARDIEN_H
