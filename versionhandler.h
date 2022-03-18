#ifndef VERSIONHANDLER_H
#define VERSIONHANDLER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <wsdl_LoanCalcVerify.h>

using namespace Version;

class VersionHandler : public QObject
{    
    Q_OBJECT

public:
    VersionHandler(QObject *parent = nullptr);
    bool PingService();
    VersionSoap11Binding* versionsoap11binding();

private:   
    const char* versionURL="https://loancalcservice.herokuapp.com/services/Version";
    const KDSoapClientInterface::SoapVersion soapVersion = KDSoapClientInterface::SOAP1_1;

};

#endif // VERSIONHANDLER_H
