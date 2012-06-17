#include "DonneeFactory.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Complexe.h"
#include "string"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Expression.h"
#include "DonneeException.h"
using namespace std;

DonneeFactory* DonneeFactory::instance=0;

DonneeFactory& DonneeFactory::getInstance()
{
    if (instance==0)
        instance = new DonneeFactory;
    return *instance;

}

void DonneeFactory::releaseInstance()
{
    if (instance!=0)
        delete instance;
}

Donnee* DonneeFactory::getType(QString s)
{
    if(CollectionPile::getInstance().at(CollectionPile::getInstance().getActif())->getType()=="Complexe" && (Donnee::isComplexe(s)||Donnee::isReel(s)))
        {
        return new Complexe(s);
        }
        else if(CollectionPile::getInstance().at(CollectionPile::getInstance().getActif())->getType()=="Entier" && Donnee::isEntier(s))
            return new Entier(s);
        else if(CollectionPile::getInstance().at(CollectionPile::getInstance().getActif())->getType()=="Reel" && Donnee::isReel(s))
            return new Reel(s);
        else if(CollectionPile::getInstance().at(CollectionPile::getInstance().getActif())->getType()=="Rationnel" && (Donnee::isRationnel(s)||Donnee::isEntier(s)))
        {
             try
            {
                return new Rationnel(s);
            }
            catch (std::exception &e)
            {
                 QMessageBox msgBox;
                  msgBox.setText(e.what());
                  msgBox.exec();
            }
        }
        if(Donnee::isExpression(s))
            return new Expression(s);
        else
        {
            return NULL;
        }
}

