#ifndef DOM_H
#define DOM_H

#include <QTextStream>
#include <QtXml/QDomDocument>
#include <QFile>
#include <QMessageBox>
#include <QString>

#include "pile.h"


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
