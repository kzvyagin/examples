#ifndef PERIODICTASKSERVICE_H
#define PERIODICTASKSERVICE_H

#include <QObject>
#include "periodicthread.h"
#include "periodicworker.h"
#include <QVariantHash>

class PeriodicTaskService: public PeriodicThread<PeriodicWorker>
{
    Q_OBJECT
public:
   explicit PeriodicTaskService(QObject *parent = nullptr);

public:
signals:
    void sendWorkChank();//const QVariantHash &payload

};

void usageExampleOfPeriodicTaskService();

#endif // PERIODICTASKSERVICE_H
