#ifndef CALCPOLO_H
#define CALCPOLO_H

#include <QMainWindow>
#include <stack>
#include "NombreReel.h"
#include <QString>
#include <QMessageBox>


namespace Ui {
class CalcPolo;
}

class CalcPolo : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CalcPolo(QWidget *parent = 0);
    ~CalcPolo();


    
private:
    Ui::CalcPolo *ui;
    std::stack<Reel> Pile;  //Pour l'instant pile de reel, mais il faudra changer (ou pas)



private slots:
    void hide_show_offon();
    void empiler_reel();
    //void affiche_pile();

    void affiche_pile();
    void empile_plus();
    void empile_moins();
    void empile_fois();
    void empile_div();
    void empile_sin();
    void clear_pile();



    //SLOTS sans connect
    void on_pushButton_Load_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_point_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_return_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_less_clicked();
    void on_pushButton_multi_clicked();
    void on_pushButton_cless_clicked();
    void on_pushButton_div_clicked();
    void on_pushButton_clear_clicked();



    void on_pushButton_sin_clicked();
};

#endif // CALCPOLO_H
