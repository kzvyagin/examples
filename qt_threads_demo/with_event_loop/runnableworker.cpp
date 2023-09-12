#include "runnableworker.h"
#include <QDebug>
#include <QThread>

void RunnableWorker::RunnableWorker::run()
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId();
    locatEventLoop.exec();
}

void RunnableWorker::endEventLoop()
{
    qDebug()<<Q_FUNC_INFO<<__LINE__<<"threadId:"<<QThread::currentThreadId();
    locatEventLoop.exit();
}
