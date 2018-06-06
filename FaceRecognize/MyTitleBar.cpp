#include "MyTitleBar.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QFile>
#include <QMouseEvent>
#include <QDebug>

#define BUTTON_HEIGHT 25        // ��ť�߶�;
#define BUTTON_WIDTH 25         // ��ť���;
#define TITLE_HEIGHT 20         // �������߶�;

MyTitleBar::MyTitleBar(QWidget *parent)
	: QWidget(parent)
	, m_colorR(153)
	, m_colorG(153)
	, m_colorB(153)
	, m_isPressed(false)
	, m_buttonType(MIN_MAX_BUTTON)
	, m_windowBorderWidth(0)
	, m_isTransparent(false)
{
	// ��ʼ��;
	initControl();
	initConnections();
	// ���ر�����ʽ MyTitle.css�ļ�;
	//loadStyleSheet("black");
}

MyTitleBar::~MyTitleBar()
{
}

// ��ʼ���ؼ�;
void MyTitleBar::initControl()
{
	m_pIcon = new QLabel;
	m_pTitleContent = new QLabel;

	m_pButtonMin = new QPushButton;
	m_pButtonRestore = new QPushButton;
	m_pButtonMax = new QPushButton;
	m_pButtonClose = new QPushButton;

	m_pButtonMin->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_pButtonRestore->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_pButtonMax->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));
	m_pButtonClose->setFixedSize(QSize(BUTTON_WIDTH, BUTTON_HEIGHT));

	m_pTitleContent->setObjectName("TitleContent");
	m_pButtonMin->setObjectName("ButtonMin");
	m_pButtonRestore->setObjectName("ButtonRestore");
	m_pButtonMax->setObjectName("ButtonMax");
	m_pButtonClose->setObjectName("ButtonClose");

	m_pButtonMin->setStyleSheet("background-color: rgba(200, 200, 200,0);");
	m_pButtonRestore->setStyleSheet("background-color: rgba(200, 200, 200,0);");
	m_pButtonMax->setStyleSheet("background-color: rgba(200, 200, 200,0);");
	m_pButtonClose->setStyleSheet("background-color: rgba(200, 200, 200,0);");

	m_pButtonMin->setToolTip(QStringLiteral("��С��"));
	m_pButtonRestore->setToolTip(QStringLiteral("��ԭ"));
	m_pButtonMax->setToolTip(QStringLiteral("���"));
	m_pButtonClose->setToolTip(QStringLiteral("�ر�"));

	setMinIcon("Resources/minus.png");
	setMaxIcon("Resources/maxus.png");
	setCloseIcon("Resources/close.png");

	m_pTitleContent->setStyleSheet("background-color:grey; min-height:25px");

	QHBoxLayout* mylayout = new QHBoxLayout(this);
	mylayout->addWidget(m_pIcon);
	mylayout->addWidget(m_pTitleContent);

	mylayout->addWidget(m_pButtonMin);
	mylayout->addWidget(m_pButtonRestore);
	mylayout->addWidget(m_pButtonMax);
	mylayout->addWidget(m_pButtonClose);

	mylayout->setContentsMargins(5, 0, 0, 0);
	mylayout->setSpacing(0); 

	m_pTitleContent->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	this->setFixedHeight(40);
	//this->setFixedWidth(30);
	this->setWindowFlags(Qt::FramelessWindowHint);
	//this->setButtonType(m_buttonType);
}

// �źŲ۵İ�;
void MyTitleBar::initConnections()
{
	qDebug() << "initconnections";
	connect(m_pButtonMin, SIGNAL(clicked()), this, SLOT(onButtonMinClicked()));
	connect(m_pButtonRestore, SIGNAL(clicked()), this, SLOT(onButtonRestoreClicked()));
	connect(m_pButtonMax, SIGNAL(clicked()), this, SLOT(onButtonMaxClicked()));
	connect(m_pButtonClose, SIGNAL(clicked()), this, SLOT(onButtonCloseClicked()));
}

// ���ñ���������ɫ,��paintEvent�¼��н��л��Ʊ���������ɫ;
// �ڹ��캯���и���Ĭ��ֵ�������ⲿ������ɫֵ�ı����������ɫ;
void MyTitleBar::setBackgroundColor(int r, int g, int b, bool isTransparent)
{
	m_colorR = r;
	m_colorG = g;
	m_colorB = b;
	m_isTransparent = isTransparent;
	// ���»��ƣ�����paintEvent�¼���;
	update();
}

// ���ñ�����ͼ��;
void MyTitleBar::setTitleIcon(QString filePath, QSize IconSize)
{
	QPixmap titleIcon(filePath);
	m_pIcon->setPixmap(titleIcon.scaled(IconSize));
}

//������С��ͼ��
void MyTitleBar::setMinIcon(QString filePath, QSize IconSize)
{
	QPixmap titleIcon(filePath);
	m_pButtonMin->setIcon(titleIcon.scaled(IconSize));
}

//�������ͼ��
void MyTitleBar::setMaxIcon(QString filePath, QSize IconSize)
{
	QPixmap titleIcon(filePath);
	m_pButtonMax->setIcon(titleIcon.scaled(IconSize));
}

// ���ûָ�ͼ��
void MyTitleBar::setRestoreIcon(QString filePath, QSize IconSize)
{
	QPixmap titleIcon(filePath);
	m_pButtonRestore->setIcon(titleIcon.scaled(IconSize));
}

//���ùر�ͼ��
void MyTitleBar::setCloseIcon(QString filePath, QSize IconSize)
{
	QPixmap titleIcon(filePath);
	m_pButtonClose->setIcon(titleIcon.scaled(IconSize));
}

// ���ñ�������;
void MyTitleBar::setTitleContent(QString titleContent, int titleFontSize)
{
	// ���ñ��������С;
	QFont font = m_pTitleContent->font();
	font.setPointSize(titleFontSize);
	m_pTitleContent->setFont(font);
	// ���ñ�������;
	m_pTitleContent->setText(titleContent);
	m_titleContent = titleContent;

	
}

// ���ñ���������;
void MyTitleBar::setTitleWidth(int width)
{
	this->setFixedWidth(width);
}

// ���ñ������ϰ�ť����;
// ���ڲ�ͬ���ڱ������ϵİ�ť����һ�������Կ����Զ���������еİ�ť;
// �����ṩ���ĸ���ť���ֱ�Ϊ��С������ԭ����󻯡��رհ�ť�������Ҫ������ť�������������;
void MyTitleBar::setButtonType(ButtonType buttonType)
{
	m_buttonType = buttonType;

	switch (buttonType)
	{
	case MIN_BUTTON:
	{
		m_pButtonRestore->setVisible(false);
		m_pButtonMax->setVisible(false);
	}
	break;
	case MIN_MAX_BUTTON:
	{
		m_pButtonRestore->setVisible(false);
	}
	break;
	case ONLY_CLOSE_BUTTON:
	{
		m_pButtonMin->setVisible(false);
		m_pButtonRestore->setVisible(false);
		m_pButtonMax->setVisible(false);
	}
	break;
	default:
		break;
	}
}

// ���ñ������еı����Ƿ���Զ�����������Ƶ�Ч��;
// һ������±������еı��������ǲ������ģ����Ǽ�Ȼ�Զ���Ϳ��Լ���Ҫ�����ô��ƾ���ô��O(��_��)O��
void MyTitleBar::setTitleRoll()
{
	connect(&m_titleRollTimer, SIGNAL(timeout()), this, SLOT(onRollTitle()));
	m_titleRollTimer.start(200);
}

// ���ô��ڱ߿���;
void MyTitleBar::setWindowBorderWidth(int borderWidth)
{
	m_windowBorderWidth = borderWidth;
}

// ���洰�����ǰ���ڵ�λ���Լ���С;
void MyTitleBar::saveRestoreInfo(const QPoint point, const QSize size)
{
	m_restorePos = point;
	m_restoreSize = size;
}

// ��ȡ�������ǰ���ڵ�λ���Լ���С;
void MyTitleBar::getRestoreInfo(QPoint& point, QSize& size)
{
	point = m_restorePos;
	size = m_restoreSize;
}

// ���Ʊ���������ɫ;
void MyTitleBar::paintEvent(QPaintEvent *event)
{
	// �Ƿ����ñ���͸��;
	if (!m_isTransparent)
	{
		//���ñ���ɫ;
		QPainter painter(this);
		QPainterPath pathBack;
		pathBack.setFillRule(Qt::WindingFill);
		pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
		painter.setRenderHint(QPainter::Antialiasing, true);
		painter.fillPath(pathBack, QBrush(QColor(m_colorR, m_colorG, m_colorB)));
	}

	// ��������󻯻��߻�ԭ�󣬴��ڳ��ȱ��ˣ��������ĳ���Ӧ��һ��ı�;
	// �����ȥm_windowBorderWidth ������Ϊ���ڿ��������˲�ͬ��ȵı߿�;
	// ��������б߿�����Ҫ����m_windowBorderWidth��ֵ������m_windowBorderWidthĬ��Ϊ0;
	if (this->width() != (this->parentWidget()->width() - m_windowBorderWidth))
	{
		this->setFixedWidth(this->parentWidget()->width() - m_windowBorderWidth);
	}
	QWidget::paintEvent(event);
}

// ˫����Ӧ�¼�����Ҫ��ʵ��˫��������������󻯺���С������;
void MyTitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
	qDebug() << "mouseDoubleClickEvent";
	// ֻ�д�����󻯡���ԭ��ťʱ˫������Ч;
	if (m_buttonType == MIN_MAX_BUTTON)
	{
		// ͨ����󻯰�ť��״̬�жϵ�ǰ�����Ǵ�����󻯻���ԭʼ��С״̬;
		// ����ͨ���������ñ�������ʾ��ǰ����״̬;
		if (m_pButtonMax->isVisible())
		{
			onButtonMaxClicked();
		}
		else
		{
			onButtonRestoreClicked();
		}
	}

	return QWidget::mouseDoubleClickEvent(event);
}

// ����ͨ��mousePressEvent��mouseMoveEvent��mouseReleaseEvent�����¼�ʵ��������϶��������ƶ����ڵ�Ч��;
void MyTitleBar::mousePressEvent(QMouseEvent *event)
{
	qDebug() << "mousePressEvent";
	if (m_buttonType == MIN_MAX_BUTTON)
	{
		// �ڴ������ʱ��ֹ�϶�����;
		if (m_pButtonMax->isVisible())
		{
			m_isPressed = true;
			m_startMovePos = event->globalPos();
		}
	}
	else
	{
		m_isPressed = true;
		m_startMovePos = event->globalPos();
	}

	return QWidget::mousePressEvent(event);
}

void MyTitleBar::mouseMoveEvent(QMouseEvent *event)
{
	qDebug() << "mouseMoveEvent";
	if (m_isPressed)
	{
		QPoint movePoint = event->globalPos() - m_startMovePos;
		QPoint widgetPos = this->parentWidget()->pos();
		m_startMovePos = event->globalPos();
		this->parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
	}
	return QWidget::mouseMoveEvent(event);
}

void MyTitleBar::mouseReleaseEvent(QMouseEvent *event)
{
	qDebug() << "mouseReleaseEvent";
	m_isPressed = false;
	return QWidget::mouseReleaseEvent(event);
}

// ���ر�����ʽ�ļ�;
// ���Խ���ʽֱ��д���ļ��У���������ʱֱ�Ӽ��ؽ���;
void MyTitleBar::loadStyleSheet(const QString &sheetName)
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

// ����Ϊ��ť������Ӧ�Ĳ�;
void MyTitleBar::onButtonMinClicked()
{
	qDebug() << "onButtonMinClicked";
	emit signalButtonMinClicked();
}

void MyTitleBar::onButtonRestoreClicked()
{
	qDebug() << "onButtonRestoreClicked";
	m_pButtonRestore->setVisible(false);
	m_pButtonMax->setVisible(true);
	emit signalButtonRestoreClicked();
}

void MyTitleBar::onButtonMaxClicked()
{
	qDebug() << "onButtonMaxClicked";
	m_pButtonMax->setVisible(false);
	m_pButtonRestore->setVisible(true);
	emit signalButtonMaxClicked();
}

void MyTitleBar::onButtonCloseClicked()
{
	qDebug() << "onButtonCloseClicked";
	emit signalButtonCloseClicked();
}

// �÷�����Ҫ���ñ������еı�����ʾΪ������Ч��;
void MyTitleBar::onRollTitle()
{
	static int nPos = 0;
	QString titleContent = m_titleContent;
	// ����ȡ��λ�ñ��ַ�����ʱ����ͷ��ʼ;
	if (nPos > titleContent.length())
		nPos = 0;

	m_pTitleContent->setText(titleContent.mid(nPos));
	nPos++;
}
