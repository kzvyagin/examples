#include <QCoreApplication>
#include "simplerun.h"
#include "simplethread.h"
#include "runnableworker.h"
#include "taskservice.h"
#include "taskworker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
