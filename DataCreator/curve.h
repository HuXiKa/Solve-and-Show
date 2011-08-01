#ifndef CURVE_H
#define CURVE_H

#include <QString>

class Curve
{
public:
    Curve();

    Curve(const QString & name,const QString& formula, const QString& xAxis,const QString& yAxis) :
        m_Name(name),m_Formula(formula),m_XAxis(xAxis),m_YAxis(yAxis){}

    inline const void setName(const QString& name)          { m_Name = name;        }
    inline const void setFormula(const QString& formula)    { m_Formula = formula;  }
    inline const void setXAxis(const QString& xAxis)        { m_XAxis = xAxis;      }
    inline const void setYAxis(const QString& yAxis)        { m_YAxis = yAxis;      }

    inline const QString getName() const        { return m_Name;    }
    inline const QString getFormula() const     { return m_Formula; }
    inline const QString getXAxis() const       { return m_XAxis;   }
    inline const QString getYAxis() const       { return m_YAxis;   }

private:
    QString m_Name;
    QString m_Formula;
    QString m_XAxis;
    QString m_YAxis;
};

#endif // CURVE_H
