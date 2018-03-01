#include "GraphicsScene.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QKeyEvent>
#include "GraphicsCoordinateAxisItem.h"

using namespace std;

GraphicsScene::GraphicsScene(QObject *parent) : QGraphicsScene(parent)
{
    addItem(new GraphicsCoordinateAxisItem);

    m_pArrowItem = new GraphicsArrowItem;
    addItem(m_pArrowItem);
    connect(m_pArrowItem, SIGNAL(infoChanged()), this, SIGNAL(poseInfoChanged()));
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
//    qDebug() << mouseEvent->pos()<<mouseEvent->scenePos() << mouseEvent->screenPos();
    emit cursorChanged(mouseEvent->pos(), mouseEvent->scenePos(), mouseEvent->screenPos());

    QGraphicsScene::mouseMoveEvent(mouseEvent);
}
