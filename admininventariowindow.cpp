#include "admininventariowindow.h"
#include "ui_admininventariowindow.h"
#include "loginwindow.h"
#include <QMessageBox>

AdminInventarioWindow::AdminInventarioWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminInventarioWindow)
{
    ui->setupUi(this);

    ui->detalle->setItem(0,0,new QTableWidgetItem(QString::number(LoginWindow::CincokgCatalico)));
    ui->detalle->setItem(1,0,new QTableWidgetItem(QString::number(LoginWindow::OncekgCatalico)));
    ui->detalle->setItem(2,0,new QTableWidgetItem(QString::number(LoginWindow::QuincekgCatalico)));
    ui->detalle->setItem(3,0,new QTableWidgetItem(QString::number(LoginWindow::CuarentaYCincokgCatalico)));
    ui->detalle->setItem(0,1,new QTableWidgetItem(QString::number(LoginWindow::CincokgNoCatalico)));
    ui->detalle->setItem(1,1,new QTableWidgetItem(QString::number(LoginWindow::OncekgNoCatalico)));
    ui->detalle->setItem(2,1,new QTableWidgetItem(QString::number(LoginWindow::QuincekgNoCatalico)));
    ui->detalle->setItem(3,1,new QTableWidgetItem(QString::number(LoginWindow::CuarentaYCincokgNoCatalico)));

}

AdminInventarioWindow::~AdminInventarioWindow()
{
    delete ui;
}
//Para el costo_repo se utilizaron los valores "de fabrica" de los cilindros
void AdminInventarioWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton respuesta;
    respuesta = QMessageBox::question(this, "Confirmacion", "¿Esta seguro de reponer cilindros?", QMessageBox::Yes|QMessageBox::No);
    if (respuesta == QMessageBox::Yes){
        int costo_repo = 5000 * (300 - LoginWindow::CincokgCatalico) + 6000* (250 -LoginWindow::OncekgCatalico) +
                10000* (200-LoginWindow::QuincekgCatalico) + 30000* (150 - LoginWindow::CuarentaYCincokgCatalico)+
                4000* (150-LoginWindow::CincokgNoCatalico)+5000*(140 - LoginWindow::OncekgNoCatalico) +
                8000*(120 - LoginWindow::QuincekgNoCatalico)+ 25000*(100 - LoginWindow::CuarentaYCincokgNoCatalico);
        LoginWindow::total_ventas -= costo_repo;
        LoginWindow::CincokgCatalico = 300;
        LoginWindow::OncekgCatalico= 250;
        LoginWindow::QuincekgCatalico= 200;
        LoginWindow::CuarentaYCincokgCatalico = 150;
        LoginWindow::CincokgNoCatalico= 150;
        LoginWindow::OncekgNoCatalico = 140;
        LoginWindow::QuincekgNoCatalico = 120;
        LoginWindow::CuarentaYCincokgNoCatalico= 100;
        ui->detalle->setItem(0,0,new QTableWidgetItem(QString::number(LoginWindow::CincokgCatalico)));
        ui->detalle->setItem(1,0,new QTableWidgetItem(QString::number(LoginWindow::OncekgCatalico)));
        ui->detalle->setItem(2,0,new QTableWidgetItem(QString::number(LoginWindow::QuincekgCatalico)));
        ui->detalle->setItem(3,0,new QTableWidgetItem(QString::number(LoginWindow::CuarentaYCincokgCatalico)));
        ui->detalle->setItem(0,1,new QTableWidgetItem(QString::number(LoginWindow::CincokgNoCatalico)));
        ui->detalle->setItem(1,1,new QTableWidgetItem(QString::number(LoginWindow::OncekgNoCatalico)));
        ui->detalle->setItem(2,1,new QTableWidgetItem(QString::number(LoginWindow::QuincekgNoCatalico)));
        ui->detalle->setItem(3,1,new QTableWidgetItem(QString::number(LoginWindow::CuarentaYCincokgNoCatalico)));
        LoginWindow::total_ventas -= costo_repo;

    }
}
