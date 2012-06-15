#ifndef REEL_H
#define REEL_H

#include "Donnee.h"
#include <sstream>
#include <QString>

#include "Constante.h"
#include <QRegExp>


class reel:public Constante
{
    double data;
public:
    reel(double val=0):data(val){}
    reel(const QString &s)//pour convertir une QString en double
    {
        QString copie(s);
        copie.replace(',', '.');
        data = copie.toDouble();
    }
    double getData(){return data;}
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

    int getDecimales(){
        return toQString().section('.', 1,1).size();
                      }

};

#endif // REEL_H
