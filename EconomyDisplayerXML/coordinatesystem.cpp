#include <cmath>
#include <QWheelEvent>
#include <QLineF>
#include <QGraphicsSimpleTextItem>
#include <QTime>
#include <QFileDialog>
#include <QMenu>
#include <QApplication>
#include <QStyle>

#include "coordinatesystem.h"
#include "ecurve.h"
#include "edouble.h"


CoordinateSystem::CoordinateSystem(QWidget *parent) :
    QGraphicsView(parent)
{
    setDragMode(ScrollHandDrag);
    m_X_Scale = 1.5;
    m_Y_Scale = 1.5;
    m_X_Size = 100;
    m_Y_Size = 100;
    m_Scene = new QGraphicsScene;
    scale(1,-1);
    qsrand((uint)QTime::currentTime().msec());
}

CoordinateSystem::CoordinateSystem(const QString & name, QWidget *parent) :
    QGraphicsView(parent)
{

    setDragMode(ScrollHandDrag);
    m_X_Scale = 1;
    m_Y_Scale = 1;
    m_X_Size = 100;
    m_Y_Size = 100;
    m_Scene = new QGraphicsScene;
    scale(1,-1);
    qsrand((uint)QTime::currentTime().msec());
    m_Name = name;
    //setViewport(new QGLWidget);
    setRenderHint(QPainter::Antialiasing);    
}

void CoordinateSystem::wheelEvent(QWheelEvent *event)
{
    double numDegrees = event->delta() / 8.0;
    double numSteps = numDegrees / 15.0;
    double factor = pow(1.125, numSteps);    
    scale(factor, factor);
    updatePartners(factor);
}

void CoordinateSystem::rescale(double factor)
{
    scale(factor, factor);
}

void CoordinateSystem::setXScaleM()
{
    m_X_Scale = (double)8 / 9;
    m_Y_Scale = 1;
    scale(m_X_Scale, m_Y_Scale);
    //repaint();
}

void CoordinateSystem::setYScaleM()
{
    m_Y_Scale = (double)8 / 9;
    m_X_Scale = 1;
    scale(m_X_Scale, m_Y_Scale);
    //repaint();
}

void CoordinateSystem::setXScaleP()
{
    m_X_Scale = (double)9 / 8;
    m_Y_Scale = 1;
    scale(m_X_Scale, m_Y_Scale);
    //repaint();
}

void CoordinateSystem::setYScaleP()
{
    m_Y_Scale = (double)9 / 8;
    m_X_Scale = 1;
    scale(m_X_Scale, m_Y_Scale);
    //repaint();
}

void CoordinateSystem::setSize(int sizeX, int sizeY)
{
    m_X_Size = sizeX;
    m_Y_Size = sizeY;    
}

void CoordinateSystem::addCurve(eCurve * curve)
{
    m_Curves << curve;
    if(m_IntersectionPoints.size() == 0)
        checkIntersection();
}

void CoordinateSystem::manageCurves()
{

    if(m_Curves.size() == 0) return;
    else if(m_Curves.size() == 1){
        eCurve *curve = m_Curves.first();
        //if(curve->isDrawn()) return;
        if(curve->getLines()->size() == 0)
            curve->calculateCurve();

        if(curve->getLines()->size() > 0){
            foreach(QLineF *line, *curve->getLines()){
                if(line->p1().x() > m_X_Size || line->p1().y() > m_Y_Size)
                    continue;
                else
                    m_Scene->addLine(*line, QPen(curve->getColor()->toRgb()));
            }
        }

        QPointF *intersectpoint = new QPointF(0,0);
        if(!m_IntersectionPoints.contains(intersectpoint))
            m_IntersectionPoints << intersectpoint;

        //curve->setDrawn(true);
    }

    /*
      y_size = 500; y() = 8;
      y_size = y() * 2;

      y_size * y_scale = 500;
      y_scale = 500 / y_size

    */

    else if(m_Curves.size() > 1){
        foreach(eCurve *curve , m_Curves){
            //if(curve->isDrawn()) continue;
            if(curve->getLines()->size() == 0)
                curve->calculateCurve();

            if(curve->getLines()->size() > 0){
                foreach(QLineF *line, *curve->getLines()){
                    if(line->p1().x() > m_X_Size || line->p1().y() > m_Y_Size)
                        continue;
                    else
                        m_Scene->addLine(*line, QPen(curve->getColor()->toRgb()));
                }
            }

            //curve->setDrawn(true);
        }
        foreach(eCurve *curve, m_Curves){
            QPointF *intersectpoint = new QPointF(curve->getXAxis()->getValue(),curve->getYAxis()->getValue());
            if(!m_IntersectionPoints.contains(intersectpoint))
                m_IntersectionPoints << intersectpoint;
        }
    }

}


void CoordinateSystem::repaint()
{
    m_Scene->clear();

    m_Scene->setSceneRect(- m_X_Size / 20 * 2, - m_Y_Size / 20 * 2, m_X_Size + m_X_Size / 20 * 3, m_Y_Size + m_Y_Size / 20 * 3);


    manageCurves();


    foreach(eCurve *curve , m_Curves){
        if(curve->getLines()->size() > 0)
            setTextOnScreen(curve->getName(),curve->getLines()->last()->x2(),curve->getLines()->last()->y2(),8,false,curve->getColor()->toRgb());
    }

    createCoordinateSystem();

    scale(m_X_Scale,m_Y_Scale);

    setScene(m_Scene);
    centerOn(m_IntersectionPoints.first()->x(),m_IntersectionPoints.first()->y());

    m_X_Scale = 1;
    m_Y_Scale = 1;

}

void CoordinateSystem::setTextOnScreen(const QString &str, double x, double y, int size, bool italic, QColor color)
{        
    QGraphicsSimpleTextItem *text = new QGraphicsSimpleTextItem;
    text->setFont(QFont("Arial", size, 0, italic));
    text->setBrush(color);
    text->setText(str);
    text->setPos(x,y);
    text->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    //qDebug() << str << " ide (" << x << ";" << y << ")" << endl;

    //while(!m_Scene->collidingItems(text).isEmpty()){

    m_Scene->addItem(text);
}

void CoordinateSystem::createCoordinateSystem()
{
    //m_Scene->clear();
    QVector <QGraphicsLineItem*> coordinate_system;

    m_Scene->setPalette(QPalette(Qt::black));
    m_Scene->addLine(QLineF(0,0,0,m_Y_Size));
    m_Scene->addLine(QLineF(0,0,0,-m_Y_Size / 10));
    m_Scene->addLine(QLineF(0,0,m_X_Size,0));
    m_Scene->addLine(QLineF(0,0,-m_X_Size / 10,0));

    setTextOnScreen(QString::number(0),0,0,2,false,Qt::black);

    double xStep = m_X_Size / 20;
    double yStep = m_Y_Size / 20;
    for(double i = xStep; i <= m_X_Size ; i+=xStep ){
        QGraphicsLineItem *gline = new QGraphicsLineItem;
        QLineF *line = new QLineF(0,2,0,-2);
        gline->setLine(*line);
        gline->setPos(i,0);
        gline->setFlag(QGraphicsItem::ItemIgnoresTransformations);
        coordinate_system.push_back(gline);
        setTextOnScreen(QString::number(i),i,0,6,false,Qt::black);   // double értéknél sok a tört....
    }
    for(double i = yStep; i <= m_Y_Size ; i+=yStep ){
        QGraphicsLineItem *gline = new QGraphicsLineItem;
        QLineF *line = new QLineF(2,0,-2,0);
        gline->setLine(*line);
        gline->setPos(0,i);
        gline->setFlag(QGraphicsItem::ItemIgnoresTransformations);
        coordinate_system.push_back(gline);
        setTextOnScreen(QString::number(i),0,i,6,false,Qt::black);
    }
    for(double i = yStep; i <= m_Y_Size / 10 ; i+=yStep ){
        QGraphicsLineItem *gline = new QGraphicsLineItem;
        QLineF *line = new QLineF(-2,0,2,0);
        gline->setLine(*line);
        gline->setPos(0,-i);
        gline->setFlag(QGraphicsItem::ItemIgnoresTransformations);
        coordinate_system.push_back(gline);
        setTextOnScreen(QString::number(-i),0,-i,6,false,Qt::black);
    }    
    for(double i = xStep; i <= m_X_Size / 10 ; i+=xStep ){
        QGraphicsLineItem *gline = new QGraphicsLineItem;
        QLineF *line = new QLineF(0,2,0,-2);
        gline->setLine(*line);
        gline->setPos(-i,0);
        gline->setFlag(QGraphicsItem::ItemIgnoresTransformations);
        coordinate_system.push_back(gline);
        setTextOnScreen(QString::number(-i),-i,0,6,false,Qt::black);
    }

    for(int i = 0; i < coordinate_system.size(); i++ )
        m_Scene->addItem(coordinate_system[i]);

    if(m_Curves.size() > 1){
        foreach(QPointF * intersectionpoint, m_IntersectionPoints){
            setTextOnScreen(QString::number(intersectionpoint->x()),intersectionpoint->x(),-m_Y_Size / 30,9,true,Qt::blue);
            setTextOnScreen(QString::number(intersectionpoint->y()),-m_X_Size / 20,intersectionpoint->y(),9,true,Qt::blue);
        }
    }

    setTextOnScreen(m_Curves.at(0)->getXAxis()->getInfo(), m_X_Size + m_X_Size / 20, 0 ,9,true,Qt::green);
    setTextOnScreen(m_Curves.at(0)->getYAxis()->getInfo(), 0, m_Y_Size + m_Y_Size / 20, 9,true,Qt::green);

}


void CoordinateSystem::checkIntersection()
{
    if(m_Curves.size() < 2) return;

    m_Y_Size = m_Curves.first()->getYAxis()->getValue() * 2;
    m_Y_Scale = 500 / m_Y_Size;
    m_X_Size = m_Curves.first()->getXAxis()->getValue() * 2;
    m_X_Scale = 500 / m_X_Size;

}

void CoordinateSystem::removeCurve(const QString &name)
{

    for(int i = 0; i < m_Curves.size(); ++i)
        if(m_Curves[i]->getName() == name)
            m_Curves.removeAt(i);
        else if(m_Curves[i]->getName().endsWith(name))
            m_Curves[i]->setName(name);
    if(name.startsWith("új"))
        m_IntersectionPoints.pop_back();
    else                                    // NEMJÓ
        m_IntersectionPoints.pop_front();

}

CoordinateSystem::~CoordinateSystem()
{
    delete m_Scene;
    foreach(eCurve *curve, m_Curves)
        delete curve;
    foreach(QPointF *point, m_IntersectionPoints)
        delete point;
}

void CoordinateSystem::askToSaveImage() {
    QFileDialog fd(this, tr("Kép mentése"), QString(), tr("Kép fájlok (*.png)"));
    fd.setDefaultSuffix("png");
    fd.setAcceptMode(QFileDialog::AcceptSave);
    fd.exec();

    if(!fd.selectedFiles().isEmpty()){
        QImage *image = new QImage(width(), height(),QImage::Format_ARGB32);	// I tried Format_ARGB32
        QPainter painter(image);
        painter.setRenderHint(QPainter::Antialiasing);
        render(&painter);
        painter.end();	// I tried with and without this line
        image->save(fd.selectedFiles().front(), "PNG");
    }

    //pixmap().save(fd.selectedFiles().front());
}
void CoordinateSystem::contextMenuEvent(QContextMenuEvent *e) {
    QMenu menu;

    QIcon icon(qApp->style()->standardIcon(QStyle::SP_DialogSaveButton));
    menu.addAction(icon,tr("Kép mentése..."), this, SLOT(askToSaveImage()));

    menu.exec(e->globalPos());
}
