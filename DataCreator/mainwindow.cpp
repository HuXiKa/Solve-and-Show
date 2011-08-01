#include <QDomElement>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "variable.h"
#include "equation.h"
#include "curve.h"
#include "equationgroup.h"
#include "mmlparser.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_Parser = new MMLParser;
    ui->addEquationTableWidget->horizontalHeader()->setStretchLastSection( true );
    //ui->equationsTableWidget->horizontalHeader()->setStretchLastSection( true );
    ui->addVariableTableWidget->horizontalHeader()->setStretchLastSection( true );
    ui->variablesTableWidget->horizontalHeader()->setStretchLastSection( true );
    ui->curvesTableWidget->horizontalHeader()->setStretchLastSection( true );
    ui->addCurveTableWidget->horizontalHeader()->setStretchLastSection( true );

    connect(ui->actionQt_n_vjegy,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    button = new QPushButton("Nem jelenik meg");
    button->setCheckable(true);
    connect(button,SIGNAL(toggled(bool)),this,SLOT(setButton(bool)));
    ui->addEquationTableWidget->setCellWidget(0,2,button);
    QIcon icon("icons/qt-logo.png");
    ui->actionQt_n_vjegy->setIcon(icon);
    ui->actionMegnyit_s->setIcon(QIcon(qApp->style()->standardIcon(QStyle::SP_DirOpenIcon)));
    ui->actionMent_s_m_sk_nt->setIcon(QIcon(qApp->style()->standardIcon(QStyle::SP_DialogSaveButton)));
    ui->actionKil_p_s->setIcon(QIcon(qApp->style()->standardIcon(QStyle::SP_TitleBarCloseButton)));

    //ui->addEquationTableWidget
}

void MainWindow::setButton(bool checked)
{
    if(checked)
        button->setText("Megjelenik");
    else
        button->setText("Nem jelenik meg");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Fájl megnyitása"),
                                         QDir::currentPath(),
                                         tr("MML fájlok (*.mml)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Hiba!"),
                             tr("Fájl megnyitása sikertelen %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QDomDocument doc;    
    statusBar()->showMessage(tr("Megnyitás..."));
    if(m_Parser->read(&file,&doc)){
        updateGui(&doc);
        statusBar()->showMessage(tr("Fájl sikeresen betöltve (%1 db változó és %2 db egyenletrendszer)")
                                 .arg(m_Parser->variableCount()).arg(m_Parser->equationCount()), 4000);
    }
    else
    {
        statusBar()->showMessage(tr("Fájl betöltése sikertelen"), 4000);
    }    
}

void MainWindow::updateParser()
{
    m_Parser->clear();
    m_Parser->addAbout(ui->creatorLineEdit->text());
    m_Parser->addAbout(ui->modulNameLineEdit->text());
    m_Parser->addAbout(ui->aboutPlainTextEdit->toPlainText());
    for(int i = 0; i < ui->variablesTableWidget->rowCount(); ++i)
    {
        Variable *var = new Variable(ui->variablesTableWidget->item(i,0)->text(),
                                     ui->variablesTableWidget->item(i,1)->text().toDouble(),
                                     ui->variablesTableWidget->item(i,2)->text());
        m_Parser->addVariables(var);
    }

    for(int i = 0; i < ui->equationsTabWidget->count(); ++i)
    {
        EquationGroup *eqg = new EquationGroup(ui->equationsTabWidget->tabText(i));
        for(int j = 0; j < ui->equationsTabWidget->getTables()->at(i)->rowCount(); ++j){
            Equation *eq = new Equation(ui->equationsTabWidget->getTables()->at(i)->item(j,1)->text(),
                                        ui->equationsTabWidget->getTables()->at(i)->item(j,0)->text(),
                                        false);

            if(ui->equationsTabWidget->getTables()->at(i)->item(j,2)->backgroundColor() == Qt::green)
                eq->setDisplayed(true);            
            eqg->addEquation(eq);
        }
        m_Parser->addEquationGroup(eqg);
    }

    for(int i = 0; i < ui->curvesTableWidget->rowCount(); ++i)
    {
        Curve *curve = new Curve(ui->curvesTableWidget->item(i,1)->text(),ui->curvesTableWidget->item(i,0)->text(),
                                 ui->curvesTableWidget->item(i,2)->text(),ui->curvesTableWidget->item(i,3)->text());
        m_Parser->addCurve(curve);
    }
}

void MainWindow::saveAs()
{    
    updateParser();
    if(m_Parser->validate()){
        QString fileName =
                QFileDialog::getSaveFileName(this, tr("Fájl mentése"),
                                             QDir::currentPath(),
                                             tr("MML fájlok (*.mml)"));
        if (fileName.isEmpty())
            return;

        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Truncate | QFile::Text)) {
            QMessageBox::warning(this, tr("Hiba!"),
                                 tr("Nem sikerült elmenteni a fájlt %1:\n%2.")
                                 .arg(fileName)
                                 .arg(file.errorString()));
            return;
        }
        statusBar()->showMessage(tr("Mentés..."));
        if (m_Parser->write(&file))
            statusBar()->showMessage(tr("Fájl sikeresen elmentve"), 4000);
        else
            statusBar()->showMessage(tr("Fájl mentése sikertelen"), 4000);
    }
}

void MainWindow::addVariable()
{
    ui->variablesTableWidget->setRowCount(ui->variablesTableWidget->rowCount() + 1);
    QString name = ui->addVariableTableWidget->item(0,0) == NULL ? "" : ui->addVariableTableWidget->item(0,0)->text();
    QString value = ui->addVariableTableWidget->item(0,1) == NULL ? "" : ui->addVariableTableWidget->item(0,1)->text();
    QString info = ui->addVariableTableWidget->item(0,2) == NULL ? "" : ui->addVariableTableWidget->item(0,2)->text();
    QTableWidgetItem *namew = new QTableWidgetItem(name);
    QTableWidgetItem *valuew = new QTableWidgetItem(value);
    QTableWidgetItem *infow = new QTableWidgetItem(info);
    ui->addVariableTableWidget->clearContents();
    //name->setFlags(QFlag(0b1111101));
    //value->setFlags(QFlag(0b1111101));  // nem lehet átírni
    //info->setFlags(QFlag(0b1111101));
    ui->variablesTableWidget->setItem(ui->variablesTableWidget->rowCount() - 1,0,namew);
    ui->variablesTableWidget->setItem(ui->variablesTableWidget->rowCount() - 1,1,valuew);
    ui->variablesTableWidget->setItem(ui->variablesTableWidget->rowCount() - 1,2,infow);

}

void MainWindow::removeVariable()
{
    if( ui->variablesTableWidget->selectedItems().size() > 0)
    {
        int rowindex = ui->variablesTableWidget->selectedItems().at(0)->row();
        if(rowindex >= 0)
            ui->variablesTableWidget->removeRow(rowindex);
    }
}

void MainWindow::addEquation()
{
    QTableWidget *currentTable = ui->equationsTabWidget->getTables()->at(ui->equationsTabWidget->currentIndex());
    currentTable->setRowCount(currentTable->rowCount() + 1);
    QString name = ui->addEquationTableWidget->item(0,0) == NULL ? "" : ui->addEquationTableWidget->item(0,0)->text();
    QString value = ui->addEquationTableWidget->item(0,1) == NULL ? "" : ui->addEquationTableWidget->item(0,1)->text();
    //QString displayed = ui->addEquationTableWidget->item(0,2) == NULL ? "" : ui->addEquationTableWidget->item(0,2)->text();
    QTableWidgetItem *namew = new QTableWidgetItem(name);
    QTableWidgetItem *valuew = new QTableWidgetItem(value);
    QTableWidgetItem *displayedw = new QTableWidgetItem();
    if(!button->isChecked())
    {
        displayedw->setIcon(QIcon("icons/No.png"));
        displayedw->setBackgroundColor(Qt::red);
    }
    else
    {
        displayedw->setIcon(QIcon("icons/Yes.png"));
        displayedw->setBackgroundColor(Qt::green);
    }

    if(ui->addEquationTableWidget->item(0,0) != NULL)
        ui->addEquationTableWidget->item(0,0)->setText("");
    if(ui->addEquationTableWidget->item(0,1) != NULL)
        ui->addEquationTableWidget->item(0,1)->setText("");
    button->setChecked(false);

    currentTable->setItem(currentTable->rowCount() - 1,0,namew);
    currentTable->setItem(currentTable->rowCount() - 1,1,valuew);
    currentTable->setItem(currentTable->rowCount() - 1,2,displayedw);
}

void MainWindow::removeEquation()
{
    QTableWidget *currentTable = ui->equationsTabWidget->getTables()->at(ui->equationsTabWidget->currentIndex());
    if(currentTable->selectedItems().size() > 0) {
        int rowindex = currentTable->selectedItems().at(0)->row();
        currentTable->removeRow(rowindex);
    }
}

void MainWindow::updateGui(QDomDocument *dom)
{

    QDomElement set = dom->namedItem("mml").toElement();
    if ( set.isNull() ) {
        qWarning() << "Hiányzik az <mml> tag, érvénytelen fájl!";
        return;
    }

    QDomNode nd = set.firstChild();
    QStringList about = m_Parser->getAbout(&nd);
    ui->creatorLineEdit->setText(about.takeLast());
    ui->modulNameLineEdit->setText(about.takeLast());
    ui->aboutPlainTextEdit->appendPlainText(about.takeLast());


    nd = nd.nextSibling();
    QList<Variable*> variables = m_Parser->getVariables(&nd);

    int i = 0;
    ui->variablesTableWidget->setRowCount(variables.size());
    foreach(Variable *var,variables)
    {
        QTableWidgetItem *name = new QTableWidgetItem(var->getName());
        QString str = var->getValue() == INT_MIN ? "" : QString::number(var->getValue());
        QTableWidgetItem *value = new QTableWidgetItem(str);
        QTableWidgetItem *info = new QTableWidgetItem(var->getInfo());
        //name->setFlags(QFlag(0b1111101));
        //value->setFlags(QFlag(0b1111101));  // nem lehet átírni
        //info->setFlags(QFlag(0b1111101));
        ui->variablesTableWidget->setItem(i,0,name);
        ui->variablesTableWidget->setItem(i,1,value);
        ui->variablesTableWidget->setItem(i,2,info);
        i++;
    }

    nd = nd.nextSibling();

    QList<EquationGroup*> equationGroups = m_Parser->getEquationGroups(&nd);
    int j = 0;
    ui->equationsTabWidget->getTables()->clear();
    ui->equationsTabWidget->clear();
    foreach(EquationGroup *eqg, equationGroups){

        ui->equationsTabWidget->addNewTab(eqg->getName());
        QTableWidget *currentTable = ui->equationsTabWidget->getTables()->at(j);
        currentTable->setRowCount(eqg->getEquationCount());
        currentTable->setWindowTitle(eqg->getName());
        i = 0;
        foreach(Equation *eq, *eqg->getEquations())
        {
            QTableWidgetItem *name = new QTableWidgetItem(eq->getName());
            QTableWidgetItem *formula = new QTableWidgetItem(eq->getFormula());
            QTableWidgetItem *isDisplayed = new QTableWidgetItem();
            if(eq->getDisplayed())
            {
                isDisplayed->setIcon(QIcon("icons/Yes.png"));
                isDisplayed->setBackgroundColor(Qt::green);                
            }
            else
            {
                isDisplayed->setIcon(QIcon("icons/No.png"));
                isDisplayed->setBackgroundColor(Qt::red);
            }

            //name->setFlags(QFlag(0b1111101));
            //value->setFlags(QFlag(0b1111101));  // nem lehet átírni
            //info->setFlags(QFlag(0b1111101));
            currentTable->setItem(i,1,name);
            currentTable->setItem(i,0,formula);
            currentTable->setItem(i,2,isDisplayed);
            i++;
        }
        j++;
    }

    nd = nd.nextSibling();
    QList<Curve*> curves = m_Parser->getCurves(&nd);

    i = 0;
    ui->curvesTableWidget->setRowCount(curves.size());
    foreach(Curve *curve,curves)
    {
        QTableWidgetItem *equation = new QTableWidgetItem(curve->getFormula());
        QTableWidgetItem *name = new QTableWidgetItem(curve->getName());
        QTableWidgetItem *xaxis = new QTableWidgetItem(curve->getXAxis());
        QTableWidgetItem *yaxis = new QTableWidgetItem(curve->getYAxis());
        //name->setFlags(QFlag(0b1111101));
        //value->setFlags(QFlag(0b1111101));  // nem lehet átírni
        //info->setFlags(QFlag(0b1111101));
        ui->curvesTableWidget->setItem(i,0,equation);
        ui->curvesTableWidget->setItem(i,1,name);
        ui->curvesTableWidget->setItem(i,2,xaxis);
        ui->curvesTableWidget->setItem(i,3,yaxis);
        i++;
    }

}

void MainWindow::about()
{
    QMessageBox::about(this, tr("A programról"),
                       tr("Az <b>Adatmódosító</b> segítségével modulokat "
                          "tudunk létrehozni az <b>EconomyDisplayer</b> "
                          "programhoz."));
}

void MainWindow::addCurve()
{
    ui->curvesTableWidget->setRowCount(ui->curvesTableWidget->rowCount() + 1);
    QString name = ui->addCurveTableWidget->item(0,0) == NULL ? "" : ui->addCurveTableWidget->item(0,0)->text();
    QString value = ui->addCurveTableWidget->item(0,1) == NULL ? "" : ui->addCurveTableWidget->item(0,1)->text();
    QString xaxis = ui->addCurveTableWidget->item(0,2) == NULL ? "" : ui->addCurveTableWidget->item(0,2)->text();
    QString yaxis = ui->addCurveTableWidget->item(0,3) == NULL ? "" : ui->addCurveTableWidget->item(0,3)->text();
    QTableWidgetItem *namew = new QTableWidgetItem(name);
    QTableWidgetItem *valuew = new QTableWidgetItem(value);
    QTableWidgetItem *xaxisw = new QTableWidgetItem(xaxis);
    QTableWidgetItem *yaxisw = new QTableWidgetItem(yaxis);
    ui->addCurveTableWidget->clearContents();
    //name->setFlags(QFlag(0b1111101));
    //value->setFlags(QFlag(0b1111101));  // nem lehet átírni
    //info->setFlags(QFlag(0b1111101));
    ui->curvesTableWidget->setItem(ui->curvesTableWidget->rowCount() - 1,0,namew);
    ui->curvesTableWidget->setItem(ui->curvesTableWidget->rowCount() - 1,1,valuew);
    ui->curvesTableWidget->setItem(ui->curvesTableWidget->rowCount() - 1,2,xaxisw);
    ui->curvesTableWidget->setItem(ui->curvesTableWidget->rowCount() - 1,3,yaxisw);

}

void MainWindow::removeCurve()
{
    if( ui->curvesTableWidget->selectedItems().size() > 0)
    {
        int rowindex = ui->curvesTableWidget->selectedItems().at(0)->row();
        if(rowindex >= 0)
            ui->curvesTableWidget->removeRow(rowindex);
    }
}
