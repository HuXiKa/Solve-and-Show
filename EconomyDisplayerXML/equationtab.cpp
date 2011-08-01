#include <QLineEdit>

#include "equationtab.h"
#include "ui_equationtab.h"
#include "abbrevations.h"
#include "edouble.h"

EquationTab::EquationTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EquationTab)
{
    ui->setupUi(this);    
}

EquationTab::EquationTab(Equation * eq, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EquationTab),
    m_Equation(eq)
{
    ui->setupUi(this);
    createUi(eq);
    setStyleSheet("QLineEdit {"
                  "padding: 1px;"
                  "border-style: solid;"
                  "border: 2px solid gray;"
                  "border-radius: 8px;"
                  "selection-color: yellow;"
                  "selection-background-color: blue;"
                  "}"
                  "QLineEdit:disabled {"
                  "background: gray;"
                  "}"
                  "QLineEdit:selected {"
                  "color: yellow;"
                  "background-color: blue;"
                  "}"
                  );
}

EquationTab::~EquationTab()
{
    delete ui;
    foreach(QLineEdit *lineedit, m_LineEdits.values())
        delete lineedit;
}

void EquationTab::createUi(Equation *eq)
{
    QStringList colors;
    colors << "#000000" << "#0055FF" << "#005500" << "#AAFF00"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF"
           << "#000000" << "#0055FF" << "#005500" << "#AAFF00"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF";
    int i = 1;
    ui->nameLabel->setText(eq->getName());
    QFont font;
    font.setPointSize(40);
    QStringList formula = eq->getFormula().split(" ");

    QString formulaHTML = "<p align=\"center\"\n"
            "<span></span>";

    //?? miért kell elé +1 span?
    ui->formulaHorizontalLayout->setAlignment(Qt::AlignCenter);

    foreach(QString str, formula)    { // "M" "*" "V" "=" "P" "*" "Y"
        QLabel *chLabel = new QLabel(this);        
        chLabel->setFont(font);        
        bool isVar = false;
        if(str.size() > 0){
            isVar = str.at(0).isLetter();
        }        
        chLabel->setText(str);
        ui->formulaHorizontalLayout->addWidget(chLabel);

        if(isVar){ // ha változó akkor csináljunk hozzá értékadó részt is (ha még nem volt)
            chLabel->setStyleSheet(":hover { color: white }");
            QString info = eq->getVariableInfo(str);
            chLabel->setToolTip(info);
            if(!m_LineEdits.keys().contains(str)){
                QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
                QHBoxLayout *layout = new QHBoxLayout();
                layout->setObjectName(str + "HorizontalLayout");
                QLabel *nameLabel = new QLabel(ui->valueSetterBox);
                nameLabel->setObjectName(str + "NameLabel");
                QFont valueFont;
                valueFont.setPointSize(12);
                nameLabel->setFont(valueFont);
                nameLabel->setText(str + " =");

                layout->addWidget(nameLabel);

                QLineEdit *valueLineEdit = new QLineEdit(this);
                m_LineEdits.insert(str,valueLineEdit);
                valueLineEdit->setObjectName(str + "ValueLineEdit");
                sizePolicy.setHeightForWidth(valueLineEdit->sizePolicy().hasHeightForWidth());
                valueLineEdit->setSizePolicy(sizePolicy);
                connect(valueLineEdit,SIGNAL(textChanged(QString)),this,SLOT(updateFormulaText()));

                QRegExp regExp("^[0-9,-\.]{0,6}$"); // csak szám, 6 számjegyig, enged több pontot is!!!
                valueLineEdit->setValidator(new QRegExpValidator(regExp, this));
                layout->addWidget(valueLineEdit);

                QLabel * infoLabel = new QLabel(this);
                infoLabel->setObjectName(str + "InfoLabel");
                infoLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
                infoLabel->setText(info);

                layout->addWidget(infoLabel);
                ui->valueSettersGridLayout->addLayout(layout,ui->valueSettersGridLayout->rowCount(),0,1,1);


                formulaHTML.append("<span style=\" font-size:12pt; font-weight:600; color:" + colors.at(i++) + "\">" + str + "</span>");
            }

        }else{
            formulaHTML.append("<span style=\" font-size:12pt; font-weight:600; color:" + colors.at(0) + "\">" + str + "</span>");
        }
        formulaHTML.append("<span style=\" font-size:12pt; \"> </span>");
    }
    formulaHTML.append("</p></body></html>");
    ui->formulaTextEdit->setText(formulaHTML);
    //setFormulaText();
}

void EquationTab::setFormulaText()
{
    QStringList colors;
    colors << "#000000" << "#0055FF" << "#005500" << "#AAFF00"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF"
           << "#000000" << "#0055FF" << "#005500" << "#AAFF00"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF";
    QString html = "<p align=\"center\"\n"
            "<span></span>";
    int i = 1;
    QStringList formula = m_Equation->getFormula().split(" ");
    foreach(QString str, formula){
        if(!abbrevations::variables.contains(str)){
            html.append("<span style=\" font-size:12pt; font-weight:600; color:" + colors.at(0) + "\">" + str + "</span>");
        }
        else{
            double val = abbrevations::variables[str]->getValue();            
            if(val == abbrevations::noValue){
                html.append("<span style=\" font-size:12pt; font-weight:600; color:" + colors.at(i++) + "\">" + str + "</span>");
            }
            else{
                html.append("<span style=\" font-size:12pt; font-weight:600; color:" + colors.at(i++) + "\">" + QString::number(val) + "</span>");
            }
        }
        html.append("<span style=\" font-size:12pt; \"> </span>");
    }
    html.append("</p></body></html>");
    ui->formulaTextEdit->setText(html);
}

void EquationTab::updateFormulaText(){
    QLineEdit *sender = static_cast<QLineEdit*>(QObject::sender());
    QStringList colors;
    colors << "#000000" << "#0055FF" << "#005500" << "#AAFF00"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF"
           << "#000000" << "#0055FF" << "#005500" << "#AAFF00"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF"
           << "#550000 "<< "#FFAAFF" << "#cfcfcf" << "#0011FF";
    QString html = "<p align=\"center\"\n"
            "<span></span>";
    int i = 1;
    QStringList formula = m_Equation->getFormula().split(" ");
    //QString varName = sender->objectName();
    //int index = varName.indexOf("Value");
    //varName.remove(index, varName.length() - index);
    //abbrevations::variables[varName]->setValue(sender->text().toDouble());
    foreach(QString str, formula){
        if(!abbrevations::variables.contains(str)){
            html.append("<span style=\" font-size:12pt; font-weight:600; color:" + colors.at(0) + "\">" + str + "</span>");
        }
        else{
            QString senderName = sender->objectName();
            int index = senderName.indexOf("Value");
            senderName.remove(index, senderName.length() - index);
            double val;
            if(senderName == str){
                if(sender->text().size() == 0)
                    val = abbrevations::noValue;
                else
                    val = sender->text().toDouble();
            }
            else{
                if(!m_LineEdits[str]->text().isEmpty()){
                    val = m_LineEdits[str]->text().toDouble(); //abbrevations::variables[str]->getValue();
                }
                else{
                    val = abbrevations::noValue;
                }
            }
            if(val == abbrevations::noValue){
                html.append("<span style=\" font-size:12pt; font-weight:600; color:" + colors.at(i++) + "\">" + str + "</span>");
            }
            else{
                html.append("<span style=\" font-size:12pt; font-weight:600; color:" + colors.at(i++) + "\">" + QString::number(val) + "</span>");
            }
        }
        html.append("<span style=\" font-size:12pt; \"> </span>");
    }
    html.append("</p></body></html>");
    ui->formulaTextEdit->setText(html);
}
