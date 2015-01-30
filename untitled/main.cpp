#include <iostream>
#include <QApplication>
#include <QtGui>
#include "WalkingWidgetPlugin/WalkingWidgetPlugin.h"
#include "NDLCom-Qt/InterfaceContainerWidget.h"


using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

   WalkingWidgetPlugin* plug = new WalkingWidgetPlugin;
//    ndlcom_qt::InterfaceContainerWidget* test = new ndlcom_qt::InterfaceContainerWidget;

    plug->show();

    return a.exec();
}

