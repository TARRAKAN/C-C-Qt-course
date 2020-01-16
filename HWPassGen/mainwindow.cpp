#include "QtWidgets"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <QFile>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->bGen, SIGNAL(clicked()), SLOT(randPass()));
    connect(ui->bSave, SIGNAL(clicked()), SLOT(savePass()));
}

void MainWindow::randPass(){
    QChar c;
    QString pass;
    srand(time(NULL));
    for(int i = 0; i < ui->size->value();){
        c = 33 + rand() % ((126+1)-33);
        if(ui->simb->isChecked()&&ui->num->isChecked()){
            pass += c;
            i++;
        }else if(ui->simb->isChecked()){
            if(((c>32)&&(c<48))||((c>57)&&(c<127))){
                pass += c;
                i++;
            }
        }else if(ui->num->isChecked()){
            if(((c>47)&&(c<58))||((c>64)&&(c<91))||((c<96)&&(c>123))){
                pass += c;
                i++;
            }
        }else {
            if(((c>64)&&(c<91))||((c<96)&&(c>123))){
                pass += c;
                i++;
            }
        }
    }
    ui->passOut->setText(pass);
}

void MainWindow::savePass(){
    qDebug() << ui->passName->text() <<" : "<< ui->passOut->text() << '\n';
    QFile passFile("passes.txt");
    if(passFile.open(QIODevice::Append|QIODevice::Text)){
    qDebug() << "it's OK";
    QTextStream writeStream(&passFile);
    writeStream << ui->passName->text() <<":"<< ui->passOut->text() << '\n';
    passFile.close();
    }else qDebug() << "NO";
}
