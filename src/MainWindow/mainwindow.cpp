#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("browserless");
    ui->lineEdit->setText("https://github.com/dev-gazer/browserless");
    ui->webEngineView->load(ui->lineEdit->text());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->webEngineView->load(ui->lineEdit->text());
}

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void MainWindow::on_webEngineView_loadStarted()
{
    ui->statusbar->showMessage("Gazing...");
}

void MainWindow::on_webEngineView_loadFinished(bool arg1)
{
    if(arg1){
        ui->statusbar->showMessage("Gazed!");
        ui->lineEdit->setText(ui->webEngineView->url().toString());
    }else{
        ui->statusbar->showMessage("Failed to gaze. Too bad.");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->webEngineView->back();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->webEngineView->forward();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->webEngineView->reload();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText("https://github.com/dev-gazer/browserless");
    ui->webEngineView->load(ui->lineEdit->text());
}
