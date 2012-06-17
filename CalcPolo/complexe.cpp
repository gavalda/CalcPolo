#include "Complexe.h"
#include "Entier.h"
#include "Reel.h"
#include "Expression.h"
#include "Rationnel.h"
#include "DonneeException.h"
#include "DonneeFactory.h"



Donnee* Complexe::operator +(Donnee & t){
    try
    {
        Complexe &tmp=dynamic_cast<Complexe&>(t);
       /* if ((*im + *tmp.im)->toQString()=="0")
            return *re + *tmp.re;*/
       Complexe *resultat=new Complexe;
       resultat->re= dynamic_cast<Constante*> (*re + *tmp.re);
       resultat->im= dynamic_cast<Constante*>(*im + *tmp.im);


       return resultat;
    }
    catch(std::exception &e){}

    try
    {
       Entier &tmp=dynamic_cast<Entier&>(t);
       Complexe conv(tmp.toQString());
       Donnee * resultat;
       resultat=conv+*this;
       return resultat;
    }
    catch(std::exception &e){}

    try
    {
       Reel &tmp=dynamic_cast<Reel&>(t);

       Complexe conv(tmp.toQString());
       Donnee * resultat;
       resultat=conv+*this;
       return resultat;
    }
    catch(std::exception &e){}

 /*   try{
        Expression &tmp=dynamic_cast<Expression&>(t);
        QString e;
        e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " +'";
        return new Expression(e);
    }
    catch(std::exception &e){}
*/
    try{
       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Complexe conv(tmp.toQString());
       Donnee * resultat;
       resultat=conv+*this;
       return resultat;
    }
    catch(std::exception &e){}

    throw DonneeException("erreur Complexe op+");


}

Donnee* Complexe::operator /(Donnee & t)
{
    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);


        Reel &im1=dynamic_cast<Reel&>(*this->getIm());
        Reel &re1=dynamic_cast<Reel&>(*this->getRe());
        Reel &im2=dynamic_cast<Reel&>(*tmp.getIm());
        Reel &re2=dynamic_cast<Reel&>(*tmp.getRe());
        Reel &im2sqr=dynamic_cast<Reel&>(*im2.sqr());
        Reel &re2sqr=dynamic_cast<Reel&>(*re2.sqr());







         Reel* re_f = new Reel(((re1.getData()*re2.getData())-(im1.getData()*im2.getData()))/(re2sqr.getData()+im2sqr.getData()));
         Reel* im_f = new Reel(((im1.getData()*re2.getData())-(re1.getData()*im2.getData()))/(re2sqr.getData()+(im2sqr.getData())));







     /*  double re;
       double im;
       Complexe *resultat(re,im);
      // resultat= *(*this * *(tmp.conjugue())) / *(tmp * *(tmp.conjugue())) ;
*/

       Complexe* result = new Complexe(re_f, im_f);
       return result;

       }
    catch(std::exception &e){}

  /*     Constante *tmp=dynamic_cast<Constante*>(&t);
       if (tmp)
       {
       Complexe *resultat=new Complexe;
       resultat->re= dynamic_cast<Constante*> (*re / *tmp);
       resultat->im= dynamic_cast<Constante*>(*im / *tmp);
       return resultat;
       }



      try{
           Expression &tmp=dynamic_cast<Expression&>(t);
           QString e;
           e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " /'";
           return new Expression(e);
    }
    catch(std::exception &e){}
*/

    throw DonneeException("erreur Complexe op/");
}

Donnee * Complexe::operator*(Donnee& t){
    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       if ((*(*re * *tmp.im)+*(*im * *tmp.re))->toQString()=="0")
           return DonneeFactory::getInstance().getType((*(*re * *tmp.re)-*(*im * *tmp.im))->toQString());
       Complexe *resultat=new Complexe;
       resultat->re= dynamic_cast<Constante*> (*(*re * *tmp.re)-*(*im * *tmp.im));
       resultat->im= dynamic_cast<Constante*>(*(*re * *tmp.im)+*(*im * *tmp.re));
       return resultat;
    }
    catch(std::exception &e){}

    try{
       Entier &tmp=dynamic_cast<Entier&>(t);
       Complexe conv(tmp.toQString());
       Donnee * resultat;
       resultat=conv*(*this);
       return resultat;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       Complexe conv(tmp.toQString());
       Donnee * resultat;
       resultat=conv*(*this);
       return resultat;
    }
    catch(std::exception &e){}

 /*   try{
        Expression &tmp=dynamic_cast<Expression&>(t);
        QString e;
        e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " *'";
        return new Expression(e);
    }
    catch(std::exception &e){}

 */  try{
       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Complexe conv(tmp.toQString());
       Donnee * resultat;
       resultat=conv*(*this);
       return resultat;
    }
    catch(std::exception &e){}

    throw DonneeException("erreur Complexe op*");
}

Donnee* Complexe::operator-(Donnee& t){
    try{
       Complexe &tmp=dynamic_cast<Complexe&>(t);
       Complexe *resultat=new Complexe;
       resultat->re= dynamic_cast<Constante*> (*re - *tmp.re);
       resultat->im= dynamic_cast<Constante*>(*im - *tmp.im);

       return resultat;
    }
    catch(std::exception &e){}

      try{
       Entier &tmp=dynamic_cast<Entier&>(t);
       Complexe conv(tmp.toQString());
       Donnee * resultat;
       resultat=conv-(*this);
       return resultat;
    }
    catch(std::exception &e){}

    try{
       Reel &tmp=dynamic_cast<Reel&>(t);
       Complexe conv(tmp.toQString());
       Donnee * resultat;
       resultat=conv-(*this);
       return resultat;
    }
    catch(std::exception &e){}

   /* try{
        Expression &tmp=dynamic_cast<Expression&>(t);
        QString e;
        e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " -'";
        return new Expression(e);
    }
    catch(std::exception &e){}

   */ try{
       Rationnel &tmp=dynamic_cast<Rationnel&>(t);
       Complexe conv(tmp.toQString());
       Donnee * resultat;
       resultat=conv-(*this);
       return resultat;
    }
    catch(std::exception &e){}

    throw DonneeException("erreur Complexe op-");
}

QString Complexe::toQString(){
    QString resultat;
    QTextStream ss(&resultat);
    ss << re->toQString() <<'$'<< im->toQString();
    return resultat;
}

Donnee* Complexe::sign(){
    Constante* resultat_re;
    Constante* resultat_im;
    resultat_re=dynamic_cast<Constante*>(re->sign());
    resultat_im=dynamic_cast<Constante*>(im->sign());
    Donnee* t= new Complexe(resultat_re,resultat_im);
    return t;
}

Donnee* Complexe::conjugue(){
    Constante* resultat_im;
    resultat_im=dynamic_cast<Constante*>(im->sign());
    QString resultat =Complexe(re,resultat_im).toQString();
    return new Complexe(resultat);
}
