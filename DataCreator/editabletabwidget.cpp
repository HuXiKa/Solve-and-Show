#include <QToolButton>
#include <QTabBar>
#include <QHeaderView>
#include <QTableWidget>
#include <QGridLayout>

#include "editabletabwidget.h"

EditableTabWidget::EditableTabWidget(QWidget* parent) :
    QTabWidget(parent) {
    EditableTabBar* t = new EditableTabBar();
    connect(t, SIGNAL(tabTextChanged(int, const QString &)), this,
            SIGNAL(tabTextChanged(int, const QString &)));
    setTabBar(t);
    addNewTab();

    QToolButton *newTabButton = new QToolButton(this);
    setCornerWidget(newTabButton, Qt::TopLeftCorner);
    newTabButton->setCursor(Qt::ArrowCursor);
    newTabButton->setAutoRaise(true);
    newTabButton->setIcon(QIcon("icons/add_tab.png"));
    QObject::connect(newTabButton, SIGNAL(clicked()), this, SLOT(addNewTab()));
    newTabButton->setToolTip(tr("Új oldal"));
}

void EditableTabWidget::addNewTab()
{
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    QTableWidget *table = new QTableWidget(this);
    if (table->columnCount() < 3)
        table->setColumnCount(3);
    QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem(tr("Egyenlet"));
    table->setHorizontalHeaderItem(0, __qtablewidgetitem9);
    QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem(tr("Név"));
    table->setHorizontalHeaderItem(1, __qtablewidgetitem10);
    QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem(tr("Megjelenik"));
    table->setHorizontalHeaderItem(2, __qtablewidgetitem11);
    QSizePolicy sizePolicy1;
    sizePolicy1.setHeightForWidth(table->sizePolicy().hasHeightForWidth());
    table->setSizePolicy(sizePolicy1);
    table->setAlternatingRowColors(true);
    table->verticalHeader()->setVisible(false);

    table->horizontalHeader()->setStretchLastSection( true );

    gridLayout->addWidget(table, 0, 0, 1, 1);
    addTab(table,"");
    m_Tables << table;
}

void EditableTabWidget::addNewTab(const QString& name)
{
    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    QTableWidget *table = new QTableWidget(this);
    if (table->columnCount() < 3)
        table->setColumnCount(3);
    QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem(tr("Egyenlet"));
    table->setHorizontalHeaderItem(0, __qtablewidgetitem9);
    QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem(tr("Név"));
    table->setHorizontalHeaderItem(1, __qtablewidgetitem10);
    QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem(tr("Megjelenik"));
    table->setHorizontalHeaderItem(2, __qtablewidgetitem11);
    QSizePolicy sizePolicy1;
    sizePolicy1.setHeightForWidth(table->sizePolicy().hasHeightForWidth());
    table->setSizePolicy(sizePolicy1);
    table->setAlternatingRowColors(true);
    table->verticalHeader()->setVisible(false);

    table->horizontalHeader()->setStretchLastSection( true );

    gridLayout->addWidget(table, 0, 0, 1, 1);
    addTab(table,name);
    m_Tables << table;
}
