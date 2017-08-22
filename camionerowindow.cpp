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
    QString cilin_disponibles = QString::number(camion.get_CilindrosRestantes());
    ui->Nombrecerrocamion_2->setText(cerro);
    ui->capacidadcamion_2->setText(capacidad +" Cilindros");
    ui->cilindros_restantes_2->setText(cilin_disponibles+ " Cilindros");
    if (camion.get_Estado() == true)
        ui->Estado_2->setText("En reparto");
    else
        ui->Estado_2->setText("Disponible para pedido");
    vector <Pedido> pedidos_camion = camion.get_Pedidos();
    for(int i=0; i<pedidos_camion.size(); i++){
        ui->detalles_pedidos->insertRow(ui->detalles_pedidos->rowCount());
        QString nombre = QString::fromStdString(pedidos_camion[i].get_Nombre_sol())+ ", ";
        QString medio_pago = QString::fromStdString(pedidos_camion[i].get_medio_pago())+ ", ";
        QString Detalle_cilindros = "";
        for(int j=0; j<pedidos_camion[i].get_Cilindros().size(); j++){
            int cnt = pedidos_camion[i].get_Cilindros()[j].get_Cantidad();
            int cap = pedidos_camion[i].get_Cilindros()[j].get_Capacidad();
            QString tipo = QString::fromStdString(pedidos_camion[i].get_Cilindros()[j].get_Tipo());
            Detalle_cilindros+= QString::number(cnt) + " Cilindro(s) " + tipo + "(s) de " + QString::number(cap) + " kg; ";
        }
        QString final = "Nombre: " + nombre + "Pago: " + medio_pago + "Pedido: " + Detalle_cilindros;
        ui->detalles_pedidos->setItem(i,1,new QTableWidgetItem(final));
        QCheckBox *confirmacion = new QCheckBox("¿Si?");
        ui->detalles_pedidos->setCellWidget(i,0,(QWidget*)confirmacion);

    }
}

CamioneroWindow::~CamioneroWindow()
{
    delete ui;
}

void CamioneroWindow::on_bt_recargar_clicked()
{

    vector <Pedido> pedidos = VendedorWindow::pedidos;
    Camion camion = LoginWindow::camiones[LoginWindow::indice_login];
    for(int i=0; i<ui->detalles_pedidos->rowCount();i++){
        QTableWidgetItem *estado = ui->detalles_pedidos->item(i,0);
        if (estado->checkState())
            QMessageBox::information(this,"Ok","bien");


    }



    //QMessageBox::information(this,"Ok","valor primera entrega"+ QString::number(pedido.get_ValorEntrega()));
}
