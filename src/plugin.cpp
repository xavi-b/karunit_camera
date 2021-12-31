#include "plugin.h"

QString KU_Camera_Plugin::name() const
{
    return "Camera";
}

QString KU_Camera_Plugin::id() const
{
    return "karunit_camera";
}

KU::PLUGIN::PluginVersion KU_Camera_Plugin::version() const
{
    return {1, 0, 0};
}

QString KU_Camera_Plugin::license() const
{
    return "LGPL";
}

QString KU_Camera_Plugin::icon() const
{
    return "camera-video";
}

bool KU_Camera_Plugin::initialize()
{
    return true;
}

bool KU_Camera_Plugin::stop()
{
    return true;
}

bool KU_Camera_Plugin::loadSettings()
{
    return true;
}

bool KU_Camera_Plugin::saveSettings() const
{
    return true;
}
