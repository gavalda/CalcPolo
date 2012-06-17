#ifndef DONNEEFACTORY_H
#define DONNEEFACTORY_H
#include <QString>
#include "Donnee.h"
#include <QStringList>

class DonneeFactory
{
    static DonneeFactory * instance;/*!<  Instance unique de la factory*/
public:

    DonneeFactory (const DonneeFactory&);

    ~DonneeFactory(){}

    DonneeFactory(){}

    DonneeFactory operator =(const DonneeFactory);
public:

    static DonneeFactory& getInstance();

    static void releaseInstance();

    Donnee* getType(QString s);

};

#endif // DONNEEFACTORY_H
