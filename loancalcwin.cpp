#include "loancalcwin.h"
#include "ui_loancalcwin.h"
#include "amortsched.h"
#include <QLocale>
#include <QDebug>

LoanCalcWin::LoanCalcWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoanCalcWin)
    , m_loancalc(new LoanCalcStruct)
{


    ui->setupUi(this);

    //window attributes - no resize, minimize btn, close btn
    setWindowFlags(Qt::Window |
                   Qt::MSWindowsFixedSizeDialogHint |
                   Qt::WindowMinimizeButtonHint |
                   Qt::WindowCloseButtonHint);

    ui->pb_calculate->setDisabled(true);  //disable calc butten until service is verified
    ui->rb_loan_pmt->setChecked(true);    //default calculation
    ui->le_loan_amt->setFocus();

    //check service availability immediately
    QTimer::singleShot(0, this, &LoanCalcWin::verify_service);

    //setup timer for checking service availability periodically
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, this, &LoanCalcWin::verify_service);
    timer->start(SERVICE_CHK_TIME_INTERVAL);


}

LoanCalcWin::~LoanCalcWin()
{
    delete ui;
    delete m_loancalc;
}

void LoanCalcWin::on_rb_loan_amt_toggled()
{
    qDebug("on_rb_loan_amt_toggled");

    if ( ui->rb_loan_amt->isChecked() )
    {
        qDebug("checked");
        ui->le_loan_amt->setEnabled((false));
    }
    else if ( !ui->rb_loan_amt->isChecked() )
    {
        qDebug("not checked");
        ui->le_loan_amt->setEnabled((true));
    }
}

void LoanCalcWin::on_rb_loan_amt_clicked()
{
    qDebug("on_rb_loan_amt_clicked");

    ui->le_loan_amt->setFocus();

    if ( ui->rb_loan_amt->isChecked() )
    {
        qDebug("checked");
        ui->le_loan_amt->setEnabled((false));
    }
    else if ( !ui->rb_loan_amt->isChecked() )
    {
        qDebug("not checked");
        ui->le_loan_amt->setEnabled((true));
    }
}

void LoanCalcWin::on_rb_loan_pmt_clicked()
{
    ui->le_loan_amt->setFocus();

    if ( !ui->rb_loan_pmt->isChecked())
    {
        ui->le_loan_pmt->setEnabled(true);
    }
    else if (ui->rb_loan_pmt->isChecked())
    {
        ui->le_loan_pmt->setEnabled(false);
    }
}
void LoanCalcWin::on_rb_loan_pmt_toggled()
{
    ui->le_loan_amt->setFocus();

    if ( !ui->rb_loan_pmt->isChecked())
    {
        ui->le_loan_pmt->setEnabled(true);
    }
    else if (ui->rb_loan_pmt->isChecked())
    {
        ui->le_loan_pmt->setEnabled(false);
    }
}

void LoanCalcWin::on_rb_loan_trm_clicked()
{
    ui->le_loan_amt->setFocus();

    if ( !ui->rb_loan_trm->isChecked())
    {
        ui->le_loan_trm->setEnabled(true);
    }
    else if (ui->rb_loan_trm->isChecked())
    {
        ui->le_loan_trm->setEnabled(false);
    }
}

void LoanCalcWin::on_rb_loan_trm_toggled()
{
    ui->le_loan_amt->setFocus();

    if ( !ui->rb_loan_trm->isChecked())
    {
        ui->le_loan_trm->setEnabled(true);
    }
    else if (ui->rb_loan_trm->isChecked())
    {
        ui->le_loan_trm->setEnabled(false);
    }
}

void LoanCalcWin::on_rb_int_rate_clicked()
{
    ui->le_loan_amt->setFocus();

    if (!ui->rb_int_rate->isChecked())
    {
        ui->le_int_rate->setEnabled(true);
    }
    else if (ui->rb_int_rate->isChecked())
    {
        ui->le_int_rate->setEnabled(false);
    }
}

void LoanCalcWin::on_rb_int_rate_toggled()
{
    ui->le_loan_amt->setFocus();

    if (!ui->rb_int_rate->isChecked())
    {
        ui->le_int_rate->setEnabled(true);
    }
    else if (ui->rb_int_rate->isChecked())
    {
        ui->le_int_rate->setEnabled(false);
    }
}


void LoanCalcWin::on_pb_calculate_clicked()
{
    if (ui->rb_int_rate->isChecked())
    {
        this->loancalctype = LOANCALCTYPE::LOANRTE;
        m_loancalc->setLoanAmt(ui->le_loan_amt->text().toDouble());
        m_loancalc->setLoanPmt(ui->le_loan_pmt->text().toDouble());
        m_loancalc->setLoanTrm(ui->le_loan_trm->text().toInt());

    }
    else if (ui->rb_loan_trm->isChecked())
    {
        this->loancalctype = LOANCALCTYPE::LOANTRM;
        m_loancalc->setLoanAmt(ui->le_loan_amt->text().toDouble());
        m_loancalc->setLoanPmt(ui->le_loan_pmt->text().toDouble());
        m_loancalc->setIntRate(ui->le_int_rate->text().toDouble());

    }
    else if (ui->rb_loan_pmt->isChecked())
    {
        this->loancalctype = LOANCALCTYPE::LOANPMT;
        m_loancalc->setLoanAmt(ui->le_loan_amt->text().toDouble());
        m_loancalc->setIntRate(ui->le_int_rate->text().toDouble());
        m_loancalc->setLoanTrm(ui->le_loan_trm->text().toInt());

    }
    else if (ui->rb_loan_amt->isChecked())
    {
        this->loancalctype = LOANCALCTYPE::LOANAMT;
        m_loancalc->setLoanPmt(ui->le_loan_pmt->text().toDouble());
        m_loancalc->setLoanTrm(ui->le_loan_trm->text().toInt());
        m_loancalc->setIntRate(ui->le_int_rate->text().toDouble());

    }


    //create thread, worker object, & connections to make remote service call and cleanup after call
    QThread* loanCalcThread = new QThread;
    LoanCalcWorker *loanCalcWorker = new LoanCalcWorker(loancalctype, m_loancalc);
    loanCalcWorker->moveToThread(loanCalcThread);


    if ( !connect(loanCalcWorker, &LoanCalcWorker::error, this, &LoanCalcWin::report_error))
         qDebug() << "connect(loanCalcWorker, &LoanCalcWorker::error(QString), this, &LoanCalcWin::report_error(QString) failed.";

    if ( !connect(loanCalcThread, &QThread::started, loanCalcWorker, &LoanCalcWorker::calc))
        qDebug() << "connect(workerThread, &QThread::started, workerObject, &LoanCalcWorker::calc) failed.";

    if ( !connect(loanCalcThread, &QThread::finished, loanCalcWorker, &LoanCalcWorker::deleteLater))
        qDebug() << "connect(workerThread, &QThread::finished, workerObject, &LoanCalcWorker::deleteLater failed.";

    if ( !connect(loanCalcWorker, &LoanCalcWorker::doneProcess, loanCalcThread, &QThread::quit))
        qDebug() << "connect(workerObject, &LoanCalcWorker::doneProcess, workerThread, &QThread::quit) failed.";

    if ( !connect(loanCalcWorker, &LoanCalcWorker::doneProcess, loanCalcWorker, &LoanCalcWorker::deleteLater))
        qDebug() << "connect(workerObject, &LoanCalcWorker::doneProcess, workerObject, &LoanCalcWorker::deleteLater) failed.";

    if ( !connect(loanCalcWorker, &LoanCalcWorker::calcResult, this, &LoanCalcWin::update_loancalculator_result, Qt::QueuedConnection))
        qDebug() << "connect(workerObject, &LoanCalcWorker::calcresult, this, &LoanCalcWin::update_loancalculator_result, Qt::QueuedConnection) failed.";

    if ( !connect(loanCalcThread, &QThread::finished, loanCalcThread, &QThread::deleteLater))
        qDebug() << "connect(workerThread, &QThread::finished, workerThread, &QThread::deleteLater) failed.";

    loanCalcThread->start();
}

void LoanCalcWin::update_loancalculator_result(LOANCALCTYPE loancalctype, LoanCalcStruct* loancalcparms)
{

    if (loancalctype == LOANCALCTYPE::LOANAMT)
    {
        QString loanAmt = QString("%1").arg(loancalcparms->LoanAmt());

        ui->le_loan_amt->setText(loanAmt);

    }
    else if (loancalctype == LOANCALCTYPE::LOANPMT)
    {
        QString loanPmt = QString("%1").arg(loancalcparms->LoanPmt());

        ui->le_loan_pmt->setText(loanPmt);
    }
    else if (loancalctype == LOANCALCTYPE::LOANRTE)
    {
        QString loanRte = QString("%1").arg(loancalcparms->IntRate());

        ui->le_int_rate->setText(loanRte);
    }
    else if (loancalctype == LOANCALCTYPE::LOANTRM)
    {
        QString loanTrm = QString("%1").arg(loancalcparms->LoanTrm());

        ui->le_loan_trm->setText(loanTrm);
    }


    //double amt, double pmt, double rte, int trm

    double loan_amt = ui->le_loan_amt->text().toDouble();
    double loan_pmt = ui->le_loan_pmt->text().toDouble();
    int loan_trm = ui->le_loan_trm->text().toDouble();
    double int_rate = ui->le_int_rate->text().toDouble();

    amortsched* as = new amortsched(loan_amt,
                                    loan_pmt,
                                    int_rate,
                                    loan_trm);

    ui->textEdit->setText(as->createschedule());
}

void LoanCalcWin::verify_service()
{
   QThread* versionThread = new QThread(NULL);
   VersionWorker* versionWorker = new VersionWorker(NULL);
   versionWorker->moveToThread(versionThread);

   bool connected = false;
   connected = connect(versionThread, &QThread::started, versionWorker, &VersionWorker::ping);
   if (!connected) qDebug("connect(versionThread, &QThread::started, versionWorker, &VersionWorker::ping)");
   connected = connect(versionThread, &QThread::finished, versionWorker, &VersionWorker::deleteLater);
   if (!connected) qDebug("connect(versionThread, &QThread::finished, versionWorker, &VersionWorker::deleteLater)");
   connected = connect(versionThread, &QThread::finished, versionThread, &QThread::quit);
   if (!connected) qDebug("connect(versionThread, &QThread::finished, versionThread, &VersionWorker::quit)");
   connected = connect(versionWorker, &VersionWorker::updateCalcBtn, this, &LoanCalcWin::update_calculate_btn, Qt::QueuedConnection);
   if (!connected) qDebug("connect(versionWorker, &VersionWorker::ping, this, &LoanCalcWin::update_calculate_btn, Qt::QueuedConnection)");
   connected = connect(versionThread, &QThread::finished, versionThread, &QThread::deleteLater);
   if (!connected) qDebug("connect(versionThread, &QThread::finished, versionThread, &QThread::deleteLater)");

   versionThread->start();
}

void LoanCalcWin::update_calculate_btn(bool service_available)
{
    service_available ? ui->pb_calculate->setDisabled(false): ui->pb_calculate->setDisabled(true);
}



void LoanCalcWin::report_error(QString err_msg)
{
   qDebug() << "Error message - " << err_msg;
}
