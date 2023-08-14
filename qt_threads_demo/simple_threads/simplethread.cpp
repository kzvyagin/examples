#include "simplethread.h"

SimpleThread::SimpleThread()
{

}

void SimpleThread::run()
{
    uint64_t  longValue=0;
    for(int i=0;i< 100000000; i++){
        longValue+=1;
    }
}
