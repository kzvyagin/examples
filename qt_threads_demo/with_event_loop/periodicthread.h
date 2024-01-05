#ifndef PERIODICTHREAD_H
#define PERIODICTHREAD_H
#include "stablethread.h"

template <typename PeriodicWorker>
class PeriodicThread : public StableThread<PeriodicWorker>
{
public:

    explicit PeriodicThread(PeriodicWorker *worker,
                         QObject *parent = nullptr)
        : StableThread<PeriodicWorker>(worker,parent) {
        StableThread<PeriodicWorker>::worker()->moveToThread(this);
        StableThread<PeriodicWorker>::start();
    }

    ~PeriodicThread() {
        restore();
        StableThread<PeriodicWorker>::quit();
        StableThread<PeriodicWorker>::wait();
    }

    void postpone() {
        auto worker = qobject_cast<PeriodicWorker*>(StableThread<PeriodicWorker>::worker());
        if (worker != nullptr) {
            worker->fellAsleep();
        }
    }

    void restore() {
        auto worker = qobject_cast<PeriodicWorker*>(StableThread<PeriodicWorker>::worker());
        if (worker != nullptr) {
            worker->awake();
        }
    }

};

#endif // PERIODICTHREAD_H
