#include "eventthread.h"
#include <QDebug>

/**
 * @brief EventThread::EventThread
 * Create a new Thread with an event loop.
 * @param parent Parent QObject.
 */
EventThread::EventThread(QObject *parent) :
    QThread(parent)
{

}

/**
 * @brief EventThread::run
 * Run as Thread.
 */
void EventThread::run()
{
    qDebug() << "Thread started: " << currentThreadId();
    exec();
}
