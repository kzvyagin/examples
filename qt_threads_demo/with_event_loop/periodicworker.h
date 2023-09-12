#ifndef PERIODICWORKER_H
#define PERIODICWORKER_H

#include <QObject>
#include <QMutex>
#include <QWaitCondition>

class PeriodicWorker: public QObject
{
    Q_OBJECT
public:
    explicit  PeriodicWorker(QObject *parent = nullptr);
    ~PeriodicWorker();

    /**
    * @brief awake this function restores working process
    *  have to be called from outer thread
    */
    void awake();

    /**
     * @brief fellAsleep this function stops thread activity
     * have to be called from outer thread.
     * the function  would block the caller's thread until -
    * the worker thread is suspended. -
     */
    void fellAsleep();

private slots:
    void metCondition();

private:
   QMutex mutex;
   QWaitCondition waitMutex;

};

#endif // PERIODICWORKER_H
