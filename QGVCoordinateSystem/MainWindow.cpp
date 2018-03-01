#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pGraphicsScene = new GraphicsScene(this);
    ui->graphicsView->setScene(m_pGraphicsScene);
    connect(m_pGraphicsScene, SIGNAL(cursorChanged(QPointF, QPointF, QPointF)), this, SLOT(onCursorChanged(QPointF, QPointF, QPointF)));
    m_pItemPropertyController = new ItemPropertyController(m_pGraphicsScene, ui->tableWidget, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCursorChanged(const QPointF &pos, const QPointF &scenePos, const QPointF &screenPos)
{
    ui->statusBar->showMessage("pos : (" + QString::number(pos.x()) + ", " + QString::number(pos.y()) + "); " +
                               "scenePos : (" + QString::number(scenePos.x()) + ", " + QString::number(scenePos.y()) + "); " +
                               "screenPos : (" + QString::number(screenPos.x()) + ", " + QString::number(screenPos.y()) + ")" );
}
