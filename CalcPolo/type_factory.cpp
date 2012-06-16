#include "type_factory.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include "string"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "expression.h"
#include "typeexception.h"
using namespace std;

type_factory* type_factory::instance=0;

type_factory& type_factory::getInstance()
{
    if (instance==0)
        instance = new type_factory;
    return *instance;

}

void type_factory::releaseInstance()
{
    if (instance!=0)
        delete instance;
}

Donnee* type_factory::getType(QString s)
{
    if(Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->getType()=="complexe" && Donnee::isComplexe(s))  //meee Ici il faut rajouter un test un peu comme celui là, mais comment ?
        {
        return new complexe(s);
        }
        else if(Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->getType()=="entier" && Donnee::isEntier(s))
            return new entier(s);
        else if(Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->getType()=="reel" && Donnee::isReel(s))
            return new reel(s);
        else if(Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->getType()=="rationnel" && rationnel::isRationnel(s))
        {
             try
            {
                 Donnee* res= new rationnel(s);
                 return res;
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
