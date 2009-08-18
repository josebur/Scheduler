#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QtGui/QMainWindow>

class QSplitter;

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

protected:
    void closeEvent(QCloseEvent *event);

private:
    void readSettings();
    void writeSettings();

    Ui::Scheduler *m_ui;
    QSplitter *m_vertSplitter;
    QSplitter *m_mainSplitter;
};

#endif // SCHEDULER_H
