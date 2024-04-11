#include "capsmanagerment.h"
#include "ui_capsmanagerment.h"

CapsManagerment::CapsManagerment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CapsManagerment)
{
    ui->setupUi(this);
}

CapsManagerment::~CapsManagerment()
{
    qDebug() << "in ~CapsManagerment()";
    delete ui;
}

void CapsManagerment::on_btnSave_clicked()
{
    QString Type = ui->txtType->text();
    QString Km = ui->txtKm->text();
    QString Name = ui->txtName->text();

    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);
    query.prepare("insert into Cabs (Type, Km, Name)" " values('" + Type + "','" + Km + "','"+ Name +"')");
    query.exec();
    query.finish();query.clear();
    qDebug() << "Last error : "<< query.lastError().text();
}

void CapsManagerment::on_btnReset_clicked()
{
    ui->txtType->clear();
    ui->txtKm->clear();
    ui->txtName->clear();
}

