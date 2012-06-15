#include "type_factory.h"
#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"

#include "expression.h"
#include "typeexception.h"

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
        if(Donnee::isComplexe(s))
        {
        return new complexe(s);
        }
        if(Donnee::isEntier(s))
            return new entier(s);
        if(Donnee::isReel(s))
            return new reel(s);
        if(rationnel::isRationnel(s))
        {
            try
        {
            Donnee* res= new rationnel(s);
            return res;
        }catch (std::exception &e) {
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
