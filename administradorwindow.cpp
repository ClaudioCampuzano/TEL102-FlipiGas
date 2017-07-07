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
    adminCamionesWindow = new AdminCamionesWindow(this);
    adminCamionesWindow->show();
}

void AdministradorWindow::on_bt_ventaybodega_clicked()
{
    adminVentasCruzadasWindow = new AdminVentasCruzadasWindow(this);
    adminVentasCruzadasWindow->show();
}

void AdministradorWindow::on_bt_inventario_clicked()
{
    adminInventarioWindow = new AdminInventarioWindow(this);
    adminInventarioWindow->show();
}
