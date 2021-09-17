#include <QWidget>
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file0("test.txt");
    if (!file0.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Open file failed.";
        return -1;
    }
    else
    {
        while (!file0.atEnd())
        {
            qDebug() << file0.readLine();
        }
    }

    QFileInfo info(file0);
    qDebug() << info.isDir();            //false
    qDebug() << info.isExecutable();     //false
    qDebug() << info.baseName();         //test
    qDebug() << info.completeBaseName(); //test.txt
    qDebug() << info.suffix();           //txt
    qDebug() << info.completeSuffix();   //txt

    QFileInfo fi("/tmp/archive.tar.gz");
    qDebug() << fi.baseName();         // base = "archive"
    qDebug() << fi.completeBaseName(); // base = "archive.tar"
    qDebug() << fi.suffix();           // ext = "gz"
    qDebug() << fi.completeSuffix();   // ext = "tar.gz"

    ///////////////////////////二进制文件读写
    QFile file1("file.dat");
    file1.open(QIODevice::WriteOnly);
    QDataStream out(&file1);
    out << QString("the answer is");
    out << (qint32)42;

    QFile file2("file.dat");
    file2.open(QIODevice::ReadOnly);
    QDataStream in(&file2);
    QString str;
    qint32 a;
    in >> str >> a;
    return app.exec();
}