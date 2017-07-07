#ifndef CAMIONES_ADMINISTRADOR_H
#define CAMIONES_ADMINISTRADOR_H

#include <QDialog>

namespace Ui {
class Camiones_Administrador;
}

class Camiones_Administrador : public QDialog
{
    Q_OBJECT

public:
    explicit Camiones_Administrador(QWidget *parent = 0);
    ~Camiones_Administrador();

private:
    Ui::Camiones_Administrador *ui;
};

#endif // CAMIONES_ADMINISTRADOR_H
