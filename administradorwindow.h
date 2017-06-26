#ifndef ADMINISTRADORWINDOW_H
#define ADMINISTRADORWINDOW_H

#include <QDialog>

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



private:
    Ui::AdministradorWindow *ui;
};

#endif // ADMINISTRADORWINDOW_H
