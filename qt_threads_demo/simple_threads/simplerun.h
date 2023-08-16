#ifndef SIMPLERUN_H
#define SIMPLERUN_H

#include <QObject>
#include <QtConcurrent/QtConcurrentRun>
#include <QFuture>

class SimpleRun: public QObject
{
    Q_OBJECT
public:
    SimpleRun();
    ~SimpleRun();
    void run();

    void job1();
    void job2();
    void job3();
private:
    QThreadPool pool;
    QFuture<void> voidFuture;
    QFuture<QString> stringFuture;
};

#endif // SIMPLERUN_H
