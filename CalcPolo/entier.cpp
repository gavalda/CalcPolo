#include <exception>
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "Expression.h"
#include "DonneeException.h"

#include <cmath>
#include "mainwindow.h"






Donnee* Entier::operator +(Donnee & t)
{
    try
    {

       Entier &tmp=dynamic_cast<Entier&>(t);            //conversion en entier
       Entier *resultat=new Entier(data+tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try
    {

       Reel &tmp=dynamic_cast<Reel&>(t);
       Reel *resultat=new Reel(data+tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try
    {

       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Rationnel *resultat = new Rationnel((data*tmp.getDenum()+tmp.getNum())/tmp.getDenum());
       return resultat;
    }
    catch(std::exception &e){}

 /*   try
    {

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " +'";
       return new Expression(e);
    }
    catch(std::exception &e){}

 */   try
    {
       Complexe &tmp=dynamic_cast<Complexe&>(t);

       Reel &retmp=dynamic_cast<Reel&>(*tmp.getRe());
       Reel &imtmp=dynamic_cast<Reel&>(*tmp.getIm());

       double re_d = getData()+retmp.getData();
       double im_d = imtmp.getData();

       Reel* re=new Reel(re_d);
       Reel* im=new Reel(im_d);

       Complexe* result= new Complexe(re,im);

       return result;
    }
    catch(std::exception &e){}


    throw DonneeException("erreur Entier op+");


}

Donnee* Entier::operator /(Donnee & t)
{

    try
    {
            Entier &tmp=dynamic_cast<Entier&>(t);
            int a1 = this->getData();
            int a2 = tmp.getData();

            if(a1%a2==0)
            {
                Entier *result=new Entier(this->getData()/tmp.getData());
                return result;

            }
            else
            {
                Rationnel *result=new Rationnel(data,tmp.getData());
                return result;
            }
       }
    catch(std::exception &e){}

    try
    {
       Reel &tmp=dynamic_cast<Reel&>(t);
       Reel *resultat=new Reel(data/tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try
    {
       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Rationnel *resultat=new Rationnel(data*tmp.getDenum(), tmp.getNum());
       return resultat;
    }
    catch(std::exception &e){}

/*    try
    {

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " /'";
       return new Expression(e);
    }
    catch(std::exception &e){}
*/
    try
    {
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       Complexe conv(toQString());
       Donnee * resultat;
       resultat=conv/tmp;
       return resultat;
    }
    catch(std::exception &e){}

    throw DonneeException("erreur Entier op/");
}

Donnee* Entier::operator*(Donnee& t)
{
    try
    {
       Entier &tmp=dynamic_cast<Entier&>(t);
       Entier *resultat=new Entier(data*tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try
    {
       Reel &tmp=dynamic_cast<Reel&>(t);
       Reel *resultat=new Reel(data*tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try
    {
       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Rationnel *resultat=new Rationnel(data*tmp.getNum(), tmp.getDenum());
       return resultat;
    }
    catch(std::exception &e){}

/*    try
    {

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() +" "+ tmp.toQString().remove("'") + " *'";
       return new Expression(e);
    }
    catch(std::exception &e){}
*/
    try
    {
        Complexe &tmp=dynamic_cast<Complexe&>(t);


        Reel &im2=dynamic_cast<Reel&>(*tmp.getIm());
        Reel &re2=dynamic_cast<Reel&>(*tmp.getRe());


        Reel* re_f = new Reel(re2.getData()*getData());
        Reel* im_f = new Reel(im2.getData()*getData());

        Complexe* result = new Complexe(re_f, im_f);

        return result;
    }
    catch(std::exception &e){}

    throw DonneeException("erreur Entier op*");
}

Donnee* Entier::operator-(Donnee& t)
{
    try
    {
       Entier &tmp=dynamic_cast<Entier&>(t);
       Entier *resultat=new Entier(data-tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       Reel *resultat=new Reel(data-tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    try{

       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Donnee* resultat;
       Rationnel r(data,1);
       resultat=r-tmp;
       return resultat;
    }
    catch(std::exception &e){}

/*    try{

       Expression &tmp=dynamic_cast<Expression&>(t);
       QString e;
       e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " -'";
       return new Expression(e);
    }
    catch(std::exception &e){}
*/
    try
    {
       Complexe &tmp=dynamic_cast<Complexe&>(t);


       Reel &retmp=dynamic_cast<Reel&>(*tmp.getRe());
       Reel &imtmp=dynamic_cast<Reel&>(*tmp.getIm());

       double re_d = getData()-retmp.getData();
       double im_d = imtmp.getData();

       Reel* re=new Reel(re_d);
       Reel* im=new Reel(im_d);

       Complexe* result= new Complexe(re,im);

       return result;
    }
    catch(std::exception &e){}

    throw DonneeException("erreur Entier op-");
}


Donnee* Entier::pow(Donnee & t){
    try{

       Entier &tmp=dynamic_cast<Entier&>(t);
       Entier *resultat=new Entier(std::pow(double(data),tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}
/*
    try{

       Reel &tmp=dynamic_cast<Reel&>(t);
       Entier *resultat=new Entier(std::pow(data,tmp.getData()));
       return resultat;
    }
    catch(std::exception &e){}
    */
    throw DonneeException("erreur Entier");
}

Donnee* Entier::mod(Donnee & t){
    try{

       Entier &tmp=dynamic_cast<Entier&>(t);
       Entier *resultat=new Entier(data % tmp.getData());
       return resultat;
    }
    catch(std::exception &e){}

    throw DonneeException("erreur Entier mod");
}



QString Entier::toQString(){
    QString resultat;
    QTextStream ss(&resultat);
    ss << data;
    return resultat;
}

Donnee* Entier::sign(){
    double tmp(-data);
    Donnee* t= new Entier(tmp);
    return t;
}

Donnee* Entier::sinus(bool degre){
    double tmp(data);
    if(degre)
        tmp=sin(tmp*M_PI /180);
    else
        tmp=sin(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Entier::cosinus(bool degre){
    double tmp(data);
    if(degre)
        tmp=cos(tmp*M_PI /180);
    else
        tmp=cos(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Entier::tangente(bool degre){
    double tmp(data);
    if(degre)
        tmp=tan(tmp*M_PI /180);
    else
        tmp=tan(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Entier::sinush(bool degre){
    double tmp(data);
    if(degre)
        tmp=sinh(tmp*M_PI /180);
    else
        tmp=sinh(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Entier::cosinush(bool degre){
    double tmp(data);
    if(degre)
        tmp=cosh(tmp*M_PI /180);
    else
        tmp=cosh(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Entier::tangenteh(bool degre){
    double tmp(data);
    if(degre)
        tmp=tanh(tmp*M_PI /180);
    else
        tmp=tanh(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}



Donnee* Entier::ln(){
    double tmp(data);
    tmp=std::log(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Entier::log(){
    double tmp(data);
    tmp=log10(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Entier::inv(){
    double tmp(data);
    tmp=1/tmp;
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Entier::sqrt(){
    double tmp(data);
    tmp=std::sqrt(tmp);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Entier::sqr(){
    double tmp(data);
    tmp=std::pow(tmp,2);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Entier::cube(){
    double tmp(data);
    tmp=std::pow(tmp,3);
    Donnee* t= new Reel(tmp);
    return t;
}

Donnee* Entier::fact(){
    int tmp(1);

    for(int i=1; i<=data; i++)
        tmp*=i;

    Donnee* t= new Reel(tmp);
    return t;
}

