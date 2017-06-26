#include "camionerowindow.h"
#include "ui_camionerowindow.h"

CamioneroWindow::CamioneroWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CamioneroWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0,300);

}

CamioneroWindow::~CamioneroWindow()
{
    delete ui;
}

void CamioneroWindow::on_bt_recargar_clicked()
{

}
