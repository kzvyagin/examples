#ifndef STABLETASKSERVICE_H
#define STABLETASKSERVICE_H
#include "stablethread.h"
#include "taskworker.h"
#include <QObject>
#include <QVariantHash>

class StableTaskService:  public StableThread<TaskWorker>
{
    Q_OBJECT
public:
    explicit StableTaskService(QObject *parent = nullptr);

signals:
    void sendWorkChank(const QVariantHash &payload);
};


#endif // STABLETASKSERVICE_H
