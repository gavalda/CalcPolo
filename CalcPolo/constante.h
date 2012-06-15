#ifndef CONSTANTE_H
#define CONSTANTE_H
#include "D.h"
#include "Donnee.h"

class Constante : public D
{
public:
    Constante(){}
    virtual Donnee* operator+(Donnee & t)=0;
    virtual Donnee* operator/(Donnee & t)=0;
    virtual Donnee* operator*(Donnee & t)=0;
    virtual Donnee* operator-(Donnee & t)=0;
    virtual Donnee* pow(Donnee & t)=0;
    virtual Donnee* sign()=0;
    virtual Donnee* sinus(bool degre)=0;
    virtual Donnee* cosinus(bool degre)=0;
    virtual Donnee* tangente(bool degre)=0;
    virtual Donnee* sinush(bool degre)=0;
    virtual Donnee* cosinush(bool degre)=0;
    virtual Donnee* tangenteh(bool degre)=0;
    virtual Donnee* ln()=0;
    virtual Donnee* log()=0;
    virtual Donnee* inv()=0;
    virtual Donnee* sqrt()=0;
    virtual Donnee* sqr()=0;
    virtual Donnee* cube()=0;
    virtual QString eval(){throw typeException("erreur eval");}
};



#endif // CONSTANTE_H



