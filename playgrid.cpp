#include "playgrid.h"
#include <QDebug>

PlayGrid::PlayGrid(QWidget *parent, size_t s) : QGridLayout(parent)
{
    area = QVector<QVector<size_t>>(s, QVector<size_t>(s, size_t(0)));
}

void PlayGrid::GetCurPlay(long long y, long long x, size_t cur)
{
    qDebug() << "GetCurPlay: " << x << " " << y;
    area[x][y] = cur + 1;
    bool win = false;
    QVector<QWidget*> winItem;
    {
        x -= 2;
        size_t streak = 0;
        for (int i = x; i < x + 5; ++i) {
            try {
                if (area.value(i, QVector<size_t>(area.size()))[y] == cur + 1) {
                    streak++;
                    winItem.push_back(itemAtPosition(i, y)->widget());
                    if (streak >= 3) {
                        qDebug() << "win!";
                    }
                } else {
                    streak = 0;
                    winItem.clear();
                }
            } catch (...) {
                break;
            }
        }
    }
    if (win) {
        qDebug() << "win of: " << (cur == 1 ? "cross" : "circle");
    }
}
