#ifndef EQUATIONGROUP_H
#define EQUATIONGROUP_H

#include <QMap>
#include <QString>

class Equation;

class EquationGroup
{
public:
    EquationGroup();
    EquationGroup(const QString& name):m_Name(name){}

    inline const QList<Equation*> * getEquations() const    { return &m_Equations;          }
    inline const QString getName() const                    { return m_Name;                }
    inline const int getEquationCount() const               { return m_Equations.size();    }

    inline const void setName(const QString& name)  { m_Name = name; }

    inline void addEquation(Equation* eq)           { m_Equations << eq; }
private:
    QList<Equation*> m_Equations;
    QString m_Unknown;
    QString m_Name;
};

#endif // EQUATIONGROUP_H
