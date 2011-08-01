#ifndef EDITABLETABWIDGET_H
#define EDITABLETABWIDGET_H

#include <QObject>
#include <QTabWidget>
#include <QTableWidget>

#include "editabletabwidget.h"
#include "editabletabbar.h"

class EditableTabWidget : public QTabWidget {
    Q_OBJECT
public:
    EditableTabWidget(QWidget* parent = 0);
    inline QList<QTableWidget*> * getTables() { return &m_Tables; }
    void addNewTab(const QString& name);
public slots:
    void addNewTab();
signals:
    void tabTextChanged(int index,const QString &text);
private:
    QList<QTableWidget*> m_Tables;
};

#endif // EDITABLETABWIDGET_H
