#include "administradorwindow.h"
#include "ui_administradorwindow.h"

AdministradorWindow::AdministradorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdministradorWindow)
{
    ui->setupUi(this);
}

AdministradorWindow::~AdministradorWindow()
{
    delete ui;
}

void AdministradorWindow::on_bt_solicitudes_clicked()
{
}

void AdministradorWindow::on_bt_camiones_clicked()
{

}

void AdministradorWindow::on_bt_ventaybodega_clicked()
{

}
