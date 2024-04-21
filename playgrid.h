#ifndef PLAYGRID_H
#define PLAYGRID_H
#include <QVector>
#include <QGridLayout>

class PlayGrid : public QGridLayout
{
    Q_OBJECT
    QVector<QVector<size_t>> area;
public:
    PlayGrid(QWidget* parent = nullptr, size_t s = 3);

public slots:
    void GetCurPlay(long long x, long long y, size_t cur);
};

#endif // PLAYGRID_H
