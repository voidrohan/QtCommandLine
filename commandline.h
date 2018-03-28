#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTextStream>

class CommandLine : public QObject
{
    Q_OBJECT
public:
    explicit CommandLine(QObject *parent = 0);

signals:
    void onReadLine(QString Line);

public slots:

    void ReadSTDIN();
    void HandleSTDIN(QString Line);
    void WriteSTDOUT(QString Line);

 private:
    QThread mThread;
};

#endif // COMMANDLINE_H
