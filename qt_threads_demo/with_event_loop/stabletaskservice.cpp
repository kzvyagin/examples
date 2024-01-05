#include "stabletaskservice.h"

StableTaskService::StableTaskService(QObject *parent):
    StableThread<TaskWorker>(new TaskWorker, parent)
{
    QObject::connect(this, &StableTaskService::sendWorkChank,
                     worker(), &TaskWorker::startDoingJob);
}
