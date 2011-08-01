/********************************************************************************
** Form generated from reading UI file 'equationtab.ui'
**
** Created: Sat Jul 30 16:44:38 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUATIONTAB_H
#define UI_EQUATIONTAB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EquationTab
{
public:
    QGridLayout *gridLayout_5;
    QLabel *nameLabel;
    QGroupBox *formulaLabelGroup;
    QGridLayout *gridLayout_3;
    QHBoxLayout *formulaHorizontalLayout;
    QTextEdit *formulaTextEdit;
    QGroupBox *valueSetterBox;
    QGridLayout *valueSettersGridLayout;

    void setupUi(QWidget *EquationTab)
    {
        if (EquationTab->objectName().isEmpty())
            EquationTab->setObjectName(QString::fromUtf8("EquationTab"));
        EquationTab->resize(421, 342);
        gridLayout_5 = new QGridLayout(EquationTab);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        nameLabel = new QLabel(EquationTab);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        gridLayout_5->addWidget(nameLabel, 0, 0, 1, 1);

        formulaLabelGroup = new QGroupBox(EquationTab);
        formulaLabelGroup->setObjectName(QString::fromUtf8("formulaLabelGroup"));
        gridLayout_3 = new QGridLayout(formulaLabelGroup);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        formulaHorizontalLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        formulaHorizontalLayout->setContentsMargins(0, 0, 0, 0);
#endif
        formulaHorizontalLayout->setObjectName(QString::fromUtf8("formulaHorizontalLayout"));

        gridLayout_3->addLayout(formulaHorizontalLayout, 0, 0, 1, 1);


        gridLayout_5->addWidget(formulaLabelGroup, 1, 0, 1, 1);

        formulaTextEdit = new QTextEdit(EquationTab);
        formulaTextEdit->setObjectName(QString::fromUtf8("formulaTextEdit"));
        formulaTextEdit->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(formulaTextEdit->sizePolicy().hasHeightForWidth());
        formulaTextEdit->setSizePolicy(sizePolicy);
        formulaTextEdit->setMaximumSize(QSize(600000, 31));
        formulaTextEdit->setReadOnly(true);

        gridLayout_5->addWidget(formulaTextEdit, 2, 0, 1, 1);

        valueSetterBox = new QGroupBox(EquationTab);
        valueSetterBox->setObjectName(QString::fromUtf8("valueSetterBox"));
        valueSettersGridLayout = new QGridLayout(valueSetterBox);
        valueSettersGridLayout->setObjectName(QString::fromUtf8("valueSettersGridLayout"));

        gridLayout_5->addWidget(valueSetterBox, 3, 0, 1, 1);


        retranslateUi(EquationTab);

        QMetaObject::connectSlotsByName(EquationTab);
    } // setupUi

    void retranslateUi(QWidget *EquationTab)
    {
        EquationTab->setWindowTitle(QApplication::translate("EquationTab", "Form", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("EquationTab", "A nemzeti sz\303\241mlarendszer azonoss\303\241ga:", 0, QApplication::UnicodeUTF8));
        formulaLabelGroup->setTitle(QString());
        formulaTextEdit->setHtml(QApplication::translate("EquationTab", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        valueSetterBox->setTitle(QApplication::translate("EquationTab", "V\303\241ltoz\303\263k", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EquationTab: public Ui_EquationTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUATIONTAB_H
