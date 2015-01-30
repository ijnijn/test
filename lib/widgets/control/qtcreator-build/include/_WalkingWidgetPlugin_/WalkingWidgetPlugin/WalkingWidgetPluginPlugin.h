#ifndef WALKINGWIDGETPLUGINPLUGIN_H
#define WALKINGWIDGETPLUGINPLUGIN_H

#include <QtGui>
#include <QtDesigner/QDesignerCustomWidgetInterface>

class WalkingWidgetPluginPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    WalkingWidgetPluginPlugin(QObject *parent = 0);
    virtual ~WalkingWidgetPluginPlugin();

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget* createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool initialized; 
};

#endif /* WALKINGWIDGETPLUGINPLUGIN_H */  
