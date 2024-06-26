#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    size_t& cur;
public:
    MainWindow(size_t& cur, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void changeTurn(size_t turn);
    void changeTurnC();
    void win();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
