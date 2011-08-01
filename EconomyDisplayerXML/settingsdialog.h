#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
    class SettingsDialog;
}

class SettingsDialog : public QDialog {
    Q_OBJECT
public:
    SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();    

    inline const Ui::SettingsDialog * getUI() const { return ui; }

    void refreshCurveList();

protected:
    void changeEvent(QEvent *e);

private slots:
    void addLines();
    void removeLines();
    void addCoordinateSystem();
    void removeCoordinateSystem();
    void addCoordinateSystem(int id);

private:
    Ui::SettingsDialog *ui;

};

#endif // SETTINGSDIALOG_H
