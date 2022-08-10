#include "amortsched.h"

AmortizationSchedule::AmortizationSchedule(double amt, double pmt, double rte, int trm)
{
    this->loanamt = amt;
    this->loanpmt = pmt;
    this->loanrte = rte;
    this->loantrm = trm;

}

double AmortizationSchedule::totalinterestpaid()
{

    double monthlyintrate = 0.0;
    double totintpaid = 0.0;
    double princpmt = 0.0;
    double balance = this->loanamt;

    for(int x=1; x <= this->loantrm; x++)
    {
        monthlyintrate = round(balance * this->loanrte/(12.0*100.0),3);
        princpmt = round(this->loanpmt - monthlyintrate,3);
        totintpaid += monthlyintrate;
        balance = round(balance - princpmt, 3);
    }

    return totintpaid;
}


void AmortizationSchedule::calcPIB(double& balance, double& principle, double& interest)
{
    double monthlyintrate = this->loanrte / (12.0 * 100.0);
    double payment = round(this->loanpmt, 3);
    principle = 0.0;
    interest = 0.0;


    interest = round(balance * monthlyintrate,3);
    principle = payment - interest;
    principle = round(principle, 3);
    balance = round(balance - principle > 0 ? balance - principle : 0 ,3);

}

QString AmortizationSchedule::createschedule()
{
    QString sched;
    QString header;

    sched += "Month    Payment   Principal    Interest       Balance \n\n";

    double balance = this->loanamt;
    double principle = 0.0;
    double interest = 0.0;
    double totint = 0.0;
    for(int x=1; x <= this->loantrm; x++)
    {
        calcPIB(balance, principle, interest);
        totint += interest;
        sched += "  " + QString().asprintf("%3i", x) + "    " + QString().asprintf("%7.2f", this->loanpmt) + "     " + QString().asprintf("%7.2f", principle) + "     " + QString().asprintf("%7.2f", interest) + "     " + QString().asprintf("%7.2f", balance) + "\n";
    }

    header = "--------------Loan Amortization Schedule--------------\n\n";
    header += "Loan Amount .......:  " + QString().asprintf("%9.3f", this->loanamt) + "\n";
    header += "Loan Payment ......:  " + QString().asprintf("%7.3f", this->loanpmt) + "\n";
    header += "Interest Rate .....:  " + QString().asprintf("%5.3f", this->loanrte) + "\n";
    header += "Loan Term .........:  " + QString().asprintf("%3i", this->loantrm) + "\n";
    header += "Interest Paid .....:  " + QString().asprintf("%9.3f", totint) + "\n\n\n";

    QString schedule(header + sched);

    return schedule;

}
