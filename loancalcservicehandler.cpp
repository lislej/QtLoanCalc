#include "loancalcservicehandler.h"

LoanCalcServiceHandler::LoanCalcServiceHandler(QObject *parent)
{
    m_service.setEndPoint("https://loancalcservice.herokuapp.com/services/LoanCalcService");
    m_service.setSoapVersion(KDSoapClientInterface::SOAP1_1);
}


void LoanCalcServiceHandler::CalculateLoanAmt(const TNS__CalcLoanAmt& params)
{
    m_service.calcLoanAmt(params);
}

void LoanCalcServiceHandler::CalculateLoanPmt(const TNS__CalcLoanPmt& params)
{
    m_service.calcLoanPmt(params);
}

void LoanCalcServiceHandler::CalculateLoanRate(const TNS__CalcLoanRate& params)
{
   m_service.calcLoanRate(params);
}

void LoanCalcServiceHandler::CalculateLoanTerm(const TNS__CalcLoanTerm& params)
{
   m_service.calcLoanTerm(params);
}

LoanCalcService* LoanCalcServiceHandler::loancalcservice()
{
    return &m_service;
}



