/* Usuarios PreDefinidos
 * Vendedor {User: Vendedor, Pass: vendedor123}
 * Administrador {User: Administrador, Pass: Holamundo}
 * Camionero (existiran 3 tipos de camiones de 25, 50 y 100 cilindros
 * {User: tipo_Cerro, Pass: Cerro} donde Cerro, correspondera a uno de los cerros de valparaiso.
 */

#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QMessageBox>
#include <camion.h>
#include "vendedorwindow.h"

vector<Camion> LoginWindow::camiones;
int LoginWindow::indice_login;
vector<string> LoginWindow::cerros;

void Creando_Camioneros();

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->lineEdit_pass->setEchoMode(QLineEdit::Password);
    Creando_Camioneros();

}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void Creando_Camioneros(){
    LoginWindow::cerros.push_back("Alegre");LoginWindow::cerros.push_back("Barón");LoginWindow::cerros.push_back("Blanco");
    LoginWindow::cerros.push_back("Bellavista");LoginWindow::cerros.push_back("Concepción");LoginWindow::cerros.push_back("Cordillera");
    LoginWindow::cerros.push_back("Delicias");LoginWindow::cerros.push_back("El Litre");LoginWindow::cerros.push_back("El Molino");
    LoginWindow::cerros.push_back("Esperanza");LoginWindow::cerros.push_back("Jiménez");LoginWindow::cerros.push_back("Larraín");
    LoginWindow::cerros.push_back("La Cruz");LoginWindow::cerros.push_back("La Cárcel");LoginWindow::cerros.push_back("La Florida");
    LoginWindow::cerros.push_back("La Merced");LoginWindow::cerros.push_back("La Virgen");LoginWindow::cerros.push_back("Las Cañas");
    LoginWindow::cerros.push_back("Las Jarcias");LoginWindow::cerros.push_back("Las Monjas");LoginWindow::cerros.push_back("Los Placeres");
    LoginWindow::cerros.push_back("Loceras");LoginWindow::cerros.push_back("Lecheros");LoginWindow::cerros.push_back("Mariposas");
    LoginWindow::cerros.push_back("Mesilla");LoginWindow::cerros.push_back("Miraflores");LoginWindow::cerros.push_back("O'Higgins");
    LoginWindow::cerros.push_back("Pajonal");LoginWindow::cerros.push_back("Panteón");LoginWindow::cerros.push_back("Playa Ancha");
    LoginWindow::cerros.push_back("Perdices");LoginWindow::cerros.push_back("Polanco");LoginWindow::cerros.push_back("Ramaditas");
    LoginWindow::cerros.push_back("San Juan de Dios");LoginWindow::cerros.push_back("Santo Domingo");LoginWindow::cerros.push_back("San Francisco");
    LoginWindow::cerros.push_back("Toro");LoginWindow::cerros.push_back("Yungay");
    for(int i =0; i < LoginWindow::cerros.size(); i++){
        Camion *cami = new Camion(LoginWindow::cerros[i],25);
        Camion *cami1 = new Camion(LoginWindow::cerros[i],50);
        Camion *cami2 = new Camion(LoginWindow::cerros[i],100);

        LoginWindow::camiones.push_back(*cami);
        LoginWindow::camiones.push_back(*cami1);
        LoginWindow::camiones.push_back(*cami2);
    }
}

int Verificador_Camionero(QString user, QString pass){
    for (int i=0; i<LoginWindow::camiones.size();i++){
        Camion temporal;
        temporal =LoginWindow::camiones[i];
        if (temporal.get_Cerro()==pass.toStdString())
            if(QString::number(temporal.get_Capacidad()) == user.split("_").at(0))
                if(temporal.get_Cerro() == user.split("_").at(1).toStdString())
                    return i;
    }
    return -1;
}

void LoginWindow::on_pushButton_Login_clicked(){
    QString usuario = ui->lineEdit_user->text();
    QString contrasena = ui->lineEdit_pass->text();
    if (ui->checkBox_Qcamionero->checkState()){
        indice_login=Verificador_Camionero(usuario, contrasena);
        if (indice_login!=-1){
            camionero = new CamioneroWindow(this);
            camionero->show();
        }else
            QMessageBox::warning(this,"Login","Nombre de usuario o contraseña incorrectos");
    }else if(usuario == "Vendedor" && contrasena == "vendedor123"){
        vendedor = new VendedorWindow(this);
        vendedor ->show();
    }else if (usuario == "Administrador" && contrasena == "Holamundo"){
        administrador= new AdministradorWindow(this);
        administrador->show();
    }else
        QMessageBox::warning(this,"Login","Nombre de usuario o contraseña incorrectos");
}


