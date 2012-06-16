#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pile.h"

#include "entier.h"
#include "reel.h"
#include "rationnel.h"
#include "complexe.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <QTextStream>



using namespace std;


//Design Pattern Singleton
MainWindow* MainWindow::instanceUnique = 0;

// Donne une instance -> Singleton.
MainWindow& MainWindow::donneInstance()
{
    Pile pile;
    if (instanceUnique == 0)
        instanceUnique = new MainWindow (pile,0);

    return *instanceUnique;
}

// Libere instance du Singleton.
void MainWindow::libereInstance()
{
    if (instanceUnique != 0)
            delete instanceUnique;
    instanceUnique = 0;
}

// Destructeur.
MainWindow::~MainWindow()
{
    if (instanceUnique != 0)
    {
        delete instanceUnique->ui;
        delete instanceUnique;
    }
}


MainWindow::MainWindow(Pile &pile, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(keyPress(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
    QObject::connect(this, SIGNAL(pushStack_signal(const QString&)), this, SLOT(pushStack_slot(const QString&)));
    QObject::connect(this, SIGNAL(cleanList_signal()), this, SLOT(cleanList_slot()));
    QObject::connect(this, SIGNAL(refresh_signal()), this, SLOT(refresh_slot()));
    QObject::connect(ui->show_hide, SIGNAL(clicked()),this, SLOT(hide_show_offon()));

    Collection_pile::getInstance().addPile(&pile);
    emit refresh_signal();
    ui->degUnit->setChecked(true);

}
/*   plus utile car declaration de l'instance unique qui detruit l'objet
MainWindow::~MainWindow()
{
    delete ui;
}*/


void MainWindow::hide_show_offon()
{
    if (height()==256)
        setFixedHeight(512);
    else setFixedHeight(256);

}



//Connexion des pushButton 0 � 9
void MainWindow::on_pushButton0_clicked(){
    ui->lineEdit->insert("0");
}
void MainWindow::on_pushButton1_clicked(){
    ui->lineEdit->insert("1");
}
void MainWindow::on_pushButton2_clicked(){
    ui->lineEdit->insert("2");
}
void MainWindow::on_pushButton3_clicked(){
    ui->lineEdit->insert("3");
}
void MainWindow::on_pushButton4_clicked(){
    ui->lineEdit->insert("4");
}
void MainWindow::on_pushButton5_clicked(){
    ui->lineEdit->insert("5");
}
void MainWindow::on_pushButton6_clicked(){
    ui->lineEdit->insert("6");
}
void MainWindow::on_pushButton7_clicked(){
    ui->lineEdit->insert("7");
}
void MainWindow::on_pushButton8_clicked(){
    ui->lineEdit->insert("8");
}
void MainWindow::on_pushButton9_clicked(){
    ui->lineEdit->insert("9");
}

void MainWindow::on_espace_clicked(){
    ui->lineEdit->insert(" ");
}


void MainWindow::on_return_Button_clicked(){

    if (ui->lineEdit->text()!="")
    {
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->parser(ui->lineEdit->text());
    //dans la pile active
    refresh_signal();
    ui->lineEdit->clear();
    }

}

void MainWindow::on_affichePile_clicked(){
   emit refresh_signal();
}

void MainWindow::on_swap_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->swap(0, 1);
    emit refresh_signal();
}

void MainWindow::on_sum_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->sum(10);
    emit refresh_signal();
}

void MainWindow::on_mean_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->mean(10);
    emit refresh_signal();
}

void MainWindow::on_clear_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->clear();
    emit cleanList_signal();
}

void MainWindow::on_dup_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->dup();
    emit refresh_signal();
}

void MainWindow::on_drop_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->drop();
    emit refresh_signal();
}


//Selection du type de donnee utilise
void MainWindow::pushStack_slot(const QString& t){
    ui->list->addItem(t);
}

void MainWindow::on_backspace_clicked(){
    ui->lineEdit->backspace();
}

void MainWindow::cleanList_slot(){
    ui->list->clear();
}

void MainWindow::refresh_slot(){
    ui->list->clear();
    ui->NbAffiche->clear();
    int n=Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->getNb();
    ui->NbAffiche->setValue(n);
    for(int i=Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->size()-1; i>=0 && n>0; i--){
        ui->list->addItem((Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->at(i))->toQString());
        n--;
    }
}

void MainWindow::on_complexeButton_clicked(){
        ui->lineEdit->insert("$");
}

void MainWindow::on_reelButton_clicked(){
            ui->lineEdit->insert(",");
}

void MainWindow::on_rationnelButton_clicked(){
             ui->lineEdit->insert("/");
}


void MainWindow::on_addition_clicked(){
    ui->lineEdit->insert("+");

    refresh_signal();
}

void MainWindow::on_soustraction_clicked()
{
    ui->lineEdit->insert("-");
    refresh_signal();
}


void MainWindow::on_multiplication_clicked()
{
    ui->lineEdit->insert("*");
    refresh_signal();
}

void MainWindow::on_division_clicked()
{
    ui->lineEdit->insert("/");
    refresh_signal();
}

void MainWindow::on_pow_clicked(){
    ui->lineEdit->insert("pow");
    refresh_signal();
}

void MainWindow::on_mod_clicked(){
    ui->lineEdit->insert("mod");
    refresh_signal();
}

void MainWindow::on_sign_clicked(){
    ui->lineEdit->insert("sign");
    refresh_signal();
}


void MainWindow::on_sin_clicked(){
    ui->lineEdit->insert("sin");
    refresh_signal();
}

void MainWindow::on_cos_clicked(){
    ui->lineEdit->insert("cos");
    refresh_signal();
}
void MainWindow::on_tan_clicked(){
    ui->lineEdit->insert("tan");
    refresh_signal();
}
void MainWindow::on_sinh_clicked(){
    ui->lineEdit->insert("sinh");
    refresh_signal();
}
void MainWindow::on_cosh_clicked(){
    ui->lineEdit->insert("cosh");
    refresh_signal();
}
void MainWindow::on_tanh_clicked(){
    ui->lineEdit->insert("tanh");
    refresh_signal();
}

void MainWindow::on_ln_clicked(){
    ui->lineEdit->insert("ln");
    refresh_signal();
}

void MainWindow::on_log_clicked(){
    ui->lineEdit->insert("log");
    refresh_signal();
}

void MainWindow::on_inv_clicked(){
    ui->lineEdit->insert("inv");
    refresh_signal();
}

void MainWindow::on_sqrt_clicked(){
    ui->lineEdit->insert("sqrt");
    refresh_signal();
}

void MainWindow::on_sqr_clicked(){
    ui->lineEdit->insert("sqr");
    refresh_signal();
}

void MainWindow::on_cube_clicked(){
    ui->lineEdit->insert("cube");
    refresh_signal();
}

void MainWindow::on_fact_clicked(){
    ui->lineEdit->insert("!");
    refresh_signal();
}

void MainWindow::on_eval_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->eval();
    refresh_signal();
}




void MainWindow::on_actionParametre_triggered()
{
}

void MainWindow::on_quote_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ui->quote->text());
}

void MainWindow::on_undo_clicked(){

}

void MainWindow::on_redo_clicked(){
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->undo();
    emit refresh_signal();

}

void MainWindow::createOnglet()
{
    Collection_pile::getInstance().addPile(Collection_pile::getInstance().at(Collection_pile::getInstance().getActif()));

}

void MainWindow::on_tabWidget_currentChanged(unsigned int index)
{
    if(index>=Collection_pile::getInstance().size())
    createOnglet();
    Collection_pile::getInstance().setActif(index);
    emit refresh_signal();
}

void MainWindow::on_actionNouvel_onglet_triggered()
{


}

void MainWindow::on_actionNouvel_onglet_2_triggered()
{
    createOnglet();
    QWidget *ajout = new QTabWidget(this);
    QString res;
    QTextStream ss(&res);
    ss << "Onglet "<< Collection_pile::getInstance().size();

        ui->tabWidget->addTab(ajout,res);
        ui->tabWidget->setCurrentIndex(Collection_pile::getInstance().size()-1);
}

void MainWindow::on_actionAnnuler_triggered()
{
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->undo();
   emit refresh_signal();
}

void MainWindow::on_actionR_tablir_triggered()
{
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->redo();
   emit refresh_signal();
}

void MainWindow::on_tabWidget_destroyed()
{

}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if (index>0)
    {

    delete Collection_pile::getInstance().at(index);
        Collection_pile::getInstance().erase(Collection_pile::getInstance().begin()+index);
    ui->tabWidget->removeTab(index);

    }
}

void MainWindow::on_actionR_glage_triggered()
{
}



void MainWindow::on_nbelt_textChanged(const QString &arg1){}


void MainWindow::on_nbelt_textEdited(const QString &arg1)
{
    int n=arg1.toInt();
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->setNbElt(n);
    emit refresh_signal();
}

void MainWindow::on_charger_triggered(){
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "XML files (*.xml)");
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->charger(fichier);
    emit refresh_signal();
}

void MainWindow::on_sauvegarder_triggered(){
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "XML files (*.xml)");
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->sauvegarder(fichier);
    emit refresh_signal();
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{

}

void MainWindow::on_NbAffiche_valueChanged(int arg1)
{
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->setNbElt(arg1);
    emit refresh_signal();
}

void MainWindow::on_degUnit_clicked()
{
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->setDegre(true);
}

void MainWindow::on_radUnit_clicked()
{
    Collection_pile::getInstance().at(Collection_pile::getInstance().getActif())->setDegre(false);
}



