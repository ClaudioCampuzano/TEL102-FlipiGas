#ifndef CAMIONEROWINDOW_H
#define CAMIONEROWINDOW_H

#include <QDialog>
#include "vendedorwindow.h"
#include <QCheckBox>
//#include "loginwindow.h"

namespace Ui {
class CamioneroWindow;
}

class CamioneroWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CamioneroWindow(QWidget *parent = 0);
    ~CamioneroWindow();

private slots:
    void on_bt_recargar_clicked();

private:
    Ui::CamioneroWindow *ui;
};

#endif // CAMIONEROWINDOW_H
