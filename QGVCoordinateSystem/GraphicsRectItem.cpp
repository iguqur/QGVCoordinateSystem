#include "GraphicsRectItem.h"
#include <QPen>
#include <QKeyEvent>
#include <QPainter>

GraphicsRectItem::GraphicsRectItem(QGraphicsItem *parent)
    : QGraphicsRectItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);

}

void GraphicsRectItem::setPenColor(const QColor &color)
{
    QPen pen(color);
    pen.setWidth(3);
    setPen(pen);

    QColor brushColor = color;
    brushColor.setAlpha(100);
    setBrush(brushColor);
}

QVariant GraphicsRectItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (scene())
    {
        if (change == ItemPositionHasChanged)
        {
            emit infoChanged();
        }
    }
    return QGraphicsItem::itemChange(change, value);
}

void GraphicsRectItem::keyPressEvent(QKeyEvent *event)
{
    //    qDebug()<<event;
    // 旋转控制
    if (event->key() == Qt::Key_Plus)
    {
        setRotation(rotation() + 1);
    }
    else if (event->key() == Qt::Key_Minus)
    {
        setRotation(rotation() - 1);
    }
    //移动控制
    else if (event->key() == Qt::Key_Up)
    {
    }
    else if (event->key() == Qt::Key_Down)
    {
    }
    else if (event->key() == Qt::Key_Left)
    {
    }
    else if (event->key() == Qt::Key_Right)
    {
    }
    else
    {
        return QGraphicsItem::keyPressEvent(event);
    }

    emit infoChanged();
}

void GraphicsRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsRectItem::paint(painter, option, widget);

    // 将文本翻转
    QTransform transform;
    transform.setMatrix(1, 0, 0,
                        0, -1, 0,
                        0, rect().center().y() * 2, 1);
    painter->setTransform(transform, true);
    painter->drawText(rect(), Qt::AlignCenter,  QObject::tr("静态区域"));

}
