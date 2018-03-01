#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "GraphicsArrowItem.h"

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
     explicit GraphicsScene(QObject *parent = nullptr);


signals:
    void poseInfoChanged();
    void cursorChanged(const QPointF &pos, const QPointF &scenePos, const QPointF &screenPos);

public slots:

protected:

    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private slots:

private:

    GraphicsArrowItem *m_pArrowItem = nullptr;
};



#endif // GRAPHICSSCENE_H
