#include "complexe.h"
#include "entier.h"
#include "reel.h"
#include "Expression.h"
#include "rationnel.h"
#include "typeexception.h"
#include "type_factory.h"



Donnee* complexe::operator +(Donnee & t){
    try{
        complexe &tmp=dynamic_cast<complexe&>(t);
       /* if ((*im + *tmp.im)->toQString()=="0")
            return *re + *tmp.re;*/
       complexe *res=new complexe;
       res->re= dynamic_cast<Constante*> (*re + *tmp.re);
       res->im= dynamic_cast<Constante*>(*im + *tmp.im);


       return res;
    }
    catch(std::exception &e){}

    try{
       entier &tmp=dynamic_cast<entier&>(t);
       complexe conv(tmp.toQString());
       Donnee * res;
       res=conv+*this;
       return res;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       complexe conv(tmp.toQString());
       Donnee * res;
       res=conv+*this;
       return res;
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
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       complexe conv(tmp.toQString());
       Donnee * res;
       res=conv+*this;
       return res;
    }
    catch(std::exception &e){}

    throw typeException("erreur complexe op+");


}

Donnee* complexe::operator /(Donnee & t)
{
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);


        reel &im1=dynamic_cast<reel&>(*this->getIm());
        reel &re1=dynamic_cast<reel&>(*this->getRe());
        reel &im2=dynamic_cast<reel&>(*tmp.getIm());
        reel &re2=dynamic_cast<reel&>(*tmp.getRe());
        reel &im2sqr=dynamic_cast<reel&>(*im2.sqr());
        reel &re2sqr=dynamic_cast<reel&>(*re2.sqr());







         reel* re_f = new reel(((re1.getData()*re2.getData())-(im1.getData()*im2.getData()))/(re2sqr.getData()+im2sqr.getData()));
         reel* im_f = new reel(((im1.getData()*re2.getData())-(re1.getData()*im2.getData()))/(re2sqr.getData()+(im2sqr.getData())));







     /*  double re;
       double im;
       complexe *res(re,im);
      // res= *(*this * *(tmp.conjugue())) / *(tmp * *(tmp.conjugue())) ;
*/

       complexe* result = new complexe(re_f, im_f);
       return result;

       }
    catch(std::exception &e){}

  /*     Constante *tmp=dynamic_cast<Constante*>(&t);
       if (tmp)
       {
       complexe *res=new complexe;
       res->re= dynamic_cast<Constante*> (*re / *tmp);
       res->im= dynamic_cast<Constante*>(*im / *tmp);
       return res;
       }



      try{
           Expression &tmp=dynamic_cast<Expression&>(t);
           QString e;
           e = "'" + toQString() + " "+ tmp.toQString().remove("'") + " /'";
           return new Expression(e);
    }
    catch(std::exception &e){}
*/

    throw typeException("erreur complexe op/");
}

Donnee * complexe::operator*(Donnee& t){
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       if ((*(*re * *tmp.im)+*(*im * *tmp.re))->toQString()=="0")
           return type_factory::getInstance().getType((*(*re * *tmp.re)-*(*im * *tmp.im))->toQString());
       complexe *res=new complexe;
       res->re= dynamic_cast<Constante*> (*(*re * *tmp.re)-*(*im * *tmp.im));
       res->im= dynamic_cast<Constante*>(*(*re * *tmp.im)+*(*im * *tmp.re));
       return res;
    }
    catch(std::exception &e){}

    try{
       entier &tmp=dynamic_cast<entier&>(t);
       complexe conv(tmp.toQString());
       Donnee * res;
       res=conv*(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       complexe conv(tmp.toQString());
       Donnee * res;
       res=conv*(*this);
       return res;
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
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       complexe conv(tmp.toQString());
       Donnee * res;
       res=conv*(*this);
       return res;
    }
    catch(std::exception &e){}

    throw typeException("erreur complexe op*");
}

Donnee* complexe::operator-(Donnee& t){
    try{
       complexe &tmp=dynamic_cast<complexe&>(t);
       complexe *res=new complexe;
       res->re= dynamic_cast<Constante*> (*re - *tmp.re);
       res->im= dynamic_cast<Constante*>(*im - *tmp.im);

       return res;
    }
    catch(std::exception &e){}

      try{
       entier &tmp=dynamic_cast<entier&>(t);
       complexe conv(tmp.toQString());
       Donnee * res;
       res=conv-(*this);
       return res;
    }
    catch(std::exception &e){}

    try{
       reel &tmp=dynamic_cast<reel&>(t);
       complexe conv(tmp.toQString());
       Donnee * res;
       res=conv-(*this);
       return res;
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
       rationnel &tmp=dynamic_cast<rationnel&>(t);
       complexe conv(tmp.toQString());
       Donnee * res;
       res=conv-(*this);
       return res;
    }
    catch(std::exception &e){}

    throw typeException("erreur complexe op-");
}

QString complexe::toQString(){
    QString res;
    QTextStream ss(&res);
    ss << re->toQString() <<'$'<< im->toQString();
    return res;
}

Donnee* complexe::sign(){
    Constante* res_re;
    Constante* res_im;
    res_re=dynamic_cast<Constante*>(re->sign());
    res_im=dynamic_cast<Constante*>(im->sign());
    Donnee* t= new complexe(res_re,res_im);
    return t;
}

Donnee* complexe::conjugue(){
    Constante* res_im;
    res_im=dynamic_cast<Constante*>(im->sign());
    QString res =complexe(re,res_im).toQString();
    return new complexe(res);
}
