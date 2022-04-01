#ifndef LEGENDINFO_H
#define LEGENDINFO_H

#include <QString>
#include <QtNetwork>

class LegendInfo
{
public:
    explicit LegendInfo(QJsonObject legendInfo);
    LegendInfo();
    int minIncidence;
    int maxIncidence;
    QString incidenceRange;
    QString color;
    friend QDataStream &operator<<(QDataStream &out, const LegendInfo &data);
    friend QDataStream &operator>>(QDataStream &in, LegendInfo &data);
};

QDataStream &operator<<(QDataStream &out, const LegendInfo &data);
QDataStream &operator>>(QDataStream &in, LegendInfo &data);

#endif // LEGENDINFO_H
