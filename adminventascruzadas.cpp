#include "adminventascruzadas.h"
#include "ui_adminventascruzadas.h"

AdminVentasCruzadas::AdminVentasCruzadas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminVentasCruzadas)
{
    ui->setupUi(this);
}

AdminVentasCruzadas::~AdminVentasCruzadas()
{
    delete ui;
}
