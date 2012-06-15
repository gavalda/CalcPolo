#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "Donnee.h"
#include <iostream>
#include <sstream>
#include <QString>

#include "Constante.h"
#include "typeexception.h"
#include <QRegExp>



class rationnel:public Constante
{
    int num;
    int denum;
public:

    rationnel(int _num=0,int _denum=1):num(_num),denum(_denum){if (denum==0) throw typeException("Division par 0"); simplifie();}

    rationnel(const QString &s)//pour convertir une QString en rationnel
    {
        QString copie(s);

        num=(copie.section('/', 0,0)).toInt();
        denum=(copie.section('/', 1,1)).toInt();
         if (denum==0) throw typeException("Division par 0");
        simplifie();

    }

    Donnee* operator +(Donnee & t);

    Donnee* operator /(Donnee & t);

    Donnee* operator*(Donnee& t);

    Donnee* operator-(Donnee& t);

    Donnee* sinus(bool degre);

    Donnee* pow(Donnee & t);

    Donnee* sign();

    Donnee* cosinus(bool degre);

    Donnee* tangente(bool degre);

    Donnee* sinush(bool degre);

    Donnee* cosinush(bool degre);

    Donnee* tangenteh(bool degre);

    Donnee* ln();

    Donnee* log();

    Donnee* inv();

    Donnee* sqrt();

    Donnee* sqr();

    Donnee* cube();

    QString toQString();

    QString eval();

    void simplifie();

    int pgcd(int, int ) const;

    int getNum(){return num;}

    int getDenum(){return denum;}


};

#endif // RATIONNEL_H
