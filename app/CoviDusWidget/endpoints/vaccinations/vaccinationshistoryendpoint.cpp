#include "vaccinationshistoryendpoint.h"

VaccinationsHistoryEndpoint::VaccinationsHistoryEndpoint(QString baseUrl): Endpoint(baseUrl, "vaccinations/history")
{

}

void VaccinationsHistoryEndpoint::handleReply(QNetworkReply *reply)
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

    VaccinationsHistoryEndpointData *data = new VaccinationsHistoryEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
