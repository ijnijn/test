#include "WalkingWidgetPluginPlugin.h"
#include "WalkingWidgetPlugin.h"

Q_EXPORT_PLUGIN2(WalkingWidgetPlugin, WalkingWidgetPluginPlugin)

WalkingWidgetPluginPlugin::WalkingWidgetPluginPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}

WalkingWidgetPluginPlugin::~WalkingWidgetPluginPlugin()
{
}

bool WalkingWidgetPluginPlugin::isContainer() const
{
    return false;
}

bool WalkingWidgetPluginPlugin::isInitialized() const
{
    return initialized;
}

QIcon WalkingWidgetPluginPlugin::icon() const
{
    return QIcon("");
}

QString WalkingWidgetPluginPlugin::domXml() const
{
        return "<ui language=\"c++\">\n"
            " <widget class=\"WalkingWidgetPlugin\" name=\"walkingwidgetplugin\">\n"
            "  <property name=\"geometry\">\n"
            "   <rect>\n"
            "    <x>0</x>\n"
            "    <y>0</y>\n"
            "     <width>300</width>\n"
            "     <height>120</height>\n"
            "   </rect>\n"
            "  </property>\n"
//            "  <property name=\"toolTip\" >\n"
//            "   <string>WalkingWidgetPlugin</string>\n"
//            "  </property>\n"
//            "  <property name=\"whatsThis\" >\n"
//            "   <string>WalkingWidgetPlugin</string>\n"
//            "  </property>\n"
            " </widget>\n"
            "</ui>\n";
}

QString WalkingWidgetPluginPlugin::group() const {
    return "Rock-Robotics";
}

QString WalkingWidgetPluginPlugin::includeFile() const {
    return "WalkingWidgetPlugin/WalkingWidgetPlugin.h";
}

QString WalkingWidgetPluginPlugin::name() const {
    return "WalkingWidgetPlugin";
}

QString WalkingWidgetPluginPlugin::toolTip() const {
    return whatsThis();
}

QString WalkingWidgetPluginPlugin::whatsThis() const
{
    return "";
}

QWidget* WalkingWidgetPluginPlugin::createWidget(QWidget *parent)
{
    return new WalkingWidgetPlugin(parent);
}

void WalkingWidgetPluginPlugin::initialize(QDesignerFormEditorInterface *core)
{
     if (initialized)
         return;

     initialized = true;
}
