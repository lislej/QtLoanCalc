#ifndef LOANCALCWORKER_H
#define LOANCALCWORKER_H

#include <QObject>
#include <QThread>
#include "wsdl_LoanCalcService.h"
#include "loancalcservicehandler.h"
#include "loancalcstruct.h"

enum class LOANCALCTYPE{ LOANAMT, LOANPMT, LOANTRM, LOANRTE};

class LoanCalcWorker : public QObject
{
    Q_OBJECT

public:
    explicit LoanCalcWorker(QObject* parent = nullptr);
    explicit LoanCalcWorker(LOANCALCTYPE, LoanCalcStruct*);
    ~LoanCalcWorker();

public slots:
    void calc();

signals:

    void calcResult(LOANCALCTYPE, LoanCalcStruct*);
    void error(QString);    
    void finished();


private:
    LOANCALCTYPE m_loancalctype;
    LoanCalcStruct* m_loanattribs;

};

Q_DECLARE_METATYPE(LOANCALCTYPE)

#endif // LOANCALCWORKER_H
