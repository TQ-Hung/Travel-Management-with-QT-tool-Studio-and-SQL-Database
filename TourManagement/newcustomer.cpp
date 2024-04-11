#include "newcustomer.h"
#include "ui_newcustomer.h"

NewCustomer::NewCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCustomer)
{
    ui->setupUi(this);
}

NewCustomer::~NewCustomer()
{
    qDebug() << "~ NewCustomer()";
    delete ui;
}

void NewCustomer::on_pushButton_2_clicked()
{
    QString customerID = ui->txtID->text();
    QString customerName = ui->txtName->text();
    QString customerAge = ui->txtAge->text();
    QString customerNumber = ui->txtNumber->text();
    QString customerAddress = ui->txtAddress->text();
    QString customerGender = ui->txtGender->text();

    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);
    query.prepare("insert into Customer (ID, Name, Age, Number, Address, Gender)" " values('" + customerID + "','" + customerName + "','" + customerAge + "', '" + customerNumber + "', '" + customerAddress + "','"+customerGender+"')");
    query.exec();
    query.finish();query.clear();
    qDebug() << "Last error : "<< query.lastError().text();
}


void NewCustomer::on_pushButton_clicked()
{
    ui->txtID->clear();
    ui->txtName->clear();
    ui->txtAge->clear();
    ui->txtNumber->clear();
    ui->txtAddress->clear();
    ui->txtGender->clear();
}

