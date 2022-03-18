#include "loancalcworker.h"

LoanCalcWorker::LoanCalcWorker(LOANCALCTYPE loancalctype, LoanCalcStruct* loanattribs)
{

    m_loancalctype = loancalctype;
    m_loanattribs = loanattribs;

}

LoanCalcWorker::~LoanCalcWorker()
{
   delete m_loanattribs;
}

void LoanCalcWorker::calc ()
{

    LoanCalcServiceHandler lch;

    if (m_loancalctype == LOANCALCTYPE::LOANAMT)
    {
        TNS__CalcLoanAmt calcloanamt;

        calcloanamt.setLoanPmt(m_loanattribs->LoanPmt());
        calcloanamt.setLoanRate(m_loanattribs->IntRate());
        calcloanamt.setLoanTerm(m_loanattribs->LoanTrm());

        TNS__CalcLoanAmtResponse calcloanamt_resp = lch.loancalcservice()->calcLoanAmt(calcloanamt);

        m_loanattribs->setLoanAmt(calcloanamt_resp.loanAmt());

    }
    else if (m_loancalctype == LOANCALCTYPE::LOANTRM)
    {
        TNS__CalcLoanTerm calcloanterm;

        calcloanterm.setLoanAmt(m_loanattribs->LoanAmt());
        calcloanterm.setLoanPmt(m_loanattribs->LoanPmt());
        calcloanterm.setLoanRate(m_loanattribs->IntRate());

        TNS__CalcLoanTermResponse calcloanterm_resp = lch.loancalcservice()->calcLoanTerm(calcloanterm);

        m_loanattribs->setLoanTrm(calcloanterm_resp.loanTerm());

    }
    else if (m_loancalctype == LOANCALCTYPE::LOANPMT)
    {

        TNS__CalcLoanPmt calcloanpmt;

        calcloanpmt.setLoanAmt(m_loanattribs->LoanAmt());
        calcloanpmt.setLoanRate(m_loanattribs->IntRate());
        calcloanpmt.setLoanTerm(m_loanattribs->LoanTrm());

        TNS__CalcLoanPmtResponse calcloanpmt_resp =   lch.loancalcservice()->calcLoanPmt(calcloanpmt);

        m_loanattribs->setLoanPmt(calcloanpmt_resp.loanPmt());

    }
    else if (m_loancalctype == LOANCALCTYPE::LOANRTE)
    {
        TNS__CalcLoanRate calcloanrate;

        calcloanrate.setLoanAmt(m_loanattribs->LoanAmt());
        calcloanrate.setLoanPmt(m_loanattribs->LoanPmt());
        calcloanrate.setLoanTerm(m_loanattribs->LoanTrm());

        TNS__CalcLoanRateResponse calcloanrate_resp = lch.loancalcservice()->calcLoanRate(calcloanrate);

        m_loanattribs->setIntRate(calcloanrate_resp.loanRate());

    }

    emit calcResult(m_loancalctype, m_loanattribs);

}

