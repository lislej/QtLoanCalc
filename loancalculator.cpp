#include "loancalculator.h"

LoanCalculator::LoanCalculator()
{


}


//long double loan_amt;
//long double loan_pmt;
//long double int_rate;
//int    loan_trm;

//loan amt
LoanCalculator::LoanCalculator(long double loanpmt, long double rate, int loanterm) :
    loan_pmt(loanpmt), int_rate(rate), loan_trm(loanterm)
{}

//loan pmt
LoanCalculator::LoanCalculator(long double loanamt, int loanterm, long double rate ) :
    loan_amt(loanamt), int_rate(rate), loan_trm(loanterm)
{}

//loan term
LoanCalculator::LoanCalculator(long double loanamt, long double loanpmt, long double rate) :
    loan_amt(loanamt), loan_pmt(loanpmt), int_rate(rate)
{}

//interest rate
LoanCalculator::LoanCalculator(int loanterm, long double loanamt, long double loanpmt) :
    loan_amt(loanamt),loan_pmt(loanpmt), loan_trm(loanterm)
{}

double LoanCalculator::CalcLoanPmt(long double amt, long double rate, int term)
{
    return 0.0;
}

double LoanCalculator::CalcLoanAmt(int term, long double amt, long double pmt)
{
    return 0.0;
}

double LoanCalculator::CalcLoanRate(long double amt, int term, long double pmt)
{
    return 0.0;
}

int LoanCalculator::CalcLoanTerm(long double amt, long double pmt, long double rate)
{
    return 0;
}

