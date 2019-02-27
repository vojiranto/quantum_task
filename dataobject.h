#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <QObject>

class DataObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString user_id READ user_id WRITE set_user_id NOTIFY user_id_changed)
    Q_PROPERTY(QString user_name READ user_name WRITE set_user_name NOTIFY user_name_changed)
    Q_PROPERTY(QString phone_number READ phone_number WRITE set_phone_number NOTIFY phone_number_changed)
public:
    explicit DataObject(QString a_user_id, QString a_user_name, QString a_phone_number, QObject *parent = nullptr);

    void set_user_id(QString a_user_id);
    void set_user_name(QString a_user_name);
    void set_phone_number(QString a_phone_number);

    QString user_id();
    QString user_name();
    QString phone_number();

signals:
    void user_id_changed(QString a_user_id);
    void user_name_changed(QString a_user_id);
    void phone_number_changed(QString a_user_id);

private:
    QString m_user_id;
    QString m_user_name;
    QString m_phone_number;
};

#endif // DATAOBJECT_H
