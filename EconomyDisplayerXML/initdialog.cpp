#include <QTableWidgetItem>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QDebug>

#include "initdialog.h"
#include "ui_initdialog.h"
#include "abbrevations.h"
#include "mainwindow.h"
#include "equationtab.h"
#include "equationgroup.h"
#include "edouble.h"


InitDialog::InitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InitDialog)
{
    m_VariablesEditable = false;
    ui->setupUi(this);    
    loadUi();

    //connect(this,SIGNAL(accepted()),this,SLOT(OKPressed2()));
    connect(ui->editVariablesCheckBox, SIGNAL(toggled(bool)),this,SLOT(refreshValuesInDialog()));
    //foreach(EquationTab *tab, m_Tabs)
    //    foreach(QLineEdit *lineedit, tab->getLineEdits())
    //        qDebug() << lineedit-> << endl;
}

void InitDialog::setLineEdits()
{
    foreach(EquationTab *tab, m_Tabs){
        foreach(QLineEdit *lineedit, tab->getLineEdits()){
            QString varName = lineedit->objectName();
            int index = varName.indexOf("Value");
            varName.remove(index, varName.length() - index);
            double v = abbrevations::variables[varName]->getValue();
            QString value = v == abbrevations::noValue ? "" : QString::number(v);
            lineedit->setText(value);
        }
    }
}

void InitDialog::OKPressed2(){
    QString *name;
    QLineEdit *le;
    QString str;
    QList<QLineEdit*> list;
    foreach(EquationTab *tab, m_Tabs){
        foreach(QLineEdit *lineedit , tab->getLineEdits()){
            list << lineedit;
        }
    }

    foreach(QLineEdit *lineedit , list){
        str = lineedit->objectName();
        int index = str.indexOf("Value");
        str.remove(index, str.length() - index);
        int size = lineedit->text().size();
        if(size > 0){
            double value = lineedit->text().toDouble();
            if(value == 0.3 || value == 0.33 || value == 0.333 || value == 0.3333
                    || value == 0.33333 || value == 0.333333)
                value = 1.0 / 3.0;
            if(value == 0.6 || value == 0.66 || value == 0.666 || value == 0.6666
                    || value == 0.66666 || value == 0.666666 || value == 0.666667)
                value = 2.0 / 3.0;
            abbrevations::variables[str]->setValue(value);
        }else
        {
            abbrevations::variables[str]->setValue(abbrevations::noValue);
        }
    }

    le = 0;
    name = 0;
    int i = 0;
    foreach(QString str , abbrevations::variables.keys()){
        bool ok;
        double newVal = ui->valuesTableIWidget->item(i,3)->text().toDouble(&ok);
        if(ok)
            abbrevations::variables[str]->setValue(newVal);
        i++;
    }

    abbrevations::solve();
}

void InitDialog::addEquationTab(Equation *equation)
{
    EquationTab *tab = new EquationTab(equation,this);
    ui->tabWidget->insertTab(m_Tabs.size(), tab,equation->getName());
    ui->listWidget->insertItem(ui->listWidget->count() - 1, equation->getName());
    m_Tabs << tab;
}

void InitDialog::refresh()
{
    m_Tabs.clear();
    ui->tabWidget->clear();
    loadUi();
    refreshValuesInDialog();
}

void InitDialog::showVariablesInDialog()
{
    QStringList list;

    foreach(EquationTab *tab, m_Tabs){
        foreach(QLineEdit *lineedit , tab->getLineEdits()){
            list << lineedit->objectName().remove("ValueLineEdit");
        }
    }

    ui->valuesTableIWidget->setRowCount(abbrevations::variables.size());
    int i = 0;
    foreach(QString str , abbrevations::variables.keys()){
        QTableWidgetItem *name = new QTableWidgetItem(str);
        QString val = QString::number(abbrevations::variables.value(str)->getValue());
        val == QString::number(abbrevations::noValue) ? val = "Nincs érték" : val;
        QTableWidgetItem *value = new QTableWidgetItem(val);
        QTableWidgetItem *info = new QTableWidgetItem(abbrevations::variables.value(str)->getInfo());
        QTableWidgetItem *newValue = new QTableWidgetItem();


        if(list.contains(str)){
            name->setFlags(QFlag(0b0));
            value->setFlags(QFlag(0b0));  //  ne legyen semmi
            info->setFlags(QFlag(0b0));
            newValue->setFlags(QFlag(0b0));
        }
        else{
            name->setFlags(QFlag(0b1111101));
            value->setFlags(QFlag(0b1111101));  //  ne legyen átírható
            info->setFlags(QFlag(0b1111101));
        }
        ui->valuesTableIWidget->setItem(i,0,name);
        ui->valuesTableIWidget->setItem(i,1,value);
        ui->valuesTableIWidget->setItem(i,2,info);
        ui->valuesTableIWidget->setItem(i,3,newValue);
        i++;
    }
}


void InitDialog::loadUi()
{    
    ui->listWidget->clear();
    foreach(EquationGroup *eqg, abbrevations::equationGroups){
        foreach(Equation *eq, *eqg->getEquations()){
            {
                if(eq->getDisplayed() == true){
                    EquationTab *tab = new EquationTab(eq);
                    ui->tabWidget->addTab(tab,eq->getName());
                    ui->listWidget->addItem(eq->getName());
                    m_Tabs << tab;
                }
            }
        }
    }    


    ui->tabWidget->addTab(ui->tab_2,QString()); // Ld = ( ( X * l ) / w ) ^ ( 1 / -l )
    ui->tabWidget->setTabText(ui->tabWidget->indexOf(ui->tab_2), QApplication::translate("InitDialog", "Egy\303\251b", 0, QApplication::UnicodeUTF8));
    ui->listWidget->addItem("Egyéb");

    showVariablesInDialog();

    refreshValuesInDialog();
}


void InitDialog::refreshValuesInDialog()
{

    QStringList list;
    int i = 0;

    foreach(EquationTab *tab, m_Tabs){
        foreach(QLineEdit *lineedit , tab->getLineEdits()){
            QString str = lineedit->objectName();
            int index = str.indexOf("Value");
            str.remove(index, str.length() - index);
            double value = abbrevations::variables.value(str)->getValue();   //  kezdõbetû változó értéke
            QString text;
            value == abbrevations::noValue ? text = "" : text = QString::number(value);
            lineedit->setText(text);
            list << lineedit->objectName().remove("ValueLineEdit");
        }
    }

    if(ui->valuesTableIWidget->rowCount() != abbrevations::variables.size())
    {
        ui->valuesTableIWidget->clearContents();
        showVariablesInDialog();
    }

    i = 0;
    foreach(QString str , abbrevations::variables.keys()){
        QString val = QString::number(abbrevations::variables.value(str)->getValue());
        val == QString::number(abbrevations::noValue) ? val = "Nincs érték" : val;
        QTableWidgetItem *value = new QTableWidgetItem(val);
        QTableWidgetItem *newValue = new QTableWidgetItem();

        if(!m_VariablesEditable){
            if(list.contains(str)){
                ui->valuesTableIWidget->item(i,0)->setFlags(QFlag(0b0));
                ui->valuesTableIWidget->item(i,2)->setFlags(QFlag(0b0));
                value->setFlags(QFlag(0b0));  //  ne legyen semmi
                newValue->setFlags(QFlag(0b0));
                newValue->setForeground(Qt::blue);
            }
        }
        else{
            ui->valuesTableIWidget->item(i,0)->setFlags(QFlag(0b1111101));
            ui->valuesTableIWidget->item(i,2)->setFlags(QFlag(0b1111101));
            ui->valuesTableIWidget->item(i,3)->setFlags(QFlag(0b1111101));
            value->setFlags(QFlag(0b1111101));  //  ne legyen átírható
        }

        ui->valuesTableIWidget->setItem(i,1,value);
        ui->valuesTableIWidget->setItem(i,3,newValue);
        i++;
    }
}


InitDialog::~InitDialog()
{
    delete ui;
    foreach(EquationTab *eqtab, m_Tabs)
        delete eqtab;
}

/*
void InitDialog::OKPressed()
{    
    QString *name;
    QLineEdit *le;    
    QString str;
    foreach(QLineEdit *lineedit , m_VarLineEdits){
        str = lineedit->objectName();
        int index = str.indexOf("Value");
        str.remove(index, str.length() - index);
        int size = lineedit->text().size();
        if(size > 0){
            double value = lineedit->text().toDouble();
            if(value == 0.3 || value == 0.33 || value == 0.333 || value == 0.3333
                    || value == 0.33333 || value == 0.333333)
                value = 1.0 / 3.0;
            if(value == 0.6 || value == 0.66 || value == 0.666 || value == 0.6666
                    || value == 0.66666 || value == 0.666666 || value == 0.666667)
                value = 2.0 / 3.0;
            abbrevations::variables[str].setValue(value);
        }else
        {
            abbrevations::variables[str].setValue(abbrevations::noValue);            
        }
    }    
    foreach(QLineEdit *lineedit, m_ConstLineEdits)
    {
        str = lineedit->objectName();
        int index = str.indexOf("Value");
        str.remove(index, str.length() - index);
        int size = lineedit->text().size();
        if(size > 0){
            double value = lineedit->text().toDouble();
            if(value == 0.3 || value == 0.33 || value == 0.333 || value == 0.3333
                    || value == 0.33333 || value == 0.333333)
                value = 1.0 / 3.0;
            if(value == 0.6 || value == 0.66 || value == 0.666 || value == 0.6666
                    || value == 0.66666 || value == 0.666666 || value == 0.666667)
                value = 2.0 / 3.0;
            abbrevations::constants.insert(str,eDouble(value,""));
        }else
            abbrevations::constants[str].setValue(abbrevations::noValue);
    }

    le = 0;
    name = 0;
    int i = 0;
    foreach(QString str , abbrevations::variables.keys()){                
        bool ok;
        double newVal = ui->valuesTableIWidget->item(i,3)->text().toDouble(&ok);
        if(ok)
            abbrevations::variables[str].setValue(newVal);
        i++;        
    }

    abbrevations::setVariables();
    abbrevations::calculate();        
*/

/*QString value;
    foreach(QLineEdit *lineedit , m_VarLineEdits){
        value = lineedit->text();
        if(value != 0){
            QChar *c = lineedit->objectName().begin();
            switch (c->toAscii()){
            case 'Y' : ABBREVATIONS_H::Y = value.toInt(); break;
            case 'C' : ABBREVATIONS_H::C = value.toInt(); break;
            case 'I' : ABBREVATIONS_H::I = value.toInt(); break;
            case 'G' : ABBREVATIONS_H::G = value.toInt(); break;
            case 'N' : ABBREVATIONS_H::Nx = value.toInt(); break;

            case 'M' : ABBREVATIONS_H::M = value.toInt(); break;
            case 'V' : ABBREVATIONS_H::V = value.toInt(); break;
            case 'P' : ABBREVATIONS_H::P = value.toInt(); break;
                //case 'Y' : ABBREVATIONS_H::Y = value.toInt(); break;

            case 'L' : ABBREVATIONS_H::L = value.toInt(); break;
            case 'K' : ABBREVATIONS_H::K = value.toInt(); break;
            }
        }
    }*/

//close();
/*QString value = ui->YValueLineEdit->text();
    if(value.size() != 0) ABBREVATIONS_H::Y = value.toInt();
    value = ui->CValueLineEdit->text();
    if(value.size() != 0) ABBREVATIONS_H::C = value.toInt();
    value = ui->IValueLineEdit->text();
    if(value.size() != 0) ABBREVATIONS_H::I = value.toInt();
    value = ui->GValueLineEdit->text();
    if(value.size() != 0) ABBREVATIONS_H::G = value.toInt();
    value = ui->NxValueLineEdit->text();
    if(value.size() != 0) ABBREVATIONS_H::Nx = value.toInt();

    value = ui->MValueLineEdit->text();
    if(value.size() != 0) ABBREVATIONS_H::M = value.toInt();
    value = ui->VValueLineEdit->text();
    if(value.size() != 0) ABBREVATIONS_H::V = value.toInt();
    value = ui->PValueLineEdit->text();
    if(value.size() != 0) ABBREVATIONS_H::P = value.toInt();
    value = ui->YValueLineEdit_2->text();
    if(value.size() != 0) ABBREVATIONS_H::Y = value.toInt();

    value = ui->LValueLineEdit->text();
    if(value.size() != 0) ABBREVATIONS_H::L = value.toInt();
    value = ui->KValueLineEdit->text();
    if(value.size() != 0) ABBREVATIONS_H::K = value.toInt();

}
*/

void InitDialog::editVariablesClicked(bool b)
{
    if (b == false) {
        m_VariablesEditable = false;
        foreach(EquationTab *tab, m_Tabs){
            foreach(QLineEdit *lineedit , tab->getLineEdits()){
                lineedit->setEnabled(true);
            }
        }
        return;
    }
    QMessageBox msgBox;
    msgBox.setText("Figyelem! Ebben a módban kizárólag itt van lehetõség értékeket bevinni!");
    msgBox.setInformativeText("Biztos benne, hogy ezt szeretné?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setIcon(QMessageBox::Warning);
    int ret = msgBox.exec();

    switch (ret) {
    case QMessageBox::Ok:
        m_VariablesEditable = true;
        foreach(EquationTab *tab, m_Tabs){
            foreach(QLineEdit *lineedit , tab->getLineEdits()){
                lineedit->clear();
                lineedit->setEnabled(false);
            }
        }
        break;
    case QMessageBox::Cancel:
        ui->editVariablesCheckBox->setChecked(!ui->editVariablesCheckBox->isChecked());
        break;
    default:
        // should never be reached
        break;
    }
}
