#ifndef TASKWORKER_H
#define TASKWORKER_H

#include <QObject>
/**
 * @brief The TaskWorker class
 * Implements class for douing some usefull job that will be moved to thread
 */

static int workerCounter=0;

class TaskWorker: public QObject
{
    Q_OBJECT
public:
    TaskWorker(QObject *parent = nullptr);

public slots:
    /**
     * @brief startDoingJob slot that starts a job
     * @param payload - usefull payload as QVatintHash structure
     *
     */
    void startDoingJob(const QVariantHash &payload);
private:
    int workerNumber;
};

#endif // TASKWORKER_H
