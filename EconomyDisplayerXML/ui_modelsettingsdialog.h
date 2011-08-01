/********************************************************************************
** Form generated from reading UI file 'modelsettingsdialog.ui'
**
** Created: Sat Jul 30 16:44:38 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELSETTINGSDIALOG_H
#define UI_MODELSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModelSettingsDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *showStepsCheckBox;
    QCheckBox *coordinateScaleableCheckBox;
    QCheckBox *useWolframAlphaCheckBox;
    QCheckBox *showMonterayCheckBox;
    QCheckBox *showFiscalCheckBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ModelSettingsDialog)
    {
        if (ModelSettingsDialog->objectName().isEmpty())
            ModelSettingsDialog->setObjectName(QString::fromUtf8("ModelSettingsDialog"));
        ModelSettingsDialog->resize(237, 189);
        ModelSettingsDialog->setModal(true);
        gridLayout = new QGridLayout(ModelSettingsDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(ModelSettingsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        showStepsCheckBox = new QCheckBox(groupBox);
        showStepsCheckBox->setObjectName(QString::fromUtf8("showStepsCheckBox"));

        verticalLayout->addWidget(showStepsCheckBox);

        coordinateScaleableCheckBox = new QCheckBox(groupBox);
        coordinateScaleableCheckBox->setObjectName(QString::fromUtf8("coordinateScaleableCheckBox"));

        verticalLayout->addWidget(coordinateScaleableCheckBox);

        useWolframAlphaCheckBox = new QCheckBox(groupBox);
        useWolframAlphaCheckBox->setObjectName(QString::fromUtf8("useWolframAlphaCheckBox"));

        verticalLayout->addWidget(useWolframAlphaCheckBox);

        showMonterayCheckBox = new QCheckBox(groupBox);
        showMonterayCheckBox->setObjectName(QString::fromUtf8("showMonterayCheckBox"));

        verticalLayout->addWidget(showMonterayCheckBox);

        showFiscalCheckBox = new QCheckBox(groupBox);
        showFiscalCheckBox->setObjectName(QString::fromUtf8("showFiscalCheckBox"));

        verticalLayout->addWidget(showFiscalCheckBox);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ModelSettingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(ModelSettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ModelSettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ModelSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ModelSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *ModelSettingsDialog)
    {
        ModelSettingsDialog->setWindowTitle(QApplication::translate("ModelSettingsDialog", "Be\303\241ll\303\255t\303\241sok", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ModelSettingsDialog", "Be\303\241ll\303\255t\303\241sok", 0, QApplication::UnicodeUTF8));
        showStepsCheckBox->setText(QApplication::translate("ModelSettingsDialog", "Megold\303\241sok levezet\303\251s\303\251nek mutat\303\241sa", 0, QApplication::UnicodeUTF8));
        coordinateScaleableCheckBox->setText(QApplication::translate("ModelSettingsDialog", "Koordin\303\241ta rendszerek sk\303\241l\303\241zhat\303\263ak", 0, QApplication::UnicodeUTF8));
        useWolframAlphaCheckBox->setText(QApplication::translate("ModelSettingsDialog", "WolframAlpha haszn\303\241lata", 0, QApplication::UnicodeUTF8));
        showMonterayCheckBox->setText(QApplication::translate("ModelSettingsDialog", "Monet\303\241ris ablak mutat\303\241sa", 0, QApplication::UnicodeUTF8));
        showFiscalCheckBox->setText(QApplication::translate("ModelSettingsDialog", "Fisk\303\241lis ablak mutat\303\241sa", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ModelSettingsDialog: public Ui_ModelSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELSETTINGSDIALOG_H
