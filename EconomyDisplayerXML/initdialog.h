#ifndef INITDIALOG_H
#define INITDIALOG_H

#include <QDialog>
#include <QList>

class EquationTab;
class Equation;

namespace Ui {
    class InitDialog;
}

class InitDialog : public QDialog {
    Q_OBJECT
public:
    InitDialog(QWidget *parent = 0);
    ~InitDialog();

    void addEquationTab (Equation* equation);
    void refresh();

private slots:
    void OKPressed2();
    void refreshValuesInDialog();
    void editVariablesClicked(bool);
    void setLineEdits();
    void showVariablesInDialog();

private:
    Ui::InitDialog *ui;
    QList<EquationTab*> m_Tabs;
    bool m_VariablesEditable;

    void loadUi();
};

#endif // INITDIALOG_H
