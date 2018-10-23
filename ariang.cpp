#include "ariang.h"
#include "QHideEvent"
#include <QDir>
#include <QtQuick/QQuickView>



ariang::ariang(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QUrl url = QUrl(QFileInfo("./AriaNg/index.html").absoluteFilePath());
    //QUrl url = QUrl("C:/Users/cr/source/repos/ariang/x64/Release/AriaNg/index.html");

    ui.webEngineView->load(url);


    //设置托盘图标
    {
        //设置托盘图标
        QIcon icon = QIcon(":/ariang/Resources/tileicon.png"); //png,ico,svg,bmp各种格式，尺寸无限制（推荐60x60），加载图标可以用相对、绝对、资源路径
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(icon);
        trayIcon->show();

        //绑定托盘点击事件
        QObject::connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    }


    //启动aria cmd
    start_aria_cmd();

}

void ariang::resizeEvent(QResizeEvent *)
{
    ui.webEngineView->resize(this->size());
}


void ariang::hideEvent(QHideEvent *event)
{
    if (trayIcon->isVisible())
    {
        hide(); //隐藏窗口
        //trayIcon->showMessage("title", "隐藏到托盘图标了"); //提示用户隐藏到了托盘
        event->ignore(); //忽略事件
    }
}

void ariang::start_aria_cmd()
{
    STARTUPINFOA si = { 0 };

    si.cb = sizeof(STARTUPINFOA);


    //设置aria 命令 字符串
 

    //QString cmd_start = "\"";//命令路径套上引号防止空格
    ////exe 文件具体路径
    //QString cmd_exe_path = QFileInfo("./aria2c_line/aria2c.exe").absoluteFilePath().append("\"");
    ////conf 文件具体路径
    //QString cmd_conf_path = QFileInfo("./aria2c_line/aria2.conf").absoluteFilePath().append("\"");

    ////合成启动命令
    //cmd_start = cmd_start.append(cmd_exe_path).append(" --conf-path \"").append(cmd_conf_path);

    ////qstring to char *
    ////QByteArray ba_cmd_start_aria = cmd_start.toLatin1();
    ////char *p_str_cmd_start_aria = ba_cmd_start_aria.data();


    //std::string str_cmd_start = cmd_start.toStdString();
    ////准备载体
    //char *p_str_cmd_start_aria = new char[str_cmd_start.length() + 1];
    ////复制出来
    //strcpy(p_str_cmd_start_aria, str_cmd_start.c_str());


    //我们直接设置成相对路径启动
    QString cmd_start = "\"";//命令路径套上引号防止空格
    //exe 文件具体路径
    QString cmd_exe_path = QString("aria2c_line/aria2c.exe").append("\" ");
    //conf 文件具体路径
    QString cmd_conf_path = QString("aria2c_line/aria2.conf").append("\" ");

    //合成启动命令
    cmd_start = cmd_start.append(cmd_exe_path).append(" --conf-path \"").append(cmd_conf_path);

    //qstring to char *
    //QByteArray ba_cmd_start_aria = cmd_start.toLatin1();
    //char *p_str_cmd_start_aria = ba_cmd_start_aria.data();


    std::string str_cmd_start = cmd_start.toStdString();
    //准备载体
    char *p_str_cmd_start_aria = new char[str_cmd_start.length() + 1];
    //复制出来
    strcpy(p_str_cmd_start_aria, str_cmd_start.c_str());

    OutputDebugStringA(p_str_cmd_start_aria);
    CreateProcessA(NULL, p_str_cmd_start_aria, NULL, NULL, 0, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);


}

void ariang::closeEvent(QCloseEvent * event)
{
    //trayIcon->showMessage("title", "close ");

    TerminateProcess(
        pi.hProcess,
        0
    );

}

void ariang::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
        //单机
    case QSystemTrayIcon::Trigger:
    {

        if (this->isHidden()) {

            //this->setWindowFlags(Qt::WindowStaysOnTopHint);//设置在z轴的最顶端(这里是区z的极限)

            this->activateWindow();//将窗口设置在当前所有z轴截面的上一层

            this->showNormal();//一定要用showNormal否则 无法设置 z轴

        }
        else {


            this->hide();

        }

    }
    break;

    //双击
    //case QSystemTrayIcon::DoubleClick:


    //中键
    //case QSystemTrayIcon::MiddleClick:

    default:
        break;
    }
}
