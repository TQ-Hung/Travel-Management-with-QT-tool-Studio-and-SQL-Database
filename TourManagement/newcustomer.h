#ifndef NEWCUSTOMER_H
#define NEWCUSTOMER_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class NewCustomer;
}

class NewCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit NewCustomer(QWidget *parent = nullptr);
    ~NewCustomer();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::NewCustomer *ui;
};

#endif // NEWCUSTOMER_H
