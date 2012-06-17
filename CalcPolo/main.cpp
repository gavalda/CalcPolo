#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QStack>
#include "pile.h"
#include "Entier.h"
#include <iostream>
#include "Rationnel.h"
#include "Reel.h"

#include "Memento.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Pile pile;
    MainWindow w(pile, 0);
    w.show();


    return a.exec();
}
