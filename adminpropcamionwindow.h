#ifndef ADMINPROPCAMIONWINDOW_H
#define ADMINPROPCAMIONWINDOW_H

#include <QDialog>

namespace Ui {
class AdminPropCamionWindow;
}

class AdminPropCamionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPropCamionWindow(QWidget *parent = 0);
    ~AdminPropCamionWindow();

private:
    Ui::AdminPropCamionWindow *ui;
};

#endif // ADMINPROPCAMIONWINDOW_H
