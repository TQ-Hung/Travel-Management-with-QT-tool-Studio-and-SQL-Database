#ifndef BOOKINGSMANAGERMENT_H
#define BOOKINGSMANAGERMENT_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class Bookingsmanagerment;
}

class Bookingsmanagerment : public QDialog
{
    Q_OBJECT

public:
    explicit Bookingsmanagerment(QWidget *parent = nullptr);
    ~Bookingsmanagerment();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Bookingsmanagerment *ui;
};

#endif // BOOKINGSMANAGERMENT_H
