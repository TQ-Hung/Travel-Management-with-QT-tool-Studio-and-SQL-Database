#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrCustomerManagerment = new CustomerManagerment();
    ptrCapsManagerment = new CapsManagerment();
    ptrBookingsmanagerment = new Bookingsmanagerment();
    ptrBill = new Bill();

    database = QSqlDatabase::addDatabase("QSQLITE", "DB1");
    database.setDatabaseName("C:/Users/WELCOME/Documents/TourManagerment.db");

    if(!database.open()){
        qDebug() << "Error: Unable to open database..";
    }
    else{
        qDebug() << "Database open successfully..";
    }
}

MainWindow::~MainWindow()
{
    delete ptrCapsManagerment;
    delete ptrCustomerManagerment;
    delete ptrBookingsmanagerment;
    delete ptrBill;
    delete ui;
    database.close();
    QSqlDatabase::removeDatabase(database.connectionName());
    qDebug() << " ~MainWindow()";
}


void MainWindow::on_pushButton_clicked()
{
    ptrCustomerManagerment -> show();
}



void MainWindow::on_btnCapsManagerment_clicked()
{
    ptrCapsManagerment -> show();
}


void MainWindow::on_pushButton_3_clicked()
{
    ptrBookingsmanagerment -> show();
}


void MainWindow::on_pushButton_4_clicked()
{
    ptrBill -> show();
}

