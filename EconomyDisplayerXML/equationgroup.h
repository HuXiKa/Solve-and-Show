#ifndef EQUATIONGROUP_H
#define EQUATIONGROUP_H

#include <QMap>
#include <QString>

class eDouble;
class Equation;

class EquationGroup
{
public:
    EquationGroup();
    ~EquationGroup();

    inline const QString getName() const                       { return m_Name;         }
    inline const QMap<QString,Equation*> *getEquations() const { return &m_Equations;   }

    inline const void setName(const QString& name){ m_Name = name;}

    void addEquation(const QString& key, Equation* eq){ m_Equations.insert(key,eq);}
    void addUnKnown(eDouble* unKnown){ m_UnKnowns << unKnown; }

    bool isInstantSolvable(){ return m_UnKnowns.size() == 1; }
    void checkUnKnows();

    const QList<eDouble*> * getUnKnowns() const { return &m_UnKnowns; }
    bool solveLinearSystem(EquationGroup* otherEquationGroup);

private:
    QMap<QString,Equation*> m_Equations; // kulcs: egyenlet bal oldala 'Y' = (M * V / Y)    
    QString m_Name;
    QList<eDouble*> m_UnKnowns;
};

#endif // EQUATIONGROUP_H
