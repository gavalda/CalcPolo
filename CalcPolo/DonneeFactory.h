#ifndef DONNEEFACTORY_H
#define DONNEEFACTORY_H
#include <QString>
#include "Donnee.h"
#include <QStringList>

/// \file DonneeFactory.h
/// \author Clémence BLOT, Benoît GAVALDA
/// \brief DonneFactory Classe à instance unique qui créer les Objets de type Donnee (Reel, Rationnel, Entier, Complexe)
///
/// \param instance Instance unique
///
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
