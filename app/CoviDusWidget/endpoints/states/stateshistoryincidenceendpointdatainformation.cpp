#include "stateshistoryincidenceendpointdatainformation.h"

StatesHistoryIncidenceEndpointDataInformation::StatesHistoryIncidenceEndpointDataInformation(
        QString &id,
        QString &state,
        QVector<HistoryData> &data
    ):
    id(id),
    state(state),
    name(state),
    data(data)
{

}

StatesHistoryIncidenceEndpointDataInformation::StatesHistoryIncidenceEndpointDataInformation() :
    id(),
    state(),
    name(),
    data()
{

}

QDataStream &operator<<(QDataStream &out, const StatesHistoryIncidenceEndpointDataInformation &data)
{
    out << data.id
        << data.state
        << data.name
        << data.data;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesHistoryIncidenceEndpointDataInformation &data)
{
    data = StatesHistoryIncidenceEndpointDataInformation();
    in >> data.id
       >> data.state
       >> data.name
       >> data.data;
    return in;
}
