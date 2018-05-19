#include "GraphicsScene.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QKeyEvent>
#include "GraphicsRectItem.h"
#include "GraphicsCoordinateAxisItem.h"

using namespace std;

GraphicsScene::GraphicsScene(QObject *parent) : QGraphicsScene(parent)
{
    addItem(new GraphicsCoordinateAxisItem);

    m_pArrowItem = new GraphicsArrowItem;
    addItem(m_pArrowItem);
    connect(m_pArrowItem, SIGNAL(infoChanged()), this, SIGNAL(poseInfoChanged()));

   GraphicsRectItem *pRectItem = new GraphicsRectItem;
    pRectItem->setRect(0, 0, 100, 100);
    pRectItem->setPenColor(QColor(Qt::blue));
    addItem(pRectItem);
    connect(pRectItem, SIGNAL(infoChanged()), this, SIGNAL(poseInfoChanged()));

    pRectItem = new GraphicsRectItem;
    pRectItem->setRect(100, 100, 100, 100);
    pRectItem->setPenColor(QColor(Qt::black));
    addItem(pRectItem);
    connect(pRectItem, SIGNAL(infoChanged()), this, SIGNAL(poseInfoChanged()));

    pRectItem = new GraphicsRectItem;
    pRectItem->setRect(-400, -400, 400, 400);
    pRectItem->setPenColor(QColor(Qt::yellow));
    addItem(pRectItem);
    connect(pRectItem, SIGNAL(infoChanged()), this, SIGNAL(poseInfoChanged()));

    GraphicsRectItem *pChild = new GraphicsRectItem(pRectItem);
    pChild->setRect(-200, -200, 100, 100);
    pChild->setPenColor(QColor(Qt::darkGray));
    pChild->setToolTip(tr("parent为黄色框"));
    connect(pChild, SIGNAL(infoChanged()), this, SIGNAL(poseInfoChanged()));

    pRectItem = new GraphicsRectItem;
    pRectItem->setRect(0, 0, 100, 100);
    pRectItem->setPenColor(QColor(Qt::magenta));
    pRectItem->setPos(-200, 200);
    pRectItem->setToolTip(tr("（0, 0)位置在原点，然后setPos(-200, 200)"));
    addItem(pRectItem);
    connect(pRectItem, SIGNAL(infoChanged()), this, SIGNAL(poseInfoChanged()));

}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
//    qDebug() << mouseEvent->pos()<<mouseEvent->scenePos() << mouseEvent->screenPos();
    emit cursorChanged(mouseEvent->pos(), mouseEvent->scenePos(), mouseEvent->screenPos());

    QGraphicsScene::mouseMoveEvent(mouseEvent);
}
