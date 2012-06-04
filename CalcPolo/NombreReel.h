#ifndef NOMBREREEL_H
#define NOMBREREEL_H


/*class NombreReel
{

};
*/


class Reel
{
private :
    double valeur;

public:
    Reel(double r) : valeur(r){}
    Reel operator+(Reel const& R1);
    double getvaleur(){return valeur;}



};


#endif // NOMBREREEL_H
