#include "taskworker.h"
#include <QDebug>
#include <QThread>

TaskWorker::TaskWorker(QObject *parent):workerNumber(workerCounter++)
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId()<<"Creation of worker "<< workerNumber;
}

TaskWorker::~TaskWorker()
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId()<<"Destriction of worker "<< workerNumber;
}

void TaskWorker::startDoingJob(const QVariantHash &payload)
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId()<< "Worker " <<workerNumber<<" starts his own job...";
    auto i=payload.constBegin();
    while ( i !=payload.constEnd() ){
        qDebug()<<Q_FUNC_INFO<< "Worker " <<workerNumber
               <<" payloadKey:"<<i.key()
              <<" payloadValue:"<<i.value();

        ++i;
    }
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId()<< "Worker " <<workerNumber<<" ends his own job...";
}
