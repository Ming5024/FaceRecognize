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
	bool newTcpConnect(QString connectIP);	//创建新的连接
	void sendLoginMessage(QString message);		//发送登录消息
	void sendLogoutMessage();		//发送登出消息
	void showWidget(int num);				//根据模式选择widget
	void closeConnect();
	void opencamera();						//开启摄像头
	void closecamera();						//关闭摄像头
	IplImage* face_reg(IplImage *frame1);

	char buffer[1024];
	bool isshow;
	bool camopen;
	bool issignin;
	QMap<QString, QString> info;

signals:
	void ExitWin();//新建一个信号槽
	void sendlogin(const QString& s);
	void returntoConnect();		//返回连接界面的信号

private:
	Ui::mode ui;
	QTcpSocket *tcpSocket;
	QTimer *timer;
	//QTimer 计时用；  
	int cnt;

	void paintEvent(QPaintEvent *event);

	IplImage* pFrame;
	//申请IplImage类型指针，就是申请内存空间来存放每一帧图像  

	CvCapture *cam;
	// 视频获取结构， 用来作为视频获取函数的一个参数


	String face_cascade_name = "haarcascade_frontalface_default.xml";
	CascadeClassifier face_cascade;   //定义人脸分类器  

	private slots:
	void exit();
	void recvMessage();
	void returnConnect();

	//学生界面
	void controlcam(int index);
	void readframe();
	void capture();
	void recap();
	void upload();
	void query();


	//教师界面
	void normal_signin();
	void dynamic_signin();
	void finish_signin();
	void broadcast();
	void teacher_query();
	void manSignin();
	//void startThread();
};
