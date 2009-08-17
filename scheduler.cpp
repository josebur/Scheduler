#include "scheduler.h"
#include "ui_scheduler.h"

Scheduler::Scheduler(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Scheduler)
{
    ui->setupUi(this);
}

Scheduler::~Scheduler()
{
    delete ui;
}
