#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservationh.h"
#include <QApplication>
#include <QMessageBox>
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Id->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_rh->setModel(R.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_ajoutcl_clicked()

{   int Id=ui->lineEdit_Id->text().toInt();
    QString nomPrenom=ui->lineEdit_nomPrenom->text();
    QString hebergement=ui->lineEdit_hebergement->text();
    QDate checkin=ui->dateEdit_checkin->date();
    QDate checkout=ui->dateEdit_checkout->date();
    int prix=ui->lineEdit_prix->text().toInt();
    reservationh R(Id,nomPrenom,hebergement,checkin,checkout,prix);
    bool test=R.ajouter();
    if(test)
       {QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("AJOUT EFFECTUER.\n""click cancel to exit"),QMessageBox::Cancel);
       ui->tab_rh->setModel(R.afficher());}
    else
        QMessageBox::critical(nullptr,QObject::tr("nn"),QObject::tr("ajout non effectuer.\n""click cancel to exit"),QMessageBox::Cancel);

}
void MainWindow::on_pushButton_modifcl_clicked()
{
    int Id=ui->lineEdit_Id->text().toInt();
    QString nomPrenom=ui->lineEdit_nomPrenom->text();
    QString hebergement=ui->lineEdit_hebergement->text();
    QDate checkin=ui->dateEdit_checkin->date();
    QDate checkout=ui->dateEdit_checkout->date();
    int prix=ui->lineEdit_prix->text().toInt();

    reservationh R(Id,nomPrenom,hebergement,checkin,checkout,prix);
    bool test=R.modifier(Id);
           if (test)

           {
               ui->tab_rh->setModel(R.afficher());
               QMessageBox :: information (nullptr, QObject ::tr("OK"),
                            QObject ::tr("modifier effectué\n"
                                         "click cancel to exit"),
                       QMessageBox:: Cancel);
       }
           else
           {
               QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                    QObject::tr("try again.\n"
                                                "click cancel to exit."),QMessageBox::Cancel);
           }
}
void MainWindow::on_pushButton_supcl_clicked()
{

       int n=ui->lineEdit_Id->text().toInt();
             bool test=R.supprimer(n);
             if (test)
             {
                 ui->tab_rh->setModel(R.afficher());
                QMessageBox :: information (nullptr, QObject ::tr("OK"),
                              QObject ::tr("suppression effectué\n"
                                           "click cancel to exit"),
                         QMessageBox:: Cancel);

            }
             else
             {
                 QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                      QObject::tr("try again.\n"
                                                  "click cancel to exit."),QMessageBox::Cancel);
             }

}
