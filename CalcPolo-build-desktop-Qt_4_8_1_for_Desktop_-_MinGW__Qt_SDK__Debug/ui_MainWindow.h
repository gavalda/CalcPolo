/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Sun 17. Jun 13:56:26 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionParametre;
    QAction *charger;
    QAction *actionAnnuler;
    QAction *actionR_tablir;
    QAction *actionR_glage;
    QAction *sauvegarder;
    QAction *sauvegarder_all;
    QAction *actionNouvel_onglet_2;
    QWidget *centralWidget;
    QListWidget *list;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButton4;
    QPushButton *pushButton5;
    QPushButton *pushButton6;
    QPushButton *pushButton7;
    QPushButton *pushButton8;
    QPushButton *pushButton9;
    QPushButton *pushButton0;
    QPushButton *reelButton;
    QPushButton *rationnelButton;
    QPushButton *complexeButton;
    QPushButton *quote;
    QPushButton *backspace;
    QPushButton *espace;
    QPushButton *affichePile;
    QTabWidget *tabWidget;
    QWidget *Onglet_1;
    QLabel *label;
    QSpinBox *NbAffiche;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_7;
    QPushButton *sin;
    QPushButton *cos;
    QPushButton *sqr;
    QPushButton *cosh;
    QPushButton *sqrt;
    QPushButton *ln;
    QPushButton *sinh;
    QPushButton *log;
    QPushButton *cube;
    QPushButton *tan;
    QPushButton *tanh;
    QPushButton *inv;
    QPushButton *fact;
    QPushButton *eval;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *swap;
    QPushButton *sum;
    QPushButton *mean;
    QPushButton *clear;
    QPushButton *dup;
    QPushButton *drop;
    QLineEdit *lineEdit;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QPushButton *addition;
    QPushButton *multiplication;
    QPushButton *pow;
    QPushButton *soustraction;
    QPushButton *division;
    QPushButton *mod;
    QPushButton *sign;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *degUnit;
    QRadioButton *radUnit;
    QPushButton *return_Button;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *entier_radioButton;
    QRadioButton *rationnel_radioButton;
    QRadioButton *reel_radioButton;
    QRadioButton *complexe_radioButton;
    QRadioButton *show_hide;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdition;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(652, 600);
        MainWindow->setMinimumSize(QSize(400, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setAcceptDrops(false);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionParametre = new QAction(MainWindow);
        actionParametre->setObjectName(QString::fromUtf8("actionParametre"));
        charger = new QAction(MainWindow);
        charger->setObjectName(QString::fromUtf8("charger"));
        actionAnnuler = new QAction(MainWindow);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionR_tablir = new QAction(MainWindow);
        actionR_tablir->setObjectName(QString::fromUtf8("actionR_tablir"));
        actionR_glage = new QAction(MainWindow);
        actionR_glage->setObjectName(QString::fromUtf8("actionR_glage"));
        sauvegarder = new QAction(MainWindow);
        sauvegarder->setObjectName(QString::fromUtf8("sauvegarder"));
        sauvegarder_all = new QAction(MainWindow);
        sauvegarder_all->setObjectName(QString::fromUtf8("sauvegarder_all"));
        actionNouvel_onglet_2 = new QAction(MainWindow);
        actionNouvel_onglet_2->setObjectName(QString::fromUtf8("actionNouvel_onglet_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        list = new QListWidget(centralWidget);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 30, 231, 121));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 190, 239, 221));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton1 = new QPushButton(gridLayoutWidget);
        pushButton1->setObjectName(QString::fromUtf8("pushButton1"));

        gridLayout->addWidget(pushButton1, 0, 0, 1, 1);

        pushButton2 = new QPushButton(gridLayoutWidget);
        pushButton2->setObjectName(QString::fromUtf8("pushButton2"));

        gridLayout->addWidget(pushButton2, 0, 1, 1, 1);

        pushButton3 = new QPushButton(gridLayoutWidget);
        pushButton3->setObjectName(QString::fromUtf8("pushButton3"));

        gridLayout->addWidget(pushButton3, 0, 2, 1, 1);

        pushButton4 = new QPushButton(gridLayoutWidget);
        pushButton4->setObjectName(QString::fromUtf8("pushButton4"));

        gridLayout->addWidget(pushButton4, 1, 0, 1, 1);

        pushButton5 = new QPushButton(gridLayoutWidget);
        pushButton5->setObjectName(QString::fromUtf8("pushButton5"));

        gridLayout->addWidget(pushButton5, 1, 1, 1, 1);

        pushButton6 = new QPushButton(gridLayoutWidget);
        pushButton6->setObjectName(QString::fromUtf8("pushButton6"));

        gridLayout->addWidget(pushButton6, 1, 2, 1, 1);

        pushButton7 = new QPushButton(gridLayoutWidget);
        pushButton7->setObjectName(QString::fromUtf8("pushButton7"));

        gridLayout->addWidget(pushButton7, 2, 0, 1, 1);

        pushButton8 = new QPushButton(gridLayoutWidget);
        pushButton8->setObjectName(QString::fromUtf8("pushButton8"));

        gridLayout->addWidget(pushButton8, 2, 1, 1, 1);

        pushButton9 = new QPushButton(gridLayoutWidget);
        pushButton9->setObjectName(QString::fromUtf8("pushButton9"));

        gridLayout->addWidget(pushButton9, 2, 2, 1, 1);

        pushButton0 = new QPushButton(gridLayoutWidget);
        pushButton0->setObjectName(QString::fromUtf8("pushButton0"));

        gridLayout->addWidget(pushButton0, 3, 0, 1, 1);

        reelButton = new QPushButton(gridLayoutWidget);
        reelButton->setObjectName(QString::fromUtf8("reelButton"));

        gridLayout->addWidget(reelButton, 3, 1, 1, 1);

        rationnelButton = new QPushButton(gridLayoutWidget);
        rationnelButton->setObjectName(QString::fromUtf8("rationnelButton"));

        gridLayout->addWidget(rationnelButton, 3, 2, 1, 1);

        complexeButton = new QPushButton(gridLayoutWidget);
        complexeButton->setObjectName(QString::fromUtf8("complexeButton"));

        gridLayout->addWidget(complexeButton, 4, 2, 1, 1);

        quote = new QPushButton(gridLayoutWidget);
        quote->setObjectName(QString::fromUtf8("quote"));

        gridLayout->addWidget(quote, 5, 2, 1, 1);

        backspace = new QPushButton(gridLayoutWidget);
        backspace->setObjectName(QString::fromUtf8("backspace"));

        gridLayout->addWidget(backspace, 4, 0, 1, 1);

        espace = new QPushButton(gridLayoutWidget);
        espace->setObjectName(QString::fromUtf8("espace"));

        gridLayout->addWidget(espace, 4, 1, 1, 1);

        affichePile = new QPushButton(centralWidget);
        affichePile->setObjectName(QString::fromUtf8("affichePile"));
        affichePile->setGeometry(QRect(280, 60, 75, 61));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 0, 781, 21));
        tabWidget->setTabsClosable(true);
        Onglet_1 = new QWidget();
        Onglet_1->setObjectName(QString::fromUtf8("Onglet_1"));
        tabWidget->addTab(Onglet_1, QString());
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 40, 151, 16));
        NbAffiche = new QSpinBox(centralWidget);
        NbAffiche->setObjectName(QString::fromUtf8("NbAffiche"));
        NbAffiche->setGeometry(QRect(420, 30, 42, 22));
        gridLayoutWidget_7 = new QWidget(centralWidget);
        gridLayoutWidget_7->setObjectName(QString::fromUtf8("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(410, 290, 239, 141));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        sin = new QPushButton(gridLayoutWidget_7);
        sin->setObjectName(QString::fromUtf8("sin"));

        gridLayout_7->addWidget(sin, 0, 0, 1, 1);

        cos = new QPushButton(gridLayoutWidget_7);
        cos->setObjectName(QString::fromUtf8("cos"));

        gridLayout_7->addWidget(cos, 0, 1, 1, 1);

        sqr = new QPushButton(gridLayoutWidget_7);
        sqr->setObjectName(QString::fromUtf8("sqr"));

        gridLayout_7->addWidget(sqr, 3, 1, 1, 1);

        cosh = new QPushButton(gridLayoutWidget_7);
        cosh->setObjectName(QString::fromUtf8("cosh"));

        gridLayout_7->addWidget(cosh, 1, 1, 1, 1);

        sqrt = new QPushButton(gridLayoutWidget_7);
        sqrt->setObjectName(QString::fromUtf8("sqrt"));

        gridLayout_7->addWidget(sqrt, 3, 0, 1, 1);

        ln = new QPushButton(gridLayoutWidget_7);
        ln->setObjectName(QString::fromUtf8("ln"));

        gridLayout_7->addWidget(ln, 2, 0, 1, 1);

        sinh = new QPushButton(gridLayoutWidget_7);
        sinh->setObjectName(QString::fromUtf8("sinh"));

        gridLayout_7->addWidget(sinh, 1, 0, 1, 1);

        log = new QPushButton(gridLayoutWidget_7);
        log->setObjectName(QString::fromUtf8("log"));

        gridLayout_7->addWidget(log, 2, 1, 1, 1);

        cube = new QPushButton(gridLayoutWidget_7);
        cube->setObjectName(QString::fromUtf8("cube"));

        gridLayout_7->addWidget(cube, 3, 2, 1, 1);

        tan = new QPushButton(gridLayoutWidget_7);
        tan->setObjectName(QString::fromUtf8("tan"));

        gridLayout_7->addWidget(tan, 0, 2, 1, 1);

        tanh = new QPushButton(gridLayoutWidget_7);
        tanh->setObjectName(QString::fromUtf8("tanh"));

        gridLayout_7->addWidget(tanh, 1, 2, 1, 1);

        inv = new QPushButton(gridLayoutWidget_7);
        inv->setObjectName(QString::fromUtf8("inv"));

        gridLayout_7->addWidget(inv, 2, 2, 1, 1);

        fact = new QPushButton(gridLayoutWidget_7);
        fact->setObjectName(QString::fromUtf8("fact"));

        gridLayout_7->addWidget(fact, 4, 0, 1, 1);

        eval = new QPushButton(gridLayoutWidget_7);
        eval->setObjectName(QString::fromUtf8("eval"));

        gridLayout_7->addWidget(eval, 4, 1, 1, 2);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(420, 220, 239, 61));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        swap = new QPushButton(gridLayoutWidget_2);
        swap->setObjectName(QString::fromUtf8("swap"));

        gridLayout_2->addWidget(swap, 0, 0, 1, 1);

        sum = new QPushButton(gridLayoutWidget_2);
        sum->setObjectName(QString::fromUtf8("sum"));

        gridLayout_2->addWidget(sum, 0, 1, 1, 1);

        mean = new QPushButton(gridLayoutWidget_2);
        mean->setObjectName(QString::fromUtf8("mean"));

        gridLayout_2->addWidget(mean, 0, 2, 1, 1);

        clear = new QPushButton(gridLayoutWidget_2);
        clear->setObjectName(QString::fromUtf8("clear"));

        gridLayout_2->addWidget(clear, 1, 0, 1, 1);

        dup = new QPushButton(gridLayoutWidget_2);
        dup->setObjectName(QString::fromUtf8("dup"));

        gridLayout_2->addWidget(dup, 1, 1, 1, 1);

        drop = new QPushButton(gridLayoutWidget_2);
        drop->setObjectName(QString::fromUtf8("drop"));

        gridLayout_2->addWidget(drop, 1, 2, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 160, 231, 20));
        lineEdit->setReadOnly(true);
        gridLayoutWidget_5 = new QWidget(centralWidget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(320, 190, 77, 199));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        addition = new QPushButton(gridLayoutWidget_5);
        addition->setObjectName(QString::fromUtf8("addition"));

        gridLayout_5->addWidget(addition, 0, 0, 1, 1);

        multiplication = new QPushButton(gridLayoutWidget_5);
        multiplication->setObjectName(QString::fromUtf8("multiplication"));

        gridLayout_5->addWidget(multiplication, 2, 0, 1, 1);

        pow = new QPushButton(gridLayoutWidget_5);
        pow->setObjectName(QString::fromUtf8("pow"));

        gridLayout_5->addWidget(pow, 4, 0, 1, 1);

        soustraction = new QPushButton(gridLayoutWidget_5);
        soustraction->setObjectName(QString::fromUtf8("soustraction"));

        gridLayout_5->addWidget(soustraction, 1, 0, 1, 1);

        division = new QPushButton(gridLayoutWidget_5);
        division->setObjectName(QString::fromUtf8("division"));

        gridLayout_5->addWidget(division, 3, 0, 1, 1);

        mod = new QPushButton(gridLayoutWidget_5);
        mod->setObjectName(QString::fromUtf8("mod"));

        gridLayout_5->addWidget(mod, 6, 0, 1, 1);

        sign = new QPushButton(gridLayoutWidget_5);
        sign->setObjectName(QString::fromUtf8("sign"));

        gridLayout_5->addWidget(sign, 5, 0, 1, 1);

        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(280, 130, 81, 44));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        degUnit = new QRadioButton(verticalLayoutWidget_3);
        degUnit->setObjectName(QString::fromUtf8("degUnit"));

        verticalLayout_3->addWidget(degUnit);

        radUnit = new QRadioButton(verticalLayoutWidget_3);
        radUnit->setObjectName(QString::fromUtf8("radUnit"));

        verticalLayout_3->addWidget(radUnit);

        return_Button = new QPushButton(centralWidget);
        return_Button->setObjectName(QString::fromUtf8("return_Button"));
        return_Button->setGeometry(QRect(260, 190, 51, 61));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(380, 70, 111, 92));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        entier_radioButton = new QRadioButton(verticalLayoutWidget);
        entier_radioButton->setObjectName(QString::fromUtf8("entier_radioButton"));

        verticalLayout->addWidget(entier_radioButton);

        rationnel_radioButton = new QRadioButton(verticalLayoutWidget);
        rationnel_radioButton->setObjectName(QString::fromUtf8("rationnel_radioButton"));

        verticalLayout->addWidget(rationnel_radioButton);

        reel_radioButton = new QRadioButton(verticalLayoutWidget);
        reel_radioButton->setObjectName(QString::fromUtf8("reel_radioButton"));
        reel_radioButton->setChecked(true);

        verticalLayout->addWidget(reel_radioButton);

        complexe_radioButton = new QRadioButton(verticalLayoutWidget);
        complexe_radioButton->setObjectName(QString::fromUtf8("complexe_radioButton"));

        verticalLayout->addWidget(complexe_radioButton);

        show_hide = new QRadioButton(centralWidget);
        show_hide->setObjectName(QString::fromUtf8("show_hide"));
        show_hide->setGeometry(QRect(410, 190, 82, 18));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 652, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuFile->addAction(charger);
        menuFile->addAction(sauvegarder);
        menuFile->addAction(actionNouvel_onglet_2);
        menuFile->addAction(actionQuit);
        menuEdition->addAction(actionAnnuler);
        menuEdition->addAction(actionR_tablir);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculatrice", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionParametre->setText(QApplication::translate("MainWindow", "Parametre", 0, QApplication::UnicodeUTF8));
        charger->setText(QApplication::translate("MainWindow", "Charger une nouvelle pile", 0, QApplication::UnicodeUTF8));
        charger->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionR_tablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        actionR_tablir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionR_glage->setText(QApplication::translate("MainWindow", "R\303\251glages", 0, QApplication::UnicodeUTF8));
        sauvegarder->setText(QApplication::translate("MainWindow", "Enregistrer la pile sous", 0, QApplication::UnicodeUTF8));
        sauvegarder->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        sauvegarder_all->setText(QApplication::translate("MainWindow", "Sauvegarder toutes les piles", 0, QApplication::UnicodeUTF8));
        sauvegarder_all->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionNouvel_onglet_2->setText(QApplication::translate("MainWindow", "Nouvel onglet", 0, QApplication::UnicodeUTF8));
        actionNouvel_onglet_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        pushButton1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        pushButton1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        pushButton2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        pushButton2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        pushButton3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushButton3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        pushButton4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        pushButton4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        pushButton5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        pushButton5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        pushButton6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        pushButton6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        pushButton7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        pushButton7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        pushButton8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        pushButton8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        pushButton9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        pushButton9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        pushButton0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        pushButton0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        reelButton->setText(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        reelButton->setShortcut(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        rationnelButton->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        rationnelButton->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        complexeButton->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        complexeButton->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        quote->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        quote->setShortcut(QApplication::translate("MainWindow", "Q", 0, QApplication::UnicodeUTF8));
        backspace->setText(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        backspace->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        espace->setText(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        espace->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        affichePile->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        affichePile->setShortcut(QApplication::translate("MainWindow", "A", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        Onglet_1->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        Onglet_1->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        tabWidget->setTabText(tabWidget->indexOf(Onglet_1), QApplication::translate("MainWindow", "Calcul 1", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Nombre d'\303\251l\303\251m\303\251nts \303\240 afficher :", 0, QApplication::UnicodeUTF8));
        sin->setText(QApplication::translate("MainWindow", "Sin", 0, QApplication::UnicodeUTF8));
        cos->setText(QApplication::translate("MainWindow", "Cos", 0, QApplication::UnicodeUTF8));
        sqr->setText(QApplication::translate("MainWindow", "Sqr", 0, QApplication::UnicodeUTF8));
        cosh->setText(QApplication::translate("MainWindow", "CosH", 0, QApplication::UnicodeUTF8));
        sqrt->setText(QApplication::translate("MainWindow", "Sqrt", 0, QApplication::UnicodeUTF8));
        ln->setText(QApplication::translate("MainWindow", "Ln", 0, QApplication::UnicodeUTF8));
        sinh->setText(QApplication::translate("MainWindow", "SinH", 0, QApplication::UnicodeUTF8));
        log->setText(QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        cube->setText(QApplication::translate("MainWindow", "Cube", 0, QApplication::UnicodeUTF8));
        tan->setText(QApplication::translate("MainWindow", "Tan", 0, QApplication::UnicodeUTF8));
        tanh->setText(QApplication::translate("MainWindow", "TanH", 0, QApplication::UnicodeUTF8));
        inv->setText(QApplication::translate("MainWindow", "Inv", 0, QApplication::UnicodeUTF8));
        fact->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        eval->setText(QApplication::translate("MainWindow", "Eval", 0, QApplication::UnicodeUTF8));
        swap->setText(QApplication::translate("MainWindow", "Swap", 0, QApplication::UnicodeUTF8));
        sum->setText(QApplication::translate("MainWindow", "Sum", 0, QApplication::UnicodeUTF8));
        mean->setText(QApplication::translate("MainWindow", "Mean", 0, QApplication::UnicodeUTF8));
        clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        clear->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        dup->setText(QApplication::translate("MainWindow", "Dup", 0, QApplication::UnicodeUTF8));
        drop->setText(QApplication::translate("MainWindow", "Drop", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
        addition->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        multiplication->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        pow->setText(QApplication::translate("MainWindow", "Pow", 0, QApplication::UnicodeUTF8));
        soustraction->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        division->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        mod->setText(QApplication::translate("MainWindow", "Mod", 0, QApplication::UnicodeUTF8));
        sign->setText(QApplication::translate("MainWindow", "Sign", 0, QApplication::UnicodeUTF8));
        degUnit->setText(QApplication::translate("MainWindow", "Degr\303\251", 0, QApplication::UnicodeUTF8));
        radUnit->setText(QApplication::translate("MainWindow", "Radiant", 0, QApplication::UnicodeUTF8));
        return_Button->setText(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        return_Button->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        entier_radioButton->setText(QApplication::translate("MainWindow", "Entier", 0, QApplication::UnicodeUTF8));
        rationnel_radioButton->setText(QApplication::translate("MainWindow", "Rationnel", 0, QApplication::UnicodeUTF8));
        reel_radioButton->setText(QApplication::translate("MainWindow", "Reel", 0, QApplication::UnicodeUTF8));
        complexe_radioButton->setText(QApplication::translate("MainWindow", "Complexe", 0, QApplication::UnicodeUTF8));
        show_hide->setText(QApplication::translate("MainWindow", "Hide", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
