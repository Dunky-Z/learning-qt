#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCommandLineParser parser;                        // 定义解析实例
    parser.setApplicationDescription("TestCommandLine");  // 描述可执行程序的属性
    parser.addHelpOption();                           // 添加帮助命令
    parser.addVersionOption();                        // 添加版本选择命令
    parser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
    QCommandLineOption  CommandExe("d", QGuiApplication::translate("main","Take  the  first  argument  as a command to execute."));
    CommandExe.setValueName("value");
    parser.addOption(CommandExe);

    parser.process(a);                                // 把用户的命令行的放入解析实例
    int ce = (parser.value(CommandExe)).toInt();

    if (ce < 0)
    {
        fprintf(stderr, "%s\n", qPrintable(QGuiApplication::translate("main", "Error: Invalid format argument.")));
        parser.showHelp();
    }
    MainWindow w;
    w.show();
    return a.exec();
}
