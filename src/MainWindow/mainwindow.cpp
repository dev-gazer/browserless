#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("browserless");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->webView->load(ui->lineEdit->text());
}

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void MainWindow::on_webView_loadStarted()
{
    ui->statusbar->showMessage("Gazing...");
}

void MainWindow::on_webView_loadFinished(bool arg1)
{
    if(arg1){
        ui->statusbar->showMessage("Gazed!");
        ui->lineEdit->setText(ui->webView->url().toString());
    }else{
        ui->statusbar->showMessage("Failed to gaze. Too bad.");
    }
}
