#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

QImage img(600,600,QImage::Format_RGB888);
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

void MainWindow :: dda(float x1, float y1, float x2, float y2){
    float xinc,yinc,dx,dy,length,x,y;

    dx = x2-x1;
    dy = y2-y1;

    if(abs(dx)>=abs(dy)){
        length = abs(dx);
    }
    else{
        length = abs(dy);
    }

    xinc = dx/length;
    yinc = dy/length;

    x = x1;
    y = y1;

    int i=1;

    while(i<=length){
        img.setPixel(x,y,qRgb(255,0,0));
        x += xinc;
        y += yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_clicked()
{
    int x1,y1,x5,y5;
    int level = ui->textEdit->toPlainText().toInt();

    x1 = 70;
    y1 = 200;
    x5 = 300;
    y5 = 200;

    paint_recursive(level,x1,y1,x5,y5);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow :: paint_recursive(int order, int x1, int y1, int x5, int y5){
    int x2,y2,x3,y3,x4,y4,deltax,deltay;

    if(order == 1){
        dda(x1,y1,x5,y5);
    }
    else{
        deltax = x5-x1;
        deltay = y5-y1;

        x2 = x1+deltax/3;
        y2 = y1+deltay/3;

        x3 = int((x1 + x5) / 2 + (sqrt(3.0)/6) * deltay);
        y3 = int((y1 + y5) / 2 - (sqrt(3.0)/6) * deltax);

        x4 = x1 + deltax * 2 / 3;
        y4 = y1 + deltay * 2 / 3;

        paint_recursive(order - 1,x1,y1,x2,y2);
        paint_recursive(order - 1,x2,y2,x3,y3);
        paint_recursive(order - 1,x3,y3,x4,y4);
        paint_recursive(order - 1,x4,y4,x5,y5);
    }
}

