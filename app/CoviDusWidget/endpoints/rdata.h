#ifndef RDATA_H
#define RDATA_H

#include<QString>
#include<QDateTime>

class RData
{
public:
    RData(double value, const QString& date);
    RData();
    double value;
    QDateTime date;
    friend QDataStream &operator<<(QDataStream &out, const RData &rData);
    friend QDataStream &operator>>(QDataStream &in, RData &rData);
};

QDataStream &operator<<(QDataStream &out, const RData &rData);
QDataStream &operator>>(QDataStream &in, RData &rData);

#endif // RDATA_H
