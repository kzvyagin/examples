#ifndef SIMPLERUN_H
#define SIMPLERUN_H

#include <QObject>
#include <QtConcurrent/QtConcurrentRun>
#include <QFuture>


/*
 * This  SimpleRun domonstates sinple usage of threading without eventloop and singal/slot connectivity;
 * This is a part of qt_trads_demo without slot/signals
*/

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
