#include "bill.h"
#include "ui_bill.h"

Bill::Bill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bill)
{
    ui->setupUi(this);
}

Bill::~Bill()
{
    qDebug() << "in ~Bill()";
    delete ui;
}



void Bill::on_btnLoadname_clicked()
{
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

    query.prepare("select Name from Hotel");
    query.exec();
    while(query.next())
    {
        ui->cmbName->addItem(query.value(0).toString());
        qDebug() << "Filling Combobox " << query.value(0).toString();
    }

    qDebug() << "Last error : "<< query.lastQuery();
    qDebug() << "Last error : "<< query.lastError().text();
}


void Bill::on_cmbName_currentIndexChanged(int index)
{
    QString Name = ui->cmbName->currentText();
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

    query.prepare("select HotelName from Hotel where Name ='" + Name + "'");
    query.exec(); query.next();
    ui->txtShowhotel->setText(query.value(0).toString());
    query.finish();query.clear();
    qDebug() << "Last error : "<< query.lastQuery();
    qDebug() << "Last error : "<< query.lastError().text();
}


void Bill::on_btnCalculate_clicked()
{
    QString Name = ui->cmbName->currentText();
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

    query.prepare("select TypePack from Hotel where Name ='" + Name + "'");
    query.exec(); query.next();
    int hotelpack = query.value(0).toInt();

    query.prepare("select Type,Km from Cabs where Name ='" + Name + "'");
    query.exec(); query.next();
    int typecabs = query.value(0).toInt();
    int km = query.value(1).toInt();
    int hotelprice;
    int cabsprice;
    if(typecabs == 1)
    {
        cabsprice = km * 2;
    }
    else
    {
        cabsprice = km*3;
    }

    if(hotelpack == 1)
    {
        hotelprice = 80;
    }
    if(hotelpack == 2)
    {
        hotelprice = 100;
    }
    if(hotelpack == 3)
    {
        hotelprice = 120;
    }
     int totalPrice = hotelprice + cabsprice;
    QString resultText = "Name: " + Name + "\n"
                         + "Hotel Price: " + QString::number(hotelprice) + " $\n"
                         + "Cabs Price: " + QString::number(cabsprice) + " $\n"
                         + "Total Price: " + QString::number(totalPrice) + " $\n";

    ui->txtResult->insertPlainText(resultText);
}



void Bill::on_pushButton_clicked()
{
    ui->txtResult->clear();
}

