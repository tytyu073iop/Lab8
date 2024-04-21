#include "playlabel.h"
#include <QMouseEvent>

PlayLabel::PlayLabel(size_t & c, QPixmap * i, size_t x, size_t y) : QLabel(), cur(c), imgs(i), x(x), y(y)
{}

void PlayLabel::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // handle left mouse button here
        // qDebug() << "pressed: " << x << " " << y;
        if (!block) {
            this->setPixmap(imgs[cur]);
            cur = (cur == 1) ? 0 : 1 ;
            block = true;
        }
    } else {
        // pass on other buttons to base class
        QLabel::mousePressEvent(event);
    }
}
