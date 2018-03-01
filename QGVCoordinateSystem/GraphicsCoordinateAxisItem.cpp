#include "GraphicsCoordinateAxisItem.h"
#include <QPainter>

GraphicsCoordinateAxisItem::GraphicsCoordinateAxisItem()
{
    m_boundingRect.setRect(-500, -500, 1000, 1000);
}

QRectF GraphicsCoordinateAxisItem::boundingRect() const
{
    return m_boundingRect;
}

void GraphicsCoordinateAxisItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPen pen(Qt::green);
    painter->setPen(pen);
    painter->drawLine(m_boundingRect.x(), m_boundingRect.center().y(), m_boundingRect.right(), m_boundingRect.center().y());
    painter->drawLine(m_boundingRect.center().x(), m_boundingRect.top(), m_boundingRect.center().x(), m_boundingRect.bottom());
}
