#ifndef FISCALDIALOG_H
#define FISCALDIALOG_H

#include <QDialog>

namespace Ui {
    class FiscalDialog;
}

class FiscalDialog : public QDialog {
    Q_OBJECT
public:
    FiscalDialog(QWidget *parent = 0);
    ~FiscalDialog();

    inline const double getNewT() const { return m_NewT; }
    inline const double getNewr() const { return m_Newr; }

protected:
    void changeEvent(QEvent *e);

private slots:
    void processData();

private:
    Ui::FiscalDialog *ui;
    double m_NewT;
    double m_Newr;
};

#endif // FISCALDIALOG_H
