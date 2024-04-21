#include "mainwindow.h"
#include <QLabel>
#include "ui_mainwindow.h"


MainWindow::MainWindow(size_t& cur, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), cur(cur)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeTurn(size_t turn) {
    //qDebug() << "change turn";
    this->setMenuWidget(new QLabel(turn == 1 ? "cross" : "circle"));
}

void MainWindow::changeTurnC()
{
    cur = (cur == 1 ? 0 : 1);
    changeTurn(cur);
}

void MainWindow::win()
{
    setMenuWidget(new QLabel("end of game!"));
}
