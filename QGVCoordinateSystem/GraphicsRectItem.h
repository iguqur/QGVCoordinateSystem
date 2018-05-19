#ifndef GRAPHICSRECTITEM_H
#define GRAPHICSRECTITEM_H

#include <QGraphicsItem>


class GraphicsRectItem :   public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    GraphicsRectItem(QGraphicsItem *parent = nullptr);

    void setPenColor(const QColor &color);
signals:
    void infoChanged();

protected:
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);

     virtual void keyPressEvent(QKeyEvent *event) override;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
};

#endif // GRAPHICSRECTITEM_H
