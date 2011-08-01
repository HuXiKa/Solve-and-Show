#ifndef MMLPARSER_H
#define MMLPARSER_H

#include <QStringList>

class QFile;
class Variable;
class EquationGroup;
class Curve;
class QDomDocument;
class QDomNode;


class MMLParser
{
public:
    MMLParser();
    bool read(QFile* file,QDomDocument *doc);
    bool write(QFile* file);
    QList<Variable*> getVariables(QDomNode *nd);
    QList<EquationGroup*> getEquationGroups(QDomNode *nd);
    QList<Curve*> getCurves(QDomNode *nd);
    QStringList getAbout(QDomNode *nd);

    inline void addVariables(Variable *var)             { m_Variables << var;               }
    inline void addEquationGroup(EquationGroup *eqg)    { m_EquationGroups << eqg;          }
    inline void addCurve(Curve *curve)                  { m_Curves << curve;                }
    inline void addAbout(const QString &ab)             { m_About << ab;                    }

    inline const int variableCount() const              { return m_Variables.size();        }
    inline const int equationCount() const              { return m_EquationGroups.size();   }
    inline const int curveCount() const                 { return m_Curves.size();           }

    void clear() { m_Variables.clear(); m_EquationGroups.clear(); m_Curves.clear(); m_About.clear(); }

    bool const validate() const;

private:
    QList<Variable*> m_Variables;
    QList<EquationGroup*> m_EquationGroups;
    QList<Curve*> m_Curves;
    QStringList m_About;
};

#endif // MMLPARSER_H
