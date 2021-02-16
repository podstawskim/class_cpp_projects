#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Speed::connect(&displacement, SIGNAL(valueChanged(float)),
            &speed, SLOT(notify(float)) );
    Acceleration::connect(&displacement, SIGNAL(valueChanged(float)),
                          &acceleration, SLOT(notify(float)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Utils utils{};
    float value = (ui->lineEdit->text()).toFloat();

    this->displacement.set(value);
    ui->lcdSpeed->display(speed.get());
    ui->lcdAcceleration->display(acceleration.get());
    ui->lineEdit->clear();
}

