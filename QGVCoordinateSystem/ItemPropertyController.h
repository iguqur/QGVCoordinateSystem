#ifndef ITEMPROPERTYCONTROLLER_H
#define ITEMPROPERTYCONTROLLER_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QObject>
#include <QTableWidget>

class GraphicsScene;

class ItemPropertyController : public QObject
{
    Q_OBJECT
public:
    explicit ItemPropertyController(GraphicsScene *pGraphicsScene, QTableWidget *tableWidget, QObject *parent = nullptr);


signals:

public slots:

private slots:
    void onItemPropertyChanged();  // 处理graphicsScene选中的Item被改变的槽

private:
    GraphicsScene *m_pGraphicsScene = nullptr;
    QTableWidget *m_tableWidget = nullptr;
};

#endif // ITEMPROPERTYCONTROLLER_H
