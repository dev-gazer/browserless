#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_webView_loadStarted();

    void on_webView_loadFinished(bool arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H