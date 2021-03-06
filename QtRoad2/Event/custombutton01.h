#include <QDebug>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>
#include <QApplication>

class CustomButton : public QPushButton
{
    Q_OBJECT

public:
    CustomButton(QWidget *parent) : QPushButton(parent)
    {
    }

protected:
    void mousePressEvent(QMouseEvent *event)
    {
        qDebug() << "CustomButton";
    }
};

class CustomButtonEx : public CustomButton
{
    Q_OBJECT
public:
    CustomButtonEx(QWidget *parent) : CustomButton(parent)
    {
    }

protected:
    void mousePressEvent(QMouseEvent *event)
    {
        qDebug() << "CustomButtonEx ";
    }
};

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    CustomWidget(QWidget *parent) : QWidget(parent)
    {
    }

protected:
    void mousePressEvent(QMouseEvent *event)
    {
        qDebug() << "CustomWidget";
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0) : QMainWindow(parent)
    {
        CustomWidget *widget = new CustomWidget(this);
        CustomButton *cbex = new CustomButton(widget);
        cbex->setText(tr("CustomButton"));
        CustomButtonEx *cb = new CustomButtonEx(widget);
        cb->setText(tr("CustomButtonEx"));
        QVBoxLayout *widgetLayout = new QVBoxLayout(widget);
        widgetLayout->addWidget(cbex);
        widgetLayout->addWidget(cb);
        this->setCentralWidget(widget);
    }

protected:
    void mousePressEvent(QMouseEvent *event)
    {
        qDebug() << "MainWindow";
    }
};