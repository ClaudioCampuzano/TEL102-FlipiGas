#ifndef ADMINCAMIONESWINDOW_H
#define ADMINCAMIONESWINDOW_H

#include <QDialog>

namespace Ui {
class AdminCamionesWindow;
}

class AdminCamionesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminCamionesWindow(QWidget *parent = 0);
    ~AdminCamionesWindow();

private:
    Ui::AdminCamionesWindow *ui;
};

#endif // ADMINCAMIONESWINDOW_H
