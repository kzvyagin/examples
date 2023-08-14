#include "runnableworker.h"


void RunnableWorker::RunnableWorker::run() {
    locatEventLoop.exec();
}

void RunnableWorker::endEventLoop() {
    locatEventLoop.exit();
}
