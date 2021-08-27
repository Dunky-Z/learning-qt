#include <QPainter>
#include <QWidget>
#include <QPaintEvent>
#include <QApplication>
#include <QMainWindow>

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    PaintedWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
};