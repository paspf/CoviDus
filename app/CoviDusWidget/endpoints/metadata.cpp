#include "metadata.h"

MetaData::MetaData(QJsonObject meta):
    source(meta["source"].toString()),
    contact(meta["contact"].toString()),
    info(meta["info"].toString()),
    lastUpdate(QDateTime::fromString(meta["lastUpdate"].toString(), Qt::DateFormat::ISODateWithMs)),
    date(QDateTime::fromString(meta["date"].toString(), Qt::DateFormat::ISODateWithMs))
{

}

MetaData::MetaData()
{

}

QDataStream &operator<<(QDataStream &out, const MetaData &data)
{
    out << data.contact
        << data.date
        << data.info
        << data.lastUpdate
        << data.source;
    return out;
}

QDataStream &operator>>(QDataStream &in, MetaData &data)
{
    data = MetaData();
    in >> data.contact
       >> data.date
       >> data.info
       >> data.lastUpdate
       >> data.source;
    return in;
}
