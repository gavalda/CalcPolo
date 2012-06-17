#ifndef PILE_H
#define PILE_H

#include <QStack>
#include "Donnee.h"
#include <QString>
#include <sstream>
#include <QStringList>
#include "DonneeFactory.h"

#include "Memento.h"

/// \file Pile.h
/// \author Clémence BLOT, Benoît GAVALDA
/// \brief Pile Classe de nos piles, héritant de QStack. Ce sont des piles de Donnee.
///
/// \param nbElt Nombre d'élément de la pile
/// \param g Memento qui permet le undo redo
/// \param degree boléen qui est vrai si on est en mode degré, faux si en radian.
/// \param type string{Complexe, Reel, Rationnel, Entier} qui indique le mode de la calculatrice.
///

class Pile : public QStack <Donnee *>
{

    int  nbElt;
    Memento* g;
    bool degre;
    std::string type;

public:

    ~Pile();
    Pile();

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

    bool getDegre() const {return degre;}
    void setDegre(bool deg){degre=deg;}

    void setType(std::string d){type = d;}
    std::string getType()const {return type;}


};

#endif // PILE_H
