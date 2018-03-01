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

    m_tableWidget->setRowCount(5);
    m_tableWidget->setColumnCount(2);
    m_tableWidget->setHorizontalHeaderLabels(QStringList{tr("属性"), tr("值")});
    m_tableWidget->setColumnWidth(0, m_tableWidget->width() * 0.45);
    m_tableWidget->setColumnWidth(1, m_tableWidget->width() * 1);

    QTableWidgetItem *newItem = new QTableWidgetItem(tr("更新时间"));
    m_tableWidget->setItem(0, 0, newItem);
    newItem = new QTableWidgetItem(QTime::currentTime().toString("mm:ss:zzz"));
    m_tableWidget->setItem(0, 1, newItem);

    newItem = new QTableWidgetItem("pos");
    m_tableWidget->setItem(1, 0, newItem);
    newItem = new QTableWidgetItem("(" + QString::number(selectedItem->pos().x()) + ", " + QString::number(selectedItem->pos().y()) + ")");
    m_tableWidget->setItem(1, 1, newItem);

    newItem = new QTableWidgetItem("scenePos");
    m_tableWidget->setItem(2, 0, newItem);
    newItem = new QTableWidgetItem("(" +  QString::number(selectedItem->scenePos().x()) + ", " + QString::number(selectedItem->scenePos().y()) + ")");
    m_tableWidget->setItem(2, 1, newItem);

    auto rectFToString = [](const QRectF &rectF){
        QString str = "(" + QString::number(rectF.x()) + ", " + QString::number(rectF.y()) + ", " + QString::number(rectF.width()) + ", " + QString::number(rectF.height());
        return str;
    };

    newItem = new QTableWidgetItem("boundingRect");
    m_tableWidget->setItem(3, 0, newItem);
    newItem = new QTableWidgetItem(rectFToString(selectedItem->boundingRect()));
    m_tableWidget->setItem(3, 1, newItem);

    newItem = new QTableWidgetItem("rotation");
    m_tableWidget->setItem(4, 0, newItem);
    newItem = new QTableWidgetItem(QString::number(selectedItem->rotation()));
    m_tableWidget->setItem(4, 1, newItem);

}
