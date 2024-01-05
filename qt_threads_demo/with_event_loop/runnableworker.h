#ifndef RUNNABLEWORKER_H
#define RUNNABLEWORKER_H

#include <QRunnable>
#include <QObject>
#include <QEventLoop>
/**
 * RunnableWorker is an independent class implements thread with event loop.
 *
 *┏━━━━━━━━━━━━━━━━━━━━━━┓
 *┃  QThread [QRunnable] ┃          ┌───────┐
 *┃                      ┃         ┌───────┐│
 *┃  ╔═══════════════╗ ┌ ┃←───────┌───────┐│┘
 *┃  ║ QEventLoop ┌↢ ║←┘ ┃        │ signal│┘
 *┃  ║ ┌──────────┴┐ ║   ┃        └───────┘
 *┃  ║ │ EventList │ ║   ┃
 *┃  ║ └──┬──────┬─┘ ║   ┃
 *┃  ║    ↓      ↓   ║   ┃
 *┃  ║ ┌─────┐┌─────┐║   ┃
 *┃  ║ │slotA││slotB│║   ┃
 *┃  ║ └─────┘└─────┘║   ┃
 *┃  ╚═══════════════╝   ┃
 *┗━━━━━━━━━━━━━━━━━━━━━━┛

*/
class RunnableWorker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    /**
     * @brief run Main loop function, start EventLoop manualy, and exit.
     * EventLoop unblock signal/slot cannetivety beetween RunnableWorker
     * and other threads.
     */
    void run() override;
public slots:
    /**
     * @brief FinishTask slot to terminate RunnableObject
     * we have to call endEventLoop slot from
     * other task thought signal or manualy befour we delete object.
     * If we delete RunnableWorker with out calling endEventLoop, thread will be blocked.
     */
    void endEventLoop();

private:
    QEventLoop locatEventLoop;
};




#endif // RUNNABLEWORKER_H
