#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QByteArray>
#include <QDateTime>
#include <QString>
#include "kanoopcommon.h"

class KANOOP_EXPORT FileUtil
{
public:
    static QString getMD5String(const QString& filename);
    static QByteArray getMD5Bytes(const QString& filename);
    static bool readAllBytes(const QString& filename, QByteArray& data);
    static bool readAllLines(const QString& filename, QStringList& data, QStringConverter::Encoding encoding = QStringConverter::Utf8);
    static bool writeAllBytes(const QString& filename, const QByteArray& data);
    static bool writeAllLines(const QString& filename, const QStringList& lines);
    static bool exists(const QString& filename);
    static bool remove(const QString& filename);
    static bool touch(const QString& filename);
    static bool move(const QString& source, const QString& destination);
    static bool moveToDirectory(const QString& sourceFilename, const QString& destinationDirectory);
    static bool setModifyTime(const QString& filename, const QDateTime& value);
};

#endif // FILEUTIL_H
