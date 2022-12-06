#ifndef RESERVATIONH_H
#define RESERVATIONH_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<iostream>
class reservationh
{
private :
    int Id ,prix;
    QString nomPrenom,hebergement,codeC;
    QDate checkin,checkout;

public:
    reservationh();
    reservationh(int,QString,QString,QDate,QDate,int,QString);
    int getId();
    int getprix();

    QString getnomPrenom();
    QString gethebergement();
    QString getcodeC();
    QDate getcheckin();
    QDate  getcheckout();

    void setId(int);
    void setnomPrenom(QString);
    void setcheckout(QDate);
    void setcheckin(QDate);
    void sethebergement(QString);
    void setprix(int);
    void setcodeC(QString);
    void creation_pdf();

    bool ajouter();
    bool supprimer (int);
    bool modifier(int );

    QSqlQueryModel* alerte();
    QSqlQueryModel * afficher();
    QSqlQueryModel * triId();
    QSqlQueryModel * triN();
    QSqlQueryModel * triP();
    QSqlQueryModel * rechercheId(int Id);
    QSqlQueryModel * rechercheN(QString a);
    QSqlQueryModel * rechercheC(QString a);



};

#endif // RESERVATIONH_H
