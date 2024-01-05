#include "periodicworker.h"
#include <QDebug>
#include <QThread>
PeriodicWorker::PeriodicWorker(QObject *parent):
    QObject(parent),
    mutex()
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId();
    mutex.lock();
}

PeriodicWorker::~PeriodicWorker()
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId();

  waitMutex.wakeAll();
  mutex.unlock();
}

void PeriodicWorker::awake()
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId();
    waitMutex.wakeAll();
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId();
}

void PeriodicWorker::fellAsleep()
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<<QThread::currentThreadId();
    //QGenericArgument argumentTable[ 1 ];
    //QVariantHash h
    //QMetaObject::invokeMethod(this, &PeriodicWorker::planDoJob , argumentTable[0]);
    QMetaObject::invokeMethod(this, &PeriodicWorker::planDoJob );

    //planDoJob(QVariantHash());
    // acquiring mutex to block the calling thread
    mutex.lock();
    mutex.unlock();
}

//void PeriodicWorker::planDoJob(const QVariantHash &payload)
void PeriodicWorker::planDoJob()
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId()<<"planing...";
    waitMutex.wait(&mutex);
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId()<<"Proceed condition slot";
}
