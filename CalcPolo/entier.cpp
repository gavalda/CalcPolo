#include <exception>
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "expression.h"
#include "typeexception.h"

#include <cmath>
#include "mainwindow.h"






Donnee* entier::operator +(Donnee & t){
    try{

       entier &tmp=dynamic_cast<entier&>(t);            //conversion en entier
       entier *resultat=new entier(data+tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try{

       reel &tmp=dynamic_cast<reel&>(t);
       reel *resultat=new reel(data+tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try{

       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *resultat = new rationnel((data*tmp.getDenum()+tmp.getNum())/tmp.getDenum());
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

 /*   try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
       Donnee * resultat;
       resultat=conv+tmp;
       return resultat;
    }
    catch(std::exception &e){}

*/
    throw typeException("erreur entier op+");


}

Donnee* entier::operator /(Donnee & t)
{

    try{
            entier &tmp=dynamic_cast<entier&>(t);
            int a1 = this->getData();
            int a2 = tmp.getData();

            if(a1%a2==0)
            {
                entier *result=new entier(this->getData()/tmp.getData());
                return result;

            }
            else
            {
                rationnel *result=new rationnel(data,tmp.getData());
                return result;
            }
       }
    catch(std::exception &e){}

/*    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *resultat=new reel(data/tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *resultat=new rationnel(data*tmp.getDenum(), tmp.getNum());
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
    throw typeException("erreur entier op/");
}

Donnee* entier::operator*(Donnee& t){
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       entier *resultat=new entier(data*tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *resultat=new reel(data*tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try{
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       rationnel *resultat=new rationnel(data*tmp.getNum(), tmp.getDenum());
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

/*    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
       Donnee * resultat;
       resultat=conv*tmp;
       return resultat;
    }
    catch(std::exception &e){}
*/
    throw typeException("erreur entier op*");
}

Donnee* entier::operator-(Donnee& t){
    try{
       entier &tmp=dynamic_cast<entier&>(t);
       entier *resultat=new entier(data-tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{
       reel &tmp=dynamic_cast<reel&>(t);
       reel *resultat=new reel(data-tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try{

       rationnel &tmp=dynamic_cast<rationnel&>(t);
       Donnee* resultat;
       rationnel r(data,1);
       resultat=r-tmp;
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

    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe conv(toQString());
       Donnee * resultat;
       resultat=conv-tmp;
       return resultat;
    }
    catch(std::exception &e){}
*/
    throw typeException("erreur entier op-");
}


Donnee* entier::pow(Donnee & t){
    try{

       entier &tmp=dynamic_cast<entier&>(t);
       entier *resultat=new entier(std::pow(double(data),tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{

       reel &tmp=dynamic_cast<reel&>(t);
       entier *resultat=new entier(std::pow(data,tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}
    */
    throw typeException("erreur entier");
}

Donnee* entier::mod(Donnee & t){
    try{

       entier &tmp=dynamic_cast<entier&>(t);
       entier *resultat=new entier(data % tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    throw typeException("erreur entier mod");
}



QString entier::toQString(){
    QString resultat;
    QTextStream ss(&resultat);
    ss << data;
    return resultat;
}

Donnee* entier::sign(){
    double tmp(-data);
    Donnee* t= new entier(tmp);
    return t;
}

Donnee* entier::sinus(bool degre){
    double tmp(data);
    if(degre)
        tmp=sin(tmp*M_PI /180);
    else
        tmp=sin(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* entier::cosinus(bool degre){
    double tmp(data);
    if(degre)
        tmp=cos(tmp*M_PI /180);
    else
        tmp=cos(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* entier::tangente(bool degre){
    double tmp(data);
    if(degre)
        tmp=tan(tmp*M_PI /180);
    else
        tmp=tan(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* entier::sinush(bool degre){
    double tmp(data);
    if(degre)
        tmp=sinh(tmp*M_PI /180);
    else
        tmp=sinh(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* entier::cosinush(bool degre){
    double tmp(data);
    if(degre)
        tmp=cosh(tmp*M_PI /180);
    else
        tmp=cosh(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* entier::tangenteh(bool degre){
    double tmp(data);
    if(degre)
        tmp=tanh(tmp*M_PI /180);
    else
        tmp=tanh(tmp);
    Donnee* t= new reel(tmp);
    return t;
}



Donnee* entier::ln(){
    double tmp(data);
    tmp=std::log(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* entier::log(){
    double tmp(data);
    tmp=log10(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* entier::inv(){
    double tmp(data);
    tmp=1/tmp;
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* entier::sqrt(){
    double tmp(data);
    tmp=std::sqrt(tmp);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* entier::sqr(){
    double tmp(data);
    tmp=std::pow(tmp,2);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* entier::cube(){
    double tmp(data);
    tmp=std::pow(tmp,3);
    Donnee* t= new reel(tmp);
    return t;
}

Donnee* entier::fact(){
    int tmp(1);

    for(int i=1; i<=data; i++)
        tmp*=i;

    Donnee* t= new reel(tmp);
    return t;
}

