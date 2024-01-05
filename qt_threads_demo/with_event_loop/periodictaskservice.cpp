#include "periodictaskservice.h"
#include <QDebug>

PeriodicTaskService::PeriodicTaskService(QObject *parent):
     PeriodicThread<PeriodicWorker>(new PeriodicWorker, parent)
{

    QObject::connect(this, &PeriodicTaskService::sendWorkChank,
                     worker(), &PeriodicWorker::planDoJob); // here is queued connection
}

void usageExampleOfPeriodicTaskService()
{
    QVariantHash a; a.insert("a","a");
    QVariantHash b; b.insert("b","b");
    QVariantHash c; c.insert("c","c");

    PeriodicTaskService s;
    qDebug()<<"send 1";
    s.sendWorkChank(); // Put message into EventLoop
    qDebug()<<"postpone";
    s.postpone();
    qDebug()<<"send 2";
    s.sendWorkChank();
    qDebug()<<"send 3";
    s.sendWorkChank();
    qDebug()<<"restoring...";
    s.restore();
}
