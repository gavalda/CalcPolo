
#include "NombreReel.h"
#include <cmath>
#include <QMessageBox>
#include <string>
#include "calcpolo.h"
#include "ui_calcpolo.h"




Reel Reel::operator+(Reel const& R1) const
{


    Reel r(valeur+R1.getValeur());
    return r;

}


Reel Reel::operator -(Reel const& R1) const
{
    Reel r(valeur-R1.getValeur());
    return r;

}

Reel Reel::operator*(Reel const& R1) const
{
    Reel r(valeur*R1.getValeur());
    return r;

}



Reel Reel::operator/(Reel const& R1) const
{
     Reel r(valeur/R1.getValeur());
     return r;

}


Reel* Reel::sin() const
{

    Reel* r = new Reel(std::sin(valeur));
    return r;

}
Reel Reel::cos() const
{
    Reel r(std::cos(valeur));
    return r;

}
Reel Reel::tan() const
{
    Reel r(std::tan(valeur));
    return r;

}
Reel Reel::cosh() const
{
    Reel r(std::cosh(valeur));
    return r;

}
Reel Reel::sinh() const
{
    Reel r(std::sinh(valeur));
    return r;

}
Reel Reel::tanh() const
{
    Reel r(std::tanh(valeur));
    return r;

}
Reel Reel::ln() const
{
    Reel r(std::log(valeur));
    return r;

}
Reel Reel::log() const
{
    Reel r(std::log10(valeur));
    return r;

}
Reel Reel::inv() const
{
    Reel r(1/valeur);
    return r;

}
Reel Reel::sqrt() const
{
    Reel r(std::sqrt(valeur));
    return r;
}
Reel Reel::sqr() const
{
    Reel r(valeur*valeur);
    return r;
}
Reel Reel::cube() const
{
    Reel r(valeur*valeur*valeur);
    return r;

}


