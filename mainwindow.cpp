#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(genPoint()));
    timer->start(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawLine(QPointF(150, QMainWindow::height() / 2), QPointF(649, QMainWindow::height() / 2));
    painter.drawLine(QPointF(QMainWindow::width() / 2, 9), QPointF(QMainWindow::width() / 2, 543));
    for (auto &point : points) {
        painter.drawPoint(point);
    }
}

void MainWindow::genPoint()
{
    if(f < 5 * (2 * M_PI))
    {
        //qDebug() << points;
        f+=step;
        double p = k * f;
        points.append(QPointF((width() / 2)-(p*cos(f)), (height() / 2)+(p*sin(f))));
        this->update();
    }
    else
    {
        f=0;
        points.clear();
    }
}
