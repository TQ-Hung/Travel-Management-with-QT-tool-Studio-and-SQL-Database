#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customermanagerment.h"
#include "capsmanagerment.h"
#include "bookingsmanagerment.h"
#include "bill.h"

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
    void on_pushButton_clicked();

    void on_btnCapsManagerment_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    CustomerManagerment *ptrCustomerManagerment;
    CapsManagerment *ptrCapsManagerment;
    Bookingsmanagerment *ptrBookingsmanagerment;
    Bill *ptrBill;

    QSqlDatabase database;
};
#endif // MAINWINDOW_H
