#include "ariang.h"
#include <QtWidgets/QApplication>
#include <QLibraryInfo>
#include <QtQuick/QQuickView>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
	/*
	三种避免使用显卡的方式
	尚未测试

	AA_UseOpenGLES  图形绘制转码给DX运行
	AA_UseSoftwareOpenGL 软解
	AA_UseDesktopOpenGL  预置的桌面实现方式
	*/

	//由于是windows平台我们设置成转给dx实现
	QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);

	QApplication a(argc, argv);

    /*
    设置运行目录
    在QApplication  初始化后才能设置
    我们设置在 文件夹的一级目录(exe/../)
    */
    QString first_dir = QCoreApplication::applicationDirPath().append("/../");

    QDir::setCurrent(first_dir);

    ariang w;
	w.show();
	return a.exec();
}
