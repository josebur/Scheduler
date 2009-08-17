#include <QtGui/QApplication>
#include "scheduler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scheduler w;
    w.show();
    return a.exec();
}
