#include "statesagegroupsendpoint.h"

StatesAgeGroupsEndpoint::StatesAgeGroupsEndpoint(QString baseUrl): Endpoint(baseUrl, "states/age-groups")
{

}

void StatesAgeGroupsEndpoint::handleReply(QNetworkReply *reply)
{
    if (reply->error())
    {
        qDebug() << reply->errorString();
        startRetryTimer();
        return;
    }

    qDebug() << reply->url();

    QByteArray response = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response);

    StatesAgeGroupsEndpointData *data = new StatesAgeGroupsEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
