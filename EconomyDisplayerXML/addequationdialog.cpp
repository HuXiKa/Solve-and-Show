#include <QString>
#include <QMessageBox>

#include "edouble.h"
#include "equation.h"
#include "abbrevations.h"
#include "addequationdialog.h"
#include "ui_addequationdialog.h"
#include "mainwindow.h"
#include "initdialog.h"
#include "settingsdialog.h"
#include "ecurve.h"
#include "equationgroup.h"

AddEquationDialog::AddEquationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEquationDialog)
{
    ui->setupUi(this);
    connect(ui->addEquationButton,SIGNAL(clicked(bool)),this,SLOT(addEquation()));

    connect(ui->isDrawableCheckBox, SIGNAL(toggled(bool)), ui->axisWidget, SLOT(setVisible(bool)));

    ui->axisWidget->hide();
}

AddEquationDialog::~AddEquationDialog()
{
    delete ui;
}

void AddEquationDialog::addEquation()
{        
    QString formula = ui->equationLineEdit->text();
    QString name = ui->equationNameLineEdit->text();
    QStringList list = formula.split(" ");
    QList<eDouble*> newVariables;
    QList<eDouble*> doubleVariables;
    if(list.size() > 1){
        foreach(QString str, list)
        {
            if(str.at(0).isLetter())
            {
                eDouble *e = new eDouble(str, abbrevations::noValue, "");
                if(!abbrevations::variables.contains(str))
                    newVariables << e;
                else
                    doubleVariables << e;
            }
        }
    }
    if(doubleVariables.size() > 0){
        QMessageBox msgBox;
        msgBox.setText("Figyelem! A következõ változók már használatban vannak!\n"
                       "Ha folytatja, ezeknek a változóknak az értéke elveszik!\n");
        foreach(eDouble* e, doubleVariables){
            msgBox.setText(msgBox.text() + "\n\t" + e->getName());
        }
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel );
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setFont(QFont("Comic Sans MS"));
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Ok:
            foreach(eDouble *e, newVariables)
                abbrevations::variables[e->getName()] = e;
            foreach(eDouble *e, doubleVariables)
                abbrevations::variables[e->getName()] = e;

            break;
        case QMessageBox::Cancel:
            return; // jaj, csúnya
            break;
        default:
            // should never be reached
            break;
        }
    }
    foreach(eDouble *e, newVariables)
        abbrevations::variables[e->getName()] = e;

    Equation *equation = new Equation;
    equation->setDisplayed(ui->isShownCheckBox->isChecked());
    equation->setFormula(formula);
    equation->setName(name);

    foreach(EquationGroup *eqg, abbrevations::equationGroups){
        if(eqg->getName() == "AddedEquations"){
            equation->setGroup(eqg);
            eqg->addEquation(formula.split("=").first(),equation);
            break;
        }
    }

    equation->setVariables();

    if(ui->isShownCheckBox->isChecked())
        abbrevations::mainWindow->id->addEquationTab(equation);
    if(ui->isDrawableCheckBox->isChecked()){
        eCurve *curve = new eCurve;
        curve->setXAxis(abbrevations::variables[ui->xAxisLineEdit->text()]);
        curve->setYAxis(abbrevations::variables[ui->yAxisLineEdit->text()]);
        curve->setName(name);
        curve->setFormula(formula);

        QStringList list = curve->getFormula().split(" ");
        foreach(QString s, list)
        {
            if(s.at(0).isLetter()){
                curve->addVariable(abbrevations::variables[s]);
            }
        }

        abbrevations::curves << curve;
        abbrevations::mainWindow->sd->refreshCurveList();
    }

    abbrevations::mainWindow->showVariables();

}
