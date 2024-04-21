#include "mainwindow.h"

#include <QApplication>

#include <QGridLayout>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QPixmap>
#include "playlabel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    size_t cp = 1;
    w.setMenuWidget(new QLabel("cross"));
    QPixmap imgs[]{QPixmap(":/circle.png").scaled(100, 100, Qt::KeepAspectRatio), QPixmap(":/cross.png").scaled(100, 100, Qt::KeepAspectRatio)};
    QWidget* qw = new QWidget();
    auto grid = QGridLayout(qw);
    qDebug() << "begin";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            auto q = new PlayLabel(cp, imgs, i, j);
            QObject::connect(q, &PlayLabel::turnChanged, &w, &MainWindow::changeTurn);
            q->setFrameShape(QFrame::Box);
            q->setScaledContents(true);
            q->show();
            grid.addWidget(q, i, j);
        }
    }
    w.setCentralWidget(qw);
    w.show();
    return a.exec();
}
