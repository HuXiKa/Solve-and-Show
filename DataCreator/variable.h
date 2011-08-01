#ifndef VARIABLE_H
#define VARIABLE_H

#include <QString>

class Variable
{
public:
    Variable();
    Variable(QString name, double value, QString info):m_Name(name),m_Value(value),m_Info(info){}

    inline const void setName(const QString & name) { m_Name = name;    }
    inline const void setValue(const double value)  { m_Value = value;  }
    inline const void setInfo(const QString & info) { m_Info = info;    }

    inline const QString getName() const { return m_Name;   }
    inline const double getValue() const { return m_Value;  }
    inline const QString getInfo() const { return m_Info;   }

private:
    QString m_Name;
    double m_Value;
    QString m_Info;
};

#endif // VARIABLE_H
