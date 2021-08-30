#include "paintwidget.h"
#include "coordinateWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PaintedWidget paintMap;
    CoordinateWidget coordWin;
    //可以注释掉其余窗口只保留一个正在学习，调试的
    //绘制系统（24，25，26章）
    //paintMap.show();
    //坐标系统（28章）
    coordWin.show();
    return app.exec();
}
