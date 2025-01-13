#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    int x = QMainWindow::width() / 2;
    int y = QMainWindow::height() / 2;

    float pi = 3.1415926f;
    double spiral = 5;
    double a = 20;
    double k = a / (2 * pi);
    double step = 0.01;

    QPainter painter(this);
    painter.drawLine(QPointF(150, QMainWindow::height() / 2), QPointF(649, QMainWindow::height() / 2));
    painter.drawLine(QPointF(QMainWindow::width() / 2, 9), QPointF(QMainWindow::width() / 2, 543));

    for (double f = 0; f < 5 * (2 * pi); f+=step) {
        double p = k * f;
        int res_x = x-(p*cos(f));
        int res_y = y+(p*sin(f));
        painter.drawPoint(res_x,res_y);
    }
}
