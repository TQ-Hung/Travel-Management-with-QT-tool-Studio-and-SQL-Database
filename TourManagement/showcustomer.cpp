#include "showcustomer.h"
#include "ui_showcustomer.h"

ShowCustomer::ShowCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowCustomer)
{
    ui->setupUi(this);
    model = NULL;
}

ShowCustomer::~ShowCustomer()
{
    qDebug() << "~ FindCustomer()";
    delete ui;
    delete model;
}

void ShowCustomer::on_btnfindCustomer_clicked()
{
    QString findName = ui->txtFindname->text();
    qDebug() << "Name : "<< findName;
    QSqlDatabase database = QSqlDatabase::database("DB1");

    if(model == NULL)
        model = new QSqlQueryModel();

    model->setQuery("select * from Customer where Name like '%" + findName + "%'", database);
    ui->tableView->setModel(model);
}

