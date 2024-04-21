#ifndef PLAYLABEL_H
#define PLAYLABEL_H

#include <QLabel>
#include <QPixmap>

class PlayLabel : public QLabel
{
    Q_OBJECT
    size_t& cur;
    QPixmap* imgs;
    const size_t x, y;
    bool block = false;
public:
    PlayLabel(size_t&, QPixmap*, size_t x, size_t y);
    void mousePressEvent(QMouseEvent *event);

signals:
    void turnChanged(size_t turn);
    void CheckWin(long long x, long long y, size_t turn);
};

#endif // PLAYLABEL_H
