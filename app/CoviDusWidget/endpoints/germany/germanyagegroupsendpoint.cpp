#include "germanyagegroupsendpoint.h"

GermanyAgeGroupsEndpoint::GermanyAgeGroupsEndpoint(QString baseUrl): Endpoint(baseUrl, "germany/age-groups")
{

}

void GermanyAgeGroupsEndpoint::handleReply(QNetworkReply *reply)
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

    GermanyAgeGroupsEndpointData *data = new GermanyAgeGroupsEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
