#include "rationnel.h"
#include "complexe.h"
#include <QDataStream>
#include <cmath>

#include "reel.h"
#include "entier.h"
#include "expression.h"



Donnee* rationnel::operator +(Donnee & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *resultat=new rationnel(num*tmp.denum+tmp.num*denum,denum*tmp.denum);
       return resultat;
    }
    catch(std::exception &e){}

    try{
       entier &tmp=dynamic_cast<entier&>(t);

       return tmp+*this;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       return tmp+*this;
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

/*    try{
       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " +'";
       return new Expression(e);
    }
    catch(std::exception &e){}
*/


    throw typeException("erreur rationnel op+");
}

Donnee* rationnel::operator -(Donnee & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *resultat=new rationnel(num*tmp.denum-tmp.num*denum,denum*tmp.denum);
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       rationnel r=rationnel(tmp.getData(),1);
       return tmp-r;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       rationnel r=rationnel(tmp.getData()*tmp.getDecimales()*10,tmp.getDecimales()*10);
       return tmp-r;
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

    throw typeException("erreur rationnel op-");
}

Donnee* rationnel::operator /(Donnee & t){
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel r(tmp.denum,tmp.num);
       return *this*r;
    }
    catch(std::exception &e){}
/*
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       rationnel r=rationnel(tmp.getData(),1);
       return tmp/r;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       rationnel r=rationnel(tmp.getData()*tmp.getDecimales()*10,tmp.getDecimales()*10);
       return tmp/r;
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

    try{
       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " /'";
       return new Expression(e);
    }
    catch(std::exception &e){}
*/

    throw typeException("erreur rationnel op/");
}


Donnee* rationnel::operator*(Donnee& t)
{
    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *resultat=new rationnel(num*tmp.num,denum*tmp.denum);
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       rationnel r=rationnel(tmp.getData(),1);
       return tmp*r;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       rationnel r=rationnel(tmp.getData()*tmp.getDecimales()*10,tmp.getDecimales()*10);
       return tmp*r;
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
    throw typeException("erreur rationnel op*");
}

Donnee* rationnel::pow(Donnee & t){
    try{

       entier &tmp=dynamic_cast<entier&>(t);
       rationnel *resultat=new rationnel(std::pow(double(num),tmp.getData()), std::pow(double(denum), tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{

       reel &tmp=dynamic_cast<reel&>(t);
       rationnel *resultat=new rationnel(std::pow(num,tmp.getData()), std::pow(denum, tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}
*/
    throw typeException("erreur rationnel pow");
}

int rationnel::pgcd(int a, int b) const {
    if (a==0||b==0) return 0;
    if (a<0) a=-a;
    if (b<0) b=-b;
    while(a!=b){
        if (a>b) a=a-b; else b=b-a;
    }
    return a;
}

void rationnel::simplifie(){
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


QString rationnel::toQString(){
    QString resultat;
    QTextStream ss(&resultat);
    ss << num;
    if (denum!=1)
        ss<<'/'<< denum;
    return resultat;
}

QString rationnel::eval(){
    QString resultat;
    QTextStream ss(&resultat);
    ss << (double)num/(double)denum;
    return resultat;
}

Donnee* rationnel::sign(){
    double tmp(-num/denum);
    Donnee* t= new rationnel(tmp);
    return t;
}


Donnee* rationnel::sinus(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=sin(tmp*M_PI /180);
    else
        tmp=sin(tmp);

    Donnee* t= new reel(tmp);
    return t;
}

Donnee* rationnel::cosinus(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=cos(tmp*M_PI /180);
    else
        tmp=cos(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* rationnel::tangente(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=tan(tmp*M_PI /180);
    else
        tmp=tan(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* rationnel::sinush(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=sinh(tmp*M_PI /180);
    else
        tmp=sinh(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* rationnel::cosinush(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=cosh(tmp*M_PI /180);
    else
        tmp=cosh(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* rationnel::tangenteh(bool degre){
    double tmp(num/denum);
    if(degre)
        tmp=tanh(tmp*M_PI /180);
    else
        tmp=tanh(tmp);
    Donnee* t= new reel(tmp);
    return t;
}


Donnee* rationnel::ln(){
    double tmp(num/denum);
    tmp=std::log(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* rationnel::log(){
    double tmp(num/denum);
    tmp=log10(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* rationnel::inv(){
    double tmp(num/denum);
    tmp=1/tmp;
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* rationnel::sqrt(){
    double tmp(num/denum);
    tmp=std::sqrt(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* rationnel::sqr(){
    double tmp(num/denum);
    tmp=std::pow (tmp,2);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* rationnel::cube(){
    double tmp(num/denum);
    tmp=std::pow (tmp,3);
    Donnee* t= new reel(tmp);
    return t;
}
