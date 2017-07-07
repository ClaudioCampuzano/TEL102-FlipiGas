#ifndef ADMININVENTARIOWINDOW_H
#define ADMININVENTARIOWINDOW_H

#include <QDialog>

namespace Ui {
class AdminInventarioWindow;
}

class AdminInventarioWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminInventarioWindow(QWidget *parent = 0);
    ~AdminInventarioWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AdminInventarioWindow *ui;
};

#endif // ADMININVENTARIOWINDOW_H
