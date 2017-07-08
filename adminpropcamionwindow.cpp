#include "adminpropcamionwindow.h"
#include "ui_adminpropcamionwindow.h"

AdminPropCamionWindow::AdminPropCamionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPropCamionWindow)
{
    ui->setupUi(this);
}

AdminPropCamionWindow::~AdminPropCamionWindow()
{
    delete ui;
}
