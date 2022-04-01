#include "stateshistoryrecoveredendpoint.h"

StatesHistoryRecoveredEndpoint::StatesHistoryRecoveredEndpoint(QString baseUrl): Endpoint(baseUrl, "states/history/recovered")
{

}

void StatesHistoryRecoveredEndpoint::handleReply(QNetworkReply *reply){
    if(reply->error()){
        qDebug() << reply->error();
        startRetryTimer();
        return;
    }

    qDebug() << reply->url();

    QByteArray response = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response);

    StatesHistoryRecoveredEndpointData *data = new StatesHistoryRecoveredEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
