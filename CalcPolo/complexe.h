#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "Donnee.h"
#include <sstream>
#include <QString>
#include "Constante.h"
#include "type_factory.h"

#include "D.h"

class complexe:public D
{
    Constante*  re;
    Constante* im;
public:

    complexe(Constante* _re=0,Constante* _im=0):re(_re), im(_im){}



    Donnee* conjugue();

    complexe(const QString &s)//pour convertir une QString en complexe
    {
        QString copie(s);

        re=dynamic_cast<Constante*>(type_factory::getInstance().getType((copie.section('$', 0,0))));
        im=dynamic_cast<Constante*>(type_factory::getInstance().getType((copie.section('$', 1,1))));
    }

    Donnee* operator +(Donnee & t);

    Donnee* operator /(Donnee & t);

    Donnee* operator*(Donnee& t);

    Donnee* operator-(Donnee& t);




    Donnee* sign();


    Constante* getRe(){return re;}

    Constante* getIm(){return im;}

    QString toQString();



};

#endif // COMPLEXE_H
