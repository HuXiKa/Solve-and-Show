#include <QKeyEvent>

#include "independentlineedit.h"

IndependentLineEdit::IndependentLineEdit(QWidget* parent) :
    QLineEdit(parent) {
    setupWidget();
}

IndependentLineEdit::IndependentLineEdit(const QString & contents, QWidget* parent) :
    QLineEdit(contents, parent) {
    setupWidget();
}

void IndependentLineEdit::setText(const QString &text) {
    QLineEdit::setText(text);
    setFocus();
    selectAll();
    show();
}

void IndependentLineEdit::keyPressEvent(QKeyEvent* event) {
    QLineEdit::keyPressEvent(event);
    if (event->key() == Qt::Key_Escape) {
        setText("");
        hide();
    }
}

void IndependentLineEdit::focusOutEvent(QFocusEvent* event) {
    QLineEdit::focusOutEvent(event);
    emit editingFinished();
}

void IndependentLineEdit::publishText() {
    if (text() != "") {
        emit newTextEntered(text());
    }
    hide();
}

void IndependentLineEdit::setupWidget() {
    connect(this, SIGNAL(editingFinished()), this, SLOT(publishText()));
    setWindowFlags(Qt::CustomizeWindowHint);
}
