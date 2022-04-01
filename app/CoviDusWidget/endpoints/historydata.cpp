#include "historydata.h"

HistoryData::HistoryData(double value, QString &date)
{
    this->value = value;
    this->date = QDateTime::fromString(date, "yyyy-MM-ddTHH:mm:ss.zzzZ");
}

HistoryData::HistoryData() :
    value(0.0),
    date(QDateTime::currentDateTime())
{

}

QDataStream &operator<<(QDataStream &out, const HistoryData &data)
{
    out << data.date
        << data.value;
    return out;
}

QDataStream &operator>>(QDataStream &in, HistoryData &data)
{
    data = HistoryData();
    in >> data.date
       >> data.value;
    return in;
}
