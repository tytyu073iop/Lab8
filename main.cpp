#include "mainwindow.h"

#include <QApplication>

#include "playgrid.h"
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QPixmap>
#include <QDockWidget>
#include <QToolBar>
#include "playlabel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    size_t cp = 1;
    w.setMenuWidget(new QLabel("cross"));
    QPixmap imgs[]{QPixmap(":/circle.png").scaled(100, 100, Qt::KeepAspectRatio), QPixmap(":/cross.png").scaled(100, 100, Qt::KeepAspectRatio)};
    QWidget* qw = new QWidget();
    auto button = new QPushButton("clear");
    // auto dock = new QDockWidget();
    // dock->setWidget(button);
    // w.addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, dock);
    // auto toolbar = new QToolBar();
    // toolbar->addWidget(button);
    // w.addToolBar(toolbar);
    auto gr = QGridLayout(qw);
    auto grid = PlayGrid();
    gr.addLayout(&grid, 0, 0);
    gr.addWidget(button, 1, 0);
    QObject::connect(&grid, &PlayGrid::winSignal, &w, &MainWindow::win);
    qDebug() << "begin";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            auto q = new PlayLabel(cp, imgs, i, j);
            QObject::connect(q, &PlayLabel::turnChanged, &w, &MainWindow::changeTurn);
            QObject::connect(q, &PlayLabel::CheckWin, &grid, &PlayGrid::GetCurPlay);
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
