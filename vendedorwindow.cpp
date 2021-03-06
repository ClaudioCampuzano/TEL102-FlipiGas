#include "vendedorwindow.h"
#include "ui_vendedorwindow.h"
#include <QMessageBox>
#include <pedido.h>
#include <QTableWidgetItem>
#include "loginwindow.h"

vector<Pedido> VendedorWindow::pedidos;

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
            vector<Cilindro> cilindros;
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
/* Al presionar el boton, se asignaran los pedidos a los diferentes camiones
*/
void VendedorWindow::on_Asignar_pedidos_clicked()
{
    int sw=0;
    for(int j=0; j<pedidos.size();j++)
        if(pedidos[j].get_Asignado()==false){
            sw = 1;
            break;
        }
    if(sw==1){
        QMessageBox::StandardButton respuesta;
        respuesta = QMessageBox::question(this, "Confirmacion", "¿Esta seguro de asignar y mandar camiones?", QMessageBox::Yes|QMessageBox::No);
        if (respuesta == QMessageBox::Yes) {
            for(int i=0; i<LoginWindow::camiones.size(); i+=3){
                int peso_pedidos=0;
                int indice_pedidos=-1;
                for(int j=0; j<pedidos.size();j++){
                    if(pedidos[j].get_Asignado() == false)
                        if(LoginWindow::camiones[i].get_Cerro() == pedidos[j].get_Cerro())
                            for(int k=0; k< pedidos[j].get_Cilindros().size();k++)
                                peso_pedidos+= pedidos[j].get_Cilindros()[k].get_Cantidad();
                    if(peso_pedidos>100){
                        indice_pedidos = j-1;
                        break;
                    }else
                        indice_pedidos=j+1;
                }
                if (indice_pedidos != -1)
                    for(int j=0; j<indice_pedidos;j++){
                        int num_cilin=0;
                        for(int k=0; k< pedidos[j].get_Cilindros().size();k++)
                            num_cilin+= pedidos[j].get_Cilindros()[k].get_Cantidad();
                        if(pedidos[j].get_Asignado() == false){
                            if ((peso_pedidos<=25)&(LoginWindow::camiones[i].get_CilindrosRestantes()-num_cilin>=0)&
                                    (LoginWindow::camiones[i].get_Estado()==false)){
                                if(LoginWindow::camiones[i].get_Cerro() == pedidos[j].get_Cerro()){
                                    pedidos[j].set_Asignado();
                                    LoginWindow::camiones[i].set_Restar_del_stock(num_cilin);
                                    LoginWindow::camiones[i].push_Pedido(pedidos[j]);
                                    QMessageBox::information(this,"Solido","Pedido ingresado al camion de 25");
                                    }
                            }else if ((peso_pedidos<=50)&(LoginWindow::camiones[i+1].get_CilindrosRestantes()-num_cilin>=0)&
                                      (LoginWindow::camiones[i+2].get_Estado()==false)){
                                if(pedidos[j].get_Asignado() == false)
                                    if(LoginWindow::camiones[i+1].get_Cerro() == pedidos[j].get_Cerro()){
                                        pedidos[j].set_Asignado();
                                        LoginWindow::camiones[i+1].set_Restar_del_stock(num_cilin);
                                        LoginWindow::camiones[i+1].push_Pedido(pedidos[j]);
                                        QMessageBox::information(this,"Solido","Pedido ingresado al camion de 50");
                                    }
                            }else if ((LoginWindow::camiones[i+2].get_CilindrosRestantes()-num_cilin>=0)&
                                      (LoginWindow::camiones[i].get_Estado()==false))
                                if(pedidos[j].get_Asignado() == false)
                                    if(LoginWindow::camiones[i+2].get_Cerro() == pedidos[j].get_Cerro()){
                                        pedidos[j].set_Asignado();
                                        LoginWindow::camiones[i+2].set_Restar_del_stock(num_cilin);
                                        LoginWindow::camiones[i+2].push_Pedido(pedidos[j]);
                                        QMessageBox::information(this,"Solido","Pedido ingresado al camion de 100");
                                    }
                        }
                    }
            }
            for(int i=0; i<LoginWindow::camiones.size(); i++)
                if (LoginWindow::camiones[i].get_CilindrosRestantes() != LoginWindow::camiones[i].get_Capacidad())
                    LoginWindow::camiones[i].set_Estado(true);
        }
    }else
        QMessageBox::information(this,"Mal","No hay pedidos que asignar");
}
