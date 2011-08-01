#include <QString>
#include <QStringList>
#include <QPointF>
#include <QLineF>
#include <QMessageBox>
#include <QScriptEngine>


#include "edouble.h"
#include "ecurve.h"
#include "coordinatesystem.h"
#include "abbrevations.h"


eCurve::eCurve()
{
    QColor *color = new QColor;
    color->setRed(qrand() % 156);
    color->setGreen(qrand() % 256);
    color->setBlue(qrand() % 256);
    m_Color = color;

}

eCurve::eCurve(QString name, CoordinateSystem * cs) :
    m_Name(name), m_Container(cs)
{    
    QColor *color = new QColor;
    color->setRed(qrand() % 156);
    color->setGreen(qrand() % 256);
    color->setBlue(qrand() % 256);
    m_Color = color;   
}

eCurve::eCurve(CoordinateSystem *cs, eCurve *curve)
{
    m_Name = "új " + curve->getName();
    m_Formula = curve->getFormula();
    m_XAxis = curve->getXAxis();
    m_YAxis = curve->getYAxis();
    m_Container = cs;
    m_Variables << curve->getVariables();

    QColor *color = new QColor;
    color->setRed(qrand() % 156);
    color->setGreen(qrand() % 256);
    color->setBlue(qrand() % 256);
    m_Color = color;
}

bool eCurve::calculateCurve()
{
    QStringList missing;
    bool isMissing = false;
    foreach(eDouble * var, m_Variables){
        if(var->getValue() == abbrevations::noValue){
            missing << var->getInfo();
            isMissing = true;
        }
    }
    if(isMissing){
        QMessageBox msgBox;
        msgBox.setText("Figyelem! A(z) " + m_Name + " egyenes ábrázolásához kevés adat" +
                       + " áll rendelkezésre! A hiányzó adatok: \n");

        foreach(QString varname, missing){
            msgBox.setText(msgBox.text() + "\n\t" + varname);
        }

        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setFont(QFont("Comic Sans MS"));
        msgBox.exec();
        return false;
    }
    //if(m_Lines.size() == m_Container->getXScale() - 1) return false;
    if(m_Variables[0]->getValue() == abbrevations::noValue) return false;

    if(m_Variables.size() == 1){
        eDouble *var = m_Variables.first();
        if(var == m_XAxis){
            QLineF *line = new QLineF(var->getValue(),0,var->getValue(),m_Container->getYSize()); // függõleges vonal
            m_Lines << line;
            return true;
        }else if(var == m_YAxis){
            QLineF *line = new QLineF(0,var->getValue(),m_Container->getXSize(),var->getValue()); // vízszintes vonal
            m_Lines << line;
            return true;
        }
    }

    QScriptEngine engine;

    /*QString paramlist = "(";
    foreach(eDouble *e, m_Variables){
        if(e != m_YAxis)
            paramlist.append(e->getName()).append(", ");
    }
    paramlist.chop(2);
    paramlist.append(")");
    QScriptValue fun = engine.evaluate("(function" + paramlist + " { return " + m_Formula.split(" =").at(1) + " ; })");
*/
    QString paramlist = "(";
    foreach(eDouble *e, m_Variables){
        if(e != m_YAxis){
            QString name = e->getName();
            if(name.contains('*'))
                paramlist.append(name.remove('*')).append(", "); // L* -ra meghalna..
            else if(name.contains('%'))                               // M%
                paramlist.append(name.remove('%').append(", "));
            else if(name.contains('\''))                               // Y'
                paramlist.append(name.remove('\'').append(", "));
            else
                paramlist.append(name.append(", "));
        }
    }
    paramlist.chop(2);
    paramlist.append(")");
    QString func = m_Formula.split(" =").at(1);
    QStringList fl = func.split(" ");
    func = "";
    foreach(QString str, fl){
        if(str.contains('*') && str.size() > 1)
            func.append(str.remove('*'));
        else if(str.contains('%') && str.size() > 1)
            func.append(str.remove('%'));
        else if(str.contains('\'') && str.size() > 1)
            func.append(str.remove('\''));
        else
            func.append(str);
        func.append(" ");
    }

    double alapKezdoIndex = 0., alapVegIndex = 0., kitevoKezdoIndex = 0., kitevoVegIndex = 0.;
    int insertTo = 0,insertLength = 0;
    while(func.contains("^")){
        QStringList form = func.split(" ");
        int hatvanyjelhelyIndex = form.indexOf("^");
        bool vanZarojel = false;

        if(form.at(hatvanyjelhelyIndex - 1).at(0) == ')'       // ( 1 / 2 ) ^ ( 2 / 3 ), alap és kitevõ is jeles
                && form.at(hatvanyjelhelyIndex + 1).at(0) == '(')
        {
            alapKezdoIndex = func.split('^').first().
                    split(" ").indexOf("(");    // alap a ( és ) között van a ^ elõtt
            alapVegIndex = hatvanyjelhelyIndex - 1;

            kitevoKezdoIndex = hatvanyjelhelyIndex + 1;
            kitevoVegIndex = hatvanyjelhelyIndex +
                    func.split('^').last().split(" ").indexOf(")");

            insertTo = func.split('^').first().
                    split(" ").indexOf("(");
            insertLength = form.at(alapKezdoIndex + 1).size()
                    + form.at(alapVegIndex - 1).size()
                    + form.at(kitevoKezdoIndex + 1).size()
                    + form.at(kitevoVegIndex - 1).size()
                    + 17;

            vanZarojel = true;
        }
        else if(form.at(hatvanyjelhelyIndex - 1).at(0) == ')'){     // ( 1 / 3 ) ^ 2, alap zárójelezve van
            alapKezdoIndex = func.split('^').first().
                    split(" ").indexOf("(");    // alap a ( és ) között van a ^ elõtt
            alapVegIndex = hatvanyjelhelyIndex - 1;

            kitevoKezdoIndex = hatvanyjelhelyIndex + 1;
            kitevoVegIndex = kitevoKezdoIndex;

            insertTo = func.indexOf("(");                           // alap kezdõ részéhez szúrunk
            insertLength = form.at(alapKezdoIndex + 1).size()
                    + form.at(alapVegIndex - 1).size()
                    + form.at(hatvanyjelhelyIndex + 1).size()
                    + 10;                                            // '1' + '3' + '2' hossza + 10

            vanZarojel = true;                                       // volt zárójel
        }
        else if(form.at(hatvanyjelhelyIndex + 1).at(0) == '(')       // 2 ^ ( 1 / 2 ) , kitevõ zárójelezve van
        {
            alapKezdoIndex = hatvanyjelhelyIndex - 1;
            alapVegIndex = alapKezdoIndex + 1; // !!!! csúnya, nem így kõne
            kitevoKezdoIndex = hatvanyjelhelyIndex + 1;
            kitevoVegIndex = hatvanyjelhelyIndex +
                    func.split('^').last().split(" ").indexOf(")");  // ^ utáni rész zárójele kell
            insertTo = func.indexOf("^") - 1 - form.at(alapKezdoIndex).size();
            insertLength = form.at(alapKezdoIndex).size()            // ua mint elõbb majdnem
                    + form.at(kitevoKezdoIndex + 1).size()
                    + form.at(kitevoVegIndex - 1).size()
                    + 10;

            vanZarojel = true;
        }
        else if(form.at(hatvanyjelhelyIndex - 1).at(0).isLetter()){      // 2 ^ 3 , nincsen zárójel sehol
            alapKezdoIndex = hatvanyjelhelyIndex - 1;               // ^ jel elõtti tag kell
            kitevoKezdoIndex = hatvanyjelhelyIndex + 1;             // ^ jel utáni tag kell
            insertTo = func.indexOf("^") - 2;                       // ^ betû elõtt 2 karakterhez szúrok be
            insertLength = form.at(hatvanyjelhelyIndex - 1).size()
                    + form.at(hatvanyjelhelyIndex + 1).size()
                    + 3;                            // ^ elõtti rész hossza +  utáni rész hossza + 3
        }


        QString alap = form.at(alapKezdoIndex), kitevo = form.at(kitevoKezdoIndex);

        if(vanZarojel == true){
            alap = "(";
            for(int i = alapKezdoIndex; i < alapVegIndex; ++i)
                alap.append(form.at(i));
            alap.append(")");
            kitevo = "(";
            for(int i = kitevoKezdoIndex; i <= kitevoVegIndex; ++i)
                kitevo.append(form.at(i));
            kitevo.append(")");
        }

        QString pow = QString("Math.pow(") + alap + QString(",") + kitevo + QString(")");
        func.replace(insertTo, insertLength, pow);

    }
    QScriptValue fun = engine.evaluate("(function" + paramlist + " { return " + func + " ; })");

    if(m_Lines.size() != 0) return false;

    double step = m_Container->getXSize() / 100;
    double y = calculateY(&fun,step);

    QPointF to, prev(0,y);

    //if(m_Lines.size() != 0) prev.setX(m_Lines.last()->p2().x());
    for(double i = step; i < m_Container->getXSize(); i+= step){
        QLineF *line = new QLineF;
        to.setX(i);
        to.setY(calculateY(&fun,i));
        line->setPoints(prev,to);
        prev = to;
        m_Lines << line;
    }

    //if (engine.hasUncaughtException()) {
    //    int line = engine.uncaughtExceptionLineNumber();
    //    qDebug() << "uncaught exception at line" << line << ":" << value.toString();
    //}

    return true;
}

double eCurve::calculateY(QScriptValue *value, double i)
{
    QScriptValueList args;
    foreach(eDouble *e, m_Variables){
        if(e != m_YAxis){
            if(e == m_XAxis)
                args << i;
            else
                args << e->getValue();
        }
    }
    QScriptValue result = value->call(QScriptValue(),args);
    return result.toVariant().toDouble();
}

eCurve::~eCurve()
{
    delete m_Color;
    foreach(QLineF *line, m_Lines)
        delete line;
}
