#ifndef KLOG_H
#define KLOG_H

#include <QByteArray>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>

class KLog
{
public:
    enum LogLevel
    {
        Always		= 0,
        Debug 		= 1,
        Info		= 2,
        Warning		= 3,
        Error		= 4,
        Fatal		= 5,
        Nothing		= 6
    };

    enum OutputFlags
    {
        None                        = 0x00000000,
        LineNumbers                 = 0x00000001,
        Timestamp                   = 0x00000002,
        Level                       = 0x00000004,
        Console                     = 0x00001000,
        File                        = 0x00002000,
        Marker                      = 0x00004000,
        QDebug                      = 0x00008000,

        Standard = LineNumbers | Timestamp | Level | Console
    };

    KLog();

    static void sysLogText(const char* file, int line, LogLevel level, const char* format, ...);
    static void sysLogText(const char* file, int line, LogLevel level, const QString& output);
    static void sysLogHex(const unsigned char *data, int count);
    static void sysLogHex(const char *data, int count) { sysLogHex(reinterpret_cast<const unsigned char*>(data), count); }
    static void sysLogHex(QByteArray &data) { sysLogHex(reinterpret_cast<const unsigned char*>(data.constData()), data.length()); }
    static void setSystemLogFile(const QString& fileName);

    static void setSystemOutputFlags(OutputFlags flags) { systemLog()->setOutputFlags(flags); };
    static OutputFlags systemOutputFlags() { return systemLog()->outputFlags(); };

    static int systemVerbosity() { return systemLog()->_verbosity; }
    static void setSystemVerbosity(int value) { systemLog()->_verbosity = value; }

    void logText(const char *file, int line, KLog::LogLevel level, const char *format...);
    void setLogFile(const QString& fileName);

    int verbosity() const { return _verbosity; }
    void setVerbosity(int value) { _verbosity = value; }

    void setOutputFlags(OutputFlags flags) { _outputFlags = flags; }
    OutputFlags outputFlags() const { return _outputFlags; };

private:
    OutputFlags _outputFlags;
    LogLevel _level;
    QTextStream _stdout;
    QTextStream* _fileOutputStream;
    QString _fileName;
    QFile* _file;
    int _verbosity;

    void outputToDestinations(QString text);
    void writeTimestamp(QTextStream &output);

    static void openSystemLog();

    static const char* _levelStrings[];

    static KLog* _systemLog;
    static OutputFlags _defaultOutputFlags;
    static LogLevel _defaultLogLevel;

    static KLog* systemLog();
};

#define KLOG_DEBUG      __FILE__,__LINE__,KLog::LogLevel::Debug
#define KLOG_INFO       __FILE__,__LINE__,KLog::LogLevel::Info
#define KLOG_WARNING    __FILE__,__LINE__,KLog::LogLevel::Warning
#define KLOG_ERROR      __FILE__,__LINE__,KLog::LogLevel::Error
#define KLOG_FATAL      __FILE__,__LINE__,KLog::LogLevel::Fatal
#define LLOG_ALWAYS     __FILE__,__LINE__,KLog::LogLevel::Always

#endif // KLOG_H
