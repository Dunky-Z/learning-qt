#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QPainter>
#include <QMovie>
#include <QHBoxLayout>
#include <QCursor>
#include <QMenu>
#include <QDebug>
#include <QTime>
//#include "accountitem.h"
#include <QPropertyAnimation>

LoginWindow::LoginWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    initWindow();
    initMyTitle();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
// 初始化窗口;
void LoginWindow::initWindow()
{
    //背景GIG图;
    QLabel* pBack = new QLabel(this);
    QMovie *movie = new QMovie();
    movie->setFileName(":/Resources/LoginWindow/back.gif");
    pBack->setMovie(movie);
    movie->start();
    pBack->move(0, 0);

    //文本框内提示
    ui->accountComboBox->setEditable(true);
    QLineEdit* lineEdit = ui->accountComboBox->lineEdit();
    lineEdit->setPlaceholderText(QStringLiteral("QQ号码/手机/邮箱"));
    ui->passwordEdit->setPlaceholderText(QStringLiteral("密码"));

}

// 初始化标题栏;
void LoginWindow::initMyTitle()
{
    // 因为这里有控件层叠了，所以要注意控件raise()方法的调用顺序;
    m_titleBar->move(0, 0);
    m_titleBar->raise();
    m_titleBar->setBackgroundColor(100, 0, 0, true);
    //m_titleBar->setButtonType(MIN_BUTTON);
    m_titleBar->setTitleWidth(this->width());
    // 这里需要设置成false，不允许通过标题栏拖动来移动窗口位置,否则会造成窗口位置错误;
    //m_titleBar->setMoveParentWindowFlag(false);
    ui->pButtonArrow->raise();
}

