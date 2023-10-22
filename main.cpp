#include "store_manager.h"
#include "stock_system.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    if(QT_VERSION>=QT_VERSION_CHECK(5,6,0)){
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    }
    QApplication a(argc, argv);
    store_manager w;
    w.show();
    return a.exec();
}


