#ifndef ADDEQUATIONDIALOG_H
#define ADDEQUATIONDIALOG_H

#include <QDialog>

namespace Ui {
    class AddEquationDialog;
}

class AddEquationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEquationDialog(QWidget *parent = 0);
    ~AddEquationDialog();

private slots:
    void addEquation();

private:
    Ui::AddEquationDialog *ui;
};

#endif // ADDEQUATIONDIALOG_H
