

#include "stateshistorydeathsendpointdatainformation.h"

StatesHistoryDeathsEndpointDataInformation::StatesHistoryDeathsEndpointDataInformation(
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

StatesHistoryDeathsEndpointDataInformation::StatesHistoryDeathsEndpointDataInformation() :
    id(),
    state(),
    name(),
    data()
{

}

QDataStream &operator<<(QDataStream &out, const StatesHistoryDeathsEndpointDataInformation &data)
{
    out << data.id
        << data.state
        << data.name
        << data.data;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesHistoryDeathsEndpointDataInformation &data)
{
    data = StatesHistoryDeathsEndpointDataInformation();
    in >> data.id
       >> data.state
       >> data.name
       >> data.data;
    return in;
}
