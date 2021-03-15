#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <qcustomplot.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double val_v;
    QTimer *time_t;
    QCustomPlot *customPlot_load;

public slots:

    void read_v();
    void on_print_btn_clicked();


private slots:
    void on_clear_btn_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
