#ifndef PLAYLABEL_H
#define PLAYLABEL_H

#include <QLabel>
#include <QPixmap>

class PlayLabel : public QLabel
{
    size_t& cur;
    QPixmap* imgs;
    const size_t x, y;
    bool block = false;
public:
    PlayLabel(size_t&, QPixmap*, size_t x, size_t y);
    void mousePressEvent(QMouseEvent *event);
};

#endif // PLAYLABEL_H
