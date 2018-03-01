#include "GraphicsArrowItem.h"
#include <QBrush>
#include <QPen>
#include <QKeyEvent>

GraphicsArrowItem::GraphicsArrowItem(QGraphicsItem *parent)
    : QGraphicsPolygonItem(parent)
{
    const qreal Width = 100;

    QPolygonF arrowPolygon;
// NOTE:lmk零度朝向为左边，但slam零度朝向为右边，算法说下面零度朝向是一样的。
#if 0   // 左边朝向为0度
    arrowPolygon << QPointF(-Width / 2, 0) << QPointF(0, Width / 2) // 中心点为0度，从箭头定点顺时针开始画的
                 << QPointF(0, Width / 5) << QPointF(Width / 2, Width / 5)
                 << QPointF(Width / 2, -Width / 5) << QPointF(0, -Width / 5)
                 << QPointF(0, -Width / 2);
#else   // 右边朝向为0度
    arrowPolygon << QPointF(Width / 2, 0) << QPointF(0, -Width / 2)  // 中心点为0度，从箭头定点顺时针开始画的
                 << QPointF(0, -Width / 5) << QPointF(-Width / 2, -Width / 5)
                 << QPointF(-Width / 2, Width / 5) << QPointF(0, Width / 5)
                 << QPointF(0, Width / 2);
#endif

    setPenColor(QColor(Qt::red));
    setPolygon(arrowPolygon);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
        setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
}

void GraphicsArrowItem::setPenColor(const QColor &color)
{
    QPen pen(color);
    pen.setWidth(3);
    setPen(pen);

    QColor brushColor = color;
    brushColor.setAlpha(100);
    setBrush(brushColor);
}

QVariant GraphicsArrowItem::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
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

void GraphicsArrowItem::keyPressEvent(QKeyEvent *event)
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

