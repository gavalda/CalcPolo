#include "Rationnel.h"
#include "Complexe.h"
#include <QDataStream>
#include <cmath>

#include "Reel.h"
#include "Entier.h"
#include "expression.h"



Donnee* Rationnel::operator +(Donnee & t){
    try{
       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Rationnel *resultat=new Rationnel(num*tmp.denum+tmp.num*denum,denum*tmp.denum);
       return resultat;
    }
    catch(std::exception &e){}

    try{
       Entier &tmp=dynamic_cast<Entier&>(t);

       return tmp+*this;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       return tmp+*this;
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

/*    try{
       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " +'";
       return new Expression(e);
    }
    catch(std::exception &e){}
*/


    throw DonneeException("erreur Rationnel op+");
}

Donnee* Rationnel::operator -(Donnee & t){
    try{
       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Rationnel *resultat=new Rationnel(num*tmp.denum-tmp.num*denum,denum*tmp.denum);
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{
       Entier &tmp=dynamic_cast<Entier&>(t);
       Rationnel r=Rationnel(tmp.getData(),1);
       return tmp-r;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       Rationnel r=Rationnel(tmp.getData()*tmp.getDecimales()*10,tmp.getDecimales()*10);
       return tmp-r;
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

    throw DonneeException("erreur Rationnel op-");
}

Donnee* Rationnel::operator /(Donnee & t){
    try{
       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Rationnel r(tmp.denum,tmp.num);
       return *this*r;
    }
    catch(std::exception &e){}
/*
    try{
       Entier &tmp=dynamic_cast<Entier&>(t);
       Rationnel r=Rationnel(tmp.getData(),1);
       return tmp/r;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       Rationnel r=Rationnel(tmp.getData()*tmp.getDecimales()*10,tmp.getDecimales()*10);
       return tmp/r;
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

    try{
       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " /'";
       return new Expression(e);
    }
    catch(std::exception &e){}
*/

    throw DonneeException("erreur Rationnel op/");
}


Donnee* Rationnel::operator*(Donnee& t)
{
    try{
       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Rationnel *resultat=new Rationnel(num*tmp.num,denum*tmp.denum);
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{
       Entier &tmp=dynamic_cast<Entier&>(t);
       Rationnel r=Rationnel(tmp.getData(),1);
       return tmp*r;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       Rationnel r=Rationnel(tmp.getData()*tmp.getDecimales()*10,tmp.getDecimales()*10);
       return tmp*r;
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
    throw DonneeException("erreur Rationnel op*");
}

Donnee* Rationnel::pow(Donnee & t){
    try{

       Entier &tmp=dynamic_cast<Entier&>(t);
       Rationnel *resultat=new Rationnel(std::pow(double(num),tmp.getData()), std::pow(double(denum), tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{

       Reel &tmp=dynamic_cast<Reel&>(t);
       Rationnel *resultat=new Rationnel(std::pow(num,tmp.getData()), std::pow(denum, tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}
*/
    throw DonneeException("erreur Rationnel pow");
}

int Rationnel::pgcd(int a, int b) const {
    if (a==0||b==0) return 0;
    if (a<0) a=-a;
    if (b<0) b=-b;
    while(a!=b){
        if (a>b) a=a-b; else b=b-a;
    }
    return a;
}

void Rationnel::simplifie(){
    if (num==0) { denum=1; return; }
    if (denum==0) return;
    int p=pgcd(num,denum);
    num/=p;
    denum/=p;
    if (denum<0) {
        denum=-denum;
        num=-num;
    }
}


QString Rationnel::toQString(){
    QString resultat;
    QTextStream ss(&resultat);
    ss << num;
    if (denum!=1)
        ss<<'/'<< denum;
    return resultat;
}

QString Rationnel::eval(){
    QString resultat;
    QTextStream ss(&resultat);
    ss << (double)num/(double)denum;
    return resultat;
}

Donnee* Rationnel::sign(){
    double tmp(-num/denum);
    Donnee* t= new Rationnel(tmp);
    return t;
}


Donnee* Rationnel::sinus(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=sin(tmp*M_PI /180);
    else
        tmp=sin(tmp);

    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Rationnel::cosinus(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=cos(tmp*M_PI /180);
    else
        tmp=cos(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Rationnel::tangente(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=tan(tmp*M_PI /180);
    else
        tmp=tan(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Rationnel::sinush(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=sinh(tmp*M_PI /180);
    else
        tmp=sinh(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Rationnel::cosinush(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=cosh(tmp*M_PI /180);
    else
        tmp=cosh(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Rationnel::tangenteh(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=tanh(tmp*M_PI /180);
    else
        tmp=tanh(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}


Donnee* Rationnel::ln(){
    double tmp(num/denum);
    tmp=std::log(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Rationnel::log(){
    double tmp(num/denum);
    tmp=log10(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Rationnel::inv(){
    double tmp(num/denum);
    tmp=1/tmp;
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Rationnel::sqrt(){
    double tmp(num/denum);
    tmp=std::sqrt(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Rationnel::sqr(){
    double tmp(num/denum);
    tmp=std::pow (tmp,2);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Rationnel::cube(){
    double tmp(num/denum);
    tmp=std::pow (tmp,3);
    Donnee* t= new Reel(tmp);
    return t;
}
