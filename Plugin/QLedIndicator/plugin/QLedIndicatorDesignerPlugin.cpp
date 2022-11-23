#include "../src/QLedIndicator.h"
#include "QLedIndicatorDesignerPlugin.h"

#include <QtPlugin>
#include <QFile>

QLedIndicatorPlugin::QLedIndicatorPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void QLedIndicatorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool QLedIndicatorPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *QLedIndicatorPlugin::createWidget(QWidget *parent)
{
    return new QLedIndicator(parent);
}

QString QLedIndicatorPlugin::name() const
{
    return QLatin1String("QLedIndicator");
}

QString QLedIndicatorPlugin::group() const
{
    return QLatin1String("");
}

QIcon QLedIndicatorPlugin::icon() const
{
    return QIcon();
}

QString QLedIndicatorPlugin::toolTip() const
{
    return QLatin1String("");
}

QString QLedIndicatorPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool QLedIndicatorPlugin::isContainer() const
{
    return false;
}

QString QLedIndicatorPlugin::domXml() const
{
    QFile file(":/QLedIndicator.xml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return QString("");

    QString content = file.readAll();
    return content;
}

QString QLedIndicatorPlugin::includeFile() const
{
    return QLatin1String("QLedIndicator.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(QLedIndicator, QLedIndicatorPlugin)
#endif // QT_VERSION < 0x050000
