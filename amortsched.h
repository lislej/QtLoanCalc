#ifndef AMORTSCHED_H
#define AMORTSCHED_H

#include <QObject>
#include <QTextEdit>
#include <QDebug>

#include "utils.h"

class AmortizationSchedule
{
public:
    AmortizationSchedule(double amt, double pmt, double rte, int trm);
    QString createschedule();

private:

    double totalinterestpaid();
    void calcPIB(double& balance, double& principle, double& interest);

    double loanamt;
    double loanpmt;
    double loanrte;
    int loantrm;    
//    QTextEdit amortschedule;
};

#endif // AMORTSCHED_H
