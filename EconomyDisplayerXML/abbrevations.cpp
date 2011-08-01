#include <QDomDocument>
#include <QFile>
#include <QScriptEngine>
#include <QDebug>
#include <QMessageBox>

#include <math.h>

#include "mmlparser.h"
#include "edouble.h"
#include "equationgroup.h"
#include "equation.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abbrevations.h"


namespace abbrevations{

QMap<QString, eDouble*> variables;
QList<EquationGroup*> equationGroups;
QList<eCurve*> curves;

MainWindow *mainWindow;

QScriptEngine *globalEngine;

bool useWolframAlpha = false;
bool coordinateSystemScaleable = false;

QScriptValue dFI(QScriptContext *context, QScriptEngine *engine)
 {
    QScriptValue value = context->argument(0);
    return 1.0 / sqrt (2.0 * acos(-1)) * exp(-0.5*value.toNumber()*value.toNumber());
 }

QScriptValue FI(QScriptContext *context, QScriptEngine *engine)
 {
    QScriptValue value = context->argument(0);
    double x = value.toVariant().toDouble();
    // constants
    double a1 =  0.254829592;
    double a2 = -0.284496736;
    double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;
    double p  =  0.3275911;

    // Save the sign of x
    int sign = 1;
    if (x < 0)
        sign = -1;
    x = fabs(x)/sqrt(2.0);

    // A&S formula 7.1.26
    double t = 1.0/(1.0 + p*x);
    double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

    return QScriptValue(0.5*(1.0 + sign*y));
 }


void initVariables(){

    /*    if(variables.size() != 0)
        return;
    QDomDocument doc;
    QFile file("C:/Makro mml/AS-AD.mml");
    MMLParser parser;
    if(parser.read(&file,&doc)){
        QDomElement root = doc.namedItem("eml").toElement();
        QDomNode nd = root.firstChild();
        nd = nd.nextSibling();
        variables = parser.getVariables(&nd);
        nd = nd.nextSibling();
        equationGroups = parser.getEquationGroups(&nd);
        nd = nd.nextSibling();
        curves = parser.getCurves(&nd);
    }
    file.close();
    doc.clear();*/
}

void openFile(QString fileName)
{
    abbrevations::globalEngine = new QScriptEngine(mainWindow);
    QScriptValue func1 = abbrevations::globalEngine->newFunction(dFI);
    abbrevations::globalEngine->globalObject().setProperty("dFI", func1);
    QScriptValue func2 = abbrevations::globalEngine->newFunction(FI);
    abbrevations::globalEngine->globalObject().setProperty("FI", func2);

    variables.clear();
    equationGroups.clear();
    curves.clear();

    QDomDocument doc;
    QFile file(fileName);
    MMLParser parser;
    if(parser.read(&file,&doc)){
        QDomElement root = doc.namedItem("mml").toElement();
        QDomNode nd = root.firstChild();
        nd = nd.nextSibling();
        variables = parser.getVariables(&nd);
        nd = nd.nextSibling();
        equationGroups = parser.getEquationGroups(&nd);
        nd = nd.nextSibling();
        curves = parser.getCurves(&nd);
    }

    bool nonlinear = false;

    foreach(EquationGroup *eqg, equationGroups){
        foreach(Equation *eq, *eqg->getEquations()){
            if(eq->getFormula().contains("^")){
                QMessageBox msgBox;
                msgBox.setText("Figyelem! Az egyenletek között szerepelnek nem lineárisak!\n"
                               "Nem lináris egyenletrendszerek megoldása jelenleg nem támogatott, "
                               "használja a Beállítások menü alatt a \"WolframAlpha használata\" lehetõséget!");

                msgBox.setStandardButtons(QMessageBox::Ok);
                msgBox.setDefaultButton(QMessageBox::Ok);
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setFont(QFont("Comic Sans MS"));
                msgBox.exec();
                nonlinear = true;
            }
            if(nonlinear)
                break;
        }
        if(nonlinear)
            break;
    }
    file.close();
    doc.clear();
    if(variables.contains("M") || variables.contains("P")){
        mainWindow->getUI()->actionMonet_ris_l_p_sek->setVisible(true);
        mainWindow->getUI()->toolBar->actions().at(7)->setVisible(true);
        mainWindow->getUI()->toolBar->actions().at(8)->setVisible(true);
        //ui->toolBar->actions().at(9)->setVisible(true);
        mainWindow->getUI()->toolBar->actions().at(10)->setVisible(true);
        mainWindow->getUI()->toolBar->actions().at(11)->setVisible(true);
    }
    if(variables.contains("T") || variables.contains("r")){
        mainWindow->getUI()->actionMonet_ris_l_p_sek->setVisible(true);
        mainWindow->getUI()->toolBar->actions().at(7)->setVisible(true);
        //ui->toolBar->actions().at(8)->setVisible(true);
        mainWindow->getUI()->toolBar->actions().at(9)->setVisible(true);
        mainWindow->getUI()->toolBar->actions().at(10)->setVisible(true);
        mainWindow->getUI()->toolBar->actions().at(11)->setVisible(true);
    }
}

void resetVariables()
{
    foreach(QString key , variables.keys())
        variables[key]->setValue(noValue);
}

bool rValueChanged = false;
bool TValueChanged = false;
bool MValueChanged = false;


void solve()
{
    foreach(EquationGroup *eqg, equationGroups)
        eqg->checkUnKnows();

    bool solved = false;
    foreach(EquationGroup *eqg, equationGroups){
        solved = false;
        if(eqg->isInstantSolvable()){   // 1 ismeretlen, kifejezés és megoldás
            foreach(Equation *e, *eqg->getEquations()){
                if(solved) break;
                if(eqg->getUnKnowns()->first()->getName() == e->getVariables()->first()->getName()){
                    double value = e->solve();
                    variables[eqg->getUnKnowns()->first()->getName()]->setValue(value);
                    solved = true;
                }
            }
        }
        else if(eqg->getUnKnowns()->size() == 2){   // több ismeretlen, átalakítás és gauss eliminációval megoldás            )
            solved = false;
            foreach(EquationGroup *eqg2, equationGroups){
                if(eqg != eqg2 && eqg2->getUnKnowns()->size() == 2){
                    if(eqg->getUnKnowns()->first() == eqg2->getUnKnowns()->first())
                        solved = eqg->solveLinearSystem(eqg2);
                }
                if(solved) break;
            }
        }        
    }
    foreach(EquationGroup *eqg, equationGroups)
        eqg->checkUnKnows();
}

void calculate()
{
    rValueChanged = false;
    TValueChanged = false;
    MValueChanged = false;

}

void changeVar(QString varName, double value){
    variables[varName]->setValue(value);
    switch(varName.at(0).toAscii()){
    case 'r' : rValueChanged = true; break;
    case 'T' : TValueChanged = true; break;
    case 'M' : MValueChanged = true; break;
    }
}

}


