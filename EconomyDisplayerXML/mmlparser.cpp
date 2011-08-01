#include <QFile>
#include <QDomDocument>
#include <QDebug>

#include "edouble.h"
#include "ecurve.h"
#include "equation.h"
#include "mmlparser.h"
#include "abbrevations.h"
#include "equationgroup.h"

MMLParser::MMLParser()
{
}

bool MMLParser::read(QFile *file,QDomDocument * doc)
{
    QString errorMsg;
    int errorLine, errorColumn;
    if ( doc->setContent( file, &errorMsg, &errorLine, &errorColumn ) )
        return true;
    else {
        qWarning() << errorMsg << " - (" << errorLine << ";" << errorColumn << endl;
        return false;
    }

}

QMap<QString, eDouble*> MMLParser::getVariables(QDomNode *nd)
{
    QMap<QString, eDouble*> result;

    if ( nd->isElement() && nd->toElement().tagName() == "variables" ) {
        for (QDomNode n = nd->firstChild() ; !n.isNull(); n = n.nextSibling() ) {
            eDouble *var = new eDouble;
            QDomElement v = n.namedItem("value").toElement();
            double value;
            if(v.isNull()){
                value = abbrevations::noValue;
            }
            else{
                value = v.text().toDouble();
                if(value == 0.3 || value == 0.33 || value == 0.333 || value == 0.3333 ||
                        value == 0.33333 || value == 0.333333)
                    value = 1. / 3.;
                if(value == 0.6 || value == 0.66 || value == 0.666 || value == 0.6666 ||
                        value == 0.66666 || value == 0.666666)
                    value = 2. / 3.;
            }
            var->setValue(value);

            v = n.namedItem("info").toElement();
            if ( !v.isNull() ) var->setInfo(v.text());

            v = n.namedItem("name").toElement();                        
            result[v.text()] = var;
            var->setName(v.text());
            //result << var;
        }
    }

    return result;
}

QList<EquationGroup*> MMLParser::getEquationGroups(QDomNode *nd)
{

    QList<EquationGroup*> result;

    if ( nd->isElement() && nd->toElement().tagName() == "equations" ) {
        for (QDomNode eqg = nd->firstChild() ; !eqg.isNull(); eqg = eqg.nextSibling() ) {
            if ( eqg.isElement() && eqg.toElement().tagName() == "equationgroup" ){
                EquationGroup *eqgroup = new EquationGroup;
                eqgroup->setName(eqg.toElement().attribute("name"));
                for (QDomNode eqn = eqg.firstChild() ; !eqn.isNull(); eqn = eqn.nextSibling() ) {
                    Equation *eq = new Equation;
                    eq->setGroup(eqgroup);
                    //qDebug() << n.toElement().attribute("displayed") << endl;
                    bool displayed = (eqn.toElement().attribute("displayed") == "true");
                    eq->setDisplayed(displayed);
                    QDomElement v = eqn.namedItem("name").toElement();
                    if ( !v.isNull() ) eq->setName(v.text());
                    v = eqn.namedItem("formula").toElement();
                    if ( !v.isNull() ) eq->setFormula(v.text());

                    eqgroup->addEquation(eq->getFormula().split(" =").first(),eq);
                    eq->setVariables();
                }
                result << eqgroup;
            }
        }
    }
    return result;
}

QStringList MMLParser::getAbout(QDomNode *nd)
{
    QStringList result;
    if(nd->isElement() && nd->toElement().tagName() == "about"){
        QDomElement n = nd->toElement();
        QDomElement v = n.namedItem("creator").toElement();
        result << v.text();
        v = n.namedItem("modulname").toElement();
        result << v.text();
        v = n.namedItem("description").toElement();
        result << v.text();
    }

    return result;
}

QList<eCurve*> MMLParser::getCurves(QDomNode *nd)
{
    QList<eCurve*> result;

    if ( nd->isElement() && nd->toElement().tagName() == "curves" ) {
        for (QDomNode n = nd->firstChild() ; !n.isNull(); n = n.nextSibling() ) {
            eCurve *curve = new eCurve;
            curve->setName(n.toElement().attribute("name"));
            curve->setXAxis(abbrevations::variables[n.toElement().attribute("x-axis")]);
            curve->setYAxis(abbrevations::variables[n.toElement().attribute("y-axis")]);
            QDomElement v = n.namedItem("formula").toElement();
            if ( !v.isNull() ) curve->setFormula(v.text());

            QStringList list = curve->getFormula().split(" ");
            foreach(QString s, list)
            {
                if(s.at(0).isLetter()){
                    curve->addVariable(abbrevations::variables[s]);
                }
            }

            result << curve;
        }
    }
    return result;
}
