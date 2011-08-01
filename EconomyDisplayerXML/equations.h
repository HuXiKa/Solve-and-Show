#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <QHash>

#include "edouble.h"

class Equations
{
public:
    Equations();
    void addVariable(QString varName, eDouble variable);
    void addConstant(QString constName, eDouble constant);

    void setVariable(QString varName, eDouble variable);
    void setVariable(QString varName, double value);

    void setConstant(QString constName, eDouble constant);
    void setConstant(QString constName, double value);

    eDouble getVariable(QString varName);
    double getVariableValue(QString varName);

    eDouble getConstant(QString constName);
    double getConstantValue(QString constName);

private:
    QHash<QString,eDouble> m_Variables;
    QHash<QString,eDouble> m_Constants;
};

#endif // EQUATIONS_H
