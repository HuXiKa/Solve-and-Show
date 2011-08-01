#ifndef MODELSETTINGSDIALOG_H
#define MODELSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
    class ModelSettingsDialog;
}

class ModelSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModelSettingsDialog(QWidget *parent = 0);
    ~ModelSettingsDialog();

private slots:
    void validateSettings();

private:
    Ui::ModelSettingsDialog *ui;
};

#endif // MODELSETTINGSDIALOG_H
