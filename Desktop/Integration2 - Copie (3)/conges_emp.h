#ifndef CONGES_EMP_H
#define CONGES_EMP_H

#include <QDialog>

namespace Ui {
class conges_emp;
}

class conges_emp : public QDialog
{
    Q_OBJECT

public:
    explicit conges_emp(QWidget *parent = nullptr);
    ~conges_emp();

private:
    Ui::conges_emp *ui;
};

#endif // CONGES_EMP_H
