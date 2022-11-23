#include "QLedIndicator.h"
#include "ui_QLedIndicator.h"

QLedIndicator::QLedIndicator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QLedIndicator),
    m_state(false)
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
