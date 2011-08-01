#include <QApplication>
#include <QSplashScreen>
#include <QDebug>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QTranslator>
#include <QLibraryInfo>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setStyle("Cleanlooks");
    app.setStyleSheet("QHeaderView::section, QHeaderView::section * {background-color: qlineargradient"
                        "(x1:0, y1:0, x2:0, y2:1,  stop:0 #616161, stop: 0.5 #505050,  stop: 0.6 #434343, stop:1 #656565);"
                        "color: white; padding-left: 4px; border: 1px solid #6c6c6c;}");

    //QTranslator qtTranslator;
    //qtTranslator.load("qt_" + QLocale::system().name(),
//                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
//    app.installTranslator(&qtTranslator);

    //QTranslator myappTranslator;
    //myappTranslator.load("economydisplayer");//"economydisplayer_" + QLocale::system().name());
    //app.installTranslator(&myappTranslator);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("c:/Documents and Settings/T/Dokumentumok/gazdaság-fel.jpg"));
    splash->show();

    Qt::Alignment botCenter = Qt::AlignCenter | Qt::AlignBottom;
    splash->showMessage(QObject::tr("Setting up the main window..."),
                        botCenter, Qt::green);


    MainWindow *mv = new MainWindow;
    app.setWindowIcon(QIcon("c:/Documents and Settings/T/Dokumentumok/gazdaság-fel.jpg"));
    mv->setWindowOpacity(0);
    mv->showMaximized();

    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect; // make sure to create using new, since effect has to be alive as long as the target widget is using it.
    opacityEffect->setOpacity(1); // initially widget should be visible
    splash->setGraphicsEffect(opacityEffect);
    QPropertyAnimation* anim = new QPropertyAnimation;
    anim->setTargetObject(opacityEffect);
    anim->setPropertyName("opacity");
    anim->setDuration(1000);
    anim->setStartValue(opacityEffect->opacity());
    anim->setEndValue(0);
    anim->setEasingCurve(QEasingCurve::InQuad);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
    QObject::connect(anim,SIGNAL(destroyed()),splash,SLOT(deleteLater()));

    delete splash;    

    qsrand(QTime::currentTime().msec());
    return app.exec();    
}

/*double dFI(double x){ return 1.0 / sqrt (2.0 * acos(-1)) * exp(-0.5*x*x); }
double phi(double x)
{
    // constants
    double a1 =  0.254829592;
    double a2 = -0.284496736;
    double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;
    double p  =  0.3275911;

    // Save the sign of x
    int sign = 1;
    if (x < 0)
        sign = -1;
    x = fabs(x)/sqrt(2.0);

    // A&S formula 7.1.26
    double t = 1.0/(1.0 + p*x);
    double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

    return 0.5*(1.0 + sign*y);
}*/
