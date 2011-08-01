#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class CoordinateSystem;
class SettingsDialog;
class InitDialog;
class MonetaryDialog;
class FiscalDialog;
class ModelSettingsDialog;
class AddEquationDialog;

namespace Ui {
class MainWindow;
}

class QGridLayout;
class QTreeWidgetItem;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    void showVariables();

    inline Ui::MainWindow *getUI() const { return ui;}

    ~MainWindow();    

protected:
    void changeEvent(QEvent *e);

private slots:
    void updateVariables();
    void showPolicyEffect();
    void updateCoordinateSystems();
    void resetVariables();
    void execFiscalPolicy();
    void execMonetaryPolicy();
    void setOpacity(qreal);
    void calculate();
    void setFullscreenMode(bool);
    void finalizePolicy();
    void undoPolicy();

    void open();    
private:
    Ui::MainWindow *ui;    
public:
    InitDialog *id;
    SettingsDialog *sd;
private:
    MonetaryDialog *md;
    FiscalDialog *fd;
    ModelSettingsDialog *msd;
    AddEquationDialog *aed;
    QList<CoordinateSystem*> m_CoordinateSystems;

    CoordinateSystem * addCurvesToCoordinateSystems(QTreeWidgetItem * top, CoordinateSystem * cs = 0);
    QGridLayout * setSubWindowLayout(QGridLayout * gridlayout, CoordinateSystem * cs);           

};

#endif // MAINWINDOW_H
