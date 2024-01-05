#ifndef TASKSERVICE_H
#define TASKSERVICE_H

#include <QObject>
#include <QThread>
#include "taskworker.h"
/**
 * @brief The TaskService class
 *
 *
 *
 *
 *┏━━━━━━━━━━━━━━━━━━━━━━┓      ┏━━━━━━━━━━━━━━━━━━━━━━┓
 *┃  Worker Thread       ┃      ┃     Main thread      ┃          ┌───────┐
 *┃    [QThread]         ┃      ┃    [TaskService]     ┃         ┌───────┐│
 *┃  ╔═══════════════╗   ┃      ┃  ╔═══════════════╗ ┌ ┃←───────┌───────┐│┘
 *┃  ║ QEventLoop ┌↢ ║←──┃──────┃↢─║ QEventLoop    ║←┘ ┃        │ signal│┘
 *┃  ║ ┌──────────┴┐ ║   ┃      ┃  ╚═══════════════╝   ┃        └───────┘
 *┃  ║ │ EventList │ ║   ┃      ┗━━━━━━━━━━━━━━━━━━━━━━┛
 *┃  ║ └──┬──────┬─┘ ║   ┃
 *┃  ║    ↓      ↓   ║   ┃
 *┃  ║ ┌─────┐┌─────┐║   ┃
 *┃  ║ │slotA││slotB│║   ┃
 *┃  ║ └─────┘└─────┘║   ┃
 *┃  ╚═══════════════╝   ┃
 *┗━━━━━━━━━━━━━━━━━━━━━━┛
 *
 *
 *
 *
 */
class TaskService : public QObject
{
    Q_OBJECT
public:
    explicit TaskService(QObject *parent = nullptr);
    ~TaskService();

signals:
    /**
     * @brief taskEvent this signal will be processed in worker thread
     * @param payload json object or variant hash
     */
    void taskEvent(const QVariantHash& payload);
private:
    QThread *wThread;
    TaskWorker * worker;


};

#endif // TASKSERVICE_H
