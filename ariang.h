#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ariang.h"
#include "windows.h"
#include <QFileInfo>
#include <QSystemTrayIcon>

class ariang : public QMainWindow
{
	Q_OBJECT

public:
	ariang(QWidget *parent = Q_NULLPTR);

	////响应 窗口大小改变
	//void resizeEvent(QResizeEvent *);
	//
	////响应 最小化消息
	//void hideEvent(QHideEvent *event);

private slots:
	
    //响应托盘点击的操作
	void iconActivated(QSystemTrayIcon::ActivationReason reason);
    
    //响应关闭事件
    void closeEvent(QCloseEvent *event);
    
    //响应 窗口大小改变
    void resizeEvent(QResizeEvent *);

    //响应 最小化消息
    void hideEvent(QHideEvent *event);

private:
	Ui::ariangClass ui;

	//托盘图标的指针
	QSystemTrayIcon *trayIcon=NULL;
    
    //启动 ariacmd
    void start_aria_cmd();

    //aria_cmd 的信息
    PROCESS_INFORMATION pi;


};
