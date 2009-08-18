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

    m_vertSplitter = new QSplitter(Qt::Vertical, parent);
    m_vertSplitter->addWidget(m_ui->workerList);
    m_vertSplitter->addWidget(m_ui->workerWidget);
    m_mainSplitter = new QSplitter(Qt::Horizontal, parent);
    m_mainSplitter->addWidget(m_vertSplitter);
    m_mainSplitter->addWidget(m_ui->scheduleView);
    setCentralWidget(m_mainSplitter);

    Worker *w1 = new Worker(m_ui->workerList, "Joe Burns", "JB", 20);
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
    settings.setValue("vertSplitter", m_vertSplitter->saveState());
    settings.setValue("mainSplitter", m_mainSplitter->saveState());
    settings.endGroup();
}
