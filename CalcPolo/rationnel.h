#ifndef RATIONNEL_H
#define RATIONNEL_H

#include "Donnee.h"
#include <iostream>
#include <sstream>
#include <QString>

#include "Constante.h"
#include "DonneeException.h"
#include <QRegExp>


/// \file Rationnel.h
/// \author Clémence BLOT, Benoît GAVALDA
/// \brief Rationnel contient la classe permet de générer les objets stockant les rationnels
///
/// \param num numérateur
///  \param denum dénominateur

class Rationnel:public Constante
{
    int num;
    int denum;
public:

    Rationnel(int _num=0,int _denum=1):num(_num),denum(_denum){if (denum==0) throw DonneeException("Division par 0"); simplifie();}

    Rationnel(const QString &s)                 //convertion QString Rationnel
    {
        QRegExp rx2("^\\d+$");
        QString copie(s);
        if (copie.contains(rx2))
        {
            num=s.toInt();
            denum=1;

        }
        else
        {
            num=(copie.section('/', 0,0)).toInt();
            denum=(copie.section('/', 1,1)).toInt();
             if (denum==0) throw DonneeException("Division par 0");
            simplifie();

        }


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
