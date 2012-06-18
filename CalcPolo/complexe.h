#ifndef COMPLEXE_H
#define COMPLEXE_H

#include "Donnee.h"
#include <sstream>
#include <QString>
#include "Constante.h"
#include "DonneeFactory.h"
#include "Reel.h"

#include "D.h"

/// \file Complexe.h
/// \author Clémence BLOT, Benoît GAVALDA
/// \brief Complexe contient la classe complexe qui hérite de D, elle même héritant de Donnee.
/// cette classe sert à créer les objets complexes a&b (lorsque le mode complexe est activé)
/// \param re partie réelle
/// \param im partie imaginaire


class Complexe:public D
{
    Constante*  re;
    Constante*  im;
public:

    Complexe(Constante* _re=0,Constante* _im=0):re(_re), im(_im){}



    Donnee* conjugue();

    Complexe(const QString &s)//pour convertir une QString en complexe
    {
        QString copie(s);

        re=new Reel(copie.section('$', 0,0));
        im=new Reel(copie.section('$', 1,1));
    }

    Donnee* operator +(Donnee & t);

    Donnee* operator /(Donnee & t);

    Donnee* operator*(Donnee& t);

    Donnee* operator-(Donnee& t);

    Donnee* sqr();

    Donnee* cube();

    Donnee* inv();

    Donnee* sign();


    Constante* getRe(){return re;}

    Constante* getIm(){return im;}



    QString toQString();



};

#endif // COMPLEXE_H
