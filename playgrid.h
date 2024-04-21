#ifndef PLAYGRID_H
#define PLAYGRID_H
#include <QVector>
#include <QGridLayout>

class PlayGrid : public QGridLayout
{
    Q_OBJECT
    QVector<QVector<size_t>> area;
    void win();
    size_t cur;
public:
    PlayGrid(size_t& cur, QWidget* parent = nullptr, size_t s = 3);

signals:
    void winSignal();

public slots:
    void GetCurPlay(long long x, long long y, size_t cur);
    void clear();
};

#endif // PLAYGRID_H
