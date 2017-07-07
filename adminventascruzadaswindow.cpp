#include "adminventascruzadaswindow.h"
#include "ui_adminventascruzadaswindow.h"

AdminVentasCruzadasWindow::AdminVentasCruzadasWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminVentasCruzadasWindow)
{
    ui->setupUi(this);
}

AdminVentasCruzadasWindow::~AdminVentasCruzadasWindow()
{
    delete ui;
}
