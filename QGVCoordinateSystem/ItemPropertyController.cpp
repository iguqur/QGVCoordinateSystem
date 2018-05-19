#include "ItemPropertyController.h"
#include "GraphicsScene.h"
#include <QTime>

ItemPropertyController::ItemPropertyController(GraphicsScene *pGraphicsScene, QTableWidget *tableWidget, QObject *parent)
    : QObject(parent)
    , m_pGraphicsScene(pGraphicsScene)
    , m_tableWidget(tableWidget)
{
    connect(m_pGraphicsScene, SIGNAL(selectionChanged()), this, SLOT(onItemPropertyChanged()));
    connect(m_pGraphicsScene, SIGNAL(poseInfoChanged()), this, SLOT(onItemPropertyChanged()));

    m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void ItemPropertyController::onItemPropertyChanged()
{
    if (m_pGraphicsScene->selectedItems().isEmpty())
    {
        m_tableWidget->clearContents();
        return;
    }

    // 我们只处理最后一个被选中的
    QGraphicsItem *selectedItem = m_pGraphicsScene->selectedItems().last();

    m_tableWidget->setRowCount(20);
    m_tableWidget->setColumnCount(2);
    m_tableWidget->setHorizontalHeaderLabels(QStringList{tr("属性"), tr("值")});
    m_tableWidget->setColumnWidth(0, m_tableWidget->width() * 0.45);
    m_tableWidget->setColumnWidth(1, m_tableWidget->width() * 0.51);


    QTableWidgetItem *newItem = new QTableWidgetItem(tr("更新时间"));
    m_tableWidget->setItem(0, 0, newItem);
    newItem = new QTableWidgetItem(QTime::currentTime().toString("mm:ss:zzz"));
    m_tableWidget->setItem(0, 1, newItem);

    auto pointFToString = [](const QPointF &pointF){
        QString str = "(" + QString::number(pointF.x()) + ", " + QString::number(pointF.y()) + ")";
        return str;

    };

    int row = 1;

    newItem = new QTableWidgetItem("scenePos");
    m_tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem(pointFToString(selectedItem->scenePos()));
    m_tableWidget->setItem(row++, 1, newItem);

    auto rectFToString = [](const QRectF &rectF){
        QString str = "(" + QString::number(rectF.x()) + ", " + QString::number(rectF.y()) + ", " + QString::number(rectF.width()) + ", " + QString::number(rectF.height()) + ")";
        return str;
    };

    newItem = new QTableWidgetItem("boundingRect");
    m_tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem(rectFToString(selectedItem->boundingRect()));
    m_tableWidget->setItem(row++, 1, newItem);

    newItem = new QTableWidgetItem("boundingMapToScene");
    m_tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem(rectFToString(selectedItem->mapRectToScene(selectedItem->boundingRect())));
    m_tableWidget->setItem(row++, 1, newItem);


    newItem = new QTableWidgetItem("rotation");
    m_tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem(QString::number(selectedItem->rotation()));
    m_tableWidget->setItem(row++, 1, newItem);

    newItem = new QTableWidgetItem("(0, 0)OnScene");
    m_tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem(pointFToString(selectedItem->mapToScene(0, 0)));
    m_tableWidget->setItem(row++, 1, newItem);

    newItem = new QTableWidgetItem("center");
    m_tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem(pointFToString(selectedItem->boundingRect().center()));
    m_tableWidget->setItem(row++, 1, newItem);

    newItem = new QTableWidgetItem("centerOnScene");
    m_tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem(pointFToString(selectedItem->mapToScene(selectedItem->boundingRect().center())));
    m_tableWidget->setItem(row++, 1, newItem);


    newItem = new QTableWidgetItem("");
    m_tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem("");
    m_tableWidget->setItem(row++, 1, newItem);

    newItem = new QTableWidgetItem(tr("parent相关坐标"));
    m_tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem(tr("parent相关坐标"));
    m_tableWidget->setItem(row++, 1, newItem);

    newItem = new QTableWidgetItem("pos");
    m_tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem(pointFToString(selectedItem->pos()));
    m_tableWidget->setItem(row++, 1, newItem);

    newItem = new QTableWidgetItem("centerOnParent");
    m_tableWidget->setItem(row, 0, newItem);
    newItem = new QTableWidgetItem(pointFToString(selectedItem->mapToParent(selectedItem->boundingRect().center())));
    m_tableWidget->setItem(row++, 1, newItem);

}
