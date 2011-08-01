#ifndef INDEPENDENTLINEEDIT_H
#define INDEPENDENTLINEEDIT_H

#include <QLineEdit>

class IndependentLineEdit: public QLineEdit {
    Q_OBJECT
public:
    IndependentLineEdit(QWidget* parent = 0);
    IndependentLineEdit(const QString & contents, QWidget* parent = 0 );
public slots:
    void setText(const QString &text);
signals:
    void newTextEntered(const QString &text);
protected:
    void keyPressEvent(QKeyEvent* event);
    void focusOutEvent(QFocusEvent* event);
private slots:
    void publishText();
    void setupWidget();
};

#endif // INDEPENDENTLINEEDIT_H
