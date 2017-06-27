#include "vendedorwindow.h"
#include "ui_vendedorwindow.h"
#include <QMessageBox>
#include <pedido.h>
#include <QTableWidgetItem>

deque <Pedido> pedidos;

VendedorWindow::VendedorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VendedorWindow)
{
    ui->setupUi(this);
    fila = -1;
}

VendedorWindow::~VendedorWindow()
{
    delete ui;
}


void VendedorWindow::on_bt_agregarpedido_clicked()
{
    if (ui->spinBox_cntCilindros->value() == 0)
        QMessageBox::information(this,"Mal","Ingrese cantidad mayor a 0 -_-");
    else{
        ui->PedidosTemporales->insertRow(ui->PedidosTemporales->rowCount());
        ui->PedidosTemporales->setItem(ui->PedidosTemporales->rowCount()-1,0,
                                   new QTableWidgetItem(QString::number(ui->spinBox_cntCilindros->value())));
        ui->PedidosTemporales->setItem(ui->PedidosTemporales->rowCount()-1,1,
                                   new QTableWidgetItem(ui->comboBox_kg->currentText()));
        ui->PedidosTemporales->setItem(ui->PedidosTemporales->rowCount()-1,2,
                                   new QTableWidgetItem(ui->comboBox_tipo->currentText()));
    }
}

void VendedorWindow::on_bt_ingresarpedido_clicked()
{
    QMessageBox::StandardButton respuesta;
    if (ui->PedidosTemporales->rowCount()!=0){
        respuesta = QMessageBox::question(this, "Confirmacion", "¿Esta seguro de ingresar pedido?", QMessageBox::Yes|QMessageBox::No);
        if (respuesta == QMessageBox::Yes) {
            int precio_pedido = 0;
            deque<Cilindro> cilindros;
            for(int i=0; i<ui->PedidosTemporales->rowCount();i++){
                QTableWidgetItem *cnt = ui->PedidosTemporales->item(i,0);
                QTableWidgetItem *cap = ui->PedidosTemporales->item(i,1);
                QTableWidgetItem *tip = ui->PedidosTemporales->item(i,2);
                int cantidad = (cnt->text()).toInt();
                int capacidad = (cap->text()).toInt();
                string tipo = (tip->text()).toStdString();
                Cilindro *cilin = new Cilindro(cantidad,capacidad,tipo);
                cilindros.push_back(*cilin);
                precio_pedido += cilin->Precio();
            }
            string nombre = ui->lineEdit_nombre->text().toStdString();
            string cerro_destino = ui->comboBox_cerro->currentText().toStdString();
            string medio_pago = ui->comboBox_tipopago->currentText().toStdString();
            Pedido *pedid = new Pedido(nombre,cerro_destino,medio_pago,cilindros,precio_pedido);
            pedidos.push_back(*pedid);
            QMessageBox mensaje;
            mensaje.setWindowTitle(" ");
            mensaje.setText("Solicitud ingresada\n"
                           "Total a pagar $"+QString::number(precio_pedido)+"\n"
                           "Tiempo de espera estimado:"+QString::number(pedid->get_TiempoEntrega())+"[min]");
            mensaje.exec();
            ui->PedidosTemporales->setRowCount(0);
        }else
            QMessageBox::information(this,"Ok","Ok sigue agregando o quitando:3");
    }else
        QMessageBox::information(this,"Mal","No has agregado ninguna wea");
}

void VendedorWindow::on_PedidosTemporales_itemClicked(QTableWidgetItem *item)
{
    fila = item->row();
}

void VendedorWindow::on_bt_borrarSelecc_clicked()
{
    ui->PedidosTemporales->removeRow(fila);
}
