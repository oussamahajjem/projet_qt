#ifndef RESERVATION_H
#define RESERVATION_H
#include<QSqlQueryModel>
#include<QtDebug>
#include <QString>
#include <QSqlQuery>
#include <iostream>
#include <QSqlQueryModel>

class Reservation
{
public:
    Reservation(){}
    //Reservation(QString, QString, QString, QString, float, float);
    Reservation(QString, QString, QString, QString, QString, QString);


    QString getdepart(){return depart;}
    QString getarrive(){return arrive;}
    QString gettransport(){return transport;}
    QString getclasse(){return classe;}
    QString geth_depart(){return h_depart;}
    QString geth_arrive(){return h_arrive;}

    void  setdepart(QString d){depart=d;}
    void  setarrive(QString a){arrive=a;}
    void  settransport(QString t){transport=t;}
    void  setclasse(QString c){classe=c;}
    void  seth_depart(float hd){h_depart=hd;}
    void seth_arrive(float ha){h_arrive=ha;}

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString num);
    bool modifier(Reservation r,int num);
    QSqlQueryModel* rechercheId(QString a);
    QSqlQueryModel* Tri();
    bool rechercher(QString num);


private:
    QString depart, arrive, transport, classe,h_depart, h_arrive;

};

#endif // RESERVATION_H
