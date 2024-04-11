#ifndef CUSTOMERMANAGERMENT_H
#define CUSTOMERMANAGERMENT_H

#include <QDialog>
#include "newcustomer.h"
#include "showcustomer.h"

namespace Ui {
class CustomerManagerment;
}

class CustomerManagerment : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerManagerment(QWidget *parent = nullptr);
    ~CustomerManagerment();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CustomerManagerment *ui;
    NewCustomer *ptrNewCustomer;
    ShowCustomer *ptrShowCustomer;
};

#endif // CUSTOMERMANAGERMENT_H
