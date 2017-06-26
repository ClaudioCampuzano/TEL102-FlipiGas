/* Usuarios PreDefinidos
 * Vendedor {User: Vendedor, Pass: vendedor123}
 * Administrador {User: Administrador, Pass: Holamundo}
 * Camionero {User: C_Cerro, Pass: Cerro} donde Cerro, correspondera a uno de los cerros de valparaiso.
 */

#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->lineEdit_pass->setEchoMode(QLineEdit::Password);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

bool Verificador_Camionero(QString user, QString pass){
    if (((user == "C_Alegre")&(pass == "Alegre"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Blanco")&(pass == "Blanco"))|((user == "C_Bellavista")&(pass == "Bellavista"))
            |((user == "C_Concepcion")&(pass == "Concepcion"))|((user == "C_Cordillera")&(pass == "Cordillera"))
            |((user == "C_Delicias")&(pass == "Delicias"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron"))|((user == "C_Baron")&(pass == "Baron"))
            |((user == "C_Baron")&(pass == "Baron")))
        return true;
    return false;
}

void LoginWindow::on_pushButton_Login_clicked()
{
    {
        QString usuario = ui->lineEdit_user->text();
        QString contrasena = ui->lineEdit_pass->text();
        if (ui->checkBox_Qcamionero->checkState()){
            if (Verificador_Camionero(usuario, contrasena)){
                //this->close();
                camionero = new CamioneroWindow(this);
                camionero->show();
            }else
                QMessageBox::warning(this,"Login","Nombre de usuario o contraseña incorrectos");
        }else if(usuario == "Vendedor" && contrasena == "vendedor123"){
            //this->close();
            vendedor = new VendedorWindow(this);
            vendedor ->show();
        }else if (usuario == "Administrador" && contrasena == "Holamundo"){
            //this->close();
            administrador= new AdministradorWindow(this);
            administrador->show();
        }else
            QMessageBox::warning(this,"Login","Nombre de usuario o contraseña incorrectos");
    }
}

