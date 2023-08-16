#include "taskservice.h"

TaskService::TaskService(QObject *parent)
    : QObject{parent}
{
    wThread=  new QThread(this);
    worker = new TaskWorker;
    worker->moveToThread(wThread);
    connect(this,&TaskService::taskEvent, worker,&TaskWorker::startDoingJob);
    connect(wThread,&QThread::finished, worker,&QObject::deleteLater);
    wThread->start();
}

TaskService::~TaskService()
{
    wThread->quit();
    wThread->wait();
}
