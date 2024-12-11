#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void window();
    void dda(float,float,float,float);
    void drawTriangle(int,int,int,int,int,int);
    void dda1(float,float,float,float);
    void on_pushButton_2_clicked();
    void clear();
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    float x1,y1,x2,y2,x3,y3;

};
#endif // MAINWINDOW_H
