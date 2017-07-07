#include "admincamioneswindow.h"
#include "ui_admincamioneswindow.h"

AdminCamionesWindow::AdminCamionesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminCamionesWindow)
{
    ui->setupUi(this);
}

AdminCamionesWindow::~AdminCamionesWindow()
{
    delete ui;
}
