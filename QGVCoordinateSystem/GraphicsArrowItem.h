#ifndef GRAPHICSARROWITEM_H
#define GRAPHICSARROWITEM_H

#include <QGraphicsItem>

class GraphicsArrowItem :  public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT

public:
    GraphicsArrowItem(QGraphicsItem *parent = Q_NULLPTR);

signals:
    void infoChanged();

protected:
    void setPenColor(const QColor &color);
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value);

     virtual void keyPressEvent(QKeyEvent *event) override;

};

#endif // GRAPHICSARROWITEM_H
