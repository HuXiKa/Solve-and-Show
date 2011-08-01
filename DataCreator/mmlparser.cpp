#include <QFile>
#include <QDomDocument>
#include <QDebug>
#include <QMessageBox>

#include "variable.h"
#include "equation.h"
#include "curve.h"
#include "mmlparser.h"
#include "equationgroup.h"
#include "equation.h"

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

QDomElement addElement( QDomDocument &doc, QDomNode &node,
                        const QString &tag,
                        const QString &value = QString::null )
{
    QDomElement el = doc.createElement( tag );
    node.appendChild( el );
    if ( !value.isNull() ) {
        QDomText txt = doc.createTextNode( value );
        el.appendChild( txt );
    }
    return el;
}

bool MMLParser::write(QFile *file)
{
    QDomDocument doc;
    QDomProcessingInstruction instr = doc.createProcessingInstruction(
                "xml", "version='1.0' encoding='UTF-8'");
    doc.appendChild(instr);
    QDomElement eml = addElement( doc, doc, "mml" );

    QDomElement about = addElement( doc, eml, "about" );
    addElement( doc, about, "creator", m_About.at(0));
    addElement( doc, about, "name", m_About.at(1));
    addElement( doc, about, "description", m_About.at(2));

    QDomElement variables = addElement( doc, eml, "variables" );
    foreach(Variable *var, m_Variables){
        QDomElement variable = addElement(doc,variables,"variable");
        if ( !var->getName().isEmpty() )
            addElement( doc, variable, "name", var->getName() );

        if ( var->getValue() != 0)
            addElement( doc, variable, "value", QString::number(var->getValue(),'f',6) );

        if ( !var->getInfo().isEmpty() )
            addElement( doc, variable, "info", var->getInfo() );
    }

    QDomElement equations = addElement( doc, eml, "equations" );
    foreach(EquationGroup *eqg, m_EquationGroups){
        QDomElement equationgroup = addElement(doc,equations,"equationgroup");
        equationgroup.setAttribute("name",eqg->getName());
        foreach(Equation *eq, *eqg->getEquations()){
            QDomElement equation = addElement(doc,equationgroup,"equation");
            if(eq->getDisplayed()) equation.setAttribute("displayed","true");
            if ( !eq->getName().isEmpty() )
                addElement( doc, equation, "name", eq->getName() );

            if ( !eq->getFormula().isEmpty() )
                addElement( doc, equation, "formula", eq->getFormula() );
        }
    }

    QDomElement curves = addElement( doc, eml, "curves" );
    foreach(Curve *c, m_Curves){
        QDomElement curve = addElement(doc,curves,"curve");
        curve.setAttribute("name",c->getName());
        curve.setAttribute("x-axis",c->getXAxis());
        curve.setAttribute("y-axis",c->getYAxis());
        //QDomElement element = new
        if ( !c->getFormula().isEmpty() )
            addElement( doc, curve, "formula", c->getFormula() );

    }
    QTextStream out(file);
    doc.save(out,2);
    return true;
}

QList<Variable*> MMLParser::getVariables(QDomNode *nd)
{

    QList<Variable*> result;

    if ( nd->isElement() && nd->toElement().tagName() == "variables" ) {
        for (QDomNode n = nd->firstChild() ; !n.isNull(); n = n.nextSibling() ) {
            Variable *var = new Variable;
            QDomElement v = n.namedItem("name").toElement();
            if ( !v.isNull() ) var->setName(v.text());
            v = n.namedItem("value").toElement();
            if ( !v.isNull() ) var->setValue(v.text().toDouble());
            else
                var->setValue(INT_MIN);
            v = n.namedItem("info").toElement();
            if ( !v.isNull() ) var->setInfo(v.text());
            result << var;
        }
    }
    m_Variables << result;
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
                    //qDebug() << n.toElement().attribute("displayed") << endl;
                    bool displayed = (eqn.toElement().attribute("displayed") == "true");
                    eq->setDisplayed(displayed);
                    QDomElement v = eqn.namedItem("name").toElement();
                    if ( !v.isNull() ) eq->setName(v.text());
                    v = eqn.namedItem("formula").toElement();
                    if ( !v.isNull() ) eq->setFormula(v.text());

                    eqgroup->addEquation(eq);
                }
                result << eqgroup;
            }
        }
    }
    m_EquationGroups << result;
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
    m_About << result;
    return result;
}

QList<Curve*> MMLParser::getCurves(QDomNode *nd)
{
    QList<Curve*> result;

    if ( nd->isElement() && nd->toElement().tagName() == "curves" ) {
        for (QDomNode n = nd->firstChild() ; !n.isNull(); n = n.nextSibling() ) {
            Curve *curve = new Curve;
            curve->setName(n.toElement().attribute("name"));
            curve->setXAxis(n.toElement().attribute("x-axis"));
            curve->setYAxis(n.toElement().attribute("y-axis"));
            QDomElement v = n.namedItem("formula").toElement();
            if ( !v.isNull() ) curve->setFormula(v.text());
            result << curve;
        }
    }
    m_Curves << result;
    return result;
}

const bool MMLParser::validate() const
{
    QString error;
    foreach(EquationGroup *eqg, m_EquationGroups){
        foreach(Equation *eq, *eqg->getEquations()){
            QStringList list = eq->getFormula().split(" ");
            foreach(QString str, list){
                if(str.at(0).isLetter()){
                    bool found = false;
                    foreach(Variable *var, m_Variables){
                        if(var->getName() == str){
                            found = true;
                            break;
                        }
                    }
                    if(!found)
                        error.append(str + "\n");
                }
            }
        }
    }
    if(!error.isEmpty()){
        QMessageBox msgBox;
        msgBox.setText("Figyelem! Az alábbi változók elõfordulnak egyenleteKben "
                       "anélkül, hogy definiálva lennének!"
                       "\nEzek meghatározása nélkül hibás lesz az mml fájl!");

        msgBox.setText(msgBox.text() + "\n\n" + error);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setFont(QFont("Comic Sans MS"));
        msgBox.exec();
        return false;
    }
    return true;
}
