#include <QCoreApplication>
#include "simplerun.h"
#include "simplethread.h"
#include "runnableworker.h"
#include "taskservice.h"
#include "taskworker.h"



 /// next section Pausing and resuming the threads (Periodiacl jobs)
 ///
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    /*
     * For jobs tahr dont' need slot/signal communication, or don't neew EventLoop we can use:
     *  QtConcurrent
     *  inheritage from QTread and override method run for job
     *  inheritage from QRunnable and run throught QThreadPool.
    */

    // TODO place here examples


    /*
     * If we have to use signal/slots and the EventLoop we have to use this construction.
       Inheritag from QObject as a worker and use moved method to instance of QThread.
    */


    // TODO place here example


    return a.exec();
}
