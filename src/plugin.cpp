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

QString KU_Camera_Plugin::license() const
{
    return "LGPL";
}

QIcon KU_Camera_Plugin::icon() const
{
    return QIcon();
}

bool KU_Camera_Plugin::initialize()
{
    return true;
}

bool KU_Camera_Plugin::stop()
{
    return true;
}

QWidget* KU_Camera_Plugin::createWidget()
{
    this->cameraWidget = new QQuickWidget;
    this->cameraWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    this->cameraWidget->setSource(QUrl("qrc:/qml/Main.qml"));
//    this->cameraWidget->setSource(QUrl("/home/xavier/workspace/make_karunit/karunit_camera/qml/Main.qml"));

    QObject* camera = this->cameraWidget->rootObject()->findChild<QObject*>("camera");
    if(camera)
    {
        QString deviceId = KU::Settings::instance()->value(this->id(), "deviceId", QString()).toString();
        if(!deviceId.isEmpty())
            camera->setProperty("deviceId", deviceId);
    }

    return this->cameraWidget;
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
    QObject* camera = this->cameraWidget->rootObject()->findChild<QObject*>("camera");
    if(camera)
        KU::Settings::instance()->setValue(this->id(), "deviceId", camera->property("deviceId").toString());

    return KU::Settings::instance()->status() == QSettings::NoError;
}
