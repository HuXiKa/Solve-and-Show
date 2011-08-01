#include <QScriptEngine>
#include <QStringList>
#include <QDebug>

#include "equationgroup.h"
#include "abbrevations.h"
#include "edouble.h"
#include "equation.h"

EquationGroup::EquationGroup()
{
}

void EquationGroup::checkUnKnows(){
    foreach(eDouble* var, m_UnKnowns)
        if(var->getValue() != abbrevations::noValue)
            m_UnKnowns.removeOne(var);
}

void eliminate(double **a, int n, int index)
{
    //double objects
    double scale_factor;

    // Eliminate object from equations.

    for(int row=index+1; row<=n-1; row++)
    {
        scale_factor = -a[row][index]/a[index][index];
        a[row][index]=0;
        for(int col=index+1; col<=n; col++)
        {
            a[row][col]+=a[index][col]*scale_factor;
        }
    }

    //the void return
    return;
}


void back_substitute(double **a, int n, double soln[])
{
    //performs back substitution in this equation.
    soln[n-1]=a[n-1][n]/a[n-1][n-1];
    for (int row=n-2; row>=0; row--)
    {
        for(int col=n-1; col>=row+1; col--)
        {
            a[row][n]-=soln[col]*a[row][col];
        }
        soln[row]= a[row][n]/a[row][row];
    }

    // Void Return
    return;
}

/*
 0 = ( ( 25 * 0.5 ) / w ) ^ ( 1 / 0.5 ) - L
 0 = 640 * w - L



 0 = a + 2 / b
 0 = 2 * a +  b
*/



double* parse (QString equation, QStringList unKnowns){
    int index = 0, i = 0;    
    double *egyutthatok;
    egyutthatok = (double*) malloc(sizeof(double) * unKnowns.size());
    for(;i < unKnowns.size(); ++i)
        egyutthatok[i] = .0;

    i = 0;
    double zarojelelotti = 0. , plusminus = 1.;
    bool zarojelben = false;
    QStringList list = equation.split(" ");    
    QStringList operators;
    operators << "+" << "-" << "*" << "/" << "^";
    foreach(QString s,list){ // 200 ; + ; 0.8 ; * ; ( ; Y ; - ; 200 ; ) ; + ; 1200 ; - ; 50 ; * ; r ; + ; 280 ; - ; Y
        double x;
        if(unKnowns.contains(s)){ // ( ; ( ; 25 ; * ; 0.5 ; ) ; / ; w ; ) ; ^ ; ( ; 1 ; / ; - ; 0.5 ; ) ; - ; ( ; L ; )
            index = unKnowns.indexOf(s);
            if(i >= 2 && list.at(i - 2).at(0).isNumber()){
                if(list.at(i - 1) == "*"){
                    double change = list.at(i-2).toDouble() * plusminus;
                    if(zarojelben)
                        change *= zarojelelotti;        // 0.75 * ( Y - 400 + 0.2 * Y )
                    egyutthatok[index] += change;       // - 50 * r
                    x = egyutthatok[index];
                } else{
                    egyutthatok[index] += plusminus;    // 280 - Y
                    x = egyutthatok[index];
                }
            }
            else if(i > 2 && !(list.at(i - 2).at(0).isNumber()) && operators.contains(list.at(i - 2))){
                egyutthatok[index] += zarojelelotti * plusminus; //  * +-(0.8)   ÉS  300 * r - Y
                x = egyutthatok[index];
            }
            else{
                egyutthatok[index] += plusminus;
                x = egyutthatok[index];
            }
        }
        else if(s == "("){
            zarojelelotti = i > 2 ? list.at(i - 2).toDouble() : list.at(i).toDouble();
            zarojelben = true;
        }
        else if(s == ")"){
            zarojelelotti = 0;
            zarojelben = false;
        }
        else if( s == "-")
            plusminus = -1;
        else if( s == "+")
            plusminus = 1;

        i++;
    }
    return egyutthatok;
}



bool EquationGroup::solveLinearSystem(EquationGroup *otherEquationGroup)
{
    QScriptEngine engine;
    QStringList unKnowns;
    QStringList equations;
    foreach(eDouble * e, m_UnKnowns)
        unKnowns << e->getName();


    QMap<QString, Equation*>::const_iterator itr = otherEquationGroup->getEquations()->begin();
    QString eq1 = ((Equation*)itr.value())->getSubstitutedFormula();
    itr = m_Equations.begin();
    QString eq2 = ((Equation*)itr.value())->getSubstitutedFormula();

    QString first = eq1.split(" =").first();
    eq1.remove(first + " = ");
    eq1.append(" - " + first);
    first = eq2.split(" =").first();
    eq2.remove(first + " = ");
    eq2.append(" - " + first);

    equations << eq1 << eq2;

    int size = unKnowns.count();
    double factors[size];

    int i = 0,j = 0;

    foreach(QString eq, equations){
        foreach(QString var, unKnowns){
            eq.replace(var,"0");
        }        
        factors[i++] = engine.evaluate(eq).toNumber();
    }


    QList< double* > coefficents;


    foreach(QString eq, equations){
        double *coeff = parse(eq,unKnowns);
        coefficents << coeff;
    }

    double **matrix;
    //[size][size + 1];
    matrix = new double * [size];
    for (int i=0; i<size; ++i)
    {
        matrix[i] = new double [size + 1];
        // if you want you can make col different in each iteration to save space,
        // for example in a upper diagonal matrix, etc. This way it doesn't have
        // to be a square or rectangular matrix.
    }
/*
  0.05 * ( 5000 - 600 ) + 200 * r - 150 - X = 0
  1000 - 300 * r - X = 0;

  220 + 200 * r - X = 0

*/
    for(i = 0;i < size; ++i)
        for(j = 0;j < size; ++j)
            matrix[i][j] = coefficents.at(i)[j];

    for(i = 0; i < size; ++i)
        matrix[i][size] = -factors[i];

    /*QString str;
    for (int var = 0; var < size; ++var) {
        for (int var2 = 0; var2 < size + 1; ++var2) {
            str.append(QString::number(matrix[var][var2]) + " ");
        }
        qDebug() << str << "\n--------";
        str = "";
    }*/
    //if (engine.hasUncaughtException()) {
    //     int line = engine.uncaughtExceptionLineNumber();
    //     qDebug() << "uncaught exception at line" << line << ":" << objectValue.toString();
    // }

    double soln[size];

    for(int index=0; index<=size-2; index++)
    {
        eliminate(matrix,size,index);
    }

    //perform back substitution step.
    back_substitute(matrix,size,soln);

    //Print solution

    /*qDebug() <<"\nSolution: \n";

    for(int i=0; i<=size-1; i++)
    {
        qDebug() << "Solution Vector" << i+1 << ": "<< soln[i] << endl;
    }*/

    i = 0;
    foreach(eDouble * e, m_UnKnowns)
        e->setValue(soln[i++]);

    for (int i=0; i < size; ++i)
    {
            delete [] matrix[i];
    }
    delete [] matrix;
    return true;
}

EquationGroup::~EquationGroup()
{

}
