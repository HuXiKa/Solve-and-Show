#include <QMdiArea>
#include <QMdiSubWindow>
#include <QGridLayout>
#include <QSlider>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_settingsdialog.h"
#include "settingsdialog.h"
#include "monetarydialog.h"
#include "fiscaldialog.h"
#include "modelsettingsdialog.h"
#include "initdialog.h"
#include "addequationdialog.h"
#include "coordinatesystem.h"
#include "abbrevations.h"
#include "edouble.h"
#include "equationgroup.h"

void MainWindow::setOpacity(qreal op)
{
    this->setWindowOpacity(op);
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::finalizePolicy()
{
    updateVariables();
    bool deletedCurve = false;

    for(int i = 0; i < m_CoordinateSystems.size(); ++i){
        if(m_CoordinateSystems[i]->getCurvesCount() > 1){
            deletedCurve = false;
            for(int j = 0; j < m_CoordinateSystems[i]->getCurvesCount(); ++j){
                QStringList list = m_CoordinateSystems[i]->getCurves()->at(j)->getName().split(" ");
                if(list.size() > 1){
                    m_CoordinateSystems[i]->removeCurve(list[1]);
                    deletedCurve = true;
                    j--;                // ha törlünk egyel kevesebb lesz....
                }
            }
            if(deletedCurve) m_CoordinateSystems[i]->repaint();
        }
    }
}

void MainWindow::undoPolicy()
{
    for(int i = 0; i < ui->valuesTableWidget->rowCount(); ++i){
        if(ui->valuesTableWidget->item(i,3)->text() > 0){
            abbrevations::variables[ui->valuesTableWidget->item(i,0)->text()]->setValue(ui->valuesTableWidget->item(i,1)->text().toDouble());
            QTableWidgetItem *nothing = new QTableWidgetItem;
            nothing->setFlags(QFlag(0b1111101));
            ui->valuesTableWidget->setItem(i,3,nothing);
        }
    }

    bool deletedCurve = false;

    for(int i = 0; i < m_CoordinateSystems.size(); ++i){
        if(m_CoordinateSystems[i]->getCurvesCount() > 1){
            deletedCurve = false;
            for(int j = 0; j < m_CoordinateSystems[i]->getCurvesCount(); ++j){
                QStringList list = m_CoordinateSystems[i]->getCurves()->at(j)->getName().split(" ");
                if(list.size() > 1){
                    m_CoordinateSystems[i]->removeCurve(list[0] + " " + list[1]);
                    deletedCurve = true;
                    j--;                // ha törlünk egyel kevesebb lesz....
                }
            }
            if(deletedCurve) m_CoordinateSystems[i]->repaint();
        }
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    abbrevations::mainWindow = this;
    ui->setupUi(this);
    EquationGroup *eqg = new EquationGroup;
    eqg->setName("AddedEquations");
    abbrevations::equationGroups << eqg;

    QIcon icon(qApp->style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionModul_megnyit_sa->setIcon(icon);
    QIcon icon2(qApp->style()->standardIcon(QStyle::SP_MessageBoxInformation));
    ui->actionN_vjegy->setIcon(icon2);
    QIcon icon3(":/icons/icons/qt-logo.png");
    ui->actionQt_n_vjegy->setIcon(icon3);
    ui->toolBar->actions().at(7)->setVisible(false);
    ui->toolBar->actions().at(8)->setVisible(false);
    ui->toolBar->actions().at(9)->setVisible(false);
    ui->toolBar->actions().at(10)->setVisible(false);
    ui->toolBar->actions().at(11)->setVisible(false);

    connect(ui->actionQt_n_vjegy,SIGNAL(triggered(bool)),qApp, SLOT(aboutQt()));
    connect(ui->actionV_ltoz_s_v_gleges_t_se,SIGNAL(triggered(bool)),this,SLOT(finalizePolicy()));    

    setWindowFlags(Qt::FramelessWindowHint);
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this); // make sure to create using new, since effect has to be alive as long as the target widget is using it.
    opacityEffect->setOpacity(0); // initially widget should be visible
    //this->setGraphicsEffect(opacityEffect);
    QPropertyAnimation* anim = new QPropertyAnimation(this);
    anim->setTargetObject(opacityEffect);
    anim->setPropertyName("opacity");
    anim->setDuration(1000);
    anim->setStartValue(opacityEffect->opacity());
    anim->setEndValue(1);
    anim->setEasingCurve(QEasingCurve::InQuad);
    anim->start(QAbstractAnimation::DeleteWhenStopped);

    connect(opacityEffect,SIGNAL(opacityChanged(qreal)),this,SLOT(setOpacity(qreal)));

    sd = new SettingsDialog(this);
    id = new InitDialog(this);
    md = new MonetaryDialog(this);
    fd = new FiscalDialog(this);
    msd = new ModelSettingsDialog(this);
    aed = new AddEquationDialog(this);

    connect(ui->actionBe_ll_t_sok,SIGNAL(triggered(bool)),msd,SLOT(show()));
    connect(ui->actionRajzol_s, SIGNAL(triggered(bool)), sd, SLOT(show()));
    connect(ui->action_rt_kad_s, SIGNAL(triggered(bool)), id, SLOT(show()));
    connect(ui->action_rt_kad_s, SIGNAL(triggered(bool)), id, SLOT(refreshValuesInDialog()));
    connect(id,SIGNAL(accepted()), this, SLOT(updateVariables()));
    connect(id,SIGNAL(accepted()), this, SLOT(updateCoordinateSystems()));
    connect(sd,SIGNAL(accepted()), this, SLOT(updateCoordinateSystems()));
    connect(ui->actionFisk_lis_l_p_sek, SIGNAL(triggered(bool)), fd, SLOT(show()));
    connect(ui->actionMonet_ris_l_p_sek, SIGNAL(triggered(bool)), md, SLOT(show()));
    connect(ui->actionEgyenlet_megad_sa,SIGNAL(triggered(bool)),aed,SLOT(show()));
    connect(ui->actionResetVariables, SIGNAL(triggered(bool)), this, SLOT(resetVariables()));
    connect(ui->actionShowNoValue, SIGNAL(toggled(bool)), this, SLOT(updateVariables()));

    connect(aed,SIGNAL(accepted()),this,SLOT(updateVariables()));
    connect(aed,SIGNAL(accepted()),id,SLOT(refreshValuesInDialog()));
    connect(fd,SIGNAL(accepted()), this, SLOT(execFiscalPolicy()));
    connect(fd,SIGNAL(accepted()), this, SLOT(showPolicyEffect()));

    connect(md,SIGNAL(accepted()), this, SLOT(execMonetaryPolicy()));
    connect(md,SIGNAL(accepted()), this, SLOT(showPolicyEffect()));

    connect(ui->action_rt_kad_s,SIGNAL(triggered(bool)),id,SLOT(setLineEdits()));
    showVariables();
    QList<int> sizes;
    sizes << ui->valuesTableWidget->horizontalHeader()->width() + 3;
    sizes << ui->valuesTableWidget->horizontalHeader()->width();
    ui->splitter->setSizes(sizes);    

    connect(ui->actionModul_megnyit_sa,SIGNAL(triggered()),this,SLOT(open()));
    //ui->variablesListWidget->addItems(list);    
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

    abbrevations::openFile(fileName);
    showVariables();
    id->refresh();
    sd->refreshCurveList();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete id;
    delete sd;
    delete md;
    delete fd;
    delete msd;
    delete aed;
    foreach(CoordinateSystem *cs, m_CoordinateSystems)
        delete cs;
    foreach(eDouble *e, abbrevations::variables.values())
        delete e;
    foreach(EquationGroup *eqg, abbrevations::equationGroups)
        delete eqg;
    foreach(eCurve *curve, abbrevations::curves)
        delete curve;


}

void MainWindow::showPolicyEffect()
{

    int i = 0;

    foreach(QString str , abbrevations::variables.keys()){
        double val = abbrevations::variables.value(str)->getValue();
        QTableWidgetItem *value = new QTableWidgetItem();
        val == abbrevations::noValue ? value->setText("Nincs érték") : value->setText(QString::number(val));

        QString prevVal = ui->valuesTableWidget->item(i,1)->text();
        prevVal == QString::number(abbrevations::noValue) ? prevVal = "Nincs érték" : prevVal;
        QString curVal = value->text();
        curVal == QString::number(abbrevations::noValue) ? curVal = "Nincs érték" : curVal;
        value->setFlags(QFlag(0b1111101));
        if(curVal != prevVal){
            value->setForeground(Qt::blue);

            if(val != abbrevations::noValue){
                ui->valuesTableWidget->showRow(i);
                ui->valuesTableWidget->setItem(i,3,value);
                i++;
            }
            else if(val == abbrevations::noValue && ui->actionShowNoValue->isChecked()){
                ui->valuesTableWidget->showRow(i);
                ui->valuesTableWidget->setItem(i,3,value);
                i++;
            }
            else
                ui->valuesTableWidget->hideRow(i++);
        }else
            ++i;
        //ui->valuesTableWidget->setItem(i++,2,info);
    }


    ui->valuesTableWidget->show();
    //ui->valuesTableWidget->clear();
}



void MainWindow::updateVariables()
{

    int i = 0;    
    if(ui->valuesTableWidget->rowCount() != abbrevations::variables.size()){
        ui->valuesTableWidget->clearContents();
        showVariables();
    }

    //    ui->valuesTableWidget->setRowCount(abbrevations::variables.size());
    foreach(QString str , abbrevations::variables.keys()){
        QTableWidgetItem *name = new QTableWidgetItem(str);
        double val = abbrevations::variables[str]->getValue();
        QTableWidgetItem *value = new QTableWidgetItem();
        val == abbrevations::noValue ? value->setText("Nincs érték") : value->setText(QString::number(val));
        QTableWidgetItem *info = new QTableWidgetItem(abbrevations::variables[str]->getInfo());
        //ui->valuesTableWidget->setItem(i,0,name);
        //value->setForeground(Qt::blue);

        QString prevVal = ui->valuesTableWidget->item(i,1)->text();
        prevVal == QString::number(abbrevations::noValue) ? prevVal = "Nincs érték" : prevVal;
        QString curVal = value->text();
        curVal == QString::number(abbrevations::noValue) ? curVal = "Nincs érték" : curVal;
        value->setFlags(QFlag(0b1111101));
        if(curVal != prevVal)
            value->setForeground(Qt::blue);

        if(val != abbrevations::noValue){
            ui->valuesTableWidget->showRow(i);
            ui->valuesTableWidget->setItem(i,0,name);
            ui->valuesTableWidget->setItem(i,1,value);
            ui->valuesTableWidget->setItem(i,2,info);
            ui->valuesTableWidget->setItem(i,3,new QTableWidgetItem());
            i++;
        }
        else if(val == abbrevations::noValue && ui->actionShowNoValue->isChecked()){
            ui->valuesTableWidget->showRow(i);
            ui->valuesTableWidget->setItem(i,0,name);
            ui->valuesTableWidget->setItem(i,1,value);
            ui->valuesTableWidget->setItem(i,2,info);
            i++;
        }
        else
            ui->valuesTableWidget->hideRow(i++);

        //ui->valuesTableWidget->setItem(i++,2,info);
    }


    ui->valuesTableWidget->show();
    //ui->valuesTableWidget->clear();
}

void MainWindow::showVariables()
{

    int i = 0;
    ui->valuesTableWidget->setRowCount(abbrevations::variables.size());
    foreach(QString str , abbrevations::variables.keys()){
        QTableWidgetItem *name = new QTableWidgetItem(str);
        QString val = QString::number(abbrevations::variables[str]->getValue());
        val == QString::number(abbrevations::noValue) ? val = "Nincs érték" : val;
        QTableWidgetItem *value = new QTableWidgetItem(val);
        QTableWidgetItem *info = new QTableWidgetItem(abbrevations::variables.value(str)->getInfo());
        name->setFlags(QFlag(0b1111101));
        value->setFlags(QFlag(0b1111101));  // nem lehet átírni
        info->setFlags(QFlag(0b1111101));
        ui->valuesTableWidget->setItem(i,0,name);
        ui->valuesTableWidget->setItem(i,1,value);
        ui->valuesTableWidget->setItem(i,2,info);

        i++;
    }
    // ui->valuesTableWidget->item(abbrevations::variables.keys().size(),1)->setText("maci");
    QList<int> sizes;
    sizes.push_back(ui->valuesTableWidget->horizontalHeader()->widthMM() * 6);
    sizes.push_back(width());
    ui->splitter->setSizes(sizes);
}

void MainWindow::updateCoordinateSystems()
{
    for(int i = 0; i < m_CoordinateSystems.size(); ++i)
        if(!m_CoordinateSystems.at(i)->parentWidget()->isVisible())
            m_CoordinateSystems.removeAt(i);


    int count = sd->getUI()->coordinateSystemsTreeWidget->topLevelItemCount();
    for(int i = 0; i < count; ++i)
    {
        QTreeWidgetItem *top = sd->getUI()->coordinateSystemsTreeWidget->topLevelItem(i);
        addCurvesToCoordinateSystems(top);
    }

}

void MainWindow::resetVariables()
{
    abbrevations::resetVariables();
    updateVariables();
}

QGridLayout * MainWindow::setSubWindowLayout(QGridLayout * gridLayout, CoordinateSystem * cs){

    gridLayout->addWidget(cs, 0, 0, 3, 3);
    if(abbrevations::coordinateSystemScaleable)
    {
        QPushButton *pushButton = new QPushButton("+");
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(21, 21));

        gridLayout->addWidget(pushButton, 0, 3, 1, 1);

        QSpacerItem *verticalSpacer = new QSpacerItem(20, 199, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 3, 1, 1);

        QPushButton *pushButton_2 = new QPushButton("-");
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMaximumSize(QSize(21, 21));

        gridLayout->addWidget(pushButton_2, 2, 3, 1, 1);

        QPushButton *pushButton_4 = new QPushButton("-");
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMaximumSize(QSize(21, 21));

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        QSpacerItem *horizontalSpacer = new QSpacerItem(398, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        QPushButton *pushButton_3 = new QPushButton("+");
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMaximumSize(QSize(21, 21));

        gridLayout->addWidget(pushButton_3, 3, 2, 1, 1);

        connect(pushButton, SIGNAL(clicked()), cs, SLOT(setYScaleP()));
        connect(pushButton_2, SIGNAL(clicked()), cs, SLOT(setYScaleM()));
        connect(pushButton_3, SIGNAL(clicked()), cs, SLOT(setXScaleP()));
        connect(pushButton_4, SIGNAL(clicked()), cs, SLOT(setXScaleM()));
        gridLayout->setVerticalSpacing(0);
        gridLayout->setHorizontalSpacing(0);
    }
    return gridLayout;
}

void MainWindow::execFiscalPolicy()
{        
    double prevT = abbrevations::variables["T"]->getValue();
    double prevr = abbrevations::variables["r"]->getValue();
    if(prevT == fd->getNewT() && prevr == fd->getNewr()) return;

    abbrevations::changeVar("T", fd->getNewT());
    abbrevations::changeVar("r", fd->getNewr());

    abbrevations::calculate();
    foreach(CoordinateSystem *cs , m_CoordinateSystems){
        foreach(eCurve *curve, *cs->getCurves())
            foreach(eDouble *e, curve->getVariables())
                if(e->getName() == "T" || e->getName() == "r"){
                    eCurve *newCurve = new eCurve(cs, curve);
                    cs->addCurve(newCurve);
                    cs->repaint();
                    break;
                }
        /*if(cs->getName() == "Keynesi kereszt"){
                eCurve *newKeynes = new eCurve("új várt GDP",eCurve::KeynesianCross, cs);
                cs->addCurve(newKeynes);
                cs->repaint();
            }
            else if(cs->getName() == "IS görbe"){
                eCurve *newIS = new eCurve("új IS",eCurve::IS, cs);
                cs->addCurve(newIS);
                cs->repaint();
            }
            else if(cs->getName() == "IS"){
                eCurve *newIS = new eCurve("új IS",eCurve::IS, cs);
                cs->addCurve(newIS);
                cs->repaint();
            }
            else if(cs->getName() == "IS - LM"){
                eCurve *newIS = new eCurve("új IS",eCurve::IS, cs);
                cs->addCurve(newIS);
                cs->repaint();
            }
            else if(cs->getName() == "Beruházási piac"){
                eCurve *newInvestS = new eCurve("új beruházási kínálat",eCurve::InvestSupply, cs);
                cs->addCurve(newInvestS);
                cs->repaint();
            }
        }
        if(prevr != fd->getNewr()){
            if(cs->getName() == "Beruházási piac"){
                eCurve *newInvestD = new eCurve("új beruházási kereslet",eCurve::InvestDemand, cs);
                eCurve *newInvestS = new eCurve("új beruházási kínálat",eCurve::InvestSupply, cs);
                cs->addCurve(newInvestS);
                cs->addCurve(newInvestD);
                cs->repaint();
            }
            else if(cs->getName() == "IS görbe"){
                eCurve *newIS = new eCurve("új IS",eCurve::IS, cs);
                cs->addCurve(newIS);
                cs->repaint();
            }
            else if(cs->getName() == "IS"){
                eCurve *newIS = new eCurve("új IS",eCurve::IS, cs);
                cs->addCurve(newIS);
                cs->repaint();
            }
            else if(cs->getName() == "Pénzpiac"){
                eCurve *newMoneyD = new eCurve("új pénzkereslet",eCurve::MoneyDemand, cs);
                eCurve *newMoneyS = new eCurve("új pénzkínálat",eCurve::MoneySupply, cs);
                cs->addCurve(newMoneyD);
                cs->addCurve(newMoneyS);
                cs->repaint();
            }
            else if(cs->getName() == "LM görbe"){
                eCurve *newLM = new eCurve("új LM",eCurve::LM, cs);
                cs->addCurve(newLM);
                cs->repaint();
            }
            else if(cs->getName() == "LM"){
                eCurve *newIS = new eCurve("új LM",eCurve::IS, cs);
                cs->addCurve(newIS);
                cs->repaint();
            }
            else if(cs->getName() == "IS - LM"){
                eCurve *newIS = new eCurve("új IS",eCurve::IS, cs);
                eCurve *newLM = new eCurve("új LM",eCurve::LM, cs);
                cs->addCurve(newIS);
                cs->addCurve(newLM);
                cs->repaint();
            }
        }*/

    }
}

void MainWindow::execMonetaryPolicy()
{
    double prevM = abbrevations::variables["M"]->getValue();
    if(prevM == md->getNewM() ) return;

    abbrevations::changeVar("M", md->getNewM());
    //abbrevations::changeVar("M/P", md->getNewM() / abbrevations::variables["P"]->getValue());

    //abbrevations::calculate();
    foreach(CoordinateSystem *cs , m_CoordinateSystems){
        foreach(eCurve *curve, *cs->getCurves())
            foreach(eDouble *e, curve->getVariables()){
                if(e->getName() == "M" || e->getName() == "P"){
                    eCurve *newCurve = new eCurve(cs, curve);
                    cs->addCurve(newCurve);
                    cs->repaint();
                    break;
                }
            }
        /*if(cs->getName() == "AS - AD"){
            eCurve *newAD = new eCurve("új AD",eCurve::AggregateDemand, cs);
            eCurve *newLRAS = new eCurve("új LRAS",eCurve::LongRangeAggregateSupply, cs);
            cs->addCurve(newAD);
            cs->addCurve(newLRAS);
            cs->repaint();
        }
        if(cs->getName() == "Pénzpiac"){
            eCurve *newMoneyS = new eCurve("új pénzkereslet",eCurve::MoneySupply, cs);
            cs->addCurve(newMoneyS);
            cs->repaint();
        }
        if(cs->getName() == "LM görbe"){
            eCurve *newLM = new eCurve("új LM",eCurve::LM, cs);
            cs->addCurve(newLM);
            cs->repaint();
        }
        if(cs->getName() == "LM"){
            eCurve *newLM = new eCurve("új LM",eCurve::LM, cs);
            cs->addCurve(newLM);
            cs->repaint();
        }
        if(cs->getName() == "IS - LM"){
            eCurve *newLM = new eCurve("új LM",eCurve::LM, cs);
            cs->addCurve(newLM);
            cs->repaint();
        }*/
    }
}

void MainWindow::calculate()
{
    abbrevations::solve();
    updateVariables();
}

void MainWindow::setFullscreenMode(bool fullscreen){

    if(fullscreen){
        showMaximized();
        setWindowFlags(Qt::FramelessWindowHint);
        this->window()->showMaximized();
    }
    else{
        showNormal();
        setWindowFlags(0);
        this->window()->showNormal();
    }
}

CoordinateSystem * MainWindow::addCurvesToCoordinateSystems(QTreeWidgetItem *top, CoordinateSystem *cs)
{
    QWidget *widget = new QWidget;
    QMdiSubWindow *sub = new QMdiSubWindow;    
    eCurve *curve = NULL;
    QList<CoordinateSystem*> coorsystems;
    bool moreThanOneCoordinateSystems = false, topLevel = true;
    if(!cs){
        cs = new CoordinateSystem(top->text(0),sub);
    }
    else{
        topLevel = false;
        cs = new CoordinateSystem(top->text(0),sub);
    }

    for(int i = 0; i < top->childCount(); ++i)
    {
        if(top->child(i)->childCount() > 0){
            coorsystems << addCurvesToCoordinateSystems(top->child(i),cs);
            moreThanOneCoordinateSystems = true;
        }
        else{
            foreach(eCurve *c, abbrevations::curves)
                if(c->getName() == top->child(i)->text(0)){
                    curve = c;
                    curve->setContainer(cs);
                    curve->setName(top->child(i)->text(0));
                    break;
                }
        }

        if(top->child(i)->childCount() == 0)
            cs->addCurve(curve);
    }

    if(!topLevel) return cs;

    if(moreThanOneCoordinateSystems){
        if(coorsystems.size() == 3){

            foreach(CoordinateSystem *cs, coorsystems){
                m_CoordinateSystems << cs;
                cs->repaint();
            }

            QGridLayout *gridLayout1 = new QGridLayout;
            gridLayout1 = setSubWindowLayout(gridLayout1, coorsystems.at(0));
            QGridLayout *gridLayout2 = new QGridLayout;
            gridLayout2 = setSubWindowLayout(gridLayout2, coorsystems.at(2));
            QGridLayout *gridLayout3 = new QGridLayout;
            gridLayout3 = setSubWindowLayout(gridLayout3, coorsystems.at(1));

            QGridLayout *gridLayout = new QGridLayout;

            gridLayout->addLayout(gridLayout1,0,1,1,1);     //gridLayout->addWidget(keynes, 0, 1, 1, 1);
            gridLayout->addLayout(gridLayout2,1,0,1,1);     //gridLayout->addWidget(ISR, 1, 0, 1, 1);
            gridLayout->addLayout(gridLayout3,1,1,1,1);     //gridLayout->addWidget(IS, 1, 1, 1, 1);

            widget->setLayout(gridLayout);
            sub->setWidget(widget);


        }
        else if(coorsystems.size() == 2){

            foreach(CoordinateSystem *cs, coorsystems){
                m_CoordinateSystems << cs;
                cs->repaint();
            }

            QGridLayout *gridLayout1 = new QGridLayout;
            gridLayout1 = setSubWindowLayout(gridLayout1, coorsystems.at(0));
            QGridLayout *gridLayout2 = new QGridLayout;
            gridLayout2 = setSubWindowLayout(gridLayout2, coorsystems.at(1));

            QGridLayout *gridLayout = new QGridLayout;

            gridLayout->addLayout(gridLayout1,0,0,1,1); //gridLayout->addWidget(money, 0, 0, 1, 1);
            gridLayout->addLayout(gridLayout2,0,1,1,1); //gridLayout->addWidget(LM, 0, 1, 1, 1);

            widget->setLayout(gridLayout);
            sub->setWidget(widget);
        }
    }

    else{
        m_CoordinateSystems << cs;
        cs->repaint();

        QGridLayout *gridLayout = new QGridLayout;
        gridLayout = setSubWindowLayout(gridLayout,cs);

        widget->setLayout(gridLayout);

        sub->setWidget(widget);
    }

    sub->setWindowTitle(top->text(0));
    ui->mdi->addSubWindow(sub);
    //sub->setWindowFlags( Qt::CustomizeWindowHint |Qt::WindowTitleHint| Qt::WindowMinMaxButtonsHint );
    sub->show();
    return cs;
}
