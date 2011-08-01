#include "modelsettingsdialog.h"
#include "ui_modelsettingsdialog.h"
#include "abbrevations.h"

ModelSettingsDialog::ModelSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelSettingsDialog)
{
    ui->setupUi(this);
    connect(this,SIGNAL(accepted()),this,SLOT(validateSettings()));
}

ModelSettingsDialog::~ModelSettingsDialog()
{
    delete ui;
}

void ModelSettingsDialog::validateSettings(){

    if(ui->showFiscalCheckBox->isChecked()){

    }
    if(ui->showMonterayCheckBox->isChecked()){

    }
    if(ui->showStepsCheckBox->isChecked()){

    }

    abbrevations::coordinateSystemScaleable = ui->coordinateScaleableCheckBox->isChecked();
    abbrevations::useWolframAlpha = ui->useWolframAlphaCheckBox->isChecked();
}
