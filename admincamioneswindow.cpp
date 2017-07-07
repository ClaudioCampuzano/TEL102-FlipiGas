#include "admincamioneswindow.h"
#include "ui_admincamioneswindow.h"
#include "loginwindow.h"
#include <QPushButton>

AdminCamionesWindow::AdminCamionesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminCamionesWindow)
{
    ui->setupUi(this);
    ui->Camiones->setColumnWidth(0,100);
    ui->Camiones->setColumnWidth(1,150);
    ui->Camiones->setColumnWidth(2,150);
    for(int i=0; i<LoginWindow::camiones.size(); i++){
        ui->Camiones->insertRow(i);
        if (LoginWindow::camiones[i].get_Estado())
            ui->Camiones->setItem(i,0, new QTableWidgetItem("En reparto"));
        else
            ui->Camiones->setItem(i,0, new QTableWidgetItem("En la planta"));
        string puto = LoginWindow::camiones[i].get_Cerro();
        QString detalle_camion = "Cerro " + QString::fromStdString(LoginWindow::camiones[i].get_Cerro())+"-"
                + QString::number(LoginWindow::camiones[i].get_Capacidad())
                +" cilindros";
        ui->Camiones->setItem(i,1,new QTableWidgetItem(detalle_camion));

        QPushButton *qPushButton = new QPushButton();;
        qPushButton->setText("Propiedades");
        ui->Camiones->setCellWidget(i,2,(QWidget*)qPushButton);
    }
}

AdminCamionesWindow::~AdminCamionesWindow()
{
    delete ui;
}
