#ifndef ABBREVATIONS_H
#define ABBREVATIONS_H

#include <QMap>

class EquationGroup;
class eCurve;
class eDouble;
class MainWindow;
class QScriptEngine;

namespace abbrevations{

enum {noValue = -65535};

extern QMap<QString, eDouble*> variables;
extern QList<EquationGroup*> equationGroups;
extern QList<eCurve*> curves;

extern QScriptEngine *globalEngine;

extern MainWindow *mainWindow;

extern void initVariables();
extern void resetVariables();
extern void changeVar(QString varName, double value);

extern void calculate();
extern void solve();

extern void openFile(QString fileName);

extern bool useWolframAlpha;
extern bool coordinateSystemScaleable;
}


#endif // ABBREVATIONS_H
