#include "Expression.h"
#include "DonneeFactory.h"



Expression::Expression(QString& exp1): exp(exp1)
{
}

Donnee* Expression::operator +(Donnee & t){
    exp = exp.remove(exp.size()-1,exp.size()-1) + ' ' + t.toQString().remove("'") + ' ' + "+'";
    return new Expression(exp);
}

Donnee* Expression::operator -(Donnee & t){
    exp = exp.remove(exp.size()-1,exp.size()-1) + ' ' + t.toQString().remove("'") + ' ' + "-'";
    return new Expression(exp);
}


Donnee* Expression::operator *(Donnee & t){
    exp = exp.remove(exp.size()-1,exp.size()-1) + ' ' + t.toQString().remove("'") + ' ' + "*'";
    return new Expression(exp);
}


Donnee* Expression::operator /(Donnee & t){
    exp = exp.remove(exp.size()-1,exp.size()-1) + ' ' + t.toQString().remove("'") + ' ' + "/'";
    return new Expression(exp);
}


Donnee* Expression::sinus(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "sin'";
    return new Expression(exp);

}

Donnee* Expression::pow(Donnee & t)
{
    exp = exp.remove(exp.size()-1,exp.size()-1) + ' ' + t.toQString().remove("'") + ' ' + "pow'";
    return new Expression(exp);
}

Donnee* Expression::mod(Donnee & t)
{
    exp = exp.remove(exp.size()-1,exp.size()-1) + ' ' + t.toQString().remove("'") + ' ' + "mod'";
    return new Expression(exp);
}

Donnee* Expression::sign()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "sign'";
    return new Expression(exp);
}




Donnee* Expression::cosinus(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "cos'";
    return new Expression(exp);
}



Donnee* Expression::tangente(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "tan'";
    return new Expression(exp);
}

Donnee* Expression::sinush(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "sinh'";
    return new Expression(exp);
}


Donnee* Expression::cosinush(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "cosh'";
    return new Expression(exp);
}

Donnee* Expression::tangenteh(bool b)
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "tanh'";
    return new Expression(exp);
}


Donnee* Expression::ln()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "ln'";
    return new Expression(exp);
}


Donnee* Expression::log()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "log'";
    return new Expression(exp);
}

Donnee* Expression::inv()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "inv'";
    return new Expression(exp);
}


Donnee* Expression::sqrt()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "sqrt'";
    return new Expression(exp);
}


Donnee* Expression::sqr()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "sqr'";
    return new Expression(exp);
}

Donnee* Expression::cube()
{
    exp = exp.remove(exp.size()-1,exp.size()-1)  + ' ' + "cube'";
    return new Expression(exp);
}


QString Expression::eval(){
    return exp.remove("'");
}



