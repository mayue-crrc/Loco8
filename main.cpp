#include "global.h"

#ifdef QT_VERSION_5_6
#include <QApplication>

#else
#include <QApplication>
#include <QWSServer>
#endif
#include "widget.h"
#include <QTextCodec>
#include "log4qt/propertyconfigurator.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef QT_VERSION_5_6
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
//    QTextCodec::setCodecForCStrings( QTextCodec::codecForLocale() );
//    QTextCodec::setCodecForTr( QTextCodec::codecForName( "UTF-8" ) );
#else
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
#endif



    QDir tempDir;
    if(!tempDir.exists("OperationRecord/"))
    {
        tempDir.mkpath("OperationRecord/");
    }

    Log4Qt::PropertyConfigurator::configure(a.applicationDirPath()+ "/log4j.properties");

    Widget w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();


    return a.exec();
}
