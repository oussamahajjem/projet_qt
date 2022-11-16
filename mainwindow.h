#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reservationh.h"
#include <QMainWindow>
#include <qjsondocument.h>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkCookie>
#include <QNetworkCookieJar>
#include <QNetworkReply>
#include <QNetworkSession>
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
private:
    Ui::MainWindow *ui;
    reservationh R;
    reservationh ptmp ;
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
};
#endif // MAINWINDOW_H
