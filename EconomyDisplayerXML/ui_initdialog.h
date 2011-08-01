/********************************************************************************
** Form generated from reading UI file 'initdialog.ui'
**
** Created: Sat Jul 30 16:44:38 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITDIALOG_H
#define UI_INITDIALOG_H

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
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitDialog
{
public:
    QGridLayout *gridLayout_14;
    QVBoxLayout *verticalLayout_12;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_11;
    QListWidget *listWidget;
    QGridLayout *gridLayout_13;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_3;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *verticalSpacer_3;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_12;
    QTableWidget *valuesTableIWidget;
    QCheckBox *editVariablesCheckBox;

    void setupUi(QDialog *InitDialog)
    {
        if (InitDialog->objectName().isEmpty())
            InitDialog->setObjectName(QString::fromUtf8("InitDialog"));
        InitDialog->setWindowModality(Qt::WindowModal);
        InitDialog->resize(766, 455);
        InitDialog->setMouseTracking(false);
        InitDialog->setWindowOpacity(1);
        InitDialog->setStyleSheet(QString::fromUtf8(" QTabWidget::pane { /* The tab widget frame */\n"
"     border-top: 2px solid #C2C7CB;\n"
" }\n"
"\n"
" QTabWidget::tab-bar {\n"
"     left: 5px; /* move to the right by 5px */\n"
" }\n"
"\n"
" /* Style the tab using the tab sub-control. Note that\n"
"     it reads QTabBar _not_ QTabWidget */\n"
" QTabBar::tab {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                 stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"     border: 2px solid #C4C4C3;\n"
"     border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"     border-top-left-radius: 4px;\n"
"     border-top-right-radius: 4px;\n"
"     min-width: 8ex;\n"
"     padding: 2px;\n"
" }\n"
"\n"
" QTabBar::tab:selected, QTabBar::tab:hover {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                 stop: 0.5 #e7e7e7, stop: 1.0 #fa"
                        "fafa);\n"
" }\n"
"\n"
" QTabBar::tab:selected {\n"
"     border-color: #9B9B9B;\n"
"     border-bottom-color: #C2C7CB; /* same as pane color */\n"
" }\n"
"\n"
" QTabBar::tab:!selected {\n"
"     margin-top: 2px; /* make non-selected tabs look smaller */\n"
" }"));
        InitDialog->setModal(true);
        gridLayout_14 = new QGridLayout(InitDialog);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        groupBox_10 = new QGroupBox(InitDialog);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_10->sizePolicy().hasHeightForWidth());
        groupBox_10->setSizePolicy(sizePolicy);
        groupBox_10->setMaximumSize(QSize(160, 200));
        groupBox_10->setStyleSheet(QString::fromUtf8(""));
        gridLayout_11 = new QGridLayout(groupBox_10);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        listWidget = new QListWidget(groupBox_10);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMaximumSize(QSize(141, 200));

        gridLayout_11->addWidget(listWidget, 0, 0, 1, 1);


        verticalLayout_12->addWidget(groupBox_10);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer, 0, 0, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_3);

        buttonBox = new QDialogButtonBox(InitDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        horizontalLayout_15->addWidget(buttonBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_4);


        gridLayout_13->addLayout(horizontalLayout_15, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));

        gridLayout_13->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer_3, 3, 0, 1, 1);


        verticalLayout_12->addLayout(gridLayout_13);


        gridLayout_14->addLayout(verticalLayout_12, 0, 0, 1, 1);

        tabWidget = new QTabWidget(InitDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_12 = new QGridLayout(tab_2);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        valuesTableIWidget = new QTableWidget(tab_2);
        if (valuesTableIWidget->columnCount() < 4)
            valuesTableIWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        valuesTableIWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        valuesTableIWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        valuesTableIWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        valuesTableIWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        valuesTableIWidget->setObjectName(QString::fromUtf8("valuesTableIWidget"));
        valuesTableIWidget->setStyleSheet(QString::fromUtf8(""));
        valuesTableIWidget->setAlternatingRowColors(true);
        valuesTableIWidget->verticalHeader()->setVisible(false);

        gridLayout_12->addWidget(valuesTableIWidget, 1, 0, 1, 1);

        editVariablesCheckBox = new QCheckBox(tab_2);
        editVariablesCheckBox->setObjectName(QString::fromUtf8("editVariablesCheckBox"));

        gridLayout_12->addWidget(editVariablesCheckBox, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_14->addWidget(tabWidget, 0, 1, 1, 1);

        QWidget::setTabOrder(editVariablesCheckBox, tabWidget);
        QWidget::setTabOrder(tabWidget, valuesTableIWidget);
        QWidget::setTabOrder(valuesTableIWidget, listWidget);
        QWidget::setTabOrder(listWidget, buttonBox);

        retranslateUi(InitDialog);
        QObject::connect(listWidget, SIGNAL(currentRowChanged(int)), tabWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(buttonBox, SIGNAL(accepted()), InitDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), InitDialog, SLOT(reject()));
        QObject::connect(InitDialog, SIGNAL(accepted()), InitDialog, SLOT(OKPressed2()));
        QObject::connect(editVariablesCheckBox, SIGNAL(toggled(bool)), InitDialog, SLOT(editVariablesClicked(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(InitDialog);
    } // setupUi

    void retranslateUi(QDialog *InitDialog)
    {
        InitDialog->setWindowTitle(QApplication::translate("InitDialog", "\303\211rt\303\251kad\303\241s", 0, QApplication::UnicodeUTF8));
        groupBox_10->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = valuesTableIWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("InitDialog", "N\303\251v", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = valuesTableIWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("InitDialog", "Jelenlegi \303\251rt\303\251k", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = valuesTableIWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("InitDialog", "Le\303\255r\303\241s", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = valuesTableIWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("InitDialog", "\303\232j \303\251rt\303\251k", 0, QApplication::UnicodeUTF8));
        editVariablesCheckBox->setText(QApplication::translate("InitDialog", "\303\226sszes \303\251rt\303\251k megad\303\241sa itt", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("InitDialog", "Egy\303\251b", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InitDialog: public Ui_InitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITDIALOG_H
