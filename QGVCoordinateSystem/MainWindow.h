#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "GraphicsScene.h"
#include <QGraphicsView>
#include "ItemPropertyController.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onCursorChanged(const QPointF &pos, const QPointF &scenePos, const QPointF &screenPos);

private:
    Ui::MainWindow *ui;

    GraphicsScene *m_pGraphicsScene = nullptr;
    ItemPropertyController *m_pItemPropertyController = nullptr;
};

#endif // MAINWINDOW_H
