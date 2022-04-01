#ifndef DELTADATA_H
#define DELTADATA_H

#include <QDataStream>



class DeltaData
{
public:
    DeltaData(int cases, int deaths, int recovered);
    DeltaData();
    int cases;
    int deaths;
    int recovered;
    friend QDataStream &operator<<(QDataStream &out, const DeltaData &deltaData);
    friend QDataStream &operator>>(QDataStream &in, DeltaData &deltaData);
};

QDataStream &operator<<(QDataStream &out, const DeltaData &deltaData);
QDataStream &operator>>(QDataStream &in, DeltaData &deltaData);

#endif // DELTADATA_H
