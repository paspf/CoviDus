#include "rdata.h"

RData::RData(double value, const QString& date):
    value(value),
    date(QDateTime::fromString(date, Qt::DateFormat::ISODateWithMs))

{

}

RData::RData()
{

}



QDataStream &operator<<(QDataStream &out, const RData &rData)
{
    out << rData.value << rData.date;
    return out;
}

QDataStream &operator>>(QDataStream &in, RData &rData)
{
    rData = RData();
    in >> rData.value >> rData.date;
    return in;
}
