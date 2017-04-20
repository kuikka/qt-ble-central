#pragma once

#include <QtCore>

class DbusObject : public QObject
{
	Q_OBJECT

public:
	DbusObject( QObject *parent ) : QObject( parent ) {};

	Q_PROPERTY(QString interface MEMBER m_interface READ interface WRITE setInterface);
	Q_PROPERTY(QString path MEMBER m_path READ path WRITE setPath);
	void setInterface( const QString &interface ) { m_interface = interface; };
	void setPath( const QString &path ) { m_path = path; };
	QString interface() const { return m_interface; };
	QString path() const { return m_path; };

private:
	QString m_interface;
	QString m_path;
};
