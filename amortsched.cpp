#include "amortsched.h"

amortsched::amortsched(double amt, double pmt, double rte, int trm)
{
    this->loanamt = amt;
    this->loanpmt = pmt;
    this->loanrte = rte;
    this->loantrm = trm;

}

double amortsched::totalinterestpaid()
{

    double intpmt = 0.0;
    double totintpaid = 0.0;
    double princpmt = 0.0;
    double balance = this->loanamt;
    for(int x=1; x <= this->loantrm; x++)
    {
        intpmt = balance * this->loanrte/(12*100);
        princpmt = this->loanpmt - intpmt;
        totintpaid += intpmt;
        balance -= princpmt;
    }

    return totintpaid;
}

void amortsched::amortization(double& balance, double& principle, double& interest)
{
    qDebug() << "Begin: " << interest << "   " << principle << "   " << balance << "\n";


    principle = 0.0;
    interest = 0.0;

    interest = balance * (this->loanrte/(12*100));
    principle = this->loanpmt - interest;
    balance -= principle;

    qDebug() << "End: " << interest << "   " << principle << "   " << balance << "\n";

}

QString amortsched::createschedule()
{

    QString sched;

    sched = "----------------Loan Amortization Schedule----------------\n\n";
    sched += "Loan Amount .......:  " + QString().asprintf("%9.3f", this->loanamt) + "\n";
    sched += "Loan Payment ......:  " + QString().asprintf("%7.3f", this->loanpmt) + "\n";
    sched += "Interest Rate .....:  " + QString().asprintf("%5.3f", this->loanrte) + "\n";
    sched += "Loan Term .........:  " + QString().asprintf("%3i",this->loantrm) + "\n";
    sched += "Interest Paid .....:  " + QString().asprintf("%9.3f",totalinterestpaid()) + "\n\n\n";


    sched += "Month    Payment   Principal    Interest       Balance \n\n";

    double balance = this->loanamt;
    double principle = 0.0;
    double interest = 0.0;
    for(int x=1; x <= this->loantrm; x++)
    {
        amortization(balance, principle, interest);
        sched += "  " + QString().asprintf("%3i", x) + "    " + QString().asprintf("%7.2f", this->loanpmt) + "     " + QString().asprintf("%7.2f", principle) + "     " + QString().asprintf("%7.2f", interest) + "     " + QString().asprintf("%7.2f", balance) + "\n";
    }


    amortschedule.setFont(QFont("Courier New",9, 11));
    amortschedule.setText(sched);


    return sched;

}
