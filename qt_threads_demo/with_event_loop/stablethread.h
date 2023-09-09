#ifndef STABLETHREAD_H
#define STABLETHREAD_H
#include <QObject>
#include <QThread>

/**
 * This class provides stable treading conception with destructing worker in the worker thread.
 *  It is important for sockets and timers.
 */
template <typename StableWorker>
class StableThread :public  QThread
{

public:
    explicit StableThread(StableWorker *worker,
                         QObject *parent = nullptr)
        : QThread(parent),
          _w(worker) {
        _w->moveToThread(this);
        start();
    }

    ~StableThread() {
        quit();
        wait();
    }

    StableWorker* worker() const {
        return _w;
    }

protected:
    void run() override {
        QThread::run();
        delete _w;
    }

private:
    StableWorker *_w;
};


#endif // STABLETHREAD_H
