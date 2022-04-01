#include "stateshistorydeathsendpoint.h"

StatesHistoryDeathsEndpoint::StatesHistoryDeathsEndpoint(QString baseUrl): Endpoint(baseUrl, "states/history/deaths")
{

}

void StatesHistoryDeathsEndpoint::handleReply(QNetworkReply *reply){
    if(reply->error()){
        qDebug() << reply->error();
        startRetryTimer();
        return;
    }

    qDebug() << reply->url();

    QByteArray response = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response);

    StatesHistoryDeathsEndpointData *data = new StatesHistoryDeathsEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
