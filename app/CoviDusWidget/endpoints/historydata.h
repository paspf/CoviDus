#ifndef HISTORYDATA_H
#define HISTORYDATA_H

#include<QString>
#include<QDateTime>

class HistoryData
{
public:
    HistoryData(double value, QString &date);
    HistoryData();
    double value;
    QDateTime date;
    friend QDataStream &operator<<(QDataStream &out, const HistoryData &data);
    friend QDataStream &operator>>(QDataStream &in, HistoryData &data);
};

QDataStream &operator<<(QDataStream &out, const HistoryData &data);
QDataStream &operator>>(QDataStream &in, HistoryData &data);

#endif // HISTORYDATA_H
