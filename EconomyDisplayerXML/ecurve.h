#ifndef ECURVE_H
#define ECURVE_H

#include <QList>

class eDouble;
class QString;
class QLineF;
class QColor;
class CoordinateSystem;
class QScriptValue;

class eCurve
{

public:
    eCurve();
    eCurve(QString name, CoordinateSystem * cs);      
    eCurve(CoordinateSystem * cs, eCurve *curve);
    ~eCurve();

    inline const QString getFormula() const             { return m_Formula;     }
    inline const eDouble * getXAxis() const             { return m_XAxis;       }
    inline const eDouble * getYAxis() const             { return m_YAxis;       }
    inline const QColor * getColor() const              { return m_Color;       }
    inline const QString getName() const                { return m_Name;        }
    inline const QList<QLineF*> * getLines() const      { return &m_Lines;      }
    inline const QList<eDouble*> getVariables() const   { return m_Variables;   }


    inline const void setName(const QString & name)       { m_Name = name;        }
    inline const void setFormula(const QString& formula)  { m_Formula = formula;  }
    inline const void setXAxis(eDouble *xAxis)            { m_XAxis = xAxis;      }
    inline const void setYAxis(eDouble *yAxis)            { m_YAxis = yAxis;      }
    inline const void setContainer(CoordinateSystem *cs)  { m_Container = cs;     }
    inline const void setColor(QColor *color)             { m_Color = color;      }

    void addVariable(eDouble *var)  { m_Variables << var;}


    bool calculateCurve();

private:    
    QString m_Name;
    QString m_Formula;
    const eDouble *m_XAxis;
    const eDouble *m_YAxis;
    
    const QColor *m_Color;
    CoordinateSystem *m_Container;

    QList<QLineF*> m_Lines;
    QList<eDouble*> m_Variables;

    double calculateY(QScriptValue *value, double i);
    
};

#endif // ECURVE_H
