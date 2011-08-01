#include <QString>

#include "edouble.h"

eDouble::eDouble(){}

eDouble::eDouble(double value, const QString & info) :
        m_Value(value), m_Info(info){}


bool eDouble::operator == (const double value) const
{
    return this->m_Value == value;
}

bool eDouble::operator != (const double value) const
{
    return this->m_Value != value;
}

void eDouble::operator = (double value)
{
    setValue(value);
}

double eDouble::operator - (const double value) const
{
    return m_Value - value;
}

double eDouble::operator + (const double value) const
{
    return m_Value + value;
}

double eDouble::operator * (const double value) const
{
    return m_Value * value;
}

double eDouble::operator / (const double value) const
{
    return m_Value / value;
}

double eDouble::operator - (const eDouble edouble) const
{
    return m_Value - edouble.getValue();
}

double eDouble::operator + (const eDouble edouble) const
{
    return m_Value + edouble.getValue();
}

double eDouble::operator * (const eDouble edouble) const
{
    return m_Value * edouble.getValue();
}

double eDouble::operator / (const eDouble edouble) const
{
    return m_Value / edouble.getValue();
}

bool eDouble::operator ==(eDouble edouble) const
{
    return (edouble.getValue() == m_Value && edouble.getName() == m_Name);
}
