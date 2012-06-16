#ifndef DONNEE_H
#define DONNEE_H

#include <sstream>
#include <QString>
#include <QTextStream>
#include "typeexception.h"
#include <QMessageBox>


const float M_PI = 3.14159;

class Donnee
{
public:

    Donnee(){}
    virtual ~Donnee(){}
    virtual Donnee* operator+(Donnee & t)=0;
    virtual Donnee* operator/(Donnee & t)=0;
    virtual Donnee* operator*(Donnee & t)=0;
    virtual Donnee* operator-(Donnee & t)=0;
    virtual Donnee* pow(Donnee & t){throw typeException("erreur pow");}
    virtual Donnee* mod(Donnee & t){throw typeException("erreur mod");}
    virtual Donnee* sign(){throw typeException("erreur sign");}
    virtual Donnee* sinus(bool degre=false){throw typeException("erreur sinus");}
    virtual Donnee* cosinus(bool degre=false){throw typeException("erreur cosinus");}
    virtual Donnee* tangente(bool degre=false){throw typeException("erreur tangente");}
    virtual Donnee* sinush(bool degre=false){throw typeException("erreur sinush");}
    virtual Donnee* cosinush(bool degre=false){throw typeException("erreur cosinush");}
    virtual Donnee* tangenteh(bool degre=false){throw typeException("erreur tangenteh");}
    virtual Donnee* ln(){throw typeException("erreur ln");}
    virtual Donnee* log(){throw typeException("erreur log");}
    virtual Donnee* inv(){throw typeException("erreur inv");}
    virtual Donnee* sqrt(){throw typeException("erreur sqrt");}
    virtual Donnee* sqr(){throw typeException("erreur sqr");}
    virtual Donnee* cube(){throw typeException("erreur cube");}
    virtual Donnee* fact(){throw typeException("erreur fact");}
    virtual QString eval(){throw typeException("erreur eval");}
    static bool isEntier(const QString& s){QRegExp rx("^\\d+$"); return s.contains (rx);}
    static bool isReel(const QString& s){
        QString copie(s);
        copie.replace(',', '.');
        QRegExp rx("^-?\\d*\\.?\\d*$");
        return copie.contains(rx);}
    static bool isRationnel(const QString& s){QRegExp rx("^-?\\d*/-?\\d*$");  return s.contains (rx);}
    static bool isExpression(const QString& s){return s.contains ('\'');}
    static bool isComplexe(const QString& s){
        QString copie(s);
        copie.replace(',', '.');
        QRegExp rx("^-?\\d*(/|\\.)?.?\\$-?\\d*(/|\\.)?.?$");return copie.contains (rx);}
    virtual QString toQString()=0;
};




#endif // DONNEE_H
