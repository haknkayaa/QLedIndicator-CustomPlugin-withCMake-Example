#ifndef QLEDINDICATOR_H
#define QLEDINDICATOR_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>

namespace Ui {
class QLedIndicator;
}

class QDESIGNER_WIDGET_EXPORT QLedIndicator : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(bool state READ state WRITE setState NOTIFY stateChanged)

public:
    explicit QLedIndicator(QWidget *parent = nullptr);
    ~QLedIndicator();

    const QString &label() const;
    const QString &icon() const;

    bool state() const;


public slots:
    void setLabel(const QString &newLabel);
    void setIcon(const QString &newIcon);
    void setState(bool newState);

signals:
    void labelChanged();
    void iconChanged();
    void stateChanged();

private:
    Ui::QLedIndicator *ui;
    QString m_label;
    QString m_icon;
    bool m_state;
};

#endif // QLEDINDICATOR_H
