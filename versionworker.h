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
    void enableCalcuationBtn(bool);
    void error(QString);
    void finished();

private:


};

#endif // VERSIONWORKER_H
