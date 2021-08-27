#include "paintwidget.h"

PaintedWidget::PaintedWidget(QWidget *parent) : QWidget(parent)
{
    resize(800, 600);
    setWindowTitle(tr("Paint Demo"));
}

void PaintedWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawLine(20, 20, 700, 20);
    painter.setPen(Qt::red);
    painter.drawRect(10, 10, 100, 400);
    painter.setPen(QPen(Qt::green, 5));
    painter.setBrush(Qt::blue);
    painter.drawEllipse(0, 0, 300, 40);
    painter.drawRect(120, 50, 50, 400);
    ///////////////////画笔与笔刷
    QLinearGradient gradient(QPointF(180, 50), QPointF(230, 400));
    gradient.setColorAt(0, Qt::black);
    gradient.setColorAt(1, Qt::red);
    gradient.setSpread(QGradient::PadSpread);

    QBrush brush(gradient);

    QPen pen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(180, 50, 50, 400);
    ///////////////////设置画笔样式
    QVector<qreal> dashes;
    qreal space = 4;

    dashes << 1 << space << 3 << space << 9 << space
           << 27 << space << 9 << space;
    pen.setColor(Qt::black);
    pen.setDashPattern(dashes);
    painter.setPen(pen);
    painter.drawLine(30, 300, 600, 30);
    ///////////////////设置画笔样式
}