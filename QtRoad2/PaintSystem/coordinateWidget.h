#include <QPainter>
#include <QWidget>
#include <QPaintEvent>
#include <QApplication>
#include <QMainWindow>
#include <QLinearGradient>

class CoordinateWidget : public QWidget
{
    Q_OBJECT
public:
    CoordinateWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void paintGrid();
};