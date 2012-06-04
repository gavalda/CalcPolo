#include "calcpolo.h"
#include "ui_calcpolo.h"
#include "Calculatrice.h"
#include "NombreReel.h"
#include <sstream>
#include "Function.h"
#include "string"

CalcPolo::CalcPolo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CalcPolo)
{
    ui->setupUi(this);
    setFixedSize(512,256);

    QObject::connect(ui->show_hide, SIGNAL(clicked()),this, SLOT(hide_show_offon()));
    QObject::connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(empiler_reel()));
    QObject::connect(ui->pushButton_Load, SIGNAL(clicked()),ui->listWidget, SLOT(affiche_pile()));   //ne fonctionne pas, le SLOT on_pushButton_Load_clicked() plus bas suffit.
    QObject::connect(ui->pushButton_0, SIGNAL(clicked()), ui->lineEdit, SLOT(line_0()));               //celui là non-plus. Pas de connect du coup, uniquement des SLOT
}

CalcPolo::~CalcPolo()
{
    delete ui;
}


void CalcPolo::hide_show_offon()
{
    if (height()==512)
        setFixedHeight(256);
    else setFixedHeight(512);

}






void CalcPolo::empiler_reel()
{
      QString chaine = ui->lineEdit->text();  //chaine : QString
      float fl;
      int i;
      bool b=false;
      QByteArray ba = chaine.toLocal8Bit();
      const char *cstr = ba.data();         //récupération de la chaine en char*

//a-t-on bien un réel double ?
      if (!atof(cstr))                  //si atof(cstr) renvoie 0 -> alors ça veut dire que soit  1)la chaine est '000[...]000.0000[..]00'    avec [1..n].[0..k] le nombre de 0
      {                                                                                         //2)on n'a pas un double dans la chaine
          bool point=false; //booléen qui indique vrai si il a déja rencontré un point
          b=true;           //boolée qui indique s'il doit être considéré comme un double
          if (cstr[0]!='0') //si le premier ou le dernier élément n'est pas '0' -> impossible
          {
              b=false;
          }

          else              //sinon on check chaque élément de la suite de la chaine
          {
                 for (i=1; i<ba.length(); i++)

                {
                        if (cstr[i]!='0')               //si le char est différent de '0'
                        {
                            if (cstr[i]!='.')           //alors s'il est différent de '.', on a pas un double
                            {
                                b=false; break;
                            }
                            else                        //sinon, si on a un point, alors si on a déja rencontré un point (point==true), on a pas un double
                            {
                                if (point==true)
                                {
                                    b=false; break;
                                }
                                else                    //si on n'a jamais rencontré de point avant celui là, on note qu'on vient de rencontrer un point et on continue la boucle.
                                {
                                point=true;
                                }
                            }
                        }

                }



           }
      }
      else
      {
          b=true;                       //sinon b=true, aucun problème on a à faire à un réel
      }


      if (b)
      {
          fl=atof(cstr);
          Reel R(fl);
          Pile.push(R);

      }
      ui->lineEdit->clear();


}




void CalcPolo::affiche_pile()
{
    ui->listWidget->clear();
    std::stack<Reel> Pile2=Pile;

   /* Reel R(3.5);
    Reel U(1.0);
    Reel RR(66);
    Pile2.push(R);
    Pile2.push(U);
    Pile2.push(RR);*/
    unsigned i;
    unsigned taille = Pile.size();
    for (i=0; i<taille; i++)
    {

        Reel r = Pile2.top();
        double f=r.getvaleur();

                                             //  créer un flux de sortie
          std::ostringstream oss;
                                                //  écrire un nombre dans le flux
            oss << f;
                                                     //récupérer une chaîne de caractères
         // std::string chainz = oss.str();
      //  double f=15;


        ui->listWidget->addItem(QString::number(f));
        Pile2.pop();
    }
}

void CalcPolo::empile_plus()
{
    if (Pile.size()<2){}                    //si on a moins de deux éléments dans la pile, on fait rien.
    else
    {
        Reel r1 = Pile.top();
        Pile.pop();
        Reel r2 = Pile.top();
        Pile.pop();
        Pile.push(r1+r2);
    }
}



//LES SLOTS SANS CONNECT


void CalcPolo::on_pushButton_Load_clicked()
{
    affiche_pile();
}

void CalcPolo::on_pushButton_0_clicked()
{
      ui->lineEdit->insert("0");
}

void CalcPolo::on_pushButton_point_clicked()
{
    ui->lineEdit->insert(".");
}

void CalcPolo::on_pushButton_1_clicked()
{
    ui->lineEdit->insert("1");
}

void CalcPolo::on_pushButton_2_clicked()
{
    ui->lineEdit->insert("2");
}

void CalcPolo::on_pushButton_3_clicked()
{
    ui->lineEdit->insert("3");
}

void CalcPolo::on_pushButton_4_clicked()
{
    ui->lineEdit->insert("4");
}

void CalcPolo::on_pushButton_5_clicked()
{
    ui->lineEdit->insert("5");
}

void CalcPolo::on_pushButton_6_clicked()
{
    ui->lineEdit->insert("6");
}

void CalcPolo::on_pushButton_7_clicked()
{
    ui->lineEdit->insert("7");
}

void CalcPolo::on_pushButton_8_clicked()
{
    ui->lineEdit->insert("8");
}

void CalcPolo::on_pushButton_9_clicked()
{
    ui->lineEdit->insert("9");
}

void CalcPolo::on_pushButton_return_clicked()
{
    empiler_reel();
}

void CalcPolo::on_pushButton_plus_clicked()
{
    empile_plus();
}
