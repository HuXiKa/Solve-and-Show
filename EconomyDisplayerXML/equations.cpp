#include "equations.h"

Equations::Equations()
{
}

void Equations::addVariable(QString varName, eDouble variable)
{
    m_Variables[varName] = variable;
}

void Equations::addConstant(QString constName, eDouble constant)
{
    m_Constants[constName] = constant;
}

void Equations::setVariable(QString varName, eDouble variable)
{
    m_Variables[varName] = variable;
}

void Equations::setVariable(QString varName, double value)
{
    QString info = m_Variables[varName].getInfo();
    m_Variables[varName] = eDouble(value,info);
}

void Equations::setConstant(QString constName, eDouble constant)
{
    m_Constants[constName] = constant;
}

void Equations::setConstant(QString constName, double value)
{
    QString info = m_Constants[constName].getInfo();
    m_Constants[constName] = eDouble(value,info);
}

eDouble Equations::getVariable(QString varName)
{
    return m_Variables[varName];
}

double Equations::getVariableValue(QString varName){
    return m_Variables[varName].getValue();
}

eDouble Equations::getConstant(QString constName)
{
    return m_Constants[constName];
}

double Equations::getConstantValue(QString constName)
{
    return m_Constants[constName].getValue();
}
