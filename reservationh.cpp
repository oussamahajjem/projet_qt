#include "reservationh.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QMessageBox>
#define STR_EQUAL 1
using namespace std;
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


}
QSqlQueryModel* reservationh::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* from RESERVATIONH");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomPrenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("hebergement"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("checkin"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("checkout"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));
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
    query.prepare("UPDATE RESERVATIONH SET Id=:Id,nomPrenom=:nomPrenom,hebergement=:hebergement,checkin=:checkin,checkout=:checkout,prix=:prix WHERE Id=:Id");
    query.bindValue(":Id",Id_string);
    query.bindValue(":nomPrenom",nomPrenom);
    query.bindValue(":hebergement",hebergement);
    query.bindValue(":checkin",checkin);
    query.bindValue(":checkout",checkout);
    query.bindValue(":prix",prix_string);

    return query.exec();
}
QSqlQueryModel* reservationh::triId()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from RESERVATIONH order by Id");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomPrenom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("hebergement"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("checkin"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("checkout"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));

   return model;

}
QSqlQueryModel* reservationh::triN()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from RESERVATIONH order by nomPrenom");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomPrenom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("hebergement"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("checkin"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("checkout"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));

   return model;
}
QSqlQueryModel* reservationh::triP()
{
    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from RESERVATIONH order by prix");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomPrenom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("hebergement"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("checkin"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("checkout"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));

   return model;
}
QSqlQueryModel* reservationh::rechercheId(int Id)
{
    QString res=QString ::number(Id);

    QSqlQueryModel *model=new QSqlQueryModel();
            model->setQuery("select * from RESERVATIONH where ID ='"+res+"'");

            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomPrenom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("hebergement"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("checkin"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("checkout"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));

   return model;

}
QSqlQueryModel* reservationh::rechercheN(QString a)
{


    QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM RESERVATIONH WHERE ( nomPrenom LIKE '%"+a+"%'  ) ");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("Id"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("nomPrenom"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("hebergement"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("checkin"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("checkout"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix"));

   return model;

}

void creation_pdf()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
       if (QFileInfo(fileName).suffix().isEmpty())
           { fileName.append(".pdf"); }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;
       QSqlQuery q;
       q.prepare("SELECT * FROM RESERVATIONH ");
       q.exec();
       QString pdf="<br> <h1  style='color:blue'>LISTE DES RESERVATIONH  <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>NOM </th> <th>PRENOM  </th> <th>AGE  </th><th>TEL  </th><th>ADRESS   </th> </tr>" ;
   //br traja ll star oel tr tzidlek colonne th tzidlek ligne h1 asghrr size o akbr size h6 //

       while ( q.next())
           {

           pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" <td>" +q.value(3).toString() +" <td>" +q.value(4).toString() +" <td>" +q.value(5).toString() +" "" " "</td> </td>" ;
       }
       doc.setHtml(pdf);
       doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
       doc.print(&printer);


}
QSqlQueryModel*  reservationh::alerte()
{

    QSqlQueryModel *model=new QSqlQueryModel();
             model->setQuery("SELECT Id,nomPrenom,hebergement,checkin,checkout, 0.8*prix FROM RESERVATIONH WHERE (PRIX>=1500) ");
             model->setHeaderData(5,Qt::Horizontal,QObject::tr("prix reduit"));






   return model;

   }


