#include "vaccinationsendpoint.h"

VaccinationsEndpoint::VaccinationsEndpoint(QString baseUrl): Endpoint(baseUrl, "vaccinations")
{

}

void VaccinationsEndpoint::handleReply(QNetworkReply *reply)
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

    VaccinationsEndpointData *data = new VaccinationsEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
