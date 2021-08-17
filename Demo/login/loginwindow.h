#ifndef LOGIN_H
#define LOGIN_H

#include "basewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE


// 登录状态;
typedef enum
{
    ONLINE = 1,     //在线;
    ACTIVE,         //活跃;
    AWAY,           //离开;
    BUSY,           //忙碌;
    NOT_DISTURB,    //请勿打扰;
    HIDE,           //隐身;
    OFFLINE         //离线;
}LoginState;

class LoginWindow : public BaseWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
private:
    void initMyTitle();
    void initWindow();

private:
    Ui::LoginWindow *ui;
};
#endif // LOGIN_H
