#include <QScriptEngine>
#include <QDebug>
#include <QStringList>

#include "equation.h"
#include "equationgroup.h"
#include "abbrevations.h"
#include "edouble.h"


Equation::Equation()
{
}

void Equation::setVariables()
{
    QStringList list = m_Formula.split(" ");
    foreach(QString s, list)
    {
        if(s.at(0).isLetter()){
            eDouble *e = abbrevations::variables[s];
            if(!m_Variables.contains(e))
                m_Variables << abbrevations::variables[s];
            if(m_Variables.last()->getValue() == abbrevations::noValue &&
                    !m_Group->getUnKnowns()->contains(e))
                m_Group->addUnKnown(e);
        }
    }
}

double Equation::solve()
{
    QScriptEngine engine;

    QString paramlist = "(";
    foreach(eDouble *e, m_Variables){
        if(!m_Group->getUnKnowns()->contains(e)) {
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
    QString func = m_Formula.split(" = ").at(1);
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
            //qDebug() << func.indexOf('^') << " - " << func.indexOf("(") << " + " <<
            //            func.split('^').last().indexOf(")") + 1 << endl;    // + 2 !!!

            // (26 - 0) + 9              012345678901
            // 01234567890123456789012345678901234567
            // ( ( i * Y ) / ( 2 * F ) ) ^ ( 1 / 2 )

            /*insertLength = form.at(alapKezdoIndex + 1).size()
                    + form.at(alapVegIndex - 1).size()
                    + form.at(kitevoKezdoIndex + 1).size()
                    + form.at(kitevoVegIndex - 1).size()
                    + 17;
            */
            insertLength = func.indexOf('^') - func.indexOf("(") + func.split('^').last().indexOf(")") + 2;
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
            alapVegIndex = alapKezdoIndex; //+ 1; // !!!! csúnya, nem így kõne
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
            for(int i = alapKezdoIndex; i <= alapVegIndex; ++i)
                alap.append(form.at(i));
            alap.append(")");
            kitevo = "(";
            for(int i = kitevoKezdoIndex; i <= kitevoVegIndex; ++i)
                kitevo.append(form.at(i));
            kitevo.append(")");
        }

        QString pow = QString("Math.pow(") + alap + QString(",") + kitevo + QString(")");
        func.replace(insertTo, insertLength, pow);
        /*  012345678901234567890
            ( K ^ k ) * ( L ^ l )
            form = ( , K , ^ , k , ) , * , ( , L , ^ , l , )
            index = 2
            a = 1 b = 3
            indexOf() = 4


            MPL = X * ( K / L ) ^ k
            form = X , * , ( , K , / , L , ) , ^ , k
            index = 8
            a = 2 b = 8 c = 6
            indexOf() = 14

        */
    }
    QScriptValue fun = engine.evaluate("(function" + paramlist + " { return " + func + " ; })");
    QScriptValueList args;
    foreach(eDouble *e, m_Variables)
        if(!m_Group->getUnKnowns()->contains(e))
            args << e->getValue();
    QScriptValue value = fun.call(QScriptValue(),args);

    if (engine.hasUncaughtException()) {
        int line = engine.uncaughtExceptionLineNumber();
        qDebug() << "uncaught exception at line" << line << ":" << value.toString();
    }    

    return value.toVariant().toDouble();
}

const QString Equation::getVariableInfo(const QString &name) const
{
    foreach(eDouble *e, m_Variables)
        if(e->getName() == name)
            return e->getInfo();
}

const QString Equation::getSubstitutedFormula() const
{
    QString substitutedFormula(m_Formula);
    foreach(eDouble *e, m_Variables)
        if(!(m_Group->getUnKnowns()->contains(e)))
            substitutedFormula.replace(e->getName(),QString::number(e->getValue()));
    return substitutedFormula;
}
