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
    respuesta = QMessageBox::question(this, "Confirmacion", "¿Esta seguro de ingresar pedido?", QMessageBox::Yes|QMessageBox::No);
    if (respuesta == QMessageBox::Yes) {
        int valor_acumulado = 0;
        deque<Cilindro> Cilindros;
        for(int i=0; i<ui->PedidosTemporales->rowCount();i++){
            QTableWidgetItem *cantidad = ui->PedidosTemporales->item(i,0);
            QTableWidgetItem *capacidad = ui->PedidosTemporales->item(i,1);
            QTableWidgetItem *tipo = ui->PedidosTemporales->item(i,2);
            Cilindro *cilin = new Cilindro((cantidad->text()).toInt(),(capacidad->text()).toInt(),(tipo->text()).toStdString());
            Cilindros.push_back(*cilin);
            valor_acumulado += cilin->Precio();
        }
        Pedido *pedido_temp = new Pedido((ui->lineEdit_nombre->text()).toStdString(),(ui->comboBox_cerro->currentText()).toStdString(),
                                       (ui->comboBox_tipopago->currentText()).toStdString(),Cilindros,valor_acumulado);
        pedidos.push_back(*pedido_temp);
        QMessageBox::information(this,"Bien","Precio:\nTiempo de espera: \nPedido ingresado :)");
        this->close();
    }else{
        QMessageBox::information(this,"Ok","Ok sigue agregando :3");

    }
}

void VendedorWindow::on_PedidosTemporales_itemClicked(QTableWidgetItem *item)
{
    fila = item->row();
}

void VendedorWindow::on_bt_borrarSelecc_clicked()
{
    ui->PedidosTemporales->removeRow(fila);
}
