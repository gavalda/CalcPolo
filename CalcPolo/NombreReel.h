#ifndef NOMBREREEL_H
#define NOMBREREEL_H



class NombreReel
{
   protected :
   virtual NombreReel* sin() const =0;

   virtual ~NombreReel(){}



};


class Reel : public NombreReel
{
private :
    double valeur;

public:
    Reel(double r) : valeur(r){}
    Reel operator+(Reel const& R1) const;
    Reel operator-(Reel const& R1) const;
    Reel operator*(Reel const& R1) const;
    Reel operator/(Reel const& R1) const;
    Reel* sin() const;
    Reel cos() const;
    Reel tan() const;
    Reel cosh() const;
    Reel sinh() const;
    Reel tanh() const;
    Reel ln() const;
    Reel log() const;
    Reel inv() const;
    Reel sqrt() const;
    Reel sqr() const;
    Reel cube() const;
    double getValeur() const {return valeur;}
    void setValeur(double x){valeur=x;}



};


#endif // NOMBREREEL_H
