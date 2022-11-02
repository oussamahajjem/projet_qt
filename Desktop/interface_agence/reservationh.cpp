#include "reservationh.h"
#include <QSqlQuery>
#include <QtDebug>

reservationh::reservationh()
{
    Id= 0;nomPrenom=" ";hebergement=" ";prix=0;

}
reservationh::reservationh(int Id,QString nomPrenom,QString hebergement,QDate checkin,QDate checkout,int prix)
{
    this->Id=Id;this->nomPrenom=nomPrenom;this->hebergement=hebergement;this->checkin=checkin;this->checkout=checkout;this->prix=prix;
}
int reservationh::getId(){return Id;}
QString reservationh::getnomPrenom(){return nomPrenom;}
QString reservationh::gethebergement(){return hebergement;}
QDate reservationh::getcheckin(){return checkin;}
QDate reservationh::getcheckout(){return checkout;}
int reservationh::getprix(){return prix;}
void reservationh::setId(int Id){this->Id=Id;}
void reservationh::setnomPrenom(QString nomPrenom){this->nomPrenom=nomPrenom;}
void reservationh::sethebergement(QString hebergement){this->hebergement=hebergement;}
void reservationh::setcheckin(QDate checkin){this->checkin=checkin;}
void reservationh::setcheckout(QDate checkout){this->checkout=checkout;}
void reservationh::setprix(int prix){this->prix=prix;}
bool reservationh::ajouter()
{
    //bool test=false;
    QSqlQuery query;
    QString Id_string=QString::number(Id);
    QString prix_string=QString::number(prix);
          query.prepare("INSERT INTO RESERVATIONH (Id,nomPrenom,hebergement,checkin,checkout,prix) "
                        "VALUES (:Id,:nomPrenom,:hebergement,:checkin,:checkout,:prix)");
          query.bindValue(":Id", Id_string);
          query.bindValue(":nomPrenom",nomPrenom);
          query.bindValue(":hebergement", hebergement);
          query.bindValue(":checkin", checkin);
          query.bindValue(":checkout",checkout);
          query.bindValue(":prix", prix_string);
         return query.exec();
         // return test;

}
QSqlQueryModel* reservationh::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* from RESERVATIONH");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomPrenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("hebergement"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("checkin"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("checkout"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("prix"));
    return model;


}
bool reservationh::supprimer(int n)
{
    QSqlQuery query;
    query.prepare("DELETE FROM reservationh WHERE Id= :Id");
    query.bindValue(":Id",n);
    return query.exec();
}
bool reservationh::modifier(int Id)
{
    QSqlQuery query;
    QString Id_string=QString::number(Id);
    QString prix_string=QString::number(prix);
    //QString res=QString::number(id);
    query.prepare("UPDATE RESERVATIONH SET Id=:Id,nomPrenom=:nomPrenom,hebergement=:hebergement,checkin=:checkin,checkout=:checkout,prix=:prix WHERE Id=:Id");
    query.bindValue(":Id",Id_string);
    query.bindValue(":nomPrenom",nomPrenom);
    query.bindValue(":hebergement",hebergement);
    query.bindValue(":checkin",checkin);
    query.bindValue(":checkout",checkout);
    query.bindValue(":prix",prix_string);

    return query.exec();
}

