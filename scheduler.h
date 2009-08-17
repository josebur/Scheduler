#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QtGui/QMainWindow>

namespace Ui
{
    class Scheduler;
}

class Scheduler : public QMainWindow
{
    Q_OBJECT

public:
    Scheduler(QWidget *parent = 0);
    ~Scheduler();

private:
    Ui::Scheduler *m_ui;
};

#endif // SCHEDULER_H
