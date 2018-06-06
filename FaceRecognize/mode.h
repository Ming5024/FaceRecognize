#pragma once

#include <io.h>
#include<fstream>
#include <qmap.h>
#include <QWidget>
#include <QtNetwork/QtNetwork>
#include <opencv2/opencv.hpp>
#include<qmessagebox.h>
#include <QTime>
#include "ui_mode.h"
#include "BaseWindow.h"
//#include "socketThread.h"
using namespace cv;

struct login_mes
{
	char classname[20];
	char name[20];
	char id[20];
	char character[20];
};

//class mode : public QWidget
class mode : public BaseWindow
{
	Q_OBJECT

public:
	mode(QWidget *parent = Q_NULLPTR);
	~mode();
	void closeEvent(QCloseEvent *);
	bool newTcpConnect(QString connectIP);	//�����µ�����
	void sendLoginMessage(QString message);		//���͵�¼��Ϣ
	void sendLogoutMessage();		//���͵ǳ���Ϣ
	void showWidget(int num);				//����ģʽѡ��widget
	void closeConnect();
	void opencamera();						//��������ͷ
	void closecamera();						//�ر�����ͷ
	IplImage* face_reg(IplImage *frame1);

	char buffer[1024];
	bool isshow;
	bool camopen;
	bool issignin;
	QMap<QString, QString> info;

signals:
	void ExitWin();//�½�һ���źŲ�
	void sendlogin(const QString& s);
	void returntoConnect();		//�������ӽ�����ź�

private:
	Ui::mode ui;
	QTcpSocket *tcpSocket;
	QTimer *timer;
	//QTimer ��ʱ�ã�  
	int cnt;

	void paintEvent(QPaintEvent *event);

	IplImage* pFrame;
	//����IplImage����ָ�룬���������ڴ�ռ������ÿһ֡ͼ��  

	CvCapture *cam;
	// ��Ƶ��ȡ�ṹ�� ������Ϊ��Ƶ��ȡ������һ������


	String face_cascade_name = "haarcascade_frontalface_default.xml";
	CascadeClassifier face_cascade;   //��������������  

	private slots:
	void exit();
	void recvMessage();
	void returnConnect();

	//ѧ������
	void controlcam(int index);
	void readframe();
	void capture();
	void recap();
	void upload();
	void query();


	//��ʦ����
	void normal_signin();
	void dynamic_signin();
	void finish_signin();
	void broadcast();
	void teacher_query();
	void manSignin();
	//void startThread();
};
