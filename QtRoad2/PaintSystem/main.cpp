#include "paintwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    PaintedWidget paintMap;
    paintMap.show();
    return app.exec();
}
