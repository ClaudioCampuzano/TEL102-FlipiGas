#include "adminsolicitudeswindow.h"
#include "ui_adminsolicitudeswindow.h"

AdminSolicitudesWindow::AdminSolicitudesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminSolicitudesWindow)
{
    ui->setupUi(this);
}

AdminSolicitudesWindow::~AdminSolicitudesWindow()
{
    delete ui;
}
