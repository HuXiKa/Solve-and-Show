#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QDomElement;
class QDomDocument;
class QDomNode;
class MMLParser;
class QPushButton;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void addVariable();
    void removeVariable();
    void addEquation();
    void removeEquation();
    void addCurve();
    void removeCurve();
    void open();
    void saveAs();
    void about();    

    void updateGui(QDomDocument *dom);
    void setButton(bool);

private:
    Ui::MainWindow *ui;
    MMLParser * m_Parser;
    void updateParser();
    QPushButton *button;
};

#endif // MAINWINDOW_H
