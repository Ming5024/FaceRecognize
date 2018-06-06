#include "FaceRecognize.h"
#include <QDebug>
#include <QtPlugin> 

FaceRecognize::FaceRecognize(QWidget *parent)
//	: QWidget(parent)
	: BaseWindow(parent)
{
	m_titleBar->setTitleRoll();
	//m_titleBar->setTitleIcon("Resources/titleicon.png");
	
	m_titleBar->setTitleContent(QStringLiteral("人脸识别签到系统"));
	m_titleBar->setButtonType(MIN_BUTTON);
	//m_titleBar->setTitleWidth(this->width());
	qDebug() << this->width();
	//m_titleBar->setTitleWidth(3);

	//this->loadStyleSheet("white");
	ui.setupUi(this);
	isshow = true;
}

void FaceRecognize::openlogin()
{
	QString ipaddress = ui.connectIP->text();
	bool connected = loginWin->modeWin->newTcpConnect(ipaddress);

	if (connected)
	{
		qDebug() << "openlogin";
		this->hide();
		loginWin->show();
		loginWin->isshow = true;

		//功能实现：当子窗口触发了关闭事件后，主窗口获取的子窗口关闭信号并还原主窗口
		connect(loginWin, SIGNAL(ExitWin()), this, SLOT(close()), Qt::UniqueConnection);
	}
}

// 加载本地样式文件;
// 可以将样式直接写在文件中，程序运行时直接加载进来;
void FaceRecognize::loadStyleSheet(const QString &sheetName)
{
	QFile file("Resources/" + sheetName + ".css");
	file.open(QFile::ReadOnly);
	if (file.isOpen())
	{
		QString styleSheet = this->styleSheet();
		styleSheet += QLatin1String(file.readAll());
		this->setStyleSheet(styleSheet);
	}
}
