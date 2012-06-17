#ifndef ENTIER_H
#define ENTIER_H

#include "Donnee.h"
#include <sstream>
#include <QString>
#include "Constante.h"
 #include <QRegExp>


/// \file Entier.h
/// \author Clémence BLOT, Benoît GAVALDA
/// \brief Entier contient la classe permet de générer les objets stockant les entiers
///
/// \param data La donnée à stocker
///

class Entier:public Constante
{
    int data;
public:
    Entier(int val=0):data(val){}
    Entier(const QString &s)//pour convertir une QString en int
        {data = s.toInt();}
    int getData(){return data;}
    Donnee* operator +(Donnee & t);
    Donnee* operator /(Donnee & t);
    Donnee* operator*(Donnee& t);
    Donnee* operator-(Donnee& t);
    Donnee* sinus(bool degre=false);
    Donnee* pow(Donnee & t);
    Donnee* mod(Donnee & t);
    Donnee* sign();
    Donnee* cosinus(bool degre=false);
    Donnee* tangente(bool degre=false);
    Donnee* sinush(bool degre=false);
    Donnee* cosinush(bool degre=false);
    Donnee* tangenteh(bool degre=false);
    Donnee* ln();
    Donnee* log();
    Donnee* inv();
    Donnee* sqrt();
    Donnee* sqr();
    Donnee* cube();
    Donnee* fact();
    QString toQString();


};

#endif // ENTIER_H
