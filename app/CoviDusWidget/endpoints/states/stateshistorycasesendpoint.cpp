#include "stateshistorycasesendpoint.h"

StatesHistoryCasesEndpoint::StatesHistoryCasesEndpoint(QString baseUrl): Endpoint(baseUrl, "states/history/cases")
{

}

void StatesHistoryCasesEndpoint::handleReply(QNetworkReply *reply){
    if(reply->error()){
        qDebug() << reply->error();
        startRetryTimer();
        return;
    }

    qDebug() << reply->url();

    QByteArray response = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response);

    StatesHistoryCasesEndpointData *data = new StatesHistoryCasesEndpointData(json);
    emit dataReceived(data);
    emit signalEndpointFetched();

    reply->deleteLater();
}
