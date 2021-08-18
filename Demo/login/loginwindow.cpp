#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QPainter>
#include <QMovie>
#include <QHBoxLayout>
#include <QCursor>
#include <QMenu>
#include <QDebug>
#include <QTime>
#include "accountitem.h"
#include <QPropertyAnimation>

LoginWindow::LoginWindow(QWidget *parent)
    : BaseWindow(parent)
    , ui(new Ui::LoginWindow)
    , m_loginState(ONLINE)
{
    ui->setupUi(this);
    initWindow();
    initMyTitle();
    initAccountList();
    this->loadStyleSheet(":/Resources/LoginWindow/LoginWindow.css");
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

    //密码框中的小键盘按钮;
    m_keyboardButton = new QPushButton();
    m_keyboardButton->setObjectName("pButtonKeyboard");
    m_keyboardButton->setFixedSize(QSize(16, 16));
    //鼠标放上去变成手形
    m_keyboardButton->setCursor(QCursor(Qt::PointingHandCursor));

    QHBoxLayout* passwordEditLayout = new QHBoxLayout();
    passwordEditLayout->addStretch();
    passwordEditLayout->addWidget(m_keyboardButton);
    passwordEditLayout->setSpacing(0);
    passwordEditLayout->setContentsMargins(0, 0, 8, 0);

    ui->passwordEdit->setLayout(passwordEditLayout);
    //设置密码达到最长时最后一个字符离小键盘图标的距离（12）
    ui->passwordEdit->setTextMargins(0, 0, m_keyboardButton->width() + 12, 0);

    //设置头像以及状态图标
    ui->userHead->setPixmap(QPixmap(":/Resources/LoginWindow/HeadImage.png"));
    ui->loginState->setIcon(QIcon(":/Resources/LoginWindow/LoginState/state_online.png"));
    ui->loginState->setIconSize(QSize(13, 13));


    //connect(ui->loginState, SIGNAL(clicked()), this, SLOT(onLoginStateClicked()));
    //connect(ui->pButtonArrow, SIGNAL(clicked()), this, SLOT(onNetWorkSet()));

}

// 初始化标题栏;
void LoginWindow::initMyTitle()
{
    // 因为这里有控件层叠了，所以要注意控件raise()方法的调用顺序;
    m_titleBar->move(0, 0);
    m_titleBar->raise();
    m_titleBar->setBackgroundColor(0, 0, 0, true);
    m_titleBar->setButtonType(MIN_BUTTON);
    m_titleBar->setTitleWidth(this->width());
    // 这里需要设置成false，不允许通过标题栏拖动来移动窗口位置,否则会造成窗口位置错误;
    m_titleBar->setMoveParentWindowFlag(true);
    ui->pButtonArrow->raise();
}

// 初始化用户登录信息;
void LoginWindow::initAccountList()
{
    // 设置代理;
    m_Accountlist = new QListWidget(this);
    ui->accountComboBox->setModel(m_Accountlist->model());
    ui->accountComboBox->setView(m_Accountlist);

    for (int i = 0; i < 3; i++)
    {
        AccountItem *account_item = new AccountItem();
        account_item->setAccountInfo(i, QStringLiteral("Dominic%1号").arg(i), QString(":/Resources/LoginWindow/headImage/head_%1.png").arg(i));
        //connect(account_item, SIGNAL(signalShowAccountInfo(int, QString)), this, SLOT(onShowAccountInfo(int, QString)));
        //connect(account_item, SIGNAL(signalRemoveAccount(int)), this, SLOT(onRemoveAccount(int)));
        QListWidgetItem *list_item = new QListWidgetItem(m_Accountlist);
        m_Accountlist->setItemWidget(list_item, account_item);
    }
}
