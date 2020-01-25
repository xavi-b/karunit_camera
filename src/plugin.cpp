#include "plugin.h"

QString KU_Camera_Plugin::name() const
{
    return "Camera";
}

QString KU_Camera_Plugin::id() const
{
    return "camera.me";
}

KU::PLUGIN::PluginVersion KU_Camera_Plugin::version() const
{
    return { 1, 0, 0 };
}

QSet<KU::PLUGIN::PluginInfo> KU_Camera_Plugin::dependencies() const
{
    return QSet<KU::PLUGIN::PluginInfo>();
}

QString KU_Camera_Plugin::license() const
{
    return "LGPL";
}

QIcon KU_Camera_Plugin::icon() const
{
    return QIcon();
}

bool KU_Camera_Plugin::initialize(const QSet<KU::PLUGIN::PluginInterface*>& plugins)
{
    return true;
}

bool KU_Camera_Plugin::stop()
{
    return true;
}

QWidget* KU_Camera_Plugin::createWidget()
{
    QQuickWidget* widget = new QQuickWidget;
    widget->setResizeMode(QQuickWidget::SizeRootObjectToView);
//    widget->setSource(QUrl("qrc:/qml/Main.qml"));
    widget->setSource(QUrl("/home/xavier/workspace/karunit_camera/qml/Main.qml"));
    return widget;
}

QWidget* KU_Camera_Plugin::createSettingsWidget()
{
    return new QLabel("Camera");
}

bool KU_Camera_Plugin::loadSettings()
{
    return true;
}

bool KU_Camera_Plugin::saveSettings() const
{
    return KU::Settings::instance()->status() == QSettings::NoError;
}
