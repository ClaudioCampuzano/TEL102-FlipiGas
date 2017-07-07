#include "admininventariowindow.h"
#include "ui_admininventariowindow.h"
#include "loginwindow.h"
#include <QMessageBox>

AdminInventarioWindow::AdminInventarioWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminInventarioWindow)
{
    ui->setupUi(this);
    ui->CapacidadPlanta->setText(QString::number(LoginWindow::capCilindroPlanta));
    ui->CilinRestante->setText(QString::number(LoginWindow::cilidrosRestantes));
}

AdminInventarioWindow::~AdminInventarioWindow()
{
    delete ui;
}

void AdminInventarioWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton respuesta;
    respuesta = QMessageBox::question(this, "Confirmacion", "¿Esta seguro de reponer cilindros?", QMessageBox::Yes|QMessageBox::No);
    if (respuesta == QMessageBox::Yes){
        LoginWindow::cilidrosRestantes= 5000;
        ui->CilinRestante->setText(QString::number(LoginWindow::cilidrosRestantes));
    }
}
