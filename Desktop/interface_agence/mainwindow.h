#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reservationh.h"

#include <QMainWindow>

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
private:
    Ui::MainWindow *ui;

    reservationh R;
};
#endif // MAINWINDOW_H
