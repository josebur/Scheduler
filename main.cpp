#include <QtGui/QApplication>
#include "scheduler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("SIUE");
    a.setApplicationName("Scheduler");
    Scheduler w;
    w.show();
    return a.exec();
}
