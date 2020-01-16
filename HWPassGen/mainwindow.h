#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);


private:
    Ui::MainWindow *ui;
    QString pass;

public slots:
    void randPass();
    void savePass();
};

#endif // MAINWINDOW_H
