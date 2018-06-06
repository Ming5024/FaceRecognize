#include "FaceRecognize.h"
#include <QDebug>
#include <QtPlugin> 

FaceRecognize::FaceRecognize(QWidget *parent)
//	: QWidget(parent)
	: BaseWindow(parent)
{
	m_titleBar->setTitleRoll();
	//m_titleBar->setTitleIcon("Resources/titleicon.png");
	
	m_titleBar->setTitleContent(QStringLiteral("����ʶ��ǩ��ϵͳ"));
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

		//����ʵ�֣����Ӵ��ڴ����˹ر��¼��������ڻ�ȡ���Ӵ��ڹر��źŲ���ԭ������
		connect(loginWin, SIGNAL(ExitWin()), this, SLOT(close()), Qt::UniqueConnection);
	}
}

// ���ر�����ʽ�ļ�;
// ���Խ���ʽֱ��д���ļ��У���������ʱֱ�Ӽ��ؽ���;
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
