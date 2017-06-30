#include "camionerowindow.h"
#include "ui_camionerowindow.h"
#include "camion.h"
#include <QMessageBox>
#include "loginwindow.h"
#include <QComboBox>

CamioneroWindow::CamioneroWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CamioneroWindow)
{
    ui->setupUi(this);
    ui->detalles_pedidos->setColumnWidth(0,80);
    ui->detalles_pedidos->setColumnWidth(1,500);

    Camion camion = LoginWindow::camiones[LoginWindow::indice_login];
    QString cerro = QString::fromStdString(camion.get_Cerro());
    QString capacidad = QString::number(camion.get_Capacidad());
    ui->Nombrecerrocamion->setText(cerro);
    ui->capacidadcamion->setText(capacidad +" cilindros");
    vector <Pedido> pedido_camion = camion.get_Pedidos();

    QCheckBox *confirmacion = new QCheckBox("¿Si?");
    ui->detalles_pedidos->insertRow(ui->detalles_pedidos->rowCount());

    //for(int i=0; i<pedido_camion.size(); i++){
        ui->detalles_pedidos->setCellWidget(0,0,confirmacion);
        ui->detalles_pedidos->setItem(0,1,new QTableWidgetItem("Holaaaaaa"));


    //}

}

CamioneroWindow::~CamioneroWindow()
{
    delete ui;
}

void CamioneroWindow::on_bt_recargar_clicked()
{
    Pedido pedido = VendedorWindow::pedidos.front();
    //QMessageBox::information(this,"Ok","valor primera entrega"+ QString::number(pedido.get_ValorEntrega()));
}
