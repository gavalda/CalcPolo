#ifndef TYPE_FACTORY_H
#define TYPE_FACTORY_H
#include <QString>
#include "type.h"
#include <QStringList>

class type_factory
{
    static type_factory * instance;/*!<  Instance unique de la factory*/
public:

    type_factory (const type_factory&);

    ~type_factory(){}

    type_factory(){}

    type_factory operator =(const type_factory);
public:

    static type_factory& getInstance();

    static void releaseInstance();

    Donnee* getType(QString s);

};
#endif // TYPE_FACTORY_H
