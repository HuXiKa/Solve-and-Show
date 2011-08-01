#ifndef MMLPARSER_H
#define MMLPARSER_H

#include <QStringList>

class QFile;
class EquationGroup;
class QDomDocument;
class QDomNode;
class eDouble;
class eCurve;


class MMLParser
{
public:
    MMLParser();
    bool read(QFile* file, QDomDocument *doc);
    QMap<QString, eDouble*> getVariables(QDomNode *nd);
    QList<EquationGroup*> getEquationGroups(QDomNode *nd);
    QList<eCurve*> getCurves(QDomNode *nd);
    QStringList getAbout(QDomNode *nd);    
};

#endif // MMLPARSER_H
