/* Usuarios PreDefinidos
 * Vendedor {User: Vendedor, Pass: vendedor123}
 * Administrador {User: Administrador, Pass: Holamundo}
 * Camionero (existiran 3 tipos de camiones de 25, 50 y 100 cilindros
 * {User: tipo_Cerro, Pass: Cerro} donde Cerro, correspondera a uno de los cerros de valparaiso.
 */

#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <deque>
#include <camion.h>
#include <vector>

vector<Camion> camiones;

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
    vector<string> cerros;
    cerros.push_back("Alegre");cerros.push_back("Barón");cerros.push_back("Blanco");
    cerros.push_back("Bellavista");cerros.push_back("Concepción");cerros.push_back("Cordillera");
    cerros.push_back("Delicias");cerros.push_back("El Litre");cerros.push_back("El Molino");
    cerros.push_back("Esperanza");cerros.push_back("Jiménez");cerros.push_back("Larraín");
    cerros.push_back("La Cruz");cerros.push_back("La Cárcel");cerros.push_back("La Florida");
    cerros.push_back("La Merced");cerros.push_back("La Virgen");cerros.push_back("Las Cañas");
    cerros.push_back("Las Jarcias");cerros.push_back("Las Monjas");cerros.push_back("Los Placeres");
    cerros.push_back("Loceras");cerros.push_back("Lecheros");cerros.push_back("Mariposas");
    cerros.push_back("Mesilla");cerros.push_back("Miraflores");cerros.push_back("O'Higgins");
    cerros.push_back("Pajonal");cerros.push_back("Panteón");cerros.push_back("Playa Ancha");
    cerros.push_back("Perdices");cerros.push_back("Polanco");cerros.push_back("Ramaditas");
    cerros.push_back("San Juan de Dios");cerros.push_back("Santo Domingo");cerros.push_back("San Francisco");
    cerros.push_back("Toro");cerros.push_back("Yungay");
    for(int i =0; i < cerros.size(); i++){
        Camion *cami = new Camion(cerros[i],25);
        Camion *cami1 = new Camion(cerros[i],50);
        Camion *cami2 = new Camion(cerros[i],100);
        camiones.push_back(*cami);
        camiones.push_back(*cami1);
        camiones.push_back(*cami2);
    }
}

bool Verificador_Camionero(QString user, QString pass){
    for (int i=0; i<camiones.size();i++){
        Camion temporal;
        temporal =camiones[i];
        if (temporal.get_Cerro()==pass.toStdString())
            if(QString::number(temporal.get_Capacidad()) == user.split("_").at(0))
                if(temporal.get_Cerro() == user.split("_").at(1).toStdString())
                    return true;
    }
    return false;
}

void LoginWindow::on_pushButton_Login_clicked(){
    QString usuario = ui->lineEdit_user->text();
    QString contrasena = ui->lineEdit_pass->text();
    if (ui->checkBox_Qcamionero->checkState()){
        if (Verificador_Camionero(usuario, contrasena)){
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


