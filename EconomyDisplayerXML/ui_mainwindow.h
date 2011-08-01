/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Jul 30 16:53:23 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRajzol_s;
    QAction *action_rt_kad_s;
    QAction *actionMonet_ris_l_p_sek;
    QAction *actionFisk_lis_l_p_sek;
    QAction *actionK_ls_sokkok;
    QAction *actionResetVariables;
    QAction *actionShowNoValue;
    QAction *actionKil_p_s;
    QAction *actionSz_mol_s;
    QAction *actionTeljes_k_perny_s_m_d;
    QAction *actionN_vjegy;
    QAction *actionQt_n_vjegy;
    QAction *actionV_ltoz_s_v_gleges_t_se;
    QAction *actionV_ltoz_s_visszavon_sa;
    QAction *actionBe_ll_t_sok;
    QAction *actionEgyenlet_megad_sa;
    QAction *actionModul_megnyit_sa;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QTableWidget *valuesTableWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QGridLayout *mainLayout;
    QMdiArea *mdi;
    QMenuBar *menubar;
    QMenu *menuBe_ll_t_sok;
    QMenu *menuGazdas_gi_esem_nyek;
    QMenu *menuSeg_ts_g;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(929, 373);
        MainWindow->setStyleSheet(QString::fromUtf8(" QMenu {\n"
"     background-color: #ABABAB; /* sets background of the menu */\n"
"     border: 1px solid black;\n"
" }\n"
"\n"
" QMenu::item {\n"
"     /* sets background of menu item. set this to something non-transparent\n"
"         if you want menu color and menu item color to be different */\n"
"     background-color: transparent;\n"
" }\n"
"\n"
"QMenu::item:selected { /* when user selects item using mouse or keyboard */\n"
"     background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgb(255, 255, 255), stop:1 rgb(189, 189, 189))\n"
" }\n"
"\n"
"QMenuBar {\n"
"     background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                       stop:0 lightgray, stop:1 darkgray);\n"
" }\n"
"\n"
" QMenuBar::item {\n"
"     spacing: 3px; /* spacing between menu bar items */\n"
"     padding: 1px 4px;\n"
"     background: transparent;\n"
"     border-radius: 4px;\n"
" }\n"
"\n"
" QMenuBar::item:selected { /* when selected using mouse or keyboard */\n"
"     backgrou"
                        "nd: #a8a8a8;\n"
" }\n"
"\n"
" QMenuBar::item:pressed {\n"
"     background: #888888;\n"
" }\n"
"\n"
" QToolBar {\n"
"     background: qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"                                       stop:1 lightgray, stop:0 darkgray);\n"
"     spacing: 3px; /* spacing between items in the tool bar */\n"
" }\n"
"\n"
"QDialog {\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 		rgba(100, 100, 100, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"\n"
"QListView, QTreeView{\n"
"	background: qlineargradient(spread:pad, x2:0, y2:0, x1:0, y1:1, stop:0 		rgba(100, 100, 100, 100), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
""));
        actionRajzol_s = new QAction(MainWindow);
        actionRajzol_s->setObjectName(QString::fromUtf8("actionRajzol_s"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/ikon1-ceruza copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRajzol_s->setIcon(icon);
        actionRajzol_s->setMenuRole(QAction::ApplicationSpecificRole);
        action_rt_kad_s = new QAction(MainWindow);
        action_rt_kad_s->setObjectName(QString::fromUtf8("action_rt_kad_s"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/ikon11-x copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_rt_kad_s->setIcon(icon1);
        actionMonet_ris_l_p_sek = new QAction(MainWindow);
        actionMonet_ris_l_p_sek->setObjectName(QString::fromUtf8("actionMonet_ris_l_p_sek"));
        actionMonet_ris_l_p_sek->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/ikon3-erme copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMonet_ris_l_p_sek->setIcon(icon2);
        actionFisk_lis_l_p_sek = new QAction(MainWindow);
        actionFisk_lis_l_p_sek->setObjectName(QString::fromUtf8("actionFisk_lis_l_p_sek"));
        actionFisk_lis_l_p_sek->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/ikon5-fp2 copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFisk_lis_l_p_sek->setIcon(icon3);
        actionK_ls_sokkok = new QAction(MainWindow);
        actionK_ls_sokkok->setObjectName(QString::fromUtf8("actionK_ls_sokkok"));
        actionK_ls_sokkok->setEnabled(false);
        actionResetVariables = new QAction(MainWindow);
        actionResetVariables->setObjectName(QString::fromUtf8("actionResetVariables"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/ikon6-reset copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionResetVariables->setIcon(icon4);
        actionShowNoValue = new QAction(MainWindow);
        actionShowNoValue->setObjectName(QString::fromUtf8("actionShowNoValue"));
        actionShowNoValue->setCheckable(true);
        actionShowNoValue->setChecked(false);
        actionKil_p_s = new QAction(MainWindow);
        actionKil_p_s->setObjectName(QString::fromUtf8("actionKil_p_s"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/ikon10-exit copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionKil_p_s->setIcon(icon5);
        actionSz_mol_s = new QAction(MainWindow);
        actionSz_mol_s->setObjectName(QString::fromUtf8("actionSz_mol_s"));
        actionSz_mol_s->setCheckable(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/ikon2-gyok copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSz_mol_s->setIcon(icon6);
        actionTeljes_k_perny_s_m_d = new QAction(MainWindow);
        actionTeljes_k_perny_s_m_d->setObjectName(QString::fromUtf8("actionTeljes_k_perny_s_m_d"));
        actionTeljes_k_perny_s_m_d->setCheckable(true);
        actionTeljes_k_perny_s_m_d->setChecked(true);
        actionN_vjegy = new QAction(MainWindow);
        actionN_vjegy->setObjectName(QString::fromUtf8("actionN_vjegy"));
        actionQt_n_vjegy = new QAction(MainWindow);
        actionQt_n_vjegy->setObjectName(QString::fromUtf8("actionQt_n_vjegy"));
        actionV_ltoz_s_v_gleges_t_se = new QAction(MainWindow);
        actionV_ltoz_s_v_gleges_t_se->setObjectName(QString::fromUtf8("actionV_ltoz_s_v_gleges_t_se"));
        actionV_ltoz_s_v_gleges_t_se->setEnabled(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icons/ikon7-pipa1 copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionV_ltoz_s_v_gleges_t_se->setIcon(icon7);
        actionV_ltoz_s_visszavon_sa = new QAction(MainWindow);
        actionV_ltoz_s_visszavon_sa->setObjectName(QString::fromUtf8("actionV_ltoz_s_visszavon_sa"));
        actionV_ltoz_s_visszavon_sa->setEnabled(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/icons/ikon8-vissza copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionV_ltoz_s_visszavon_sa->setIcon(icon8);
        actionBe_ll_t_sok = new QAction(MainWindow);
        actionBe_ll_t_sok->setObjectName(QString::fromUtf8("actionBe_ll_t_sok"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/icons/ikon9-options copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBe_ll_t_sok->setIcon(icon9);
        actionEgyenlet_megad_sa = new QAction(MainWindow);
        actionEgyenlet_megad_sa->setObjectName(QString::fromUtf8("actionEgyenlet_megad_sa"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/icons/ikon5-ygx copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEgyenlet_megad_sa->setIcon(icon10);
        actionModul_megnyit_sa = new QAction(MainWindow);
        actionModul_megnyit_sa->setObjectName(QString::fromUtf8("actionModul_megnyit_sa"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(true);
        valuesTableWidget = new QTableWidget(splitter);
        if (valuesTableWidget->columnCount() < 4)
            valuesTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        valuesTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        valuesTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        valuesTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        valuesTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        valuesTableWidget->setObjectName(QString::fromUtf8("valuesTableWidget"));
        valuesTableWidget->setStyleSheet(QString::fromUtf8(""));
        valuesTableWidget->setAlternatingRowColors(true);
        splitter->addWidget(valuesTableWidget);
        valuesTableWidget->verticalHeader()->setVisible(false);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mainLayout = new QGridLayout();
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mdi = new QMdiArea(groupBox);
        mdi->setObjectName(QString::fromUtf8("mdi"));
        mdi->setStyleSheet(QString::fromUtf8(""));

        mainLayout->addWidget(mdi, 0, 0, 1, 1);


        gridLayout->addLayout(mainLayout, 0, 0, 1, 1);

        splitter->addWidget(groupBox);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 929, 16));
        menuBe_ll_t_sok = new QMenu(menubar);
        menuBe_ll_t_sok->setObjectName(QString::fromUtf8("menuBe_ll_t_sok"));
        menuGazdas_gi_esem_nyek = new QMenu(menubar);
        menuGazdas_gi_esem_nyek->setObjectName(QString::fromUtf8("menuGazdas_gi_esem_nyek"));
        menuSeg_ts_g = new QMenu(menubar);
        menuSeg_ts_g->setObjectName(QString::fromUtf8("menuSeg_ts_g"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(40, 40));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuBe_ll_t_sok->menuAction());
        menubar->addAction(menuGazdas_gi_esem_nyek->menuAction());
        menubar->addAction(menuSeg_ts_g->menuAction());
        menuBe_ll_t_sok->addAction(actionModul_megnyit_sa);
        menuBe_ll_t_sok->addAction(actionRajzol_s);
        menuBe_ll_t_sok->addAction(action_rt_kad_s);
        menuBe_ll_t_sok->addAction(actionResetVariables);
        menuBe_ll_t_sok->addAction(actionShowNoValue);
        menuBe_ll_t_sok->addSeparator();
        menuBe_ll_t_sok->addAction(actionTeljes_k_perny_s_m_d);
        menuBe_ll_t_sok->addAction(actionBe_ll_t_sok);
        menuBe_ll_t_sok->addAction(actionKil_p_s);
        menuGazdas_gi_esem_nyek->addAction(actionMonet_ris_l_p_sek);
        menuGazdas_gi_esem_nyek->addAction(actionFisk_lis_l_p_sek);
        menuGazdas_gi_esem_nyek->addSeparator();
        menuGazdas_gi_esem_nyek->addAction(actionK_ls_sokkok);
        menuSeg_ts_g->addAction(actionN_vjegy);
        menuSeg_ts_g->addAction(actionQt_n_vjegy);
        toolBar->addAction(actionBe_ll_t_sok);
        toolBar->addAction(actionRajzol_s);
        toolBar->addSeparator();
        toolBar->addAction(actionResetVariables);
        toolBar->addAction(action_rt_kad_s);
        toolBar->addAction(actionSz_mol_s);
        toolBar->addAction(actionEgyenlet_megad_sa);
        toolBar->addSeparator();
        toolBar->addAction(actionMonet_ris_l_p_sek);
        toolBar->addAction(actionFisk_lis_l_p_sek);
        toolBar->addAction(actionV_ltoz_s_v_gleges_t_se);
        toolBar->addAction(actionV_ltoz_s_visszavon_sa);
        toolBar->addSeparator();
        toolBar->addAction(actionKil_p_s);

        retranslateUi(MainWindow);
        QObject::connect(actionKil_p_s, SIGNAL(triggered(bool)), MainWindow, SLOT(close()));
        QObject::connect(actionSz_mol_s, SIGNAL(triggered(bool)), MainWindow, SLOT(calculate()));
        QObject::connect(actionTeljes_k_perny_s_m_d, SIGNAL(triggered(bool)), MainWindow, SLOT(setFullscreenMode(bool)));
        QObject::connect(actionV_ltoz_s_visszavon_sa, SIGNAL(triggered(bool)), MainWindow, SLOT(undoPolicy()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Economy Displayer", 0, QApplication::UnicodeUTF8));
        actionRajzol_s->setText(QApplication::translate("MainWindow", "Rajzol\303\241s", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRajzol_s->setToolTip(QApplication::translate("MainWindow", "Egyenesek rajzol\303\241sa", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_rt_kad_s->setText(QApplication::translate("MainWindow", "\303\211rt\303\251kad\303\241s", 0, QApplication::UnicodeUTF8));
        actionMonet_ris_l_p_sek->setText(QApplication::translate("MainWindow", "Monet\303\241ris l\303\251p\303\251sek", 0, QApplication::UnicodeUTF8));
        actionFisk_lis_l_p_sek->setText(QApplication::translate("MainWindow", "Fisk\303\241lis l\303\251p\303\251sek", 0, QApplication::UnicodeUTF8));
        actionK_ls_sokkok->setText(QApplication::translate("MainWindow", "K\303\274ls\305\221 sokkok", 0, QApplication::UnicodeUTF8));
        actionResetVariables->setText(QApplication::translate("MainWindow", "\303\211rt\303\251kek vissza\303\241ll\303\255t\303\241sa", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionResetVariables->setToolTip(QApplication::translate("MainWindow", "\303\211rt\303\251kek vissza\303\241ll\303\255t\303\241sa", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionShowNoValue->setText(QApplication::translate("MainWindow", "null \303\251rt\303\251k l\303\241tsz\303\263dik", 0, QApplication::UnicodeUTF8));
        actionKil_p_s->setText(QApplication::translate("MainWindow", "Kil\303\251p\303\251s", 0, QApplication::UnicodeUTF8));
        actionSz_mol_s->setText(QApplication::translate("MainWindow", "Sz\303\241mol\303\241s", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSz_mol_s->setToolTip(QApplication::translate("MainWindow", "Sz\303\241mol\303\241s", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionTeljes_k_perny_s_m_d->setText(QApplication::translate("MainWindow", "Teljes k\303\251perny\305\221s m\303\263d", 0, QApplication::UnicodeUTF8));
        actionN_vjegy->setText(QApplication::translate("MainWindow", "N\303\251vjegy", 0, QApplication::UnicodeUTF8));
        actionQt_n_vjegy->setText(QApplication::translate("MainWindow", "Qt n\303\251vjegy", 0, QApplication::UnicodeUTF8));
        actionV_ltoz_s_v_gleges_t_se->setText(QApplication::translate("MainWindow", "V\303\241ltoz\303\241s v\303\251gleges\303\255t\303\251se", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionV_ltoz_s_v_gleges_t_se->setToolTip(QApplication::translate("MainWindow", "V\303\241ltoz\303\241s v\303\251gleges\303\255t\303\251se", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionV_ltoz_s_visszavon_sa->setText(QApplication::translate("MainWindow", "V\303\241ltoz\303\241s visszavon\303\241sa", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionV_ltoz_s_visszavon_sa->setToolTip(QApplication::translate("MainWindow", "V\303\241ltoz\303\241s visszavon\303\241sa", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionBe_ll_t_sok->setText(QApplication::translate("MainWindow", "Be\303\241ll\303\255t\303\241sok", 0, QApplication::UnicodeUTF8));
        actionEgyenlet_megad_sa->setText(QApplication::translate("MainWindow", "Egyenlet megad\303\241sa", 0, QApplication::UnicodeUTF8));
        actionModul_megnyit_sa->setText(QApplication::translate("MainWindow", "Modul megnyit\303\241sa", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = valuesTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "N\303\251v", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = valuesTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\303\211rt\303\251k", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = valuesTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Le\303\255r\303\241s", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = valuesTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "V\303\241ltoz\303\241s", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        menuBe_ll_t_sok->setTitle(QApplication::translate("MainWindow", "Be\303\241ll\303\255t\303\241sok", 0, QApplication::UnicodeUTF8));
        menuGazdas_gi_esem_nyek->setTitle(QApplication::translate("MainWindow", "Gazdas\303\241gi esem\303\251nyek", 0, QApplication::UnicodeUTF8));
        menuSeg_ts_g->setTitle(QApplication::translate("MainWindow", "S\303\272g\303\263", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
