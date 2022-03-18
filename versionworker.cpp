#include "versionworker.h"

VersionWorker::VersionWorker(QObject *parent)
    : QObject{parent}
{


}

void VersionWorker::ping()
{

   VersionHandler versionhandler;
   bool m_callstatus =  versionhandler.PingService();

   emit enableCalcuationBtn(m_callstatus);
}

