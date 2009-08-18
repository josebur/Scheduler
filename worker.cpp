#include "worker.h"

#include <QDebug>
#include <QListWidgetItem>

Worker::Worker(QListWidget *view, const QString &name, const QString &shortName, const qreal &maxHours, const qreal &hours)
    : QListWidgetItem(view, Type)
{
    m_name = name;
    m_shortName = shortName;
    m_maxHours = maxHours;
    m_hours = hours;

    setText(m_name + " (" + m_shortName + ") " + QString::number(m_hours));
}

Worker::~Worker()
{
    qDebug() << "dtor";
}

void Worker::setData(int role, const QVariant &value)
{
    if (role == NameRole) {
        m_name = value.toString();
    }
    else if (role == ShortNameRole) {
        m_shortName = value.toString();
    }
    else if (role == MaxHoursRole) {
        m_maxHours = value.toDouble();
    }
    else if (role == HoursRole) {
        m_hours = value.toDouble();
    }
    else {
        QListWidgetItem::setData(role, value);
    }
}

QVariant Worker::data(int role)
{
    if (role == NameRole) {
        return m_name;
    }
    else if (role == ShortNameRole) {
        return m_shortName;
    }
    else if (role == MaxHoursRole) {
        return m_maxHours;
    }
    else if (role == HoursRole) {
        return m_hours;
    }
    else {
        return QListWidgetItem::data(role);
    }
}
