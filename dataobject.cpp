#include "dataobject.h"

DataObject::DataObject(QString a_user_id, QString a_user_name, QString a_phone_number, QObject *parent) :
    QObject(parent),
    m_user_id(a_user_id),
    m_user_name(a_user_name),
    m_phone_number(a_phone_number)
{
}

void DataObject::set_user_id(QString a_user_id)
{
    m_user_id = a_user_id;
    emit user_id_changed(a_user_id);
}

void DataObject::set_user_name(QString a_user_name)
{
    m_user_name = a_user_name;
    emit user_name_changed(a_user_name);
}

void DataObject::set_phone_number(QString a_phone_number)
{
    m_phone_number = a_phone_number;
    emit phone_number_changed(a_phone_number);
}

QString DataObject::user_id()
{
    return m_user_id;
}

QString DataObject::user_name()
{
    return m_user_name;
}

QString DataObject::phone_number()
{
    return m_phone_number;
}
