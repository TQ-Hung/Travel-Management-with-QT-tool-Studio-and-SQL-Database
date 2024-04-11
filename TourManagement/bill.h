#ifndef BILL_H
#define BILL_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class Bill;
}

class Bill : public QDialog
{
    Q_OBJECT

public:
    explicit Bill(QWidget *parent = nullptr);
    ~Bill();

private slots:
    void on_btnLoadname_clicked();

    void on_cmbName_currentIndexChanged(int index);

    void on_btnCalculate_clicked();

    void on_pushButton_clicked();

private:
    Ui::Bill *ui;
};

#endif // BILL_H
