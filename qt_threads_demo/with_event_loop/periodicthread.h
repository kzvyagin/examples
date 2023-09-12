#ifndef PERIODICTHREAD_H
#define PERIODICTHREAD_H
#include "stablethread.h"

template <typename PeriodicWorker>
class PeriodicThread : public StableThread<PeriodicWorker>
{
public:

    ~PeriodicThread() {
        restor();
        StableThread<PeriodicWorker>::quit();
        StableThread<PeriodicWorker>::wait();
    }

    void postpone() {
        auto worker = qobject_cast<PeriodicWorker*>(StableThread<PeriodicWorker>::worker());
        if (worker != nullptr) {
            worker->fellAsleep();
        }
    }

    void restor() {
        auto worker = qobject_cast<PeriodicWorker*>(StableThread<PeriodicWorker>::worker());
        if (worker != nullptr) {
            worker->awake();
        }
    }

};

#endif // PERIODICTHREAD_H
