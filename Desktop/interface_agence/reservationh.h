        #ifndef RESERVATIONH_H
#define RESERVATIONH_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QSqlQuery>
class reservationh
{
private :
    // atributs
    int Id ,prix;
    QString nomPrenom,hebergement;
    QDate checkin,checkout;

public:
    reservationh();
// constructeur parametré
    reservationh(int,QString,QString,QDate,QDate,int);
    int getId();
    QString getnomPrenom();
    QString gethebergement();
    QDate getcheckin();
    QDate  getcheckout();
    int getprix();

    void setId(int);
    void setnomPrenom(QString);
    void setcheckout(QDate);
    void setcheckin(QDate);
    void sethebergement(QString);
    void setprix(int);
    // fonction ajout
    bool ajouter();
    // fonction afficher
    QSqlQueryModel * afficher();
    bool supprimer (int);
    bool modifier(int );

};

#endif // RESERVATIONH_H
