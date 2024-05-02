#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CReadFile.h"
#include <QPixmap>

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

void MainWindow::on_pushButton_clicked()
{
    int userInput = ui->lineEdit->text().toInt();

    if(userInput >= 0 && userInput < 50)
    {
        index = userInput;
        CReadFile reader;
        QString movie = reader.getRandomMovie(userInput % 2 == 1);

        ui->label_3->setText(movie);
    }
    else
    {
        ui->label_3->setText("Invalid input");
    }
}




void MainWindow::on_pushButton_2_clicked()
{
    close();
}

