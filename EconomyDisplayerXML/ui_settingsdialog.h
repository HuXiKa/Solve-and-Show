/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created: Sat Jul 30 16:44:38 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

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
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout;
    QListWidget *addableLinesListWidget;
    QVBoxLayout *verticalLayout_4;
    QToolButton *addLineToolButton;
    QToolButton *removeLineToolButton;
    QListWidget *addedLinesListWidget;
    QVBoxLayout *verticalLayout_5;
    QToolButton *addCoordinateSystemToolButton;
    QToolButton *removeCoordinateSystemToolButton;
    QTreeWidget *coordinateSystemsTreeWidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *ASADCheckBox;
    QCheckBox *ISLMCheckBox;
    QCheckBox *SICheckBox;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *labourCheckBox;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_16;
    QCheckBox *ISRCheckBox;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QCheckBox *outputCheckBox;
    QCheckBox *ADCheckBox;
    QCheckBox *phillipsCheckBox;
    QCheckBox *keynesCheckBox;
    QCheckBox *SRASCheckBox;
    QCheckBox *ISCheckBox;
    QCheckBox *LRASCheckBox;
    QCheckBox *LMCheckBox;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->setWindowModality(Qt::WindowModal);
        SettingsDialog->resize(468, 508);
        SettingsDialog->setModal(true);
        verticalLayout_3 = new QVBoxLayout(SettingsDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_4 = new QGroupBox(SettingsDialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setMaximumSize(QSize(450, 225));
        horizontalLayout = new QHBoxLayout(groupBox_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addableLinesListWidget = new QListWidget(groupBox_4);
        addableLinesListWidget->setObjectName(QString::fromUtf8("addableLinesListWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addableLinesListWidget->sizePolicy().hasHeightForWidth());
        addableLinesListWidget->setSizePolicy(sizePolicy1);
        addableLinesListWidget->setAlternatingRowColors(true);
        addableLinesListWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        addableLinesListWidget->setSortingEnabled(true);

        horizontalLayout->addWidget(addableLinesListWidget);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        addLineToolButton = new QToolButton(groupBox_4);
        addLineToolButton->setObjectName(QString::fromUtf8("addLineToolButton"));
        addLineToolButton->setArrowType(Qt::RightArrow);

        verticalLayout_4->addWidget(addLineToolButton);

        removeLineToolButton = new QToolButton(groupBox_4);
        removeLineToolButton->setObjectName(QString::fromUtf8("removeLineToolButton"));
        removeLineToolButton->setArrowType(Qt::LeftArrow);

        verticalLayout_4->addWidget(removeLineToolButton);


        horizontalLayout->addLayout(verticalLayout_4);

        addedLinesListWidget = new QListWidget(groupBox_4);
        addedLinesListWidget->setObjectName(QString::fromUtf8("addedLinesListWidget"));
        sizePolicy.setHeightForWidth(addedLinesListWidget->sizePolicy().hasHeightForWidth());
        addedLinesListWidget->setSizePolicy(sizePolicy);
        addedLinesListWidget->setAlternatingRowColors(true);
        addedLinesListWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        addedLinesListWidget->setSortingEnabled(true);

        horizontalLayout->addWidget(addedLinesListWidget);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        addCoordinateSystemToolButton = new QToolButton(groupBox_4);
        addCoordinateSystemToolButton->setObjectName(QString::fromUtf8("addCoordinateSystemToolButton"));
        addCoordinateSystemToolButton->setArrowType(Qt::RightArrow);

        verticalLayout_5->addWidget(addCoordinateSystemToolButton);

        removeCoordinateSystemToolButton = new QToolButton(groupBox_4);
        removeCoordinateSystemToolButton->setObjectName(QString::fromUtf8("removeCoordinateSystemToolButton"));
        removeCoordinateSystemToolButton->setArrowType(Qt::LeftArrow);

        verticalLayout_5->addWidget(removeCoordinateSystemToolButton);


        horizontalLayout->addLayout(verticalLayout_5);

        coordinateSystemsTreeWidget = new QTreeWidget(groupBox_4);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        coordinateSystemsTreeWidget->setHeaderItem(__qtreewidgetitem);
        coordinateSystemsTreeWidget->setObjectName(QString::fromUtf8("coordinateSystemsTreeWidget"));
        sizePolicy.setHeightForWidth(coordinateSystemsTreeWidget->sizePolicy().hasHeightForWidth());
        coordinateSystemsTreeWidget->setSizePolicy(sizePolicy);
        coordinateSystemsTreeWidget->setAlternatingRowColors(true);
        coordinateSystemsTreeWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        coordinateSystemsTreeWidget->setColumnCount(1);
        coordinateSystemsTreeWidget->header()->setVisible(false);

        horizontalLayout->addWidget(coordinateSystemsTreeWidget);


        verticalLayout_3->addWidget(groupBox_4);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(SettingsDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ASADCheckBox = new QCheckBox(groupBox);
        ASADCheckBox->setObjectName(QString::fromUtf8("ASADCheckBox"));

        verticalLayout->addWidget(ASADCheckBox);

        ISLMCheckBox = new QCheckBox(groupBox);
        ISLMCheckBox->setObjectName(QString::fromUtf8("ISLMCheckBox"));

        verticalLayout->addWidget(ISLMCheckBox);

        SICheckBox = new QCheckBox(groupBox);
        SICheckBox->setObjectName(QString::fromUtf8("SICheckBox"));

        verticalLayout->addWidget(SICheckBox);


        gridLayout_2->addWidget(groupBox, 0, 0, 3, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(SettingsDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labourCheckBox = new QCheckBox(groupBox_3);
        labourCheckBox->setObjectName(QString::fromUtf8("labourCheckBox"));

        verticalLayout_2->addWidget(labourCheckBox);

        checkBox_15 = new QCheckBox(groupBox_3);
        checkBox_15->setObjectName(QString::fromUtf8("checkBox_15"));

        verticalLayout_2->addWidget(checkBox_15);

        checkBox_16 = new QCheckBox(groupBox_3);
        checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));

        verticalLayout_2->addWidget(checkBox_16);

        ISRCheckBox = new QCheckBox(groupBox_3);
        ISRCheckBox->setObjectName(QString::fromUtf8("ISRCheckBox"));

        verticalLayout_2->addWidget(ISRCheckBox);


        gridLayout_2->addWidget(groupBox_3, 0, 2, 3, 1);

        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);

        groupBox_2 = new QGroupBox(SettingsDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setEnabled(true);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        outputCheckBox = new QCheckBox(groupBox_2);
        outputCheckBox->setObjectName(QString::fromUtf8("outputCheckBox"));

        gridLayout->addWidget(outputCheckBox, 0, 0, 1, 1);

        ADCheckBox = new QCheckBox(groupBox_2);
        ADCheckBox->setObjectName(QString::fromUtf8("ADCheckBox"));

        gridLayout->addWidget(ADCheckBox, 0, 1, 1, 1);

        phillipsCheckBox = new QCheckBox(groupBox_2);
        phillipsCheckBox->setObjectName(QString::fromUtf8("phillipsCheckBox"));

        gridLayout->addWidget(phillipsCheckBox, 0, 2, 1, 1);

        keynesCheckBox = new QCheckBox(groupBox_2);
        keynesCheckBox->setObjectName(QString::fromUtf8("keynesCheckBox"));

        gridLayout->addWidget(keynesCheckBox, 1, 0, 1, 1);

        SRASCheckBox = new QCheckBox(groupBox_2);
        SRASCheckBox->setObjectName(QString::fromUtf8("SRASCheckBox"));

        gridLayout->addWidget(SRASCheckBox, 1, 1, 1, 1);

        ISCheckBox = new QCheckBox(groupBox_2);
        ISCheckBox->setObjectName(QString::fromUtf8("ISCheckBox"));

        gridLayout->addWidget(ISCheckBox, 2, 0, 1, 1);

        LRASCheckBox = new QCheckBox(groupBox_2);
        LRASCheckBox->setObjectName(QString::fromUtf8("LRASCheckBox"));

        gridLayout->addWidget(LRASCheckBox, 2, 1, 1, 1);

        LMCheckBox = new QCheckBox(groupBox_2);
        LMCheckBox->setObjectName(QString::fromUtf8("LMCheckBox"));

        gridLayout->addWidget(LMCheckBox, 3, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 3, 0, 1, 3);


        verticalLayout_3->addLayout(gridLayout_2);


        retranslateUi(SettingsDialog);
        QObject::connect(addLineToolButton, SIGNAL(clicked()), SettingsDialog, SLOT(addLines()));
        QObject::connect(removeLineToolButton, SIGNAL(clicked()), SettingsDialog, SLOT(removeLines()));
        QObject::connect(addCoordinateSystemToolButton, SIGNAL(clicked()), SettingsDialog, SLOT(addCoordinateSystem()));
        QObject::connect(removeCoordinateSystemToolButton, SIGNAL(clicked()), SettingsDialog, SLOT(removeCoordinateSystem()));
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("SettingsDialog", "Tetsz\305\221leges koordin\303\241ta rendszerek hozz\303\241ad\303\241sa", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addLineToolButton->setToolTip(QApplication::translate("SettingsDialog", "Kiv\303\241lasztott egyenesek hozz\303\241ad\303\241sa", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addLineToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        removeLineToolButton->setToolTip(QApplication::translate("SettingsDialog", "Kiv\303\241lasztott egyenesek t\303\266rl\303\251se", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        removeLineToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        addCoordinateSystemToolButton->setToolTip(QApplication::translate("SettingsDialog", "Kiv\303\241lasztott egyenesekb\305\221l koordin\303\241tarendszer l\303\251trehoz\303\241sa", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addCoordinateSystemToolButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        removeCoordinateSystemToolButton->setToolTip(QApplication::translate("SettingsDialog", "Kiv\303\241lasztott koordin\303\241tarendszer t\303\266rl\303\251se", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        removeCoordinateSystemToolButton->setText(QString());
        groupBox->setTitle(QApplication::translate("SettingsDialog", "Modellek", 0, QApplication::UnicodeUTF8));
        ASADCheckBox->setText(QApplication::translate("SettingsDialog", "AS - AD", 0, QApplication::UnicodeUTF8));
        ISLMCheckBox->setText(QApplication::translate("SettingsDialog", "IS - LM", 0, QApplication::UnicodeUTF8));
        SICheckBox->setText(QApplication::translate("SettingsDialog", "Nemeti megtakar\303\255t\303\241s, \n"
"beruh\303\241z\303\241s", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("SettingsDialog", "Piacok", 0, QApplication::UnicodeUTF8));
        labourCheckBox->setText(QApplication::translate("SettingsDialog", "Munkapiac", 0, QApplication::UnicodeUTF8));
        checkBox_15->setText(QApplication::translate("SettingsDialog", "\303\201rupiac", 0, QApplication::UnicodeUTF8));
        checkBox_16->setText(QApplication::translate("SettingsDialog", "P\303\251nzpiac", 0, QApplication::UnicodeUTF8));
        ISRCheckBox->setText(QApplication::translate("SettingsDialog", "Beruh\303\241z\303\241si kereslet, \n"
"k\303\255n\303\241lat", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("SettingsDialog", "Egyenletek", 0, QApplication::UnicodeUTF8));
        outputCheckBox->setText(QApplication::translate("SettingsDialog", "Termel\303\251si f\303\274ggv\303\251ny", 0, QApplication::UnicodeUTF8));
        ADCheckBox->setText(QApplication::translate("SettingsDialog", "AD g\303\266rbe", 0, QApplication::UnicodeUTF8));
        phillipsCheckBox->setText(QApplication::translate("SettingsDialog", "Phillips - g\303\266rbe", 0, QApplication::UnicodeUTF8));
        keynesCheckBox->setText(QApplication::translate("SettingsDialog", "Keynesi kereszt", 0, QApplication::UnicodeUTF8));
        SRASCheckBox->setText(QApplication::translate("SettingsDialog", "SRAS g\303\266rbe", 0, QApplication::UnicodeUTF8));
        ISCheckBox->setText(QApplication::translate("SettingsDialog", "IS g\303\266rbe", 0, QApplication::UnicodeUTF8));
        LRASCheckBox->setText(QApplication::translate("SettingsDialog", "LRAS g\303\266rbe", 0, QApplication::UnicodeUTF8));
        LMCheckBox->setText(QApplication::translate("SettingsDialog", "LM g\303\266rbe", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
