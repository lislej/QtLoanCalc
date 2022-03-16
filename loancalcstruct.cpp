#include "loancalcstruct.h"

LoanCalcStruct::LoanCalcStruct(QObject* parent)
{

}

LoanCalcStruct::LoanCalcStruct(const LoanCalcStruct &lcstruct)
{
    m_loanamt = lcstruct.m_loanamt;
    m_loanpmt = lcstruct.m_loanpmt;
    m_intrate = lcstruct.m_intrate;
    m_loantrm = lcstruct.m_loantrm;
}

LoanCalcStruct::~LoanCalcStruct()
{

}

void LoanCalcStruct::setLoanAmt(double value)
{
    m_loanamt = value;
}

void LoanCalcStruct::setLoanPmt(double value)
{
    m_loanpmt = value;
}

void LoanCalcStruct::setIntRate(double value)
{
    m_intrate = value;
}

void LoanCalcStruct::setLoanTrm(int value)
{
    m_loantrm = value;
}

double LoanCalcStruct::LoanAmt()
{
    return m_loanamt;
}

double LoanCalcStruct::LoanPmt()
{
    return m_loanpmt;
}

double LoanCalcStruct::IntRate()
{
    return m_intrate;
}

int LoanCalcStruct::LoanTrm()
{
    return m_loantrm;
}
