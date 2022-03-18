#include "versionhandler.h"

VersionHandler::VersionHandler(QObject* parent) : QObject{parent}
{

}

bool VersionHandler::PingService()
{
   VersionSoap11Binding m_service;

   m_service.setEndPoint(versionURL);
   m_service.setSoapVersion(soapVersion);

   NS__GetVersionResponse  resp = m_service.getVersion(NS__GetVersion());

   return resp.return_().startsWith("Hi - the Axis2 version is 1.7.9" );
}
