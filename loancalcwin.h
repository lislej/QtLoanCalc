#ifndef LOANCALCWIN_H
#define LOANCALCWIN_H

#include <QMainWindow>
#include <QTimer>
#include "loancalcstruct.h"
#include "loancalcservicehandler.h"
#include "loancalcworker.h"
#include "versionworker.h"



QT_BEGIN_NAMESPACE
namespace Ui { class LoanCalcWin; }
QT_END_NAMESPACE

class LoanCalcWin : public QMainWindow
{
    Q_OBJECT

public:
    LoanCalcWin(QWidget *parent = nullptr);
    ~LoanCalcWin();
    void verify_service();
    void report_error(QString);

public slots:
        void update_loancalculator_result(LOANCALCTYPE, LoanCalcStruct*);
        void update_calculate_btn(bool);

private slots:
    void on_rb_loan_amt_clicked();
    void on_rb_loan_amt_toggled();

    void on_rb_loan_pmt_clicked();
    void on_rb_loan_pmt_toggled();

    void on_rb_loan_trm_clicked();
    void on_rb_loan_trm_toggled();

    void on_rb_int_rate_clicked();
    void on_rb_int_rate_toggled();

    void on_pb_calculate_clicked();
    void on_pb_clear_clicked();


private:
    const int SERVICE_CHK_TIME_INTERVAL = 15000;
    Ui::LoanCalcWin* ui;    
    LOANCALCTYPE loancalctype;
    LoanCalcStruct* m_loancalc;
    QTimer* m_timer;
};
#endif // LOANCALCWIN_H
