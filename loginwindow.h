#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "administradorwindow.h"
#include "vendedorwindow.h"
#include "camionerowindow.h"
#include "camion.h"
#include "admininventariowindow.h"

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
    static vector<string> cerros;
    static int CincokgCatalico;
    static int OncekgCatalico;
    static int QuincekgCatalico;
    static int CuarentaYCincokgCatalico;
    static int CincokgNoCatalico;
    static int OncekgNoCatalico;
    static int QuincekgNoCatalico;
    static int CuarentaYCincokgNoCatalico;
    static int total_ventas;
private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::LoginWindow *ui;
    AdministradorWindow *administrador;
    VendedorWindow *vendedor;
    CamioneroWindow *camionero;
    AdminInventarioWindow *adminInventarioWindow;

};

#endif // LOGINWINDOW_H
