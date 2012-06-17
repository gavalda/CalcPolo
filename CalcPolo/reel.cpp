#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"
#include "typeexception.h"

#include <cmath>




Donnee* reel::operator +(Donnee & t){

    try{

       entier &tmp=dynamic_cast<entier&>(t);
       reel *resultat=new reel(data+tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try{

       reel &tmp=dynamic_cast<reel&>(t);
       reel *resultat=new reel(data+tmp.getData());
       return resultat;
       }
    catch(std::exception &e){}

  /*  try{

       rationnel &tmp=dynamic_cast<rationnel&>(t);
       Donnee* resultat;
       rationnel r(data*10*getDecimales(),10*getDecimales());
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
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
       Donnee * resultat;
       resultat=conv+tmp;
       return resultat;
    }
    catch(std::exception &e){}
*/
    throw typeException("erreur reel op+");


}

Donnee* reel::operator /(Donnee & t){
    try{
      /* reel &tmp=dynamic_cast<reel&>(t);
       rationnel r(data*10*getDecimales(),10*getDecimales());
       rationnel r1(tmp.getData()*10*tmp.getDecimales(),10*tmp.getDecimales());
       return r/r1;*/
       reel &tmp=dynamic_cast<reel&>(t);
       reel *resultat=new reel(data/tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       rationnel r(data*10*getDecimales(),10*getDecimales());
       rationnel r1(tmp.getData(),1);
       return r/r1;
    }
    catch(std::exception &e){}

    try{

       rationnel &tmp=dynamic_cast<rationnel&>(t);
       Donnee* resultat;
       rationnel r(data*10*getDecimales(),10*getDecimales());
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
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
       Donnee * resultat;
       resultat=conv/tmp;
       return resultat;
    }
    catch(std::exception &e){}
*/
    throw typeException("erreur reel op/");
}

Donnee* reel::operator*(Donnee& t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *resultat=new reel(data*tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{

       entier &tmp=dynamic_cast<entier&>(t);
       reel *resultat=new reel(data*tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}


    try{

       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel r(data*10*getDecimales(),10*getDecimales());
       return r*tmp;
    }
    catch(std::exception &e){}

    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
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
    throw typeException("erreur reel op*");
}

Donnee* reel::operator-(Donnee& t){
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *resultat=new reel(data-tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{

       entier &tmp=dynamic_cast<entier&>(t);
       reel *resultat=new reel(data-tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}


    try{

       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel r(data*10*getDecimales(),10*getDecimales());
       return r-tmp;
    }
    catch(std::exception &e){}

    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
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
    throw typeException("erreur reel op-");
}


Donnee* reel::pow(Donnee & t){
/*    try{

       entier &tmp=dynamic_cast<entier&>(t);
       reel *resultat=new reel(std::pow(data,tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}
*/
    try{

       reel &tmp=dynamic_cast<reel&>(t);
       reel *resultat=new reel(std::pow(data,tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}

    throw typeException("erreur reel pow");
}

QString reel::toQString(){
    QString resultat;
    QTextStream ss(&resultat);
    ss << data;
    return resultat;
}

Donnee* reel::sign(){
    double tmp(-data);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* reel::sinus(bool degre){
    double tmp(data);
    if(degre)
        tmp=sin(tmp*M_PI /180);
    else
        tmp=sin(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* reel::cosinus(bool degre){
    double tmp(data);
    if(degre)
        tmp=cos(tmp*M_PI /180);
    else
        tmp=cos(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* reel::tangente(bool degre){
    double tmp(data);
    if(degre)
        tmp=tan(tmp*M_PI /180);
    else
        tmp=tan(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* reel::sinush(bool degre){
    double tmp(data);
    if(degre)
        tmp=sinh(tmp*M_PI /180);
    else
        tmp=sinh(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* reel::cosinush(bool degre){
    double tmp(data);
    if(degre)
        tmp=cosh(tmp*M_PI /180);
    else
        tmp=cosh(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* reel::tangenteh(bool degre){
    double tmp(data);
    if(degre)
        tmp=tanh(tmp*M_PI /180);
    else
        tmp=tanh(tmp);
    Donnee* t= new reel(tmp);
    return t;
}


Donnee* reel::ln(){
    double tmp(data);
    tmp=std::log(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* reel::log(){
    double tmp(data);
    tmp=log10(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* reel::inv(){
    double tmp(data);
    tmp=1/tmp;
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* reel::sqrt(){
    double tmp(data);
    tmp=std::sqrt(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* reel::sqr(){
    double tmp(data);
    tmp=std::pow(tmp,2);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* reel::cube(){
    double tmp(data);
    tmp=std::pow(tmp,3);
    Donnee* t= new reel(tmp);
    return t;
}
