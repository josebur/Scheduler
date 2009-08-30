#include "scheduler.h"
#include "ui_scheduler.h"

#include "worker.h"

#include <QCloseEvent>
#include <QSettings>
#include <QSplitter>

Scheduler::Scheduler(QWidget *parent)
    : QMainWindow(parent), m_ui(new Ui::Scheduler)
{
    m_ui->setupUi(this);

    m_splitter = new QSplitter(Qt::Horizontal, parent);
    m_splitter->addWidget(m_ui->workerList);
    m_splitter->addWidget(m_ui->scheduleView);
    setCentralWidget(m_splitter);

    Worker *w1 = new Worker(m_ui->workerList, "Joe Burns", "JB", 20);
    Worker *w2 = new Worker(m_ui->workerList, "Molly Starratt", "MS", 20, 15.5);
}

Scheduler::~Scheduler()
{
    delete m_ui;
}

void Scheduler::closeEvent(QCloseEvent *event)
{
    writeSettings();
    event->accept();
}

void Scheduler::readSettings()
{

}

void Scheduler::writeSettings()
{
    QSettings settings("SIUE", "Scheduler");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    settings.beginGroup("splitters");
    settings.setValue("splitter", m_splitter->saveState());
    settings.endGroup();
}
