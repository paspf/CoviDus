#ifndef METADATA_H
#define METADATA_H

#include <QtNetwork>

class MetaData
{
public:
    explicit MetaData(QJsonObject meta);
    MetaData();
    QString source;
    QString contact;
    QString info;
    QDateTime lastUpdate;
    QDateTime date;
    friend QDataStream &operator<<(QDataStream &out, const MetaData &data);
    friend QDataStream &operator>>(QDataStream &in, MetaData &data);
};

QDataStream &operator<<(QDataStream &out, const MetaData &data);
QDataStream &operator>>(QDataStream &in, MetaData &data);

#endif // METADATA_H
