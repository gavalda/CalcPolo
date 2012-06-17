#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "Expression.h"
#include "DonneeException.h"

#include <cmath>




Donnee* Reel::operator +(Donnee & t){

    try{

       Entier &tmp=dynamic_cast<Entier&>(t);
       Reel *resultat=new Reel(data+tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try{

       Reel &tmp=dynamic_cast<Reel&>(t);
       Reel *resultat=new Reel(data+tmp.getData());
       return resultat;
       }
    catch(std::exception &e){}

  /*  try{

       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Donnee* resultat;
       Rationnel r(data*10*getDecimales(),10*getDecimales());
       resultat=tmp+r;
       return resultat;
    }
    catch(std::exception &e){}

    try{

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " +'";
       return new Expression(e);
    }
    catch(std::exception &e){}

    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       Complexe conv(toQString());
       Donnee * resultat;
       resultat=conv+tmp;
       return resultat;
    }
    catch(std::exception &e){}
*/
    throw DonneeException("erreur Reel op+");


}

Donnee* Reel::operator /(Donnee & t){
    try{
      /* Reel &tmp=dynamic_cast<Reel&>(t);
       Rationnel r(data*10*getDecimales(),10*getDecimales());
       Rationnel r1(tmp.getData()*10*tmp.getDecimales(),10*tmp.getDecimales());
       return r/r1;*/
       Reel &tmp=dynamic_cast<Reel&>(t);
       Reel *resultat=new Reel(data/tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{
       Entier &tmp=dynamic_cast<Entier&>(t);
       Rationnel r(data*10*getDecimales(),10*getDecimales());
       Rationnel r1(tmp.getData(),1);
       return r/r1;
    }
    catch(std::exception &e){}

    try{

       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Donnee* resultat;
       Rationnel r(data*10*getDecimales(),10*getDecimales());
       resultat=tmp+r;
       return resultat;
    }
    catch(std::exception &e){}

    try{

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " /'";
       return new Expression(e);
    }
    catch(std::exception &e){}

    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       Complexe conv(toQString());
       Donnee * resultat;
       resultat=conv/tmp;
       return resultat;
    }
    catch(std::exception &e){}
*/
    throw DonneeException("erreur Reel op/");
}

Donnee* Reel::operator*(Donnee& t){
    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       Reel *resultat=new Reel(data*tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{

       Entier &tmp=dynamic_cast<Entier&>(t);
       Reel *resultat=new Reel(data*tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}


    try{

       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Rationnel r(data*10*getDecimales(),10*getDecimales());
       return r*tmp;
    }
    catch(std::exception &e){}

    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       Complexe conv(toQString());
       Donnee * resultat;
       resultat=conv*tmp;
       return resultat;
    }
    catch(std::exception &e){}

    try{

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() +" "+ tmp.toQString().remove("'") + " *'";
       return new Expression(e);
    }
    catch(std::exception &e){}
*/
    throw DonneeException("erreur Reel op*");
}

Donnee* Reel::operator-(Donnee& t){
    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       Reel *resultat=new Reel(data-tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{

       Entier &tmp=dynamic_cast<Entier&>(t);
       Reel *resultat=new Reel(data-tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}


    try{

       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Rationnel r(data*10*getDecimales(),10*getDecimales());
       return r-tmp;
    }
    catch(std::exception &e){}

    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       Complexe conv(toQString());
       Donnee * resultat;
       resultat=conv-tmp;
       return resultat;
    }
    catch(std::exception &e){}

    try{

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " -'";
       return new Expression(e);
    }
    catch(std::exception &e){}
*/
    throw DonneeException("erreur Reel op-");
}


Donnee* Reel::pow(Donnee & t){
/*    try{

       Entier &tmp=dynamic_cast<Entier&>(t);
       Reel *resultat=new Reel(std::pow(data,tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}
*/
    try{

       Reel &tmp=dynamic_cast<Reel&>(t);
       Reel *resultat=new Reel(std::pow(data,tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}

    throw DonneeException("erreur Reel pow");
}

QString Reel::toQString(){
    QString resultat;
    QTextStream ss(&resultat);
    ss << data;
    return resultat;
}

Donnee* Reel::sign(){
    double tmp(-data);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Reel::sinus(bool degre){
    double tmp(data);
    if(degre)
        tmp=sin(tmp*M_PI /180);
    else
        tmp=sin(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Reel::cosinus(bool degre){
    double tmp(data);
    if(degre)
        tmp=cos(tmp*M_PI /180);
    else
        tmp=cos(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Reel::tangente(bool degre){
    double tmp(data);
    if(degre)
        tmp=tan(tmp*M_PI /180);
    else
        tmp=tan(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Reel::sinush(bool degre){
    double tmp(data);
    if(degre)
        tmp=sinh(tmp*M_PI /180);
    else
        tmp=sinh(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Reel::cosinush(bool degre){
    double tmp(data);
    if(degre)
        tmp=cosh(tmp*M_PI /180);
    else
        tmp=cosh(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Reel::tangenteh(bool degre){
    double tmp(data);
    if(degre)
        tmp=tanh(tmp*M_PI /180);
    else
        tmp=tanh(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}


Donnee* Reel::ln(){
    double tmp(data);
    tmp=std::log(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Reel::log(){
    double tmp(data);
    tmp=log10(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Reel::inv(){
    double tmp(data);
    tmp=1/tmp;
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Reel::sqrt(){
    double tmp(data);
    tmp=std::sqrt(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Reel::sqr(){
    double tmp(data);
    tmp=std::pow(tmp,2);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Reel::cube(){
    double tmp(data);
    tmp=std::pow(tmp,3);
    Donnee* t= new Reel(tmp);
    return t;
}
