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
    vector <Pedido> pedidos_camion = camion.get_Pedidos();
    QCheckBox *confirmacion = new QCheckBox("¿Si?");
    ui->detalles_pedidos->insertRow(ui->detalles_pedidos->rowCount());
    for(int i=0; i<pedidos_camion.size(); i++){
        QString nombre = QString::fromStdString(pedidos_camion[i].get_Nombre_sol())+ ";";
        QString Detalle_cilindros = "";
        for(int j=0; j<pedidos_camion[i].get_Cilindros().size(); j++){
            int cnt = pedidos_camion[i].get_Cilindros()[j].get_Cantidad();
            int cap = pedidos_camion[i].get_Cilindros()[j].get_Capacidad();
            QString tipo = QString::fromStdString(pedidos_camion[i].get_Cilindros()[j].get_Tipo());
            Detalle_cilindros+= cnt + " cilindros " + tipo + " " + cap + " kg;";
        }
        QString final = "Nombre: " + nombre + Detalle_cilindros;
        ui->detalles_pedidos->setCellWidget(0,0,confirmacion);
        ui->detalles_pedidos->setItem(0,1,new QTableWidgetItem(final));
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



    //QMessageBox::information(this,"Ok","valor primera entrega"+ QString::number(pedido.get_ValorEntrega()));
}
