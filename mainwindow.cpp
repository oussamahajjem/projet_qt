#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservationh.h"
#include <QApplication>
#include <QMessageBox>
#include <QIntValidator>

#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include<QTextStream>
#include<QDataStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
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

void MainWindow::on_pushButton_triN_clicked()
{
     ui->tab_triR->setModel(ptmp.triN());
}
void MainWindow::on_pushButton_triId_clicked()
{
     ui->tab_triR->setModel(ptmp.triId());
}
void MainWindow::on_pushButton_triP_clicked()
{
     ui->tab_triR->setModel(ptmp.triP());
}

void MainWindow::on_pushButton_rechercheId_clicked()
{
    int Id=ui->lineEdit_rechercheId->text().toInt();
                if (Id==0) {
                    QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter a Number."));
                    return;
                } else {
                ui->tab_triR->setModel(ptmp.rechercheId(int(Id)));
                }
}


void MainWindow::on_pushButton_exportpdf_clicked()
{
    QString strStream;
            strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
                if (QFileInfo(strStream).suffix().isEmpty())
                    { strStream.append(".pdf"); }

                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(strStream);

                      QTextStream out(&strStream);

                      const int rowCount = ui->tab_rh->model()->rowCount();
                      const int columnCount = ui->tab_rh->model()->columnCount();
                      QString TT = QDateTime::currentDateTime().toString();
                      out <<"<html>\n"
                            "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          << "<title>ERP - COMmANDE LIST<title>\n "
                          << "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"
                             "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                            +"<img src=C:\\Users\\asus\\Desktop\\pdf\\logo_projet />" //path
                          "<h1 style=\"text-align: center;\"><strong> ****LISTE DES CITOYENS **** </strong></h1>"

                          "<table style=\"text-align: center; font-size: 10px;\" border=1>\n "
                            "</br> </br>";
                      // headers
                      out << "<thead><tr bgcolor=#d6e5ff>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->tab_rh->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->tab_rh->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr>";
                          for (int column = 0; column < columnCount; column++)
                        {
                              if (!ui->tab_rh->isColumnHidden(column)) {
                                  QString data =ui->tab_rh->model()->data(ui->tab_rh->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;")); //pas compriis
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table>\n"
                          "</body>\n"
                          "</html>\n";

                      QTextDocument document;
                      document.setHtml(strStream);
                      document.print(&printer);
}
void MainWindow::on_pushButton_rechercheN_clicked()
{
    QString a=ui->lineEdit_rechercheN->text() ;
      if (a == NULL) {
          QMessageBox::information(this, tr("Empty Field"),
              tr("Please enter a Name."));
          return;
      }
      else
      {
      ui->tab_triR->setModel(ptmp.rechercheN(QString(a)));}
}


/////stat

QVector<double> MainWindow::statistiques()
{
    QSqlQuery q;
    QVector<double> stat(6);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    stat[5]=0;
    q.prepare("SELECT prix FROM reservationh WHERE prix<=40");
    q.exec();
    while (q.next())
    {
        stat[0]++;

    }
    q.prepare("SELECT prix FROM reservationh WHERE 40<prix and prix<=100");
    q.exec();
    while (q.next())
    {
        stat[1]++;

    }
    q.prepare("SELECT prix FROM reservationh WHERE 100<prix and prix<=500");
    q.exec();
    while (q.next())
    {
        stat[2]++;

    }
    q.prepare("SELECT prix FROM reservationh WHERE 500<prix and prix<=1500");
    q.exec();
    while (q.next())
    {
        stat[3]++;

    }
    q.prepare("SELECT prix FROM reservationh WHERE 1500<prix and prix<=3000 ");
    q.exec();
    while (q.next())
    {
        stat[4]++;

    }
    q.prepare("SELECT prix FROM reservationh WHERE prix>3000 ");
    q.exec();
    while (q.next())
    {
        stat[5]++;

    }
    return stat;
}

void MainWindow::makePlot()
{
    // prepare data:
    QVector<double> x3(6), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customplot->xAxis, ui->customplot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::statistiques());////fonction statistiques
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customplot->replot();

    // move bars above graphs and grid below bars:
    ui->customplot->addLayer("abovemain", ui->customplot->layer("main"), QCustomPlot::limAbove);
    ui->customplot->addLayer("belowmain", ui->customplot->layer("main"), QCustomPlot::limBelow);
    ui->customplot->xAxis->grid()->setLayer("belowmain");
    ui->customplot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;//////
    QVector<QString> labels;
    labels<<"0-40"<<"40-100"<<"100-500"<<"500-1500"<<"1500-3000"<<"3000+";////////
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customplot->xAxis->setTicker(textTicker);
    ui->customplot->xAxis->setSubTicks(false);
    ui->customplot->xAxis->setTickLength(0,4);
    ui->customplot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->xAxis->setTickLabelColor(Qt::white);
    ui->customplot->yAxis->setTickLabelColor(Qt::white);
    ui->customplot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridVisible(true);
    ui->customplot->yAxis->grid()->setSubGridVisible(true);
    ui->customplot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customplot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(00, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customplot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));//
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customplot->axisRect()->setBackground(axisRectGradient);

    ui->customplot->rescaleAxes();
    ui->customplot->xAxis->setRange(0, 7);
    ui->customplot->yAxis->setRange(0, 10);


}


///////
void MainWindow::on_pushButton_alerte_clicked()
{
   QSqlQuery q;
   int t=0;
   q.prepare("SELECT prix FROM RESERVATIONH WHERE PRIX>=1500");
   q.exec();
   while(q.next())
   {
       t++;
   }
   if(t>0)
   {
           if (ptmp.alerte())

           {

               ui->tab_triR->setModel(ptmp.alerte());
               QMessageBox :: information (nullptr, QObject ::tr("OK"),
                            QObject ::tr("Prix depasse le seuil, besoin de reduction\n"
                                         "click cancel to exit"),
                       QMessageBox:: Cancel);
           }
           else
           {
               QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                    QObject::tr("erreur.\n"
                                                "click cancel to exit."),QMessageBox::Cancel);
           }
   }
   else
   {
       QMessageBox::information(nullptr,QObject::tr("not ok"),
                            QObject::tr("Prix ne depasse pas le seuil, pas besoin de reduction.\n"
                                        "click cancel to exit."),QMessageBox::Cancel);
   }



}
void MainWindow::on_pushButton_statistiques_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
    ui->customplot->clearPlottables();
    MainWindow::makePlot();
    MainWindow::makePlot();
}
void MainWindow::on_pushButton_choisir_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(
        this, tr("Evenement d'entré"), tr("Veuillez entrer le nom de l'événement"), QLineEdit::Normal, 0, &ok);
    if (!ok || text.isEmpty()) return;

    auto date = ui->calendarWidget->selectedDate();

    QString event_title = text;
    QString event_start = "";
    QString event_end = "";
    QString event_local = "";
    QString _method = "POST";
    date = date.addDays(-1);
    event_start = event_end = date.toString("yyyy-MM-ddT16%3A00%3A00Z");

    QByteArray byte;
    byte.append("calendar_event%5Btitle%5D=" + event_title.toUtf8());
    byte.append("&calendar_event%5Bstart_at%5D=" + event_start.toUtf8());
    byte.append("&calendar_event%5Bend_at%5D=" + event_end.toUtf8());
    byte.append("&calendar_event%5Blocation_name%5D=" + event_local.toUtf8());
 //   byte.append("&calendar_event%5Bcontext_code%5D=user_" + user);
    byte.append("&_method=POST");
   // byte.append("&authenticity_token=" + token);
    QString url = "http://canvas.tongji.edu.cn/api/v1/calendar_events";
    //auto re = post(url, byte, "application/x-www-form-urlencoded");

   /* auto document = QJsonDocument::fromJson(re);
    auto object = document.object();
    auto value = object.value("id");
    auto plid = value.toInt();*/

    QJsonObject temp;
    temp.insert("context_name", QString(name));
    temp.insert("context_type", "User");
    QString d = date.toString("yyyy-MM-dd");
    d = d + "T16:00:00Z";
    temp.insert("plannable_date", d);
    QJsonObject pl;
    pl.insert("title", text);
    temp.insert("plannable", QJsonValue(pl));
   // temp.insert("plannable_id", plid);
   /* QJsonValueRef ref = this->json.find(this->select_date).value();
    QJsonArray arr = ref.toArray();
    arr.append(temp);
    ref = arr;*/

    auto format =
        ui->calendarWidget->dateTextFormat(ui->calendarWidget->selectedDate());
    format.setBackground(QColor("#00FFFF"));
    ui->calendarWidget->setDateTextFormat(ui->calendarWidget->selectedDate(),
                                          format);

  //  on_calendarWidget_clicked(ui->calendarWidget->selectedDate());
}






void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    this->select_date = date.toString("yyyy-MM-dd");
    this->selected_day_json = this->json[date.toString("yyyy-MM-dd")].toArray();
    if (selected_day_json.size()) {
       // ui->comboBox->clear();
        for (int i = 0; i < selected_day_json.size(); i++) {
            auto context_name =
                selected_day_json[i].toObject()["context_name"].toString();
        }
    } else {
        ui->lineEdit_reserve->setText("reservation");
        auto format = ui->calendarWidget->dateTextFormat(
            ui->calendarWidget->selectedDate());
        format.setBackground(QColor("#FFFFFF"));
        ui->calendarWidget->setDateTextFormat(
            ui->calendarWidget->selectedDate(), format);
    }
}

