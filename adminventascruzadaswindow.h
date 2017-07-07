#ifndef ADMINVENTASCRUZADASWINDOW_H
#define ADMINVENTASCRUZADASWINDOW_H

#include <QDialog>

namespace Ui {
class AdminVentasCruzadasWindow;
}

class AdminVentasCruzadasWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminVentasCruzadasWindow(QWidget *parent = 0);
    ~AdminVentasCruzadasWindow();

private:
    Ui::AdminVentasCruzadasWindow *ui;
};

#endif // ADMINVENTASCRUZADASWINDOW_H
