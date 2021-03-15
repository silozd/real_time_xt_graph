#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <math.h>
#include <QTimer>
#include <QWidget>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->val_v, SIGNAL(valueChanged(double)), this, SLOT(read_v()));

    time_t = new QTimer(this);
    connect(time_t, SIGNAL(timeout()),this,SLOT(on_print_btn_clicked()));
    customPlot_load = new QCustomPlot(this->ui->graph_widget);
    customPlot_load->addGraph();
    customPlot_load->setGeometry(0,0,ui->graph_widget->width(),ui->graph_widget->height());
    customPlot_load->yAxis->setLabel("distance (x)");
    customPlot_load->xAxis->setLabel("time (t)");
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read_v()   
{
    ui->lbl_v->setText(QString::number(ui->val_v->value()));
}

void MainWindow::on_print_btn_clicked()
{
    static int ctr = 0;
    double x_sila;
    x_sila=(ui->val_v->value())*(ctr);
    time_t->start();
    time_t->setInterval(1000);
    ui->lbl_x->setText(QString::number(x_sila));
    customPlot_load->graph(0)->addData(ctr,x_sila);
        ctr++;
    customPlot_load->xAxis->setRange(0,ctr + 1);
    customPlot_load->yAxis->setRange(0,x_sila);
    customPlot_load->graph(0)->rescaleValueAxis(true,true);
    customPlot_load->replot();
}

void MainWindow::on_clear_btn_clicked()
{
    int remaining = time_t->remainingTime();
    time_t->stop();
    time_t->setInterval(remaining);

}

