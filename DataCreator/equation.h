#ifndef EQUATION_H
#define EQUATION_H

#include <QString>
class Variable;

class Equation
{
public:
    Equation();
    Equation(const QString & name,const QString& formula, bool isDisplayed) :
        m_Name(name),m_Formula(formula),m_isDisplayed(isDisplayed){}

    inline const void setName(const QString& name)          { m_Name = name;                }
    inline const void setFormula(const QString& formula)    { m_Formula = formula;          }
    inline const void setDisplayed(const bool displayed)    { m_isDisplayed = displayed;    }

    inline const QString getName() const        { return m_Name;        }
    inline const QString getFormula() const     { return m_Formula;     }
    inline const bool getDisplayed() const      { return m_isDisplayed; }
private:
    QString m_Name;
    QString m_Formula;
    bool m_isDisplayed;
};

#endif // EQUATION_H
