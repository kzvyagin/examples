#include "taskworker.h"
#include <QDebug>

TaskWorker::TaskWorker(QObject *parent):workerNumber(workerCounter++)
{

}

void TaskWorker::startDoingJob(const QVariantHash &payload)
{
    qDebug()<<Q_FUNC_INFO<< "Worker " <<workerNumber<<" starts his own job...";
    auto i=payload.constBegin();
    while ( i !=payload.constEnd() ){
        qDebug()<<Q_FUNC_INFO<< "Worker " <<workerNumber
               <<" payloadKey:"<<i.key()
               <<" payloadValue:"<<i.value();

        ++i;
    }
    qDebug()<<Q_FUNC_INFO<< "Worker " <<workerNumber<<" ends his own job...";
}
