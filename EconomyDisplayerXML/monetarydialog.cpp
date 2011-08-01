#include "monetarydialog.h"
#include "ui_monetarydialog.h"
#include "abbrevations.h"
#include "edouble.h"

MonetaryDialog::MonetaryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MonetaryDialog)
{
    ui->setupUi(this);

    connect(this, SIGNAL(accepted()), this, SLOT(processData()));
}

MonetaryDialog::~MonetaryDialog()
{
    delete ui;
}

void MonetaryDialog::changeEvent(QEvent *e)
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

void MonetaryDialog::processData()
{
    if(ui->MChangeValueLineEdit->text().size() > 0)
    {
        double prevM = abbrevations::variables["M"]->getValue();
        double change = ui->MChangeValueLineEdit->text().toDouble();
        int pm;
        ui->MComboBox->currentText() == "csökkentése" ? pm = -1 : pm = 1;
        bool isPercent;
        ui->MUnitComboBox->currentText() == "százalékkal" ? isPercent = true : isPercent = false;
        if(isPercent == true){
            m_NewM = prevM + (pm * (prevM * change / 100));

        }else{
            m_NewM = prevM + (pm * change);

        }
    }else m_NewM = abbrevations::variables["M"]->getValue();

}

double MonetaryDialog::getNewM()
{
    return m_NewM;
}
