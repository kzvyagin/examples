#include "periodictaskservice.h"

PeriodicTaskService::PeriodicTaskService(QObject *parent):
     PeriodicThread<PeriodicWorker>(new PeriodicWorker, parent)
{

    QObject::connect(this, &PeriodicTaskService::sendWorkChank,
                     worker(), &PeriodicWorker::planDoJob);
}

void usageExampleOfPeriodicTaskService()
{
    QVariantHash a; a.insert("a","a");
    QVariantHash b; b.insert("b","b");
    QVariantHash c; c.insert("c","c");
    PeriodicTaskService s;
    emit s.sendWorkChank(a);
    s.postpone();
    emit s.sendWorkChank(b);
    emit s.sendWorkChank(c);
    s.restore();
}
