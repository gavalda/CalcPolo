#include "NombreReel.h"




Reel Reel::operator +(Reel const& r)
{
    valeur=valeur+r.valeur;
    return *this;

}

