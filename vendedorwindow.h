#ifndef VENDEDORWINDOW_H
#define VENDEDORWINDOW_H

#include <QDialog>
#include <QTableWidgetItem>
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

    void on_PedidosTemporales_itemClicked(QTableWidgetItem *item);

    void on_bt_borrarSelecc_clicked();

private:
    Ui::VendedorWindow *ui;
    int fila;
};

#endif // VENDEDORWINDOW_H
