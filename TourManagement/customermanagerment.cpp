#include "customermanagerment.h"
#include "ui_customermanagerment.h"

CustomerManagerment::CustomerManagerment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerManagerment)
{
    ui->setupUi(this);
    ptrNewCustomer = new NewCustomer();
    ptrShowCustomer = new ShowCustomer();
}

CustomerManagerment::~CustomerManagerment()
{
    delete ptrShowCustomer;
    delete ptrNewCustomer;
    delete ui;
}

void CustomerManagerment::on_pushButton_clicked()
{
    ptrNewCustomer->show();
}


void CustomerManagerment::on_pushButton_2_clicked()
{
    ptrShowCustomer->show();
}

