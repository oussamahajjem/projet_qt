#include "reservation.h"
#include <QSqlQuery>
#include <QtDebug>
/*
Reservation::Reservation(QString depart, QString arrive, QString transport, QString classe, float h_depart, float h_arrive)
{
    this->depart=depart;
   this->arrive=arrive;
     this->transport=transport;
this->classe=classe;
this->h_depart=h_depart;
this->h_arrive=h_arrive;
}
*/

Reservation::Reservation(QString depart, QString arrive, QString transport, QString classe, QString h_depart, QString h_arrive)
{
    this->depart=depart;
    this->arrive=arrive;
    this->transport=transport;
    this->classe=classe;
    this->h_depart=h_depart;
    this->h_arrive=h_arrive;
}


/*
QString Reservation :: getdepart(){return depart;}
 QString Reservation :: getarrive(){return arrive;}
QString Reservation ::gettransport(){return transport;}
 QString Reservation ::getclasse(){return classe;}
 float Reservation ::geth_depart(){return h_depart;}
 float Reservation ::geth_arrive(){return h_arrive;}

 void  Reservation ::setdepart (QString depart){this->depart=depart; }
 void Reservation ::setarrive ( QString arrive){this->arrive=arrive; }
 void  Reservation ::settransport (QString transport){this->transport=transport;}
 void Reservation ::setclasse (QString classe){this->classe=classe; }
 void Reservation :: seth_depart (float h_depart){this->h_depart=h_depart;}
 void Reservation :: seth_arrive (float h_arrive){this->h_arrive=h_arrive;}
*/

bool Reservation ::ajouter()
{


    QSqlQuery query;
    /* QString  h_depart = QString::number(this->h_depart);

     QString  h_arrive = QString::number(this->h_arrive);*/

    query.prepare("INSERT INTO Reservation (depart, arrive, transport,classe,h_depart,h_arrive) "
                  "values (:depart, :arrive, :transport, :classe, :h_depart, :h_arrive)");
    query.bindValue(":depart", depart);
    query.bindValue(":arrive", arrive);
    query.bindValue(":transport", transport);
    query.bindValue(":classe", classe);
    query.bindValue(":h_depart", h_depart);
    query.bindValue(":h_arrive", h_arrive);
    //query.exec();

    return  query.exec();

}



QSqlQueryModel* Reservation ::afficher()
{




    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("select * from Reservation");
    model->setHeaderData(0,Qt:: Horizontal, QObject :: tr("depart"));
    model->setHeaderData(1,Qt:: Horizontal, QObject :: tr("arrive"));
    model->setHeaderData(2,Qt:: Horizontal, QObject :: tr("transport"));
    model->setHeaderData(3,Qt:: Horizontal, QObject :: tr("classe"));
    model->setHeaderData(4,Qt:: Horizontal, QObject :: tr("h_depart"));
    model->setHeaderData(5,Qt:: Horizontal, QObject :: tr("h_arrive"));

    return model;




}


bool Reservation::supprimer(QString num)
{

    QSqlQuery query;
    //QString h_depart =QString :: number(this->h_depart);

    query.prepare("Delete from Reservation where numero= :numero");
    query.bindValue(":numero",num);

    return query.exec();


}



bool Reservation::modifier(Reservation r,int num)
{
    QSqlQuery query;
    //QString h_depart =QString :: number(this->h_depart);

    query.prepare("update Reservation set depart= :depart,arrive= :arrive,classe= :classe,transport= :transport,h_depart=:h_depart,h_arrive=:h_arrive where numero = :numero");
    query.bindValue(":numero",num);
    query.bindValue(":depart", depart);
    query.bindValue(":arrive", arrive);
    query.bindValue(":transport", transport);
    query.bindValue(":classe", classe);
    query.bindValue(":h_depart", h_depart);
    query.bindValue(":h_arrive", h_arrive);

    return query.exec();
}



QSqlQueryModel* Reservation::rechercheId(QString a)
{


    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Reservation WHERE numero LIKE '%"+a+"%' or transport LIKE '%"+a+"%'" );

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("depart"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("arrive"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("transport"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("classe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("h_depart"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("h_arrive"));

    return model;

}


QSqlQueryModel* Reservation::Tri()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * from Reservation order by numero");

    return model;
}


bool Reservation::rechercher(QString num)
{
    QSqlQuery query;


    query.prepare("select * from Reservation where numero= :numero");
    query.bindValue(":numero",num);
    return query.exec();
}


