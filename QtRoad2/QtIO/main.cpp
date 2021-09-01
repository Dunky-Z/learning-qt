#include <QWidget>
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file("test.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Open file failed.";
        return -1;
    }
    else
    {
        while (!file.atEnd())
        {
            qDebug() << file.readLine();
        }
    }

    QFileInfo info(file);
    qDebug() << info.isDir();            //false
    qDebug() << info.isExecutable();     //false
    qDebug() << info.baseName();         //test
    qDebug() << info.completeBaseName(); //test.txt
    qDebug() << info.suffix();           //txt
    qDebug() << info.completeSuffix();   //txt

    QFileInfo fi("/tmp/archive.tar.gz");
    QString base = fi.baseName();          // base = "archive"
    QString cbase = fi.completeBaseName(); // base = "archive.tar"
    QString ext = fi.suffix();             // ext = "gz"
    QString ext = fi.completeSuffix();     // ext = "tar.gz"
    return app.exec();
}