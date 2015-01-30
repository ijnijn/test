#ifndef WALKINGWIDGETPLUGIN_H
#define WALKINGWIDGETPLUGIN_H


#include <QtGui>
#include <QTabWidget>
#include <QVBoxLayout>


#include "widgets/charlie/WalkingWidget.h"


#include "NDLCom/Message.h"
#include "NDLCom-Qt/NDLComContainer.h"
#include "NDLCom-Qt/CommandLineArgument.h"
#include "NDLCom-Qt/NDLCom.h"
#include "NDLCom/Protocol.h"


#include "RobotConfig/XmlReader.h"
#include "RobotConfig/DeviceClasses.h"
#include "RobotConfig/Devices.h"


#include "NDLCom-Qt/InterfaceContainerWidget.h"



class WalkingWidgetPlugin : public QWidget
{
    Q_OBJECT

    public:
        WalkingWidgetPlugin(QWidget *parent = 0);
        virtual ~WalkingWidgetPlugin();

    private:
        widgets::WalkingWidget* walkWid;

        ndlcom_qt::InterfaceContainerWidget* netWid;

        QTabWidget*  tabWid;
        QVBoxLayout* mainLayout;
        QPushButton* puBut;

    private slots:
        void showGUI(void);
};


#endif /* WALKINGWIDGETPLUGIN_H */
