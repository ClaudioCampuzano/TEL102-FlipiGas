#ifndef VENDEDORWINDOW_H
#define VENDEDORWINDOW_H

#include <QDialog>

namespace Ui {
class VendedorWindow;
}

class VendedorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit VendedorWindow(QWidget *parent = 0);
    ~VendedorWindow();

private slots:

    void on_bt_ingresarpedido_clicked();

    void on_bt_agregarpedido_clicked();


private:
    Ui::VendedorWindow *ui;
};

#endif // VENDEDORWINDOW_H
