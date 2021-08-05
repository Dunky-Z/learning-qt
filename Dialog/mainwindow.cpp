

#include "mainwindow.h"

// MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
// {
//     setWindowTitle(tr("Main Window"));

//     openAction = new QAction(QIcon(":/open.png"), tr("&Open..."), this);
//     openAction->setShortcuts(QKeySequence::Open);
//     openAction->setStatusTip(tr("Open an existing file"));
//     connect(openAction, &QAction::triggered, this, &MainWindow::open);

//     QMenu *file = menuBar()->addMenu(tr("&File"));
//     file->addAction(openAction);

//     QToolBar *toolBar = addToolBar(tr("&File"));
//     toolBar->addAction(openAction);

//     statusBar();
// }

// MainWindow::~MainWindow()
// {
// }

// /* void MainWindow::open()
// {
//     //如果 parent 为 NULL，则该对话框会作为一个顶层窗口，
//     //顶层窗口在任务栏会有自己的位置
//     QDialog dialog;
//     dialog.setWindowTitle(tr("Hello, dialog!"));
//     dialog.exec();
// } */

// /* void MainWindow::open()
// {
//     //非顶层窗口则会共享其父组件的位置
//     QDialog dialog(this);
//     dialog.setWindowTitle(tr("Hello, dialog!"));
//     dialog.show();  //一闪而过
// } */

// /* void MainWindow::open()
// {
//     //不设置parent属性，存在内存泄漏
//     //new出来的对象没有及时释放
//     //表现为关闭父窗口，子窗口仍然存在
//     QDialog *dialog = new QDialog();
//     dialog->setWindowTitle(tr("Hello, dialog!"));
//     dialog->show();
// } */

// void MainWindow::open()
// {
//     //设置parent属性，将dialog作为mainwindow的子类，mainwindow析构时，dialog也析构
//     QDialog *dialog = new QDialog(this);
//     dialog->setWindowTitle(tr("Hello, dialog!"));
//     dialog->show();
// }

// /* void MainWindow::open()
// {
//     if (QMessageBox::Yes == QMessageBox::question(this,
//                                                   tr("Question"),
//                                                   tr("Are you OK?"),
//                                                   QMessageBox::Yes | QMessageBox::No,
//                                                   QMessageBox::Yes))
//     {
//         QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
//     }
//     else
//     {
//         QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
//     }
// }
//  */

// void MainWindow::closeEvent(QCloseEvent *event)
// {
//     QMessageBox msgBox;
//     msgBox.setText(tr("The document has been modified."));
//     msgBox.setInformativeText(tr("Do you want to save your changes?"));
//     msgBox.setDetailedText(tr("Differences here..."));
//     msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
//     msgBox.setDefaultButton(QMessageBox::Save);
//     int ret = msgBox.exec();
//     switch (ret)
//     {
//     case QMessageBox::Save:
//         qDebug() << "Save document!";
//         event->accept();
//         break;
//     case QMessageBox::Discard:
//         qDebug() << "Discard changes!";
//         event->accept();
//         break;
//     case QMessageBox::Cancel:
//         qDebug() << "Close document!";
//         event->ignore();
//         break;
//     }
// }

/////////////文件对话框
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/open.png"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));

    saveAction = new QAction(QIcon(":/save.png"), tr("&Save..."), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save anew file"));

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    connect(openAction, &QAction::triggered, this, &MainWindow::openFile);
    connect(saveAction, &QAction::triggered, this, &MainWindow::saveFile);
    statusBar();
}

MainWindow::~MainWindow()
{
}

/* void MainWindow::open()
{
    //如果 parent 为 NULL，则该对话框会作为一个顶层窗口，
    //顶层窗口在任务栏会有自己的位置
    QDialog dialog;
    dialog.setWindowTitle(tr("Hello, dialog!"));
    dialog.exec();
} */

/* void MainWindow::open()
{
    //非顶层窗口则会共享其父组件的位置
    QDialog dialog(this);
    dialog.setWindowTitle(tr("Hello, dialog!"));
    dialog.show();  //一闪而过
} */

/* void MainWindow::open()
{
    //不设置parent属性，存在内存泄漏
    //new出来的对象没有及时释放
    //表现为关闭父窗口，子窗口仍然存在
    QDialog *dialog = new QDialog();
    dialog->setWindowTitle(tr("Hello, dialog!"));
    dialog->show();
} */

/* void MainWindow::open()
{
    //设置parent属性，将dialog作为mainwindow的子类，mainwindow析构时，dialog也析构
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(tr("Hello, dialog!"));
    dialog->show();
} */

/* void MainWindow::open()
{
    if (QMessageBox::Yes == QMessageBox::question(this,
                                                  tr("Question"),
                                                  tr("Are you OK?"),
                                                  QMessageBox::Yes | QMessageBox::No,
                                                  QMessageBox::Yes))
    {
        QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
    }
    else
    {
        QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
    }
}
 */

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    if (!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,
                                                tr("Open File"),
                                                ".",
                                                tr("Text Files(*.txt)"));
    if (!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Write File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Path"),
                             tr("You did not select any file."));
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox;
    msgBox.setText(tr("The document has been modified."));
    msgBox.setInformativeText(tr("Do you want to save your changes?"));
    msgBox.setDetailedText(tr("Differences here..."));
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret)
    {
    case QMessageBox::Save:
        qDebug() << "Save document!";
        event->accept();
        break;
    case QMessageBox::Discard:
        qDebug() << "Discard changes!";
        event->accept();
        break;
    case QMessageBox::Cancel:
        qDebug() << "Close document!";
        event->ignore();
        break;
    }
}
