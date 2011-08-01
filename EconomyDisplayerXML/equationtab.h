#ifndef EQUATIONTAB_H
#define EQUATIONTAB_H

#include <QWidget>
#include <QMap>
#include "equation.h"

class QLineEdit;


namespace Ui {
    class EquationTab;
}

class EquationTab : public QWidget
{
    Q_OBJECT

public:
    explicit EquationTab(QWidget *parent = 0);
    explicit EquationTab(Equation *eq, QWidget *parent = 0);
    ~EquationTab();

    inline const QList<QLineEdit*> getLineEdits() const{ return m_LineEdits.values();}

private slots:
    void updateFormulaText();    

private:    
    Ui::EquationTab *ui;    
    Equation *m_Equation;
    QMap<QString,QLineEdit*> m_LineEdits;

    void createUi(Equation *eq);
    void setFormulaText();    

};

#endif // EQUATIONTAB_H
