#include <QSignalMapper>

#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "abbrevations.h"
#include "ecurve.h"

enum ID {SRAS, AS_AD, OUTPUT, KEYNES, IS, LM, LABOUR, INVEST, IS_LM, LRAS};
QSignalMapper *signalMapper;

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);        

    ui->groupBox->setVisible(false);
    ui->groupBox_2->setVisible(false);
    ui->groupBox_3->setVisible(false);
    refreshCurveList();

    connect(this, SIGNAL(accepted()), this, SLOT(hide()));

    ui->addableLinesListWidget->sortItems();

    signalMapper = new QSignalMapper(this);
    signalMapper->setMapping(ui->SRASCheckBox, SRAS);
    signalMapper->setMapping(ui->ASADCheckBox, AS_AD);
    signalMapper->setMapping(ui->outputCheckBox, OUTPUT);
    signalMapper->setMapping(ui->keynesCheckBox, KEYNES);
    signalMapper->setMapping(ui->ISCheckBox, IS);
    signalMapper->setMapping(ui->LMCheckBox, LM);
    signalMapper->setMapping(ui->labourCheckBox, LABOUR);
    signalMapper->setMapping(ui->ISRCheckBox, INVEST);
    signalMapper->setMapping(ui->ISLMCheckBox, IS_LM);
    signalMapper->setMapping(ui->LRASCheckBox, LRAS);


    connect(signalMapper, SIGNAL(mapped(int)),
            this, SLOT(addCoordinateSystem(int)));

    connect(ui->SRASCheckBox, SIGNAL(clicked()),
            signalMapper, SLOT (map()));
    connect(ui->ASADCheckBox, SIGNAL(clicked()),
            signalMapper, SLOT (map()));
    connect(ui->outputCheckBox, SIGNAL(clicked()),
            signalMapper, SLOT (map()));
    connect(ui->keynesCheckBox, SIGNAL(clicked()),
            signalMapper, SLOT (map()));
    connect(ui->ISCheckBox, SIGNAL(clicked()),
            signalMapper, SLOT (map()));
    connect(ui->LMCheckBox, SIGNAL(clicked()),
            signalMapper, SLOT (map()));
    connect(ui->labourCheckBox, SIGNAL(clicked()),
            signalMapper, SLOT (map()));
    connect(ui->ISRCheckBox, SIGNAL(clicked()),
            signalMapper, SLOT (map()));
    connect(ui->ISLMCheckBox, SIGNAL(clicked()),
            signalMapper, SLOT (map()));
    connect(ui->LRASCheckBox, SIGNAL(clicked()),
            signalMapper, SLOT (map()));


}

void SettingsDialog::refreshCurveList()
{
    ui->addableLinesListWidget->clear();
    foreach(eCurve *curve, abbrevations::curves)
        ui->addableLinesListWidget->addItem(curve->getName());
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SettingsDialog::addLines()
{
    QStringList list;
    foreach(QListWidgetItem *item, ui->addableLinesListWidget->selectedItems())
        list << item->text();

    ui->addedLinesListWidget->addItems(list);

    for(int i = 0; i < ui->addableLinesListWidget->count(); ++i){
        if(ui->addableLinesListWidget->item(i)->isSelected()){
            ui->addableLinesListWidget->takeItem(i);
            i--;
        }
    }

    ui->addableLinesListWidget->sortItems();
    ui->addedLinesListWidget->sortItems();
}

void SettingsDialog::removeLines()
{
    QStringList list;
    foreach(QListWidgetItem *item, ui->addedLinesListWidget->selectedItems())
        list << item->text();

    ui->addableLinesListWidget->addItems(list);

    for(int i = 0; i < ui->addedLinesListWidget->count(); ++i){
        if(ui->addedLinesListWidget->item(i)->isSelected()){
            ui->addedLinesListWidget->takeItem(i);
            i--;
        }
    }

    ui->addableLinesListWidget->sortItems();
    ui->addedLinesListWidget->sortItems();
}

void SettingsDialog::addCoordinateSystem()
{
    if(ui->addedLinesListWidget->count() == 0) return;
    int count = ui->coordinateSystemsTreeWidget->topLevelItemCount();
    int size = ui->addedLinesListWidget->count();

    QString name = "";
    for(int i = 0; i < size; ++i)
        name = name + ui->addedLinesListWidget->item(i)->text() + " ";

    QTreeWidgetItem * top = new QTreeWidgetItem((QTreeWidget*)0, QStringList(name));

    for(int i = 0; i < size; ++i){
        QTreeWidgetItem * child = new QTreeWidgetItem(top);
        QString text = ui->addedLinesListWidget->item(i)->text();
        child->setText(0,text);
    }

    ui->coordinateSystemsTreeWidget->insertTopLevelItem(count,top);

    QStringList list;

    for(int i = 0; i < size; ++i)
        list << ui->addedLinesListWidget->item(i)->text();

    ui->addableLinesListWidget->addItems(list);

    ui->addedLinesListWidget->clear();


    ui->addableLinesListWidget->sortItems();

}

void SettingsDialog::removeCoordinateSystem()
{
    if(ui->coordinateSystemsTreeWidget->selectedItems().size() == 0) return;
    QTreeWidgetItem* selected = ui->coordinateSystemsTreeWidget->selectedItems().first();

    int index = ui->coordinateSystemsTreeWidget->indexOfTopLevelItem(selected);
    QStringList list;
    for(int i = 0; i < selected->childCount(); ++i){
        list << selected->child(i)->text(0);
    }

    ui->addedLinesListWidget->addItems(list);
    for(int i = 0; i < ui->addableLinesListWidget->count(); ++i){
        QString s = ui->addableLinesListWidget->item(i)->text();
        if(list.contains(s)){
            ui->addableLinesListWidget->takeItem(i--);
        }
    }

    ui->coordinateSystemsTreeWidget->takeTopLevelItem(index);
    //selected->parent()->removeChild(selected);
}

void manageCoordinateSystem(bool isChecked){

}

void SettingsDialog::addCoordinateSystem(int id)
{

    QCheckBox *sender = static_cast<QCheckBox*>(signalMapper->mapping(id));
    QTreeWidgetItem * top = new QTreeWidgetItem((QTreeWidget*)0, QStringList(sender->text()));

    switch(id){
    case SRAS :
    {
        if(ui->SRASCheckBox->isChecked()){
            QTreeWidgetItem * child = new QTreeWidgetItem(top);
            child->setText(0,"SRAS");
        }
        else{
            for(int i = 0; i < ui->coordinateSystemsTreeWidget->topLevelItemCount(); ++i)
                if(ui->coordinateSystemsTreeWidget->topLevelItem(i)->text(0) == sender->text())
                    ui->coordinateSystemsTreeWidget->takeTopLevelItem(i);
        }
        break;
    }
    case AS_AD:
    {
        if(ui->ASADCheckBox->isChecked()){
            QTreeWidgetItem * child = new QTreeWidgetItem(top);
            child->setText(0,"AD");
            child = new QTreeWidgetItem(top);
            child->setText(0,"SRAS");
            child = new QTreeWidgetItem(top);
            child->setText(0,"LRAS");
        }
        else{
            for(int i = 0; i < ui->coordinateSystemsTreeWidget->topLevelItemCount(); ++i)
                if(ui->coordinateSystemsTreeWidget->topLevelItem(i)->text(0) == sender->text())
                    ui->coordinateSystemsTreeWidget->takeTopLevelItem(i);
        }
        break;
    }
    case OUTPUT:
    {
        if(ui->outputCheckBox->isChecked()){
            QTreeWidgetItem * child = new QTreeWidgetItem(top);
            child->setText(0,"Kibocsátás");
        }
        else{
            for(int i = 0; i < ui->coordinateSystemsTreeWidget->topLevelItemCount(); ++i)
                if(ui->coordinateSystemsTreeWidget->topLevelItem(i)->text(0) == sender->text())
                    ui->coordinateSystemsTreeWidget->takeTopLevelItem(i);
        }
        break;
    }
    case LABOUR:
    {
        if(ui->labourCheckBox->isChecked()){
            QTreeWidgetItem * child = new QTreeWidgetItem(top);
            child->setText(0,"Munkakereslet");
            child = new QTreeWidgetItem(top);
            child->setText(0,"Munkakínálat");
        }
        else{
            for(int i = 0; i < ui->coordinateSystemsTreeWidget->topLevelItemCount(); ++i)
                if(ui->coordinateSystemsTreeWidget->topLevelItem(i)->text(0) == sender->text())
                    ui->coordinateSystemsTreeWidget->takeTopLevelItem(i);
        }
        break;
    }
    case INVEST:
    {
        if(ui->ISRCheckBox->isChecked()){
            QTreeWidgetItem * child = new QTreeWidgetItem(top);
            child->setText(0,"Beruházási kereslet");
            child = new QTreeWidgetItem(top);
            child->setText(0,"Beruházási kínálat");
        }
        else{
            for(int i = 0; i < ui->coordinateSystemsTreeWidget->topLevelItemCount(); ++i)
                if(ui->coordinateSystemsTreeWidget->topLevelItem(i)->text(0) == sender->text())
                    ui->coordinateSystemsTreeWidget->takeTopLevelItem(i);
        }
        break;
    }
    case KEYNES:
    {
        if(ui->keynesCheckBox->isChecked()){
            QTreeWidgetItem * child = new QTreeWidgetItem(top);
            child->setText(0,"Tervezett kibocsátás");
            child = new QTreeWidgetItem(top);
            child->setText(0,"Y = E");
        }
        else{
            for(int i = 0; i < ui->coordinateSystemsTreeWidget->topLevelItemCount(); ++i)
                if(ui->coordinateSystemsTreeWidget->topLevelItem(i)->text(0) == sender->text())
                    ui->coordinateSystemsTreeWidget->takeTopLevelItem(i);
        }
        break;
    }
    case IS:
    {
        if(ui->ISCheckBox->isChecked()){
            QTreeWidgetItem * isr = new QTreeWidgetItem(top);
            isr->setText(0,"Beruházási piac");
            QTreeWidgetItem *inv = new QTreeWidgetItem(isr);
            inv->setText(0,"Beruházási kereslet");
            inv = new QTreeWidgetItem(isr);
            inv->setText(0,"Beruházási kínálat");

            QTreeWidgetItem * keynes = new QTreeWidgetItem(top);
            keynes->setText(0,"Keynesi kereszt");
            QTreeWidgetItem * k = new QTreeWidgetItem(keynes);
            k->setText(0,"Tervezett kibocsátás");
            k = new QTreeWidgetItem(keynes);
            k->setText(0,"Y = E");

            QTreeWidgetItem * IS = new QTreeWidgetItem(top);
            IS->setText(0,"IS görbe");
            QTreeWidgetItem * is = new QTreeWidgetItem(IS);
            is->setText(0,"IS");
        }
        else{
            for(int i = 0; i < ui->coordinateSystemsTreeWidget->topLevelItemCount(); ++i)
                if(ui->coordinateSystemsTreeWidget->topLevelItem(i)->text(0) == sender->text())
                    ui->coordinateSystemsTreeWidget->takeTopLevelItem(i);
        }
        break;
    }
    case LM:
    {
        if(ui->LMCheckBox->isChecked()){
            QTreeWidgetItem * money = new QTreeWidgetItem(top);
            money->setText(0,"Pénzpiac");
            QTreeWidgetItem *m = new QTreeWidgetItem(money);
            m->setText(0,"Pénzkereslet");
            m = new QTreeWidgetItem(money);
            m->setText(0,"Pénzkínálat");

            QTreeWidgetItem * LM = new QTreeWidgetItem(top);
            LM->setText(0,"LM görbe");
            QTreeWidgetItem * lm = new QTreeWidgetItem(LM);
            lm->setText(0,"LM");
        }
        else{
            for(int i = 0; i < ui->coordinateSystemsTreeWidget->topLevelItemCount(); ++i)
                if(ui->coordinateSystemsTreeWidget->topLevelItem(i)->text(0) == sender->text())
                    ui->coordinateSystemsTreeWidget->takeTopLevelItem(i);
        }
        break;
    }
    case IS_LM:
    {
        if(ui->ISLMCheckBox->isChecked()){
            QTreeWidgetItem * child = new QTreeWidgetItem(top);
            child->setText(0,"IS");
            child = new QTreeWidgetItem(top);
            child->setText(0,"LM");
        }
        else{
            for(int i = 0; i < ui->coordinateSystemsTreeWidget->topLevelItemCount(); ++i)
                if(ui->coordinateSystemsTreeWidget->topLevelItem(i)->text(0) == sender->text())
                    ui->coordinateSystemsTreeWidget->takeTopLevelItem(i);
        }
        break;
    }
    case LRAS :
    {
        if(ui->LRASCheckBox->isChecked()){
            QTreeWidgetItem * child = new QTreeWidgetItem(top);
            child->setText(0,"LRAS");
        }
        else{
            for(int i = 0; i < ui->coordinateSystemsTreeWidget->topLevelItemCount(); ++i)
                if(ui->coordinateSystemsTreeWidget->topLevelItem(i)->text(0) == sender->text())
                    ui->coordinateSystemsTreeWidget->takeTopLevelItem(i);
        }
        break;
    }
    }

    if(top->childCount() > 0){
        int count = ui->coordinateSystemsTreeWidget->topLevelItemCount();
        ui->coordinateSystemsTreeWidget->insertTopLevelItem(count,top);
    }


}
