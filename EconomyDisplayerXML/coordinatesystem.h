#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include <QGraphicsView>

#include "ecurve.h"

class CoordinateSystem : public QGraphicsView
{
    Q_OBJECT

public:
    CoordinateSystem(QWidget *parent = 0);
    CoordinateSystem(const QString & name, QWidget *parent = 0);
    ~CoordinateSystem();

    void addCurve(eCurve *curve);
    void removeCurve(const QString & name);

    inline const QString getName() const            { return m_Name;            }
    inline const int getCurvesCount() const         { return m_Curves.size();   }
    inline const QList<eCurve*> *getCurves() const  { return &m_Curves;         }
    inline const double getXScale() const           { return m_X_Scale;         }
    inline const double getYScale() const           { return m_Y_Scale;         }
    inline const double getXSize() const            { return m_X_Size;          }
    inline const double getYSize() const            { return m_Y_Size;          }

signals:
    void updatePartners(double factor);
protected:
    void wheelEvent(QWheelEvent *event);

public slots:
    void repaint();
    void rescale(double factor);

private slots:
    void setXScaleP();
    void setYScaleP();
    void setXScaleM();
    void setYScaleM();
    void setSize(int sizeX, int sizeY);

    void askToSaveImage();

private:
    QGraphicsScene *m_Scene;
    QString m_Name;
    QList<eCurve*> m_Curves;
    QList<QPointF*> m_IntersectionPoints;

    double m_X_Scale;
    double m_Y_Scale;
    double m_X_Size;
    double m_Y_Size;


    void setTextOnScreen(const QString &str, double x, double y, int size, bool italic, QColor color);
    void createCoordinateSystem();    
    void checkIntersection();
    void manageCurves();

    void contextMenuEvent(QContextMenuEvent *event);
};

#endif // COORDINATESYSTEM_H
