#include "scheduler.h"
#include "ui_scheduler.h"

#include "worker.h"

#include <QCloseEvent>
#include <QDebug>
#include <QSettings>
#include <QSplitter>

Scheduler::Scheduler(QWidget *parent)
    : QMainWindow(parent), m_ui(new Ui::Scheduler)
{
    m_ui->setupUi(this);
    m_ui->workerList->setColumnCount(3);
    QStringList headers;
    headers << "Worker" << "Hours" << "Max Hours";
    m_ui->workerList->setHorizontalHeaderLabels(headers);

    m_splitter = new QSplitter(Qt::Horizontal, parent);
    m_splitter->addWidget(m_ui->workerList);
    m_splitter->addWidget(m_ui->scheduleView);
    setCentralWidget(m_splitter);

    Worker *w1 = new Worker("Joe Burns", "JB", 20);
    Worker *w2 = new Worker("Molly Starratt", "MS", 20, 15.5);

    qDebug() << m_ui->workerList->rowCount();
    m_ui->workerList->setItem(0, 0, w1);
    m_ui->workerList->setItem(1, 0, w2);
    qDebug() << m_ui->workerList->rowCount();

    readSettings();

    // menu actions
    connect(m_ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
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

void Scheduler::writeSettings()
{
    QSettings settings;

    if (!isMaximized()) {
        settings.setValue("max", false);
        settings.setValue("geometry", saveGeometry());
    }
    else {
        settings.setValue("max", true);
    }
    settings.setValue("splitterSizes", m_splitter->saveState());
}

void Scheduler::readSettings()
{
    QSettings settings;

   if (settings.value("max", false).toBool()) {
       showMaximized();
   }
   else {
       restoreGeometry(settings.value("geometry").toByteArray());
   }
   m_splitter->restoreState(settings.value("splitterSizes").toByteArray());
}
