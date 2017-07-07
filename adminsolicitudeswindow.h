#ifndef ADMINSOLICITUDESWINDOW_H
#define ADMINSOLICITUDESWINDOW_H

#include <QDialog>

namespace Ui {
class AdminSolicitudesWindow;
}

class AdminSolicitudesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminSolicitudesWindow(QWidget *parent = 0);
    ~AdminSolicitudesWindow();

private:
    Ui::AdminSolicitudesWindow *ui;
};

#endif // ADMINSOLICITUDESWINDOW_H
