#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage img(400,400,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap::fromImage(img));
    window();
}

void MainWindow ::window(){
    dda(0, 200, 400, 200);
    dda(200, 0, 200, 400);
}
void MainWindow :: dda(float x1, float y1, float x2, float y2){
    float dx,dy,xinc,yinc,x,y,length;
    dx = x2-x1;
    dy = y2-y1;

    if(abs(dx)>abs(dy)){
        length = abs(dx);
    }
    else{
        length = abs(dy);
    }

    xinc=dx/length;
    yinc=dy/length;
    x = x1;
    y=y1;
    int i=0;
    while(i<length){
        img.setPixel(x,y,qRgb(255,0,0));
        x+=xinc;
        y+=yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow :: dda1(float x1, float y1, float x2, float y2){
    float dx,dy,xinc,yinc,x,y,length;
    dx = x2-x1;
    dy = y2-y1;

    if(abs(dx)>abs(dy)){
        length = abs(dx);
    }
    else{
        length = abs(dy);
    }

    xinc=dx/length;
    yinc=dy/length;
    x = x1;
    y=y1;
    int i=0;
    while(i<length){
        img.setPixel(x,y,qRgb(0,0,0));
        x+=xinc;
        y+=yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3){
    dda(x1+200,y1+200,x2+200,y2+200);
    dda(x2+200,y2+200,x3+200,y3+200);
    dda(x3+200,y3+200,x1+200,y1+200);
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::clear(){
    for(int i=0;i<400;i++){
        for(int j=0;j<400;j++){
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    window();
}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_2_clicked()
{

    x1 = ui->textEdit->toPlainText().toInt();
    y1 = ui->textEdit_2->toPlainText().toInt();
    x2 = ui->textEdit_3->toPlainText().toInt();
    y2 = ui->textEdit_4->toPlainText().toInt();
    x3 = ui->textEdit_5->toPlainText().toInt();
    y3 = ui->textEdit_6->toPlainText().toInt();
    drawTriangle(x1, y1, x2, y2, x3, y3);
}


void MainWindow::on_pushButton_4_clicked()
{
    float sx,sy;
    sx = ui->textEdit_9->toPlainText().toInt();
    sy = ui->textEdit_10->toPlainText().toInt();

    x1 = x1*sx;
    y1 = y1*sy;
    x2 = x2*sx;
    y2 = y2*sy;
    x3 = x3*sx;
    y3 = y3*sy;
    clear();
    drawTriangle(x1,y1,x2,y2,x3,y3);
}


void MainWindow::on_pushButton_3_clicked()
{
    float tx,ty;
    tx = ui->textEdit_7->toPlainText().toInt();
    ty = ui->textEdit_8->toPlainText().toInt();

    x1 +=tx;
    y1+=ty;
    x2+=tx;
    y2+=ty;
    x3+=tx;
    y3+=ty;
    clear();
    drawTriangle(x1,y1,x2,y2,x3,y3);
}


void MainWindow::on_pushButton_5_clicked()
{
    float angle,required_angle;
    angle = ui->textEdit_11->toPlainText().toInt();
    required_angle = angle*0.0174533;

    x1 = x1*cos(required_angle)-y1*sin(required_angle);
    y1 = x1*sin(required_angle)+y1*cos(required_angle);
    x2 = x2*cos(required_angle)-y2*sin(required_angle);
    y2 = x2*sin(required_angle)+y2*cos(required_angle);
    x3 = x3*cos(required_angle)-y3*sin(required_angle);
    y3 = x3*sin(required_angle)+y3*cos(required_angle);

    clear();
    drawTriangle(x1,y1,x2,y2,x3,y3);
}

