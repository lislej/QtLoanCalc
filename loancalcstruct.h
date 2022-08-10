#ifndef LOANCALCSTRUCT_H
#define LOANCALCSTRUCT_H

#include <QObject>

class LoanCalcStruct : public QObject
{

    Q_OBJECT

public:    

    LoanCalcStruct(QObject* parent=nullptr);
    LoanCalcStruct(const LoanCalcStruct &lcstruct);
    ~LoanCalcStruct();

    void setLoanAmt(double);
    void setLoanPmt(double);
    void setIntRate(double);
    void setLoanTrm(int);
    double LoanAmt();
    double LoanPmt();
    double IntRate();
    int LoanTrm();

private:
    double m_loanamt;
    double m_loanpmt;
    double m_intrate;
    int    m_loantrm;

};


Q_DECLARE_METATYPE(LoanCalcStruct);
Q_DECLARE_METATYPE(LoanCalcStruct*);

#endif // LOANCALCSTRUCT_H
