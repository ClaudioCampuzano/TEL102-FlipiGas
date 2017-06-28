#include "camionerowindow.h"
#include "ui_camionerowindow.h"
#include "camion.h"
#include <QMessageBox>
#include "loginwindow.h"
CamioneroWindow::CamioneroWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CamioneroWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,300);
    Camion camion = LoginWindow::camiones[LoginWindow::indice_login];
    QString cerro = QString::fromStdString(camion.get_Cerro());
    QString capacidad = QString::number(camion.get_Capacidad());
    ui->Nombrecerrocamion->setText(cerro);
    ui->capacidadcamion->setText(capacidad);

    //camion.get_Capacidad();

}

CamioneroWindow::~CamioneroWindow()
{
    delete ui;
}

void CamioneroWindow::on_bt_recargar_clicked()
{
    Pedido pedido = VendedorWindow::pedidos.front();
    QMessageBox::information(this,"Ok","valor primera entrega"+ QString::number(pedido.get_ValorEntrega()));
}
