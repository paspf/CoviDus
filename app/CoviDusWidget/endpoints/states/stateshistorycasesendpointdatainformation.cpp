#include "stateshistorycasesendpointdatainformation.h"

StatesHistoryCasesEndpointDataInformation::StatesHistoryCasesEndpointDataInformation(
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

StatesHistoryCasesEndpointDataInformation::StatesHistoryCasesEndpointDataInformation() :
    id(),
    state(),
    name(),
    data()
{

}

QDataStream &operator<<(QDataStream &out, const StatesHistoryCasesEndpointDataInformation &data)
{
    out << data.id
        << data.state
        << data.name
        << data.data;
    return out;
}

QDataStream &operator>>(QDataStream &in, StatesHistoryCasesEndpointDataInformation &data)
{
    data = StatesHistoryCasesEndpointDataInformation();
    in >> data.id
       >> data.state
       >> data.name
       >> data.data;
    return in;
}
