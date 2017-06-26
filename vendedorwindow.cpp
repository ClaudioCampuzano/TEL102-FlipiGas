#include "vendedorwindow.h"
#include "ui_vendedorwindow.h"
#include <QMessageBox>
#include <pedido.h>
#include <cilindro.h>
#include <deque>

//deque <Pedidos> pedidos;

VendedorWindow::VendedorWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VendedorWindow)
{
    ui->setupUi(this);
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
/*
        deque<Cilindros> Cilindros;
        for(int i=0; i<ui->PedidosTemporales->rowCount();i++){

        }
        Pedidos *pedido_temp = Pedidos(ui->lineEdit_nombre->text(),ui->comboBox_cerro->currentText(),
                                       ui->comboBox_tipopago->currentText(),Cilindros);
        pedidos.push_back(*pedido_temp);
*/
        QMessageBox::information(this,"Bien","Pedido ingresado :)");
        this->close();
    }else{
        QMessageBox::information(this,"Ok","Ok sigue agregando :3");

    }
}



