#include "versionhandler.h"

VersionHandler::VersionHandler(QObject* parent) : QObject{parent}
{

    qDebug() << QThread::currentThread();

}

bool VersionHandler::PingService()
{
   VersionSoap11Binding m_service;

   m_service.setEndPoint("https://loancalcservice.herokuapp.com/services/Version");
   m_service.setSoapVersion(KDSoapClientInterface::SOAP1_1);

   NS__GetVersionResponse  resp = m_service.getVersion(NS__GetVersion());


   return resp.return_().startsWith("Hi - the Axis2 version is 1.7.9" );
}
