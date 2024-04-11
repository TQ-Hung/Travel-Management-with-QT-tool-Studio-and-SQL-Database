#include "bookingsmanagerment.h"
#include "ui_bookingsmanagerment.h"

Bookingsmanagerment::Bookingsmanagerment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bookingsmanagerment)
{
    ui->setupUi(this);
}

Bookingsmanagerment::~Bookingsmanagerment()
{
    qDebug() << "in ~BookingsManagerment()";
    delete ui;
}

void Bookingsmanagerment::on_pushButton_clicked()
{
    QString Name = ui->txtName->text();
    QString HotelName = ui->txtHotelname->text();
    QString TypePack = ui->txtTypepack->text();

    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);
    query.prepare("insert into Hotel (Name, HotelName, TypePack)" " values('" + Name + "','" + HotelName + "','"+ TypePack +"')");
    query.exec();
    query.finish();query.clear();
    qDebug() << "Last error : "<< query.lastError().text();
}


void Bookingsmanagerment::on_pushButton_2_clicked()
{
    ui->txtName->clear();
    ui->txtHotelname->clear();
    ui->txtTypepack->clear();
}

