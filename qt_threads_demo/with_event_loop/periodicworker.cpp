#include "periodicworker.h"

PeriodicWorker::PeriodicWorker(QObject *parent):
    QObject(parent),
    treadLock()
{
    treadLock.lock();
}

PeriodicWorker::~PeriodicWorker()
{
  condition.wakeAll();
  treadLock.unlock();
}

void PeriodicWorker::awake()
{
    condition.wakeAll();
}

void PeriodicWorker::fellAsleep()
{
    QMetaObject::invokeMethod(this, &PeriodicWorker::metCondition);
    // acquiring mutex to block the calling thread
    treadLock.lock();
    treadLock.unlock();
}

void PeriodicWorker::metCondition()
{
    condition.wait(&treadLock);
}
