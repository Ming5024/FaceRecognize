#include "login.h"

login::login(QWidget *parent)
//	: QWidget(parent)
	: BaseWindow(parent)
{
	//setAttribute(Qt::WA_DeleteOnClose);
	/*
	QFile file("Resources/navy.css");
	file.open(QFile::ReadOnly);
	if (file.isOpen())
	{
	QString styleSheet = this->styleSheet();
	styleSheet += QLatin1String(file.readAll());
	this->setStyleSheet(styleSheet);
	}
	*/
	m_titleBar->setButtonType(MIN_BUTTON);
	ui.setupUi(this);
	isshow = false;
	nextWidget = 0;
	ui.stu_class->setEnabled(false);
	ui.stu_id->setEnabled(false);
	ui.stu_name->setEnabled(false);
	ui.tea_class->setEnabled(false);
	ui.tea_name->setEnabled(false);
	ui.tea_password->setEnabled(false);
	ui.tea_password->setEchoMode(QLineEdit::Password);

	setTabOrder(ui.stuRadio, ui.stu_class);
	setTabOrder(ui.teacherRadio, ui.tea_class);
	setTabOrder(ui.stu_class, ui.stu_id);
	setTabOrder(ui.stu_id, ui.stu_name);
	setTabOrder(ui.tea_class, ui.tea_name);
	setTabOrder(ui.tea_name, ui.tea_password);
	setTabOrder(ui.stu_name, ui.login_2);
	setTabOrder(ui.tea_password, ui.login_2);
	setTabOrder(ui.login_2, ui.exit);
	setTabOrder(ui.exit, ui.stuRadio);

	connect(ui.stuRadio, SIGNAL(toggled(bool)), this, SLOT(stu_enable()));
	connect(ui.teacherRadio, SIGNAL(toggled(bool)), this, SLOT(tea_enable()));

	connect(modeWin, SIGNAL(returntoConnect()), this, SLOT(close()));
}

login::~login()
{
	delete modeWin;
}

//返回connect窗口
void login::returnConnect()
{
	//this->modeWin->closeConnect();
	isshow = false;
	this->close();
	//QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("你已与服务器断开连接"));
	//emit ExitWin();
}

//当窗口出发关闭事件后，将信号发射出去
void login::closeEvent(QCloseEvent *)
{
	isshow = false;
	this->modeWin->closeConnect();
	ui.stu_class->setText("");
	ui.stu_id->setText("");
	ui.stu_name->setText("");
	ui.tea_class->setText("");
	ui.tea_name->setText("");
	ui.tea_password->setText("");
	qDebug() << "closeEvent()";
	//QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("你已与服务器断开连接"));
	emit ExitWin();
}

//开启学生输入
void login::stu_enable()
{
	if (ui.stuRadio->isChecked())
	{
		ui.stu_class->setEnabled(true);
		ui.stu_id->setEnabled(true);
		ui.stu_name->setEnabled(true);
		nextWidget = 0;
	}
	else
	{
		ui.stu_class->setEnabled(false);
		ui.stu_id->setEnabled(false);
		ui.stu_name->setEnabled(false);
		ui.stu_class->setText("");
		ui.stu_id->setText("");
		ui.stu_name->setText("");
	}
}

//开启教师输入
void login::tea_enable()
{
	if (ui.teacherRadio->isChecked())
	{
		ui.tea_class->setEnabled(true);
		ui.tea_name->setEnabled(true);
		ui.tea_password->setEnabled(true);
		nextWidget = 1;
	}
	else
	{
		ui.tea_class->setEnabled(false);
		ui.tea_name->setEnabled(false);
		ui.tea_password->setEnabled(false);
		ui.tea_class->setText("");
		ui.tea_name->setText("");
		ui.tea_password->setText("");
	}
}

void login::sendmessage()
{
	login_mes mes;
	QString send_mes = "mode:login\n";
	if (nextWidget == 0)
	{
		/*
		std::string str = ui.stu_class->text().toStdString();
		strcpy(mes.classname, str.c_str());
		qDebug() << mes.classname;
		str = ui.stu_name->text().toStdString();
		strcpy(mes.name, str.c_str());
		qDebug() << mes.name;
		str = ui.stu_id->text().toStdString();
		strcpy(mes.id, str.c_str());
		qDebug() << mes.id;
		str = "student";
		strcpy(mes.character, str.c_str());
		*/
		if (ui.stu_class->text().isEmpty() || ui.stu_name->text().isEmpty() || ui.stu_id->text().isEmpty())
		{
			QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("请输入完整信息！"));
			return;
		}
		send_mes += "classname:" + ui.stu_class->text() + "\n";
		send_mes += "name:" + ui.stu_name->text() + "\n";
		send_mes += "id:" + ui.stu_id->text() + "\n";
		send_mes += "character:student\n";
		modeWin->info["character"] = "student";
		/*
		modeWin->info["classname"] = ui.stu_class->text();
		modeWin->info["name"] = ui.stu_name->text();
		modeWin->info["id"] = ui.stu_id->text();
		modeWin->info["character"] = "student";
		*/

	}
	else if (nextWidget == 1)
	{
		/*
		std::string str = ui.tea_class->text().toStdString();
		strcpy(mes.classname, str.c_str());
		qDebug() << mes.classname;
		str = ui.tea_name->text().toStdString();
		strcpy(mes.name, str.c_str());
		qDebug() << mes.name;
		str = ui.tea_password->text().toStdString();
		strcpy(mes.id, str.c_str());
		qDebug() << mes.id;
		str = "teacher";
		strcpy(mes.character, str.c_str());
		*/
		if (ui.tea_class->text().isEmpty() || ui.tea_name->text().isEmpty() || ui.tea_password->text().isEmpty())
		{
			QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("请输入完整信息！"));
			return;
		}
		send_mes += "classname:" + ui.tea_class->text() + "\n";
		send_mes += "name:" + ui.tea_name->text() + "\n";
		send_mes += "id:" + ui.tea_password->text() + "\n";
		send_mes += "character:teacher\n";
		modeWin->info["character"] = "teacher";
		/*
		modeWin->info["classname"] = ui.tea_class->text();
		modeWin->info["name"] = ui.tea_name->text();
		modeWin->info["id"] = ui.tea_password->text();
		modeWin->info["character"] = "teacher";
		*/
	}
	qDebug() << send_mes;
	modeWin->sendLoginMessage(send_mes);
	//modeWin->sendLoginMessage(mes);
	connect(modeWin, SIGNAL(sendlogin(const QString&)), this, SLOT(openmode(const QString&)), Qt::UniqueConnection);
}

//开启mode窗口
void login::openmode(const QString& s)
{
	//qDebug() << s;
	//qDebug() << "openmode";
	if (s == "login success")
	{
		this->hide();
		modeWin->showWidget(nextWidget);
		modeWin->show();
		modeWin->isshow = true;
		if (nextWidget == 0 && modeWin->camopen == true && modeWin->issignin == false)		//学生模式开启摄像头
		{
			modeWin->opencamera();
		}
	}
	else if (s == "has login")
	{
		QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("该帐号已被登录！"));
	}
	else if (s == "login fail")
	{
		QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("输入错误，请重新输入！"));
	}


	//功能实现：当子窗口触发了关闭事件后，主窗口获取的子窗口关闭信号并还原主窗口
	connect(modeWin, SIGNAL(ExitWin()), this, SLOT(logout()), Qt::UniqueConnection);
	connect(modeWin, SIGNAL(ExitWin()), this, SLOT(close()), Qt::UniqueConnection);
}

void login::logout()
{
	modeWin->sendLogoutMessage();
}

