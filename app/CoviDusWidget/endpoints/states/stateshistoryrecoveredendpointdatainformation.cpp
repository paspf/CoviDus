#include "stateshistoryrecoveredendpointdatainformation.h"

StatesHistoryRecoveredEndpointDataInformation::StatesHistoryRecoveredEndpointDataInformation(
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

StatesHistoryRecoveredEndpointDataInformation::StatesHistoryRecoveredEndpointDataInformation() :
    id(),
    state(),
    name(),
    data()
{

}

QDataStream &operator<<(QDataStream &out, const StatesHistoryRecoveredEndpointDataInformation &data)
{
    out << data.id
        << data.state
        << data.name
        << data.data;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesHistoryRecoveredEndpointDataInformation &data)
{
    data = StatesHistoryRecoveredEndpointDataInformation();
    in >> data.id
       >> data.state
       >> data.name
       >> data.data;
    return in;
}
