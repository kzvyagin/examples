#ifndef SIMPLETHREAD_H
#define SIMPLETHREAD_H

#include <QObject>
#include <QThread>

/**
 * @brief The SimpleThread class Demonstrate simple way to start thread for heavy calcualtions or foe infinity loop
 * without event loop and without slot/signal mechanizm
 */
class SimpleThread: public QThread
{
public:
    SimpleThread();
    /**
     * @brief run put here you heavy calculations that dont neew slot/signals conception
     */
    void run() override;

};

#endif // SIMPLETHREAD_H
