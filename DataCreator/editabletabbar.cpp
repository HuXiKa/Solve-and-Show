#include "editabletabbar.h"

EditableTabBar::EditableTabBar(QWidget* parent) :
    QTabBar(parent), _edit("", 0) {
    connect(&_edit, SIGNAL(newTextEntered(const QString &)), this,
            SLOT( setCurrentTabText(const QString &)));    
}

EditableTabBar::~EditableTabBar() {
    // TODO Auto-generated destructor stub
}

void EditableTabBar::mouseDoubleClickEvent(QMouseEvent* event) {
    _edit.setText(tabText(currentIndex()));
    _edit.move(mapToGlobal(event->pos()));
}

void EditableTabBar::setCurrentTabText(const QString &text) {
    setTabText(currentIndex(), text);
    emit tabTextChanged(currentIndex(), text);
}
