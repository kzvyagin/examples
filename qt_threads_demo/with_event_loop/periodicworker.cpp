#include "periodicworker.h"
#include <QDebug>

PeriodicWorker::PeriodicWorker(QObject *parent):
    QObject(parent),
    mutex()
{
    mutex.lock();
}

PeriodicWorker::~PeriodicWorker()
{
  waitMutex.wakeAll();
  mutex.unlock();
}

void PeriodicWorker::awake()
{
    waitMutex.wakeAll();
}

void PeriodicWorker::fellAsleep()
{
    QMetaObject::invokeMethod(this, &PeriodicWorker::metCondition);
    // acquiring mutex to block the calling thread
    mutex.lock();
    mutex.unlock();
}

void PeriodicWorker::metCondition()
{
    waitMutex.wait(&mutex);
    qDebug()<<Q_FUNC_INFO<<"Proceed condition slot";
}
