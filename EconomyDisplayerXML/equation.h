#ifndef EQUATION_H
#define EQUATION_H

#include <QObject>

class eDouble;
class EquationGroup;

class Equation : public QObject
{
    Q_OBJECT
public:
    Equation();
    Equation(const QString & name,const QString& formula, bool isDisplayed) :
        m_Name(name),m_Formula(formula),m_isDisplayed(isDisplayed){ setVariables(); }


    inline const void setName(const QString& name)        { m_Name = name;                         }
    inline const void setDisplayed(const bool displayed)  { m_isDisplayed = displayed;             }
    inline const void setGroup(EquationGroup * group )    { m_Group = group;                       }
    void setFormula(const QString& formula)               { m_Formula = formula;                   }

    inline const QString getName() const                { return m_Name;                            }
    inline const QString getFormula() const             { return m_Formula;                         }
    inline const EquationGroup * getGroup() const       { return m_Group;                           }
    inline const QList<eDouble*> * getVariables() const { return &m_Variables;                      }
    inline const bool getDisplayed() const              { return m_isDisplayed;                     }
    const QString getSubstitutedFormula() const;

    const QString getVariableInfo(const QString& name) const;    

    double solve();        

    void setVariables();

private:
    QString m_Name;
    QString m_Formula;
    bool m_isDisplayed;
    QString m_ScriptFormula;


    QList<eDouble*> m_Variables;
    EquationGroup* m_Group;    

};

#endif // EQUATION_H
