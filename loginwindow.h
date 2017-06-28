#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "administradorwindow.h"
#include "vendedorwindow.h"
#include "camionerowindow.h"
#include "camion.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
    static vector<Camion> camiones;
    static int indice_login;
private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::LoginWindow *ui;
    AdministradorWindow *administrador;
    VendedorWindow *vendedor;
    CamioneroWindow *camionero;
};

#endif // LOGINWINDOW_H
