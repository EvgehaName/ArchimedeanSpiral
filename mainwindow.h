#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <QtMath>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *event);
    QTimer* timer;
    double a = 20;
    double k = a / (2 * M_PI);
    double step = 0.01;
    double f = 0;
    QVector<QPointF> points;

public slots:
    void genPoint();
};
#endif // MAINWINDOW_H
