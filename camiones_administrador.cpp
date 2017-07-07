#include "camiones_administrador.h"
#include "ui_camiones_administrador.h"
#include "loginwindow.h"

Camiones_Administrador::Camiones_Administrador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Camiones_Administrador)
{/*
    ui->setupUi(this);
    for(int i=0; i < LoginWindow::camiones.size(); i++){
        ui->PedidosTemporales->insertRow(i);
        if (LoginWindow::camiones[i].get_Estado())
            ui->Camiones->setItem(i,0,QTableWidgetItem("En reparto"));
        else
            ui->Camiones->setItem(i,0,QTableWidgetItem("Disponible"));
    }*/
}

Camiones_Administrador::~Camiones_Administrador()
{
    delete ui;
}
