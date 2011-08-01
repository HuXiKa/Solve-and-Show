/********************************************************************************
** Form generated from reading UI file 'monetarydialog.ui'
**
** Created: Sat Jul 30 16:44:38 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONETARYDIALOG_H
#define UI_MONETARYDIALOG_H

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

class Ui_MonetaryDialog
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *MComboBox;
    QLineEdit *MChangeValueLineEdit;
    QComboBox *MUnitComboBox;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *MonetaryDialog)
    {
        if (MonetaryDialog->objectName().isEmpty())
            MonetaryDialog->setObjectName(QString::fromUtf8("MonetaryDialog"));
        MonetaryDialog->setWindowModality(Qt::WindowModal);
        MonetaryDialog->resize(454, 197);
        MonetaryDialog->setModal(true);
        gridLayout_5 = new QGridLayout(MonetaryDialog);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(MonetaryDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        MComboBox = new QComboBox(groupBox);
        MComboBox->setObjectName(QString::fromUtf8("MComboBox"));

        horizontalLayout->addWidget(MComboBox);

        MChangeValueLineEdit = new QLineEdit(groupBox);
        MChangeValueLineEdit->setObjectName(QString::fromUtf8("MChangeValueLineEdit"));

        horizontalLayout->addWidget(MChangeValueLineEdit);

        MUnitComboBox = new QComboBox(groupBox);
        MUnitComboBox->setObjectName(QString::fromUtf8("MUnitComboBox"));

        horizontalLayout->addWidget(MUnitComboBox);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 2, 4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 3, 2, 1);

        groupBox_2 = new QGroupBox(MonetaryDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(groupBox_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 2, 0, 2, 1);

        buttonBox = new QDialogButtonBox(MonetaryDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_4->addWidget(buttonBox, 3, 1, 3, 3);

        groupBox_3 = new QGroupBox(MonetaryDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 4, 0, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 5, 2, 1, 2);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


        retranslateUi(MonetaryDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), MonetaryDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MonetaryDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(MonetaryDialog);
    } // setupUi

    void retranslateUi(QDialog *MonetaryDialog)
    {
        MonetaryDialog->setWindowTitle(QApplication::translate("MonetaryDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MonetaryDialog", "Ny\303\255ltpiaci m\305\261veletek", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MonetaryDialog", "P\303\251nzk\303\255n\303\241lat", 0, QApplication::UnicodeUTF8));
        MComboBox->clear();
        MComboBox->insertItems(0, QStringList()
         << QApplication::translate("MonetaryDialog", "cs\303\266kkent\303\251se", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonetaryDialog", "n\303\266vel\303\251se", 0, QApplication::UnicodeUTF8)
        );
        MUnitComboBox->clear();
        MUnitComboBox->insertItems(0, QStringList()
         << QApplication::translate("MonetaryDialog", "sz\303\241zal\303\251kkal", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MonetaryDialog", "egys\303\251ggel", 0, QApplication::UnicodeUTF8)
        );
        groupBox_2->setTitle(QApplication::translate("MonetaryDialog", "K\303\266telez\305\221 tartal\303\251k", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MonetaryDialog", "K\303\266telez\305\221 tartal\303\251k m\303\251rt\303\251ke:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MonetaryDialog", "%", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MonetaryDialog", "Refinansz\303\255roz\303\241s", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MonetaryDialog", "Refinasz\303\255roz\303\241si kamatl\303\241b:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MonetaryDialog: public Ui_MonetaryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONETARYDIALOG_H
