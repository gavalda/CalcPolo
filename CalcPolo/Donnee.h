#ifndef DONNEE_H
#define DONNEE_H

#include <sstream>
#include <QString>
#include <QTextStream>
#include "DonneeException.h"
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
    virtual Donnee* pow(Donnee & t){throw DonneeException("erreur pow");}
    virtual Donnee* mod(Donnee & t){throw DonneeException("erreur mod");}
    virtual Donnee* sign(){throw DonneeException("erreur sign");}
    virtual Donnee* sinus(bool degre=false){throw DonneeException("erreur sinus");}
    virtual Donnee* cosinus(bool degre=false){throw DonneeException("erreur cosinus");}
    virtual Donnee* tangente(bool degre=false){throw DonneeException("erreur tangente");}
    virtual Donnee* sinush(bool degre=false){throw DonneeException("erreur sinush");}
    virtual Donnee* cosinush(bool degre=false){throw DonneeException("erreur cosinush");}
    virtual Donnee* tangenteh(bool degre=false){throw DonneeException("erreur tangenteh");}
    virtual Donnee* ln(){throw DonneeException("erreur ln");}
    virtual Donnee* log(){throw DonneeException("erreur log");}
    virtual Donnee* inv(){throw DonneeException("erreur inv");}
    virtual Donnee* sqrt(){throw DonneeException("erreur sqrt");}
    virtual Donnee* sqr(){throw DonneeException("erreur sqr");}
    virtual Donnee* cube(){throw DonneeException("erreur cube");}
    virtual Donnee* fact(){throw DonneeException("erreur fact");}
    virtual QString eval(){throw DonneeException("erreur eval");}


    static bool isEntier(const QString& s){QRegExp rx("^\\d+$"); return s.contains (rx);}

    static bool isReel(const QString& s)
    {
        QString copie(s);
        copie.replace(',', '.');
        QRegExp rx("^-?\\d*\\.?\\d*$");
        return copie.contains(rx);
        return false;
    }

    static bool isRationnel(const QString& s)
    {
        QRegExp rx1("^-?\\d*/-?\\d*$");



        if (s.contains(rx1)) return true;
        else return false;

    }

    static bool isExpression(const QString& s){return s.contains ('\'');}

    static bool isComplexe(const QString& s)
    {
        QString copie(s);
        copie.replace(',', '.');
        QRegExp rx("^-?\\d*(/|\\.)?.?\\$-?\\d*(/|\\.)?.?$");return copie.contains (rx);
    }

    virtual QString toQString()=0;
};




#endif // DONNEE_H
