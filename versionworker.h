#ifndef VERSIONWORKER_H
#define VERSIONWORKER_H

#include <QObject>
#include <QThread>
#include "versionhandler.h"

class VersionWorker : public QObject
{
    Q_OBJECT
public:
    explicit VersionWorker(QObject *parent = nullptr);
    ~VersionWorker(){}


public slots:
    void ping();

signals:
    void updateCalcBtn(bool);
    void error();
    void doneProcess();
    void finished();

private:


};

#endif // VERSIONWORKER_H
