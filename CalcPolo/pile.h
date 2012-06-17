#ifndef PILE_H
#define PILE_H

#include <QStack>
#include "Donnee.h"
#include <QString>
#include <sstream>
#include <QStringList>
#include "DonneeFactory.h"

#include "Memento.h"


class Pile : public QStack <Donnee *>
{

    int  nbElt;
    Memento* g;
    bool degre;
    std::string type;                       //meee

public:

    ~Pile();
    Pile();
    bool getDegre() const {return degre;}
    void setDegre(bool deg){degre=deg;}
    void sauvegarder(QString fileName);
    void charger(QString fileName);
    Pile& clone() const;
    Pile& duplique()const;
    void setMemento(Memento* _g){g=_g;}
    void setNbElt(int nb){nbElt=nb;}
    Memento* getMemento()const{return g;}
    void swap(unsigned int x,unsigned int y);
    void sum(const unsigned int x);
    void mean(const unsigned int x);
    void dup(){if(!isEmpty()){push(top());}}
    void drop(){if(!isEmpty()){pop();}}
    void addition();
    void soustraction();
    void division();
    void multiplication();
    void parser(QString s);
    int getNb(){return nbElt;}
    void undo(){Pile *tmp=g->undo();if(tmp!=0)*this=*tmp;}
    void redo(){Pile *tmp=g->redo();if(tmp!=0)*this=*tmp;}
    void pow();
    void mod();
    void sign();
    void sinus(bool degre=false);
    void cosinus(bool degre=false);
    void tangente(bool degre=false);
    void sinush(bool degre=false);
    void cosinush(bool degre=false);
    void tangenteh(bool degre=false);
    void ln();
    void log();
    void inv();
    void sqrt();
    void sqr();
    void cube();
    void fact();

    void eval();

    void setType(std::string d){type = d;}  //meee
    std::string getType(){return type;}        //meee


};

#endif // PILE_H
