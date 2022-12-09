#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "reservationh.h"
#include "reservation.h"
#include "connection.h"
#include "WebAxWidget.h"
#include <QMainWindow>
#include <qjsondocument.h>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkCookie>
#include <QNetworkCookieJar>
#include <QNetworkReply>
#include <QNetworkSession>
#include <QAbstractSocket>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //Oussema
    void on_pushButton_ajoutcl_clicked();

    void on_pushButton_modifcl_clicked();

    void on_pushButton_supcl_clicked();
    void on_pushButton_triN_clicked();
    void on_pushButton_triId_clicked();
    void on_pushButton_triP_clicked();
    void on_pushButton_rechercheId_clicked();
    void on_pushButton_rechercheN_clicked();
    void on_pushButton_exportpdf_clicked();
    void on_pushButton_alerte_clicked();
    void on_pushButton_choisir_clicked();
    QVector<double> statistiques();
    void makePlot();
    void on_pushButton_statistiques_clicked();
    void on_calendarWidget_clicked(const QDate &date);
     void on_pushButton_connect_clicked();
   /************************************************************************/

     /***perrial**/
     void on_bouton_ajouter_clicked();
     //void on_bouton_supprimer_clicked();
     void on_pushButton_clicked();

     void on_table_reservation_doubleClicked(const QModelIndex &index);

     void on_pushButton_2_clicked();

     void on_pushButton_rechercheId_2_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_6_clicked();

     /***********************************************/



     //void on_bouton_ajouter_2_clicked();


     //void on_pushButton_rechercheId_3_clicked();

     void on_pushButton_11_clicked();

     void on_pushButton_deconnexion_clicked();

     void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    //Oussema//////////////////////
     reservationh R;
     reservationh ptmp ;
     /*********************/

     /***Perrial*****/
     Reservation Etmp;
        Reservation E;
        /*********************/

     QNetworkAccessManager *manager;
             QByteArray token = "";
             QByteArray user = "";
             QByteArray name = "";
             QJsonObject json;
             QJsonArray selected_day_json;
             QString select_date;
             QByteArray post(QString url, QByteArray data, const char *type);
             QByteArray get(QString url);
             QJsonObject format(QByteArray data);
             void updatetoken(QNetworkReply *reply);
     /************************************************************************/
};
#endif // MAINWINDOW_H
