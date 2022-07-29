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

        m_loanattribs->setLoanAmt(round(calcloanamt_resp.loanAmt(),3));

    }
    else if (m_loancalctype == LOANCALCTYPE::LOANTRM)
    {
        TNS__CalcLoanTerm calcloanterm;

        calcloanterm.setLoanAmt(m_loanattribs->LoanAmt());
        calcloanterm.setLoanPmt(m_loanattribs->LoanPmt());
        calcloanterm.setLoanRate(m_loanattribs->IntRate());

        TNS__CalcLoanTermResponse calcloanterm_resp = lch.loancalcservice()->calcLoanTerm(calcloanterm);

        m_loanattribs->setLoanTrm(round(calcloanterm_resp.loanTerm(),3));

    }
    else if (m_loancalctype == LOANCALCTYPE::LOANPMT)
    {

        TNS__CalcLoanPmt calcloanpmt;

        calcloanpmt.setLoanAmt(m_loanattribs->LoanAmt());
        calcloanpmt.setLoanRate(m_loanattribs->IntRate());
        calcloanpmt.setLoanTerm(m_loanattribs->LoanTrm());

        TNS__CalcLoanPmtResponse calcloanpmt_resp =   lch.loancalcservice()->calcLoanPmt(calcloanpmt);

        m_loanattribs->setLoanPmt(round(calcloanpmt_resp.loanPmt(),3));

    }
    else if (m_loancalctype == LOANCALCTYPE::LOANRTE)
    {
        TNS__CalcLoanRate calcloanrate;

        calcloanrate.setLoanAmt(m_loanattribs->LoanAmt());
        calcloanrate.setLoanPmt(m_loanattribs->LoanPmt());
        calcloanrate.setLoanTerm(m_loanattribs->LoanTrm());

        TNS__CalcLoanRateResponse calcloanrate_resp = lch.loancalcservice()->calcLoanRate(calcloanrate);

        m_loanattribs->setIntRate(round(calcloanrate_resp.loanRate(),4));

    }

    emit calcResult(m_loancalctype, m_loanattribs);

}

