#pragma once

#include <QWidget>
#include<cstring>
#include <QTextCodec>  
#include "ui_login.h"
#include "mode.h"

//class login : public QWidget
class login : public BaseWindow
{
	Q_OBJECT

public:
	login(QWidget *parent = Q_NULLPTR);
	~login();
	void closeEvent(QCloseEvent *);
	mode* modeWin = new mode;
	bool isshow;

signals:
	void ExitWin();//�½�һ���źŲ�

private:
	Ui::login ui;
	int nextWidget;


	private slots:
	void returnConnect();
	void sendmessage();
	void openmode(const QString& s);
	void stu_enable();
	void tea_enable();
	void logout();
};
