#ifndef ADMINVENTASCRUZADAS_H
#define ADMINVENTASCRUZADAS_H

#include <QDialog>

namespace Ui {
class AdminVentasCruzadas;
}

class AdminVentasCruzadas : public QDialog
{
    Q_OBJECT

public:
    explicit AdminVentasCruzadas(QWidget *parent = 0);
    ~AdminVentasCruzadas();

private:
    Ui::AdminVentasCruzadas *ui;
};

#endif // ADMINVENTASCRUZADAS_H
