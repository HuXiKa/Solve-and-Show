#include "fiscaldialog.h"
#include "ui_fiscaldialog.h"
#include "abbrevations.h"
#include "mainwindow.h"
#include "coordinatesystem.h"
#include "edouble.h"

FiscalDialog::FiscalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FiscalDialog)
{
    ui->setupUi(this);

    connect(this, SIGNAL(accepted()), this, SLOT(processData()));
}

FiscalDialog::~FiscalDialog()
{
    delete ui;
}

void FiscalDialog::changeEvent(QEvent *e)
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

void FiscalDialog::processData()
{
    if(ui->taxChangeValueLineEdit->text().size() > 0)
    {
        double prevT = abbrevations::variables["T"]->getValue();
        double change = ui->taxChangeValueLineEdit->text().toDouble();        
        int pm;
        ui->taxComboBox->currentText() == "csökkentése" ? pm = -1 : pm = 1;
        bool isPercent;
        ui->taxUnitComboBox->currentText() == "százalékkal" ? isPercent = true : isPercent = false;
        if(isPercent == true){
            m_NewT = prevT + (pm * (prevT * change / 100));

        }else{
            m_NewT = prevT + (pm * change);

        }
    }else m_NewT = abbrevations::variables["T"]->getValue();

    if(ui->rChangeValueLineEdit->text().size() > 0)
    {
        double prevr = abbrevations::variables["r"]->getValue();
        double change = ui->rChangeValueLineEdit->text().toDouble();        
        int pm;
        ui->rComboBox->currentText() == "csökkentése"  ? pm = -1 : pm = 1;
        bool isPercent;
        ui->rUnitComboBox->currentText() == "százalékkal" ? isPercent = true : isPercent = false;
        if(isPercent == true){
            m_Newr = prevr + (pm * (prevr * change / 100));
        }else{
            m_Newr = prevr + (pm * change);

        }        
    } else m_Newr = abbrevations::variables["r"]->getValue();
}
