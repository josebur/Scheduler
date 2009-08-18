#ifndef WORKER_H
#define WORKER_H

#include <QListWidgetItem>

class Worker : public QListWidgetItem
{
    Q_ENUMS(WorkerRoles)
public:
    Worker(QListWidget *view, const QString &name, const QString &shortName,
           const qreal &maxHours = 0.0, const qreal &hours = 0.0);
    ~Worker();

    enum WorkerRoles { NameRole = Qt::UserRole, ShortNameRole, MaxHoursRole, HoursRole };
    void setData(int role, const QVariant &value);
    QVariant data(int role);

private:
    QString m_name;
    QString m_shortName;
    qreal m_maxHours;
    qreal m_hours;
};

#endif // WORKER_H
