#ifndef DOM_H
#define DOM_H

#include <QTextStream>
#include <QtXml/QDomDocument>
#include <QFile>
#include <QMessageBox>
#include <QString>

#include "pile.h"


/// \file Dom.h
/// \author Cl�mence BLOT, Beno�t GAVALDA
/// \brief Dom classe contenant les m�thodes d'�criture et de lecture de piles.
///
///
///

class Dom
{
public:

    Dom(Pile & p);

    ~Dom(){}
    void ecrire(QString fileName);

    void lire(QString fileName);

private :
    Pile& p;/*!< Pile a charger ou a sauvegarder*/
};

#endif // DOM_H
