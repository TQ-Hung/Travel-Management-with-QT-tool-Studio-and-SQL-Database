#ifndef CAPSMANAGERMENT_H
#define CAPSMANAGERMENT_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class CapsManagerment;
}

class CapsManagerment : public QDialog
{
    Q_OBJECT

public:
    explicit CapsManagerment(QWidget *parent = nullptr);
    ~CapsManagerment();

private slots:
    void on_btnSave_clicked();

    void on_btnReset_clicked();

private:
    Ui::CapsManagerment *ui;
};

#endif // CAPSMANAGERMENT_H
