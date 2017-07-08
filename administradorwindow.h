#ifndef ADMINISTRADORWINDOW_H
#define ADMINISTRADORWINDOW_H

#include <QDialog>
#include "admincamioneswindow.h"
#include "adminventascruzadaswindow.h"
#include "adminsolicitudeswindow.h"

namespace Ui {
class AdministradorWindow;
}

class AdministradorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdministradorWindow(QWidget *parent = 0);
    ~AdministradorWindow();

private slots:

    void on_bt_solicitudes_clicked();

    void on_bt_camiones_clicked();

    void on_bt_ventaybodega_clicked();



    void on_bt_inventario_clicked();

private:
    Ui::AdministradorWindow *ui;
    AdminCamionesWindow *adminCamionesWindow;
    AdminVentasCruzadasWindow *adminVentasCruzadasWindow;
    AdminSolicitudesWindow *adminSolicitudesWindow;
};

#endif // ADMINISTRADORWINDOW_H
