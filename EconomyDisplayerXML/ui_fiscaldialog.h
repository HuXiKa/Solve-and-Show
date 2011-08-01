/********************************************************************************
** Form generated from reading UI file 'fiscaldialog.ui'
**
** Created: Sat Jul 30 16:44:38 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FISCALDIALOG_H
#define UI_FISCALDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_FiscalDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *taxComboBox;
    QLineEdit *taxChangeValueLineEdit;
    QComboBox *taxUnitComboBox;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *rComboBox;
    QLineEdit *rChangeValueLineEdit;
    QComboBox *rUnitComboBox;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *FiscalDialog)
    {
        if (FiscalDialog->objectName().isEmpty())
            FiscalDialog->setObjectName(QString::fromUtf8("FiscalDialog"));
        FiscalDialog->setWindowModality(Qt::WindowModal);
        FiscalDialog->resize(410, 177);
        FiscalDialog->setModal(true);
        gridLayout_3 = new QGridLayout(FiscalDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(FiscalDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        taxComboBox = new QComboBox(groupBox);
        taxComboBox->setObjectName(QString::fromUtf8("taxComboBox"));

        horizontalLayout->addWidget(taxComboBox);

        taxChangeValueLineEdit = new QLineEdit(groupBox);
        taxChangeValueLineEdit->setObjectName(QString::fromUtf8("taxChangeValueLineEdit"));

        horizontalLayout->addWidget(taxChangeValueLineEdit);

        taxUnitComboBox = new QComboBox(groupBox);
        taxUnitComboBox->setObjectName(QString::fromUtf8("taxUnitComboBox"));

        horizontalLayout->addWidget(taxUnitComboBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 3);

        groupBox_2 = new QGroupBox(FiscalDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        rComboBox = new QComboBox(groupBox_2);
        rComboBox->setObjectName(QString::fromUtf8("rComboBox"));

        horizontalLayout_2->addWidget(rComboBox);

        rChangeValueLineEdit = new QLineEdit(groupBox_2);
        rChangeValueLineEdit->setObjectName(QString::fromUtf8("rChangeValueLineEdit"));

        horizontalLayout_2->addWidget(rChangeValueLineEdit);

        rUnitComboBox = new QComboBox(groupBox_2);
        rUnitComboBox->setObjectName(QString::fromUtf8("rUnitComboBox"));

        horizontalLayout_2->addWidget(rUnitComboBox);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(FiscalDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(109, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 2, 1, 1);


        retranslateUi(FiscalDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), FiscalDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FiscalDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(FiscalDialog);
    } // setupUi

    void retranslateUi(QDialog *FiscalDialog)
    {
        FiscalDialog->setWindowTitle(QApplication::translate("FiscalDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("FiscalDialog", "Ad\303\263politika", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FiscalDialog", "Ad\303\263k", 0, QApplication::UnicodeUTF8));
        taxComboBox->clear();
        taxComboBox->insertItems(0, QStringList()
         << QApplication::translate("FiscalDialog", "cs\303\266kkent\303\251se", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FiscalDialog", "n\303\266vel\303\251se", 0, QApplication::UnicodeUTF8)
        );
        taxUnitComboBox->clear();
        taxUnitComboBox->insertItems(0, QStringList()
         << QApplication::translate("FiscalDialog", "sz\303\241zal\303\251kkal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FiscalDialog", "egys\303\251ggel", 0, QApplication::UnicodeUTF8)
        );
        groupBox_2->setTitle(QApplication::translate("FiscalDialog", "Kamatpolitika", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FiscalDialog", "Kamatl\303\241b", 0, QApplication::UnicodeUTF8));
        rComboBox->clear();
        rComboBox->insertItems(0, QStringList()
         << QApplication::translate("FiscalDialog", "cs\303\266kkent\303\251se", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FiscalDialog", "n\303\266vel\303\251se", 0, QApplication::UnicodeUTF8)
        );
        rUnitComboBox->clear();
        rUnitComboBox->insertItems(0, QStringList()
         << QApplication::translate("FiscalDialog", "sz\303\241zal\303\251kkal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("FiscalDialog", "egys\303\251ggel", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class FiscalDialog: public Ui_FiscalDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FISCALDIALOG_H
