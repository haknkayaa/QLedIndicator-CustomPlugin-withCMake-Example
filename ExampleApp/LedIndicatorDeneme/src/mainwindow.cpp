#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [this]{
       if(ui->qLedIndicator->state() == true){
           ui->qLedIndicator->setState(false);
       } else{
           ui->qLedIndicator->setState(true);
       }
    });

    connect(ui->pushButton_2, &QPushButton::clicked, [this]{
       if(ui->qLedIndicator_2->state() == true){
           ui->qLedIndicator_2->setState(false);
       } else{
           ui->qLedIndicator_2->setState(true);
           ui->qLedIndicator_2->setIndicatorStyle(QLedIndicator::TextUnderIcon);
       }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

