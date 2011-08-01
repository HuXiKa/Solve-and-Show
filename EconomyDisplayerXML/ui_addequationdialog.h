/********************************************************************************
** Form generated from reading UI file 'addequationdialog.ui'
**
** Created: Sat Jul 30 16:44:38 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEQUATIONDIALOG_H
#define UI_ADDEQUATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEquationDialog
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QCheckBox *isDrawableCheckBox;
    QCheckBox *isShownCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *equationLineEdit;
    QPushButton *addEquationButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *equationNameLineEdit;
    QWidget *axisWidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *xAxisLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *yAxisLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddEquationDialog)
    {
        if (AddEquationDialog->objectName().isEmpty())
            AddEquationDialog->setObjectName(QString::fromUtf8("AddEquationDialog"));
        AddEquationDialog->setWindowModality(Qt::WindowModal);
        AddEquationDialog->resize(358, 235);
        AddEquationDialog->setModal(true);
        gridLayout_2 = new QGridLayout(AddEquationDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(AddEquationDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        isDrawableCheckBox = new QCheckBox(groupBox);
        isDrawableCheckBox->setObjectName(QString::fromUtf8("isDrawableCheckBox"));

        horizontalLayout_2->addWidget(isDrawableCheckBox);

        isShownCheckBox = new QCheckBox(groupBox);
        isShownCheckBox->setObjectName(QString::fromUtf8("isShownCheckBox"));

        horizontalLayout_2->addWidget(isShownCheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        equationLineEdit = new QLineEdit(groupBox);
        equationLineEdit->setObjectName(QString::fromUtf8("equationLineEdit"));
        equationLineEdit->setMaximumSize(QSize(300, 16777215));

        horizontalLayout->addWidget(equationLineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        addEquationButton = new QPushButton(groupBox);
        addEquationButton->setObjectName(QString::fromUtf8("addEquationButton"));

        gridLayout->addWidget(addEquationButton, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        equationNameLineEdit = new QLineEdit(groupBox);
        equationNameLineEdit->setObjectName(QString::fromUtf8("equationNameLineEdit"));
        equationNameLineEdit->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_3->addWidget(equationNameLineEdit);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        axisWidget = new QWidget(groupBox);
        axisWidget->setObjectName(QString::fromUtf8("axisWidget"));
        gridLayout_3 = new QGridLayout(axisWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(axisWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        xAxisLineEdit = new QLineEdit(axisWidget);
        xAxisLineEdit->setObjectName(QString::fromUtf8("xAxisLineEdit"));
        xAxisLineEdit->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_4->addWidget(xAxisLineEdit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(axisWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        yAxisLineEdit = new QLineEdit(axisWidget);
        yAxisLineEdit->setObjectName(QString::fromUtf8("yAxisLineEdit"));
        yAxisLineEdit->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_5->addWidget(yAxisLineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_5);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        gridLayout->addWidget(axisWidget, 3, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(AddEquationDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(AddEquationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddEquationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddEquationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddEquationDialog);
    } // setupUi

    void retranslateUi(QDialog *AddEquationDialog)
    {
        AddEquationDialog->setWindowTitle(QApplication::translate("AddEquationDialog", "Egyenlet hozz\303\241ad\303\241sa", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AddEquationDialog", "Egyenlet megad\303\241sa", 0, QApplication::UnicodeUTF8));
        isDrawableCheckBox->setText(QApplication::translate("AddEquationDialog", "Rajzolhat\303\263", 0, QApplication::UnicodeUTF8));
        isShownCheckBox->setText(QApplication::translate("AddEquationDialog", "Megjelenik \303\251rt\303\251kad\303\263 ablakban", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddEquationDialog", "Egyenlet:", 0, QApplication::UnicodeUTF8));
        addEquationButton->setText(QApplication::translate("AddEquationDialog", "Hozz\303\241ad\303\241s", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddEquationDialog", "N\303\251v: ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddEquationDialog", "X tengely:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AddEquationDialog", "Y tengely:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddEquationDialog: public Ui_AddEquationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEQUATIONDIALOG_H
