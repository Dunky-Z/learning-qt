#include "coordinateWidget.h"

CoordinateWidget::CoordinateWidget(QWidget *parent) : QWidget(parent)
{
    resize(800, 400);
    setWindowTitle(tr("Coordinate Demo"));
}

//绘制一个网格背景
void CoordinateWidget::paintGrid()
{
    size_t win_width = this->geometry().width();
    size_t win_height = this->geometry().height();
    QPainter painter(this);
    for (size_t x = 0; x < win_width; x += 25)
    {
        painter.drawLine(QPoint(x, 1), QPoint(x, win_height));
    }
    for (size_t y = 0; y < win_height; y += 25)
    {
        painter.drawLine(QPoint(1, y), QPoint(win_width, y));
    }
}

void CoordinateWidget::paintEvent(QPaintEvent *)
{
    paintGrid();
    QPainter painter(this);
    painter.fillRect(10, 10, 50, 100, Qt::red);
    painter.save();
    painter.translate(100, 0); // 向右平移 100px
    painter.fillRect(10, 10, 50, 100, Qt::yellow);
    painter.restore();
    painter.save();
    painter.translate(300, 0); // 向右平移 300px
    painter.rotate(30);        // 顺时针旋转 30 度
    painter.fillRect(10, 10, 50, 100, Qt::green);
    painter.restore();
    painter.save();
    painter.translate(400, 0); // 向右平移 400px
    painter.scale(2, 3);       // 横坐标单位放大 2 倍，纵坐标放大 3 倍
    painter.fillRect(10, 10, 50, 100, Qt::blue);
    painter.restore();
    painter.save();
    painter.translate(600, 0); // 向右平移 600px
    painter.shear(0, 1);       // 横向不变，纵向扭曲 1 倍
    painter.fillRect(10, 10, 50, 100, Qt::cyan);
    painter.restore();
}
