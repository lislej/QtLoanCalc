// This file is generated by KDAB's kdwsdl2cpp from LoanCalcVerify.wsdl.
// All changes you do to this file will be lost.
/*
    You may use and relicense this generated file without restriction.
*/
#pragma once

#include <QSharedPointer>
#include <QtCore/QSharedData>
#include <QtCore/QString>
#include <KDSoapClient/KDSoapJob.h>
#include <QtCore/QObject>
#include <KDSoapClient/KDSoapClientInterface.h>

#undef daylight
#undef timezone
class KDSoapMessage;
class KDSoapPendingCallWatcher;
class KDSoapValue;
namespace Version {
    class VersionSoap11Binding;
    class VersionSoap12Binding;
}


class NS__GetVersion
{
public:
    KDSoapValue serialize( const QString& valueName ) const;
    void deserialize( const KDSoapValue& mainValue );
    NS__GetVersion();
    ~NS__GetVersion();

};

class NS__GetVersionResponse
{
public:
    void setReturn( const QString& arg_return_ );
    QString return_() const;
    bool hasValueForReturn() const;
    KDSoapValue serialize( const QString& valueName ) const;
    void deserialize( const KDSoapValue& mainValue );
    NS__GetVersionResponse();
    ~NS__GetVersionResponse();

public:
    NS__GetVersionResponse( const NS__GetVersionResponse& );
    NS__GetVersionResponse &operator=( const NS__GetVersionResponse& );

private:
    class PrivateDPtr;
    QSharedDataPointer<PrivateDPtr> d_ptr;
};

namespace Version {
    namespace VersionSoap11BindingJobs {
        class GetVersionJob : public KDSoapJob
        {
            Q_OBJECT

        public:
            GetVersionJob( Version::VersionSoap11Binding* service, QObject* _parent = nullptr );
            void setParameters( const NS__GetVersion& arg0 );
            NS__GetVersion parameters() const;
            NS__GetVersionResponse resultParameters() const;

        protected:
            virtual void doStart() override;

        private Q_SLOTS:
            void slotFinished( KDSoapPendingCallWatcher* watcher );

        private:
            Version::VersionSoap11Binding *mService;
            NS__GetVersion mParameters;
            NS__GetVersionResponse mResultParameters;
        };
    } // namespace end
} // namespace end

namespace Version {
    namespace VersionSoap12BindingJobs {
        class GetVersionJob : public KDSoapJob
        {
            Q_OBJECT

        public:
            GetVersionJob( Version::VersionSoap12Binding* service, QObject* _parent = nullptr );
            void setParameters( const NS__GetVersion& arg0 );
            NS__GetVersion parameters() const;
            NS__GetVersionResponse resultParameters() const;

        protected:
            virtual void doStart() override;

        private Q_SLOTS:
            void slotFinished( KDSoapPendingCallWatcher* watcher );

        private:
            Version::VersionSoap12Binding *mService;
            NS__GetVersion mParameters;
            NS__GetVersionResponse mResultParameters;
        };
    } // namespace end
} // namespace end

namespace Version {
    class VersionSoap11Binding : public QObject
    {
        Q_OBJECT

    public:
        VersionSoap11Binding( QObject* _parent = nullptr );
        ~VersionSoap11Binding();
        /**
            Asks Qt to ignore ssl errors in https requests. Use this for
            testing only!
         */
        void ignoreSslErrors();
        /**
            Overwrite the end point defined in the .wsdl file, with another
            http/https URL.
         */
        void setEndPoint( const QString& endPoint );
        /**
            Return the end point that will be used.
         */
        QString endPoint() const;
        /**
            Overwrite the soap version defined in the .wsdl file, with another
            version.
            version can be KDSoapClientInterface::SOAP1_1 or
            KDSoapClientInterface::SOAP1_2
         */
        void setSoapVersion( KDSoapClientInterface::SoapVersion soapVersion );
        /**
            Return the soap version used.n
         */
        KDSoapClientInterface::SoapVersion soapVersion() const;
        /**
            Return the fault code from the last blocking call.
            Empty if no error.
         */
        int lastErrorCode() const;
        /**
            Return the fault code from the last blocking call.
            Empty if no error.
         */
        QString lastFaultCode() const;
        /**
            Return the error from the last blocking call.
            Empty if no error.
         */
        QString lastError() const;
        /**
            Returns the underlying KDSoapClientInterface instance, which allows
            to access setCookieJar, lastResponseHeaders, etc.
         */
        const KDSoapClientInterface *clientInterface() const;
        KDSoapClientInterface *clientInterface();
        /**
            Blocking call to getVersion.
            Not recommended in a GUI thread.
         */
        NS__GetVersionResponse getVersion( const NS__GetVersion& parameters = NS__GetVersion() );
        /**
            Asynchronous call to getVersion.
            Remember to connect to getVersionDone and
            getVersionError.
            Deprecated, use GetVersionJob instead.
         */
        void asyncGetVersion( const NS__GetVersion& parameters = NS__GetVersion() );

    Q_SIGNALS:
        /**
            This signal is emitted whenever a SOAP call failed, for a central
            processing of all SOAP errors.
            method is the name of the method (or operation) that returned the
            fault, for instance "addContact".
         */
        void soapError( const QString& method, const KDSoapMessage& fault );
        /**
            This signal is emitted whenever the asynchronous call
            asyncGetVersion() has succeeded.
         */
        void getVersionDone( const NS__GetVersionResponse& parameters );
        /**
            This signal is emitted whenever the asynchronous call
            asyncGetVersion() has failed.
         */
        void getVersionError( const KDSoapMessage& fault );

    private Q_SLOTS:
        void _kd_slotGetVersionFinished( KDSoapPendingCallWatcher* watcher );

    private:
        class PrivateDPtr;
        PrivateDPtr *d_ptr;
    };
} // namespace end

namespace Version {
    class VersionSoap12Binding : public QObject
    {
        Q_OBJECT

    public:
        VersionSoap12Binding( QObject* _parent = nullptr );
        ~VersionSoap12Binding();
        /**
            Asks Qt to ignore ssl errors in https requests. Use this for
            testing only!
         */
        void ignoreSslErrors();
        /**
            Overwrite the end point defined in the .wsdl file, with another
            http/https URL.
         */
        void setEndPoint( const QString& endPoint );
        /**
            Return the end point that will be used.
         */
        QString endPoint() const;
        /**
            Overwrite the soap version defined in the .wsdl file, with another
            version.
            version can be KDSoapClientInterface::SOAP1_1 or
            KDSoapClientInterface::SOAP1_2
         */
        void setSoapVersion( KDSoapClientInterface::SoapVersion soapVersion );
        /**
            Return the soap version used.n
         */
        KDSoapClientInterface::SoapVersion soapVersion() const;
        /**
            Return the fault code from the last blocking call.
            Empty if no error.
         */
        int lastErrorCode() const;
        /**
            Return the fault code from the last blocking call.
            Empty if no error.
         */
        QString lastFaultCode() const;
        /**
            Return the error from the last blocking call.
            Empty if no error.
         */
        QString lastError() const;
        /**
            Returns the underlying KDSoapClientInterface instance, which allows
            to access setCookieJar, lastResponseHeaders, etc.
         */
        const KDSoapClientInterface *clientInterface() const;
        KDSoapClientInterface *clientInterface();
        /**
            Blocking call to getVersion.
            Not recommended in a GUI thread.
         */
        NS__GetVersionResponse getVersion( const NS__GetVersion& parameters = NS__GetVersion() );
        /**
            Asynchronous call to getVersion.
            Remember to connect to getVersionDone and
            getVersionError.
            Deprecated, use GetVersionJob instead.
         */
        void asyncGetVersion( const NS__GetVersion& parameters = NS__GetVersion() );

    Q_SIGNALS:
        /**
            This signal is emitted whenever a SOAP call failed, for a central
            processing of all SOAP errors.
            method is the name of the method (or operation) that returned the
            fault, for instance "addContact".
         */
        void soapError( const QString& method, const KDSoapMessage& fault );
        /**
            This signal is emitted whenever the asynchronous call
            asyncGetVersion() has succeeded.
         */
        void getVersionDone( const NS__GetVersionResponse& parameters );
        /**
            This signal is emitted whenever the asynchronous call
            asyncGetVersion() has failed.
         */
        void getVersionError( const KDSoapMessage& fault );

    private Q_SLOTS:
        void _kd_slotGetVersionFinished( KDSoapPendingCallWatcher* watcher );

    private:
        class PrivateDPtr;
        PrivateDPtr *d_ptr;
    };
} // namespace end
