#ifndef DATETIMEUTIL_H
#define DATETIMEUTIL_H
#include <QDateTime>
#include <QString>

class DateTimeUtil
{
public:
    static QString toISOString(const QDateTime& date) { return date.toString("yyyy-MM-ddThh:mm:ss.zzzZ"); }
    static QString toISOString() { return QDateTime::currentDateTimeUtc().toString("yyyy-MM-ddThh:mm:ss.zzzZ"); }
    static QDateTime fromISOString(const QString& date) { return QDateTime::fromString(date, Qt::DateFormat::ISODateWithMs); }
    static QDateTime fromStandardString(const QString& date) { return QDateTime::fromString(date, "yyyy-MM-dd hh:mm:ss.zzz"); }
    static QDateTime fromString(const QString& date);

    static QString toStandardString(const QDateTime& date) { return date.toString("yyyy-MM-dd hh:mm:ss.zzz"); }
    static QString toStandardString() { return QDateTime::currentDateTimeUtc().toString("yyyy-MM-dd hh:mm:ss.zzz"); }
    static QString toSquashedString() { return QDateTime::currentDateTimeUtc().toString("yyyyMMddhhmmsszzz"); }
    static QString toSquashedString(QDateTime date) { return date.toString("yyyyMMddhhmmsszzz"); }
};

#endif // DATETIMEUTIL_H
