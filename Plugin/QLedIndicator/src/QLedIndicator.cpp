#include "QLedIndicator.h"
#include "ui_QLedIndicator.h"

QLedIndicator::QLedIndicator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLedIndicator),
    m_label("LedIndicator"),
    m_state(false),
    m_icon(":/red_light.png"),
    m_indicatorStyle(IndicatorStyle::TextBesideIcon),
    m_iconSize(20, 20)
{
    ui->setupUi(this);
}

QLedIndicator::~QLedIndicator()
{
    delete ui;
}

const QString &QLedIndicator::label() const
{
    return m_label;
}

void QLedIndicator::setLabel(const QString &newLabel)
{
    if (m_label == newLabel)
        return;
    m_label = newLabel;
    ui->label->setText(m_label);
    emit labelChanged();
}

const QString &QLedIndicator::icon() const
{
    return m_icon;
}

void QLedIndicator::setIcon(const QString &newIcon)
{
    if (m_icon == newIcon)
        return;
    m_icon = newIcon;
    ui->icon->setPixmap(QPixmap(newIcon));
    emit iconChanged();
}

bool QLedIndicator::state() const
{
    return m_state;
}

void QLedIndicator::setState(bool newState)
{
    if (m_state == newState)
        return;
    m_state = newState;
    if(m_state == false){
        this->setIcon(":/red_light.png");
    }else{
        this->setIcon(":/green_light.png");
    }
    emit stateChanged();
}

QLedIndicator::IndicatorStyle QLedIndicator::indicatorStyle() const {
    return m_indicatorStyle;
}

void QLedIndicator::setIndicatorStyle(QLedIndicator::IndicatorStyle newIndicatorStyle) {
    if (m_indicatorStyle == newIndicatorStyle)
        return;
    m_indicatorStyle = newIndicatorStyle;

    if(m_indicatorStyle == IndicatorStyle::TextOnly){
        ui->icon->setVisible(false);
        ui->label->setVisible(true);
    }else if(m_indicatorStyle == IndicatorStyle::IconOnly){
        ui->icon->setVisible(true);
        ui->label->setVisible(false);
    }else if(m_indicatorStyle == IndicatorStyle::TextUnderIcon){
        ui->icon->setVisible(true);
        ui->label->setVisible(true);
        ui->label->setAlignment(Qt::AlignCenter);
    }else if(m_indicatorStyle == IndicatorStyle::TextBesideIcon){
        ui->icon->setVisible(true);
        ui->label->setVisible(true);
        ui->label->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    }

    emit indicatorStyleChanged();
}

QSize QLedIndicator::iconSize() const {
    return m_iconSize;
}

void QLedIndicator::setIconSize(QSize newIconSize) {
    if (m_iconSize == newIconSize)
        return;
    m_iconSize = newIconSize;
    ui->icon->setFixedSize(m_iconSize);
    emit iconSizeChanged();
}




