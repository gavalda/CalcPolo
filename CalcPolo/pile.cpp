#include "Pile.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "Expression.h"
#include "string"
#include "dom.h"
#include <cmath>
#include "DonneeException.h"
#include <QRegExp>


using namespace std;

Pile::Pile():nbElt(5){
    g=new Memento;
    degre=true;
}

void Pile::sauvegarder(QString fileName){
    Dom xml(*this);
    xml.ecrire(fileName);
}

void Pile::charger(QString fileName){
    Dom xml(*this);
    xml.lire(fileName);
}


Pile::~Pile(){
    for(int i=0; i<size(); i++){
       delete at(i);
    }
    if(g)
    delete g;
}



Pile& Pile::clone() const
{
    Pile *p=new Pile();
    for(int i=0; i<size(); i++)
    {
        p->push(DonneeFactory::getInstance().getType(at(i)->toQString()));
    }

    p->setType(getType());   //string
    p->setMemento(getMemento());
    p->setDegre(getDegre());

    return *p;
}


Pile& Pile::duplique() const
{
    Pile *p=new Pile();
    for(int i=0; i<size(); i++)
    {
        p->push(DonneeFactory::getInstance().getType(at(i)->toQString()));
    }
    p->setMemento(new Memento);
    p->setType(getType());        //string
    p->setDegre(getDegre());
    return *p;
}


void Pile::swap(unsigned int x, unsigned int y)
{
    if (x < (unsigned int)this->size() && y < (unsigned int)this->size()){
        Donnee * tmp = at(size()-1-x);
        replace(size()-1-x, at(size()-1-y));
        replace(size()-1-y, tmp);
    }
}

void Pile::sum()
{
    if (!isEmpty())
    {
            Donnee* sum=pop();
         while(!isEmpty())
         {

             sum=(*sum+*pop());

         }
          push(sum);
    }
}

void Pile::mean()
{

    if (!isEmpty())
    {

         if (!(getType()=="Complexe"))
           {
              Donnee* mean=pop();
              int i=1;
                 while(!isEmpty())
             {
                 i++;
                 mean=(*mean+*pop());

                }

               mean=*mean/Reel(i);
                push(mean);
           }
    }

}



void Pile::addition()
{
    if(this->size() > 1)
    {
        g->addMemoire(this);
        Donnee * resultat;
        Donnee *op1 = pop();
        Donnee *op2 = pop();
        try{
            resultat=*op2+(*op1);
            delete op1;
            delete op2;
            push(resultat);
            g->addMemoire(this);
        }
        catch (std::exception &e)
        {
            QMessageBox msgBox;
            msgBox.setText(e.what());
            msgBox.exec();
            push(op2);
            push(op1);
        }
   }
}

void Pile::soustraction()
{
    if(this->size() > 1)
    {
        g->addMemoire(this);
        Donnee * resultat;
        Donnee *op1 = pop();
        Donnee *op2 = pop();
        try{
        resultat=*op2-(*op1);
        delete op1;
        delete op2;
        push(resultat);
        g->addMemoire(this);
        }
        catch (std::exception &e)
        {
            QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
            push(op2);
            push(op1);
        }
        }
}


void Pile::multiplication()
{
    if(this->size() > 1)
    {
        g->addMemoire(this);
        Donnee * resultat;
        Donnee *op1 = pop();
        Donnee *op2 = pop();
        try{
        resultat=*op2*(*op1);
        delete op1;
        delete op2;
        push(resultat);
        g->addMemoire(this);
        }
        catch (std::exception &e)
        {
            QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
            push(op2);
            push(op1);
        }
        }
}



void Pile::division()
{
    if(this->size() > 1)
    {
        g->addMemoire(this);
        Donnee * resultat;
        Donnee *op1 = pop();
        Donnee *op2 = pop();
        try
        {
        resultat=*op2/(*op1);
        delete op1;
        delete op2;
        push(resultat);
        g->addMemoire(this);
        }
        catch (std::exception &e)
        {
            QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
            push(op2);
            push(op1);
        }
        }
}

void Pile::pow()
{
    if(this->size() > 1)
    {
        g->addMemoire(this);
        Donnee * resultat;
        Donnee *op1 = pop();
        Donnee *op2 = pop();
        try
        {
        resultat=op2->pow(*op1);
        delete op1;
        delete op2;
        push(resultat);
        g->addMemoire(this);
        }
        catch (std::exception &e)
        {
            QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
            push(op2);
            push(op1);
        }
        }
}

void Pile::mod()
{
    if(this->size() > 1)
    {
        g->addMemoire(this);
        Donnee * resultat;
        Donnee *op1 = pop();
        Donnee *op2 = pop();
        try
        {
        resultat=op2->mod(*op1);
        delete op1;
        delete op2;
        push(resultat);
        g->addMemoire(this);
        }
        catch (std::exception &e)
        {
            QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
            push(op2);
            push(op1);
        }
        }
}

void Pile::parser(QString donnee)
{
    if(!Expression::isExpression(donnee))
    {
        Donnee* test=0;
       /* QRegExp rx("\\donnee+");
        QStringList t=(donnee.split(rx));*/
        QStringList t=(donnee.split(" "));
        for(int i=0; i<t.size();i++)
        {
            if (t[i]=="+")
                    addition();
            else if (t[i]=="-")
                    soustraction();
            else if (t[i]=="/")
                    division();
            else if (t[i]=="*")
                    multiplication();
            else if (t[i]=="pow")
                    pow();
            else if (t[i]=="mod")
                    mod();
            else if (t[i]=="sign")
                    sign();
            else if (t[i]=="sin")
                    sinus(degre);
            else if (t[i]=="cos")
                    cosinus(degre);
            else if (t[i]=="tan")
                    tangente(degre);
            else if (t[i]=="sinh")
                    sinush(degre);
            else if (t[i]=="cosh")
                    cosinush(degre);
            else if (t[i]=="tanh")
                    tangenteh(degre);
            else if (t[i]=="ln")
                    ln();
            else if (t[i]=="log")
                    log();
            else if (t[i]=="inv")
                    inv();
            else if (t[i]=="sqrt")
                    sqrt();
            else if (t[i]=="sqr")
                    sqr();
            else if (t[i]=="cube")
                    cube();
            else if (t[i]=="!")
                    fact();
            else
            {
                test=DonneeFactory::getInstance().getType(t[i]);
                if (test)
                    push(test);
                else
                {
                    QMessageBox msgBox;
                    msgBox.setText("Type non reconnu lors de l'evaluation");
                    msgBox.exec();
                }
             }
        }
    }
    else
    {
        push(new Expression(donnee));
    }

}

void Pile::sign(){

    if(this->size() > 0){

       g->addMemoire(this);
       Donnee *op = pop();
       Donnee *resultat;
       try{
       resultat=op->sign();
       delete op;
       push(resultat);
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }


     }
}


void Pile::sinus(bool degre){

    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->sinus(degre);
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}



void Pile::cosinus(bool degre){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->cosinus(degre);
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::tangente(bool degre){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->tangente(degre);
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::sinush(bool degre){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->sinush(degre);
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::cosinush(bool degre){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->cosinush(degre);
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::tangenteh(bool degre){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->tangenteh(degre);
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}



void Pile::ln(){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->ln();
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::log(){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->log();
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::inv(){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->inv();
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::sqrt(){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->sqrt();
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::sqr(){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->sqr();
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::cube(){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->cube();
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::fact(){
    if(this->size() > 0){
        g->addMemoire(this);
        Donnee *op = pop();
        Donnee *resultat;
        try{
       resultat=op->fact();
       push(resultat);
       delete op;
       g->addMemoire(this);
       }
       catch (std::exception &e) {
           QMessageBox msgBox;
 msgBox.setText(e.what());
 msgBox.exec();
           push(op);
       }
    }
}

void Pile::eval(){
    if(this->size() > 0)
    {
        g->addMemoire(this);
        Donnee *op = pop();
        QString resultat;
        try
        {
             resultat=op->eval();
             parser(resultat);
             g->addMemoire(this);
        }
        catch (std::exception &e)
        {
           QMessageBox msgBox;
            msgBox.setText(e.what());
            msgBox.exec();
           push(op);
        }
    }
}


