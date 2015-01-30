#include "WalkingWidgetPlugin.h"


WalkingWidgetPlugin::WalkingWidgetPlugin(QWidget *parent)
    : QWidget(parent)
{   
    this->puBut = new QPushButton;
    this->puBut->setText("Run GUI");

    this->mainLayout = new QVBoxLayout;
    this->mainLayout->setSizeConstraint(QLayout::SetNoConstraint);
    this->mainLayout->addWidget(this->puBut);
    this->setLayout(mainLayout);

    connect( this->puBut,SIGNAL(clicked()), this, SLOT(showGUI()) );


    ////////////////////////////// ReadXML
    QString defaultFile = "/home/vazizi/rock2/charlie/lib/widgets/control/WalkingWidgetPlugin/src/xml/CharlieConfig.xml";
    /* default, at least as far as i can see today ...but let's see if we got something different on the cmd-line */
    QString file = ndlcom_qt::CommandLineArgument("--xml-file", defaultFile, "path to RobotConfig xml-file to use");
    robotconfig::XmlReader::getInstance()->readFromFile(file.toStdString(), true);


    this->walkWid = new widgets::WalkingWidget;
    this->netWid  = new ndlcom_qt::InterfaceContainerWidget;

    //this->showGUI();
}


WalkingWidgetPlugin::~WalkingWidgetPlugin()
{
}


void WalkingWidgetPlugin::showGUI(void)
{
    this->tabWid = new QTabWidget;
    this->tabWid->addTab( this->walkWid, "Walking" );
    this->tabWid->addTab( this->netWid , "Netwrok" );

    this->mainLayout->removeWidget( this->puBut  );
    this->mainLayout->addWidget   ( this->tabWid );
}
