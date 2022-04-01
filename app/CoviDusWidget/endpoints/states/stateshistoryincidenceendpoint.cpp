#include "stateshistoryincidenceendpoint.h"

StatesHistoryIncidenceEndpoint::StatesHistoryIncidenceEndpoint(QString baseUrl): Endpoint(baseUrl, "states/history/incidence")
{

}

void StatesHistoryIncidenceEndpoint::handleReply(QNetworkReply *reply){
    if(reply->error()){
        qDebug() << reply->error();
        startRetryTimer();
        return;
    }

    qDebug() << reply->url();

    QByteArray response = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response);

    StatesHistoryIncidenceEndpointData *data = new StatesHistoryIncidenceEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
