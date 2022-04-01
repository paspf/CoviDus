#include "legendinfo.h"
#include <limits.h>

LegendInfo::LegendInfo(QJsonObject legendInfo):
    minIncidence(legendInfo["min"].toInt()),
    maxIncidence(legendInfo["max"].toInt() < minIncidence ? INT_MAX : legendInfo["max"].toInt()),
    incidenceRange(legendInfo["max"].isNull() ? "> " + QString::number(minIncidence) : QString::number(minIncidence) + " - " + QString::number(maxIncidence)),
    color(legendInfo["color"].toString())
{

}

LegendInfo::LegendInfo():
    minIncidence(),
    maxIncidence(),
    incidenceRange(),
    color()
{

}

QDataStream &operator<<(QDataStream &out, const LegendInfo &data)
{
    out << data.minIncidence
        << data.maxIncidence
        << data.incidenceRange
        << data.color;
    return out;
}

QDataStream &operator>>(QDataStream &in, LegendInfo &data)
{
    data = LegendInfo();
    in >> data.minIncidence
       >> data.maxIncidence
       >> data.incidenceRange
       >> data.color;
    return in;
}
