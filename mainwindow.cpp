#include "mainwindow.h"
#include <QLabel>
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeTurn(size_t turn) {
    qDebug() << "change turn";
    this->setMenuWidget(new QLabel(turn == 1 ? "cross" : "circle"));
}
