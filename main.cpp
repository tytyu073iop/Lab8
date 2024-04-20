#include "mainwindow.h"

#include <QApplication>

#include <QGridLayout>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QApplication b(argc, argv);
    // while (true) {
    //     int* q = new int(8);
    // }
    MainWindow w;
    // qDebug() << "zalupa";
    QWidget* qw = new QWidget();
    auto grid = QGridLayout(qw);
    //grid.addWidget(new QLabel(QString("row: %1, collum: %2").arg(i).arg(j)), i, j);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            auto pm = QPixmap(":/cross.png");
            pm = pm.scaled(100, 100, Qt::KeepAspectRatio);
            auto q = new QLabel(QString("row: %1, collum: %2").arg(i).arg(j));
            q->setFrameShape(QFrame::Box);
            q->setPixmap(pm);
            q->setScaledContents(true);
            q->show();
            grid.addWidget(q, i, j);
        }
    }
    //auto i = QLabel("Hello!", &w);
    //w.setMenuWidget(new QLabel("Hello!", &w));
    //w.setCentralWidget(&grid);
    w.setCentralWidget(qw);
    w.show();
    return a.exec();
}
