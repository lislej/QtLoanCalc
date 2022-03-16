#ifndef LOANCALCSERVICEHANDLER_H
#define LOANCALCSERVICEHANDLER_H

#include <QObject>
#include "wsdl_LoanCalcService.h"
#include "wsdl_LoanCalcVerify.h"

class LoanCalcServiceHandler : public QObject
{
    Q_OBJECT

public:
    LoanCalcServiceHandler(QObject *parent = nullptr);
    void CalculateLoanAmt(const TNS__CalcLoanAmt& parameters);
    void CalculateLoanPmt(const TNS__CalcLoanPmt& parameters);
    void CalculateLoanRate(const TNS__CalcLoanRate& parameters);
    void CalculateLoanTerm(const TNS__CalcLoanTerm& parameters);

    LoanCalcService* loancalcservice();


private:
    LoanCalcService m_service;

};

#endif // LOANCALCSERVICEHANDLER_H
