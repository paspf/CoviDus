#include "deltadata.h"

DeltaData::DeltaData(int cases, int deaths, int recovered):
    cases(cases),
    deaths(deaths),
    recovered(recovered)
{

}

DeltaData::DeltaData() :
    cases(0),
    deaths(0),
    recovered(0)
{

}

QDataStream &operator<<(QDataStream &out, const DeltaData &deltaData)
{
    out << deltaData.cases << deltaData.deaths << deltaData.recovered;
    return out;
}

QDataStream &operator>>(QDataStream &in, DeltaData &deltaData)
{
    deltaData = DeltaData();
    in >> deltaData.cases >> deltaData.deaths >> deltaData.recovered;
    return in;
}
