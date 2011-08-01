#ifndef EDOUBLE_H
#define EDOUBLE_H

class QString;

class eDouble
{

public:
    eDouble();
    eDouble(double value, const QString &info);
    eDouble(const QString & name, double value, QString info):
        m_Name(name),m_Value(value),m_Info(info){}

    inline const void setName(const QString& name){ m_Name = name;    }
    inline const void setValue(const double value){ m_Value = value;  }
    inline const void setInfo(const QString &info){ m_Info = info;    }

    inline const QString & getName() const  { return m_Name;    }
    inline const double getValue() const    { return m_Value;   }
    inline const QString getInfo() const    { return m_Info;    }

    bool operator == (const double) const;
    bool operator != (const double) const;
    void operator = (double);

    double operator - (const double) const;
    double operator + (const double) const;
    double operator * (const double) const;
    double operator / (const double) const;

    double operator - (const eDouble) const;
    double operator + (const eDouble) const;
    double operator * (const eDouble) const;
    double operator / (const eDouble) const;    

    bool operator == (const eDouble) const;

private:
    QString m_Name;
    double m_Value;
    QString m_Info;
};

#endif // EDOUBLE_H
