#ifndef SHOWCUSTOMER_H
#define SHOWCUSTOMER_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class ShowCustomer;
}

class ShowCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit ShowCustomer(QWidget *parent = nullptr);
    ~ShowCustomer();

private slots:
    void on_btnfindCustomer_clicked();

private:
    Ui::ShowCustomer *ui;
    QSqlQueryModel *model;
};

#endif // SHOWCUSTOMER_H
