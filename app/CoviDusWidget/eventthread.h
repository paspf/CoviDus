#ifndef EVENTTHREAD_H
#define EVENTTHREAD_H

#include <QThread>

/**
 * @brief The EventThread class
 * Inherits from QThread. Can be used to move QObjects in a separate thread.
 */
class EventThread : public QThread
{
    Q_OBJECT
public:
    EventThread(QObject *parent = nullptr);
    void run() override;
};

#endif // EVENTTHREAD_H
