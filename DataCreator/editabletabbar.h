#ifndef EDITABLETABBAR_H
#define EDITABLETABBAR_H

#include <QObject>
#include <QMouseEvent>
#include <QTabBar>

#include "independentlineedit.h"

class EditableTabBar : public QTabBar {
    Q_OBJECT
public:
    EditableTabBar(QWidget* parent = 0);
    virtual ~EditableTabBar();
signals:
    void tabTextChanged(int index, const QString &text);
protected:
    void mouseDoubleClickEvent(QMouseEvent* event);
private slots:
    void setCurrentTabText(const QString &text);
private:
    IndependentLineEdit _edit;

};
#endif // EDITABLETABBAR_H
