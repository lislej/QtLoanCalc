
#include <QApplication>
#include "loancalcwin.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qRegisterMetaType<LoanCalcStruct>();
    qRegisterMetaType<LoanCalcStruct*>();
    qRegisterMetaType<LOANCALCTYPE>();


    LoanCalcWin lcwin;
    lcwin.setWindowTitle("Loan Amortization Calculator");
    lcwin.show();
    return app.exec();
}
