#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QString>
#include "Donnee.h"


class Expression : public Donnee
{
    QString exp;
public:
    Expression(QString &exp1);
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
    QString eval();
    QString toQString(){return exp;}

};

#endif // EXPRESSION_H
