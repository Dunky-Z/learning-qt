#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QAction>
#include <QToolBar>
#include <QMenuBar>
#include <QtWidgets>
#include <QTextEdit>
#include <QStatusBar>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFileDialog>
#include <QMainWindow>
#include <QKeySequence>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void closeEvent(QCloseEvent *event);

    // void open();
    void openFile();
    void saveFile();

    QAction *openAction;
    QAction *saveAction;

    QTextEdit *textEdit;
};

#endif // MAINWINDOW_H