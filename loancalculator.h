#ifndef LOANCALCULATOR_H
#define LOANCALCULATOR_H


class LoanCalculator
{
public:
    LoanCalculator();
    LoanCalculator(long double pmt, long double rate, int term);    //loan amt
    LoanCalculator(long double amt, int term, long double rate );   //loan pmt
    LoanCalculator(long double amt, long double pmt, long double rate);  //loan term
    LoanCalculator(int term, long double amt, long double pmt);     //interest rate

    double CalcLoanPmt(long double amt, long double rate, int term);
    double CalcLoanAmt(int term, long double amt, long double pmt);
    double CalcLoanRate(long double amt, int term, long double pmt);
    int CalcLoanTerm(long double amt, long double pmt, long double rate);

private:
    long double loan_amt;
    long double loan_pmt;
    long double int_rate;
    int    loan_trm;

};

#endif // LOANCALCULATOR_H
