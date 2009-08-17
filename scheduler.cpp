#include "scheduler.h"
#include "ui_scheduler.h"

#include <QSplitter>

Scheduler::Scheduler(QWidget *parent)
    : QMainWindow(parent), m_ui(new Ui::Scheduler)
{
    m_ui->setupUi(this);

    QSplitter *vertSplitter = new QSplitter(Qt::Vertical, parent);
    vertSplitter->addWidget(m_ui->workerList);
    vertSplitter->addWidget(m_ui->workerWidget);
    QSplitter *mainSplitter = new QSplitter(Qt::Horizontal, parent);
    mainSplitter->addWidget(vertSplitter);
    mainSplitter->addWidget(m_ui->scheduleView);
    setCentralWidget(mainSplitter);
}

Scheduler::~Scheduler()
{
    delete m_ui;
}
