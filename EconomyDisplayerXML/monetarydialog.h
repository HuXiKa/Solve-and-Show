#ifndef MONETARYDIALOG_H
#define MONETARYDIALOG_H

#include <QDialog>

namespace Ui {
    class MonetaryDialog;
}

class MonetaryDialog : public QDialog {
    Q_OBJECT
public:
    MonetaryDialog(QWidget *parent = 0);
    ~MonetaryDialog();
    double getNewM();

protected:
    void changeEvent(QEvent *e);
private slots:
    void processData();
private:
    Ui::MonetaryDialog *ui;
    double m_NewM;
};

#endif // MONETARYDIALOG_H
