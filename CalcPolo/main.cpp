#include <QtGui/QApplication>
#include "calcpolo.h"
#include "Calculatrice.h"
#include "NombreReel.h"
#include "Function.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalcPolo w;
    w.show();
    
    return a.exec();
}
