#include "simplerun.h"
#include <QDebug>

QString functionReturningAString();
void aFunction();


struct RunnableObject
{
    void operator()(QString variable) {
        bool ok=false; digit = variable.toInt(&ok);
        if(!ok)
        digit=0;
    }

    int digit = 42;
    ~RunnableObject()
    {
        qDebug()<<Q_FUNC_INFO<<"Worker RunnableObject deleted.";
    }
};




SimpleRun::SimpleRun()
{

}

SimpleRun::~SimpleRun()
{
    pool.clear(); // instantly terminates all pending jobs, make a shure that all worker will be deleted
}

void SimpleRun::run()
{
    job1();
    job2();
    job3();

    voidFuture.waitForFinished();
    stringFuture.waitForFinished();
}

void SimpleRun::job1()
{

   voidFuture = QtConcurrent::run(&pool, aFunction);
}

void SimpleRun::job2()
{
    stringFuture = QtConcurrent::run(&pool,functionReturningAString);
}

void SimpleRun::job3()
{
    RunnableObject *worker=new RunnableObject;
    QFuture<void>  future=QtConcurrent::run(&pool,std::ref(*worker), QString("15") );
    future.waitForFinished();
    delete  worker; //
}






QString functionReturningAString()
{
    return "MySuperLongSting...";
}

void aFunction()
{
    //log job
    for(int i=0,k=0;i<1000000;i++)
    {
        k+=1;
    }
}

