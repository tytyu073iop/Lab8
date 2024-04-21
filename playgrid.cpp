#include "playgrid.h"
#include <QDebug>
#include <QLabel>

PlayGrid::PlayGrid(QWidget *parent, size_t s) : QGridLayout(parent)
{
    area = QVector<QVector<size_t>>(s, QVector<size_t>(s, size_t(0)));
}

void Colorify(const QVector<QWidget*>& winItem) {
    for (auto i : winItem) {
        auto q = static_cast<QLabel*>(i);
        q->setStyleSheet("QLabel { background-color : green; }");
    }
}

void PlayGrid::GetCurPlay(long long y, long long x, size_t cur)
{
    qDebug() << "GetCurPlay: " << x << " " << y;
    area[x][y] = cur + 1;
    auto xb = x;
    auto yb = y;
   //bool win = false;
    QVector<QWidget*> winItem;
    {
        x -= 2;
        size_t streak = 0;
        for (int i = x; i < x + 5; ++i) {
            if (area.value(i, QVector<size_t>(area.size()))[y] == cur + 1) {
                streak++;
                winItem.push_back(itemAtPosition(y, i)->widget());
                if (streak >= 3) {
                    //qDebug() << "win!";
                    Colorify(winItem);
                    return;
                }
            } else {
                streak = 0;
                winItem.clear();
            }
        }
        y -= 2;
        x = xb;
        winItem.clear();
        for (int i = y; i < y + 5; ++i) {
            if (area[x].value(i, 0) == cur + 1) {
                streak++;
                winItem.push_back(itemAtPosition(i, x)->widget());
                if (streak >= 3) {
                    //qDebug() << "win!";
                    Colorify(winItem);
                    return;
                }
            } else {
                streak = 0;
                winItem.clear();
            }
        }
        y = yb;
        winItem.clear();
        for (int i = -2; i < 3; ++i) {
            if (area.value(x + i, QVector<size_t>(area.size())).value(y + i, 0) == cur + 1) {
                streak++;
                winItem.push_back(itemAtPosition(y + i, x + i)->widget());
                if (streak >= 3) {
                    //qDebug() << "win!";
                    Colorify(winItem);
                    return;
                }
            } else {
                streak = 0;
                winItem.clear();
            }
        }
        winItem.clear();
        for (int i = -2; i < 3; ++i) {
            if (area.value(x + i, QVector<size_t>(area.size())).value(y - i, 0) == cur + 1) {
                streak++;
                winItem.push_back(itemAtPosition(y - i, x + i)->widget());
                if (streak >= 3) {
                    //qDebug() << "win!";
                    Colorify(winItem);
                    return;
                }
            } else {
                streak = 0;
                winItem.clear();
            }
        }
    }
}
