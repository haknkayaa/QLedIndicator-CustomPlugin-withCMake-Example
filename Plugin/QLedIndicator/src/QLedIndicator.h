#ifndef QLEDINDICATOR_H
#define QLEDINDICATOR_H

#include <QWidget>
#include <QtUiPlugin/QDesignerExportWidget>
#include <QMap>

namespace Ui {
    class QLedIndicator;
}

class QDESIGNER_WIDGET_EXPORT QLedIndicator : public QWidget {
Q_OBJECT
    Q_PROPERTY(QString label READ label WRITE setLabel NOTIFY labelChanged)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(bool state READ state WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(IndicatorStyle indicatorStyle READ indicatorStyle WRITE setIndicatorStyle NOTIFY indicatorStyleChanged)
    Q_PROPERTY(QSize iconSize READ iconSize WRITE setIconSize NOTIFY iconSizeChanged)

public:
    enum IndicatorStyle {
        TextOnly,
        IconOnly,
        TextUnderIcon,
        TextBesideIcon,
    };

    Q_ENUM(IndicatorStyle)

    explicit QLedIndicator(QWidget *parent = nullptr);

    ~QLedIndicator();

    const QString &label() const;

    const QString &icon() const;

    bool state() const;

    IndicatorStyle indicatorStyle() const;

    QSize iconSize() const;


public slots:

    void setLabel(const QString &newLabel);

    void setIcon(const QString &newIcon);

    void setState(bool newState);

    void setIndicatorStyle(IndicatorStyle newIndicatorStyle);

    void setIconSize(QSize);

signals:

    void labelChanged();

    void iconChanged();

    void stateChanged();

    void indicatorStyleChanged();

    void iconSizeChanged();

private:
    Ui::QLedIndicator *ui;

    QString m_label;
    QString m_icon;
    bool m_state;
    IndicatorStyle m_indicatorStyle;
    QSize m_iconSize;
};

#endif // QLEDINDICATOR_H
