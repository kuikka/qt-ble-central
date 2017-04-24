#pragma once

#include <QtCore>
#include <QtDBus/QtDBus>

class QDBusAbstractAdaptor;

static inline QString QUuidToString( const QUuid &uuid )
{
    QByteArray ba = uuid.toRfc4122();
    const char *data = ba.data();
    uint8_t *d = (uint8_t*) data;

    char s[64];
    snprintf(s, sizeof(s),
        "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
        d[0],
        d[1],
        d[2],
        d[3],
        d[4],
        d[5],
        d[6],
        d[7],
        d[8],
        d[9],
        d[10],
        d[11],
        d[12],
        d[13],
        d[14],
        d[15]);

    return QString::fromLatin1( s );
//    241   if (sscanf(string, "%08x-%04hx-%04hx-%04hx-%08x%04hx",
}

class DbusObject : public QObject
{
    Q_OBJECT;

public:
    DbusObject( QObject *parent = nullptr ) : QObject( parent ) {};

    Q_PROPERTY(QString interface READ interface);
    Q_PROPERTY(QString path MEMBER m_path READ path WRITE setPath);
    Q_PROPERTY(QDBusAbstractAdaptor* adaptor MEMBER m_adaptor READ adaptor WRITE setAdaptor);

    QString interface() const
    {
        if (m_adaptor == nullptr)
            return "";
        return m_adaptor->metaObject()->classInfo(0).value();
    };

    void setPath( const QString &path ) { qDebug() << path; m_path = path; };
    QString path() const { qDebug() << "reading path " << m_path; return m_path; };

    void setAdaptor( QDBusAbstractAdaptor *adaptor ) { m_adaptor = adaptor; };
    QDBusAbstractAdaptor* adaptor() const { return m_adaptor; };

    void notifyPropertyChanged( const char *propertyName )
    {
        QDBusMessage signal = QDBusMessage::createSignal(
            path(),
            "org.freedesktop.DBus.Properties",
            "PropertiesChanged");

        signal << interface();

        QVariantMap changedProps;
        changedProps.insert(propertyName, property(propertyName));
        signal << changedProps;
        signal << QStringList();

        QDBusConnection::systemBus().send(signal);
    }


private:
    QString m_path;
    QDBusAbstractAdaptor *m_adaptor;
};

// vim: set shiftwidth=4 expandtab cinoptions=t0,g0,j1,ws,(s,W1:
