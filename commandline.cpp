#include "commandline.h"

CommandLine::CommandLine(QObject *parent) : QObject(parent)
{
    this->moveToThread(&mThread);

    connect(&mThread, SIGNAL(started()), this, SLOT(ReadSTDIN()));
    connect(this, SIGNAL(onReadLine(QString)), this, SLOT(HandleSTDIN(QString)));

    mThread.start();

}

void CommandLine::ReadSTDIN()
{

    QTextStream stream(stdin);

    QString Line = stream.readLine();
    emit onReadLine(Line);

    ReadSTDIN();
}

void CommandLine::HandleSTDIN(QString Line)
{
   // qDebug() << Line;

    WriteSTDOUT("You Entered: " + Line + '\n');

}

void CommandLine::WriteSTDOUT(QString Line)
{
    QTextStream stream(stdout);

    stream << Line;

}
