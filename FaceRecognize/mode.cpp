#include "mode.h"
#include<QPainter>

IplImage* mode::face_reg(IplImage *frame1) {
	//qDebug() << "face_reg";
	Mat frame = cvarrToMat(frame1);
	if (!face_cascade.load(face_cascade_name)) { qDebug() << "--(!)Error loading face cascade"; return NULL; };
	std::vector<Rect> faces;
	Mat frame_gray;
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);
	//-- Detect faces  
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, CV_HAAR_DO_ROUGH_SEARCH, Size(100, 100), Size(640, 480));

	for (size_t i = 0; i < faces.size(); i++)
	{
		rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
	}

	IplImage *frame2 = &IplImage(frame);

	return frame2;
}

mode::mode(QWidget *parent)
//	: QWidget(parent)
	: BaseWindow(parent)
{
	//m_titleBar->setBackgroundColor(0, 0, 0, true);
	m_titleBar->setButtonType(MIN_BUTTON);
	//setAttribute(Qt::WA_DeleteOnClose);
	ui.setupUi(this);
	ui.dynamic_signin->setEnabled(false);
	ui.dynamic_signin->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	ui.capture_Button->setEnabled(false);
	ui.capture_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	ui.recap_Button->setEnabled(false);
	ui.recap_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	ui.upload_Button->setEnabled(false);
	ui.upload_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	this->setAttribute(Qt::WA_TranslucentBackground, true);
	ui.stackedWidget->setAttribute(Qt::WA_TranslucentBackground, true);
	QPalette pal = palette();
	pal.setColor(QPalette::Background, QColor(0x00, 0xff, 0x00, 0x00));
	setPalette(pal);
	//setWindowFlags(Qt::FramelessWindowHint | windowFlags()); //无边框   
	//setAttribute(Qt::WA_TranslucentBackground, true);//设置透明2-窗体标题栏不透明,背景透明 
	isshow = false;
	camopen = false;
	issignin = false;
	cnt = 0;
	//opencamera();
	tcpSocket = new QTcpSocket(this);

	connect(ui.tabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(controlcam(int)));
	timer = new QTimer(this);
	//初始化timer  
	cam = NULL;
	// 初始化cam
	connect(timer, SIGNAL(timeout()), this, SLOT(readframe()));
	// 时间到，读取当前摄像头信息,这个必须加，因为timer需要配合timeout()信号用  
	//没有的话会出现错误；  
	//另外注意自己有没有野指针，有的话常常会  
	//出现Program Files (x86)\SogouInput\7.2.0.2124\程序异常终止,这样的错误  
	ui.query_date1->setDisplayFormat("yyyy-MM-dd");
	ui.query_date2->setDisplayFormat("yyyy-MM-dd");
}

mode::~mode()
{
	cvReleaseCapture(&cam);
	//释放内存
}

void mode::paintEvent(QPaintEvent *event)
{
	//设置背景色;
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	//整个窗口的背景色
	painter.fillRect(this->rect(), QColor(0, 0, 0, 0));  //QColor最后一个参数80代表背景的透明度
}
	

//返回上一个窗口
void mode::exit()
{
	isshow = false;
	//sendLogoutMessage();
	this->close();
	//closecamera();
	//emit ExitWin();
}

//当窗口出发关闭事件后，将信号发射出去
void mode::closeEvent(QCloseEvent *)
{
	isshow = false;
	closecamera();
	info["classname"] = "";
	info["name"] = "";
	info["id"] = "";
	emit ExitWin();
}

//关闭窗口并返回连接连接界面的信号
void mode::returnConnect()
{
	isshow = false;
	this->hide();
	closecamera();
	emit returntoConnect();
}

//根据模式选择界面
void mode::showWidget(int num)
{
	ui.stackedWidget->setCurrentIndex(num);
}

//根据标签控制摄像头
void mode::controlcam(int index)
{
	if (camopen)
	{
		if (index == 1)
		{
			closecamera();
		}
		else if (index == 0)
		{
			opencamera();
		}
	}
}

//开启摄像头
void mode::opencamera()
{
	ui.capture_Button->setEnabled(true);
	ui.capture_Button->setStyleSheet("QPushButton{color: black;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	cam = cvCreateCameraCapture(0);
	timer->start(50);
}

//关闭摄像头
void mode::closecamera()
{
	ui.capture_Button->setEnabled(false);
	ui.capture_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	cvReleaseCapture(&cam);
	timer->stop();
}

//每50ms读取一帧
void mode::readframe()
{
	pFrame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧  
							   // 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。  

	IplImage* tempFrame = face_reg(pFrame);
	QImage image((const uchar*)tempFrame->imageData, tempFrame->width, tempFrame->height, QImage::Format_RGB888);
	//QImage image((const uchar*)pFrame->imageData, pFrame->width, pFrame->height, QImage::Format_RGB888);
	image = image.scaled(ui.camlabel->width(), ui.camlabel->height());
	ui.camlabel->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上  
}

//进行拍摄
void mode::capture()
{
	timer->stop();
	ui.recap_Button->setEnabled(true);
	ui.recap_Button->setStyleSheet("QPushButton{color: black;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	ui.upload_Button->setEnabled(true);
	ui.upload_Button->setStyleSheet("QPushButton{color: black;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	ui.capture_Button->setEnabled(false);
	ui.capture_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
}

//重拍
void mode::recap()
{
	timer->start(50);
	ui.recap_Button->setEnabled(false);
	ui.recap_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	ui.upload_Button->setEnabled(false);
	ui.upload_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	ui.capture_Button->setEnabled(true);
	ui.capture_Button->setStyleSheet("QPushButton{color: black;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
}

//上传图片
void mode::upload()
{
	QImage image((const uchar*)pFrame->imageData, pFrame->width, pFrame->height, QImage::Format_RGB888);
	QString filepath = info["classname"] + "/images/" + info["id"] + ".jpg";
	//image.save(filepath);

	std::fstream fs;
	//QString filepath = info["classname"] + "/images/" + info["id"] + ".jpg";
	qDebug() << filepath;
	fs.open(filepath.toStdString(), std::fstream::in | std::fstream::binary);

	if (fs.is_open() == false)
	{
		QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("File open fail!"));
		return;
	}

	fs.seekg(0, std::fstream::end);//以最后的位置为基准不偏移
	int filesize = fs.tellg();
	fs.seekg(0, std::fstream::beg);
	QString send_mes = "mode:sendPic\n";
	send_mes += "picsize:" + QString::fromStdString(std::to_string(filesize)) + "\n";

	tcpSocket->write(send_mes.toStdString().c_str(), strlen(send_mes.toStdString().c_str()));
	tcpSocket->waitForBytesWritten(1800);
	char szBuf[1024] = { 0 };

	//读文件
	while (!fs.eof())
	{
		fs.read(szBuf, 1024);
		int len = fs.gcount();
		//if(len == 0 ) break;
		tcpSocket->write(szBuf, len);
		tcpSocket->waitForBytesWritten(1800);
	}

	fs.close();
}

//学生查询签到次数
void mode::query()
{
	//qDebug() << ui.query_date1->date();
	//qDebug() << ui.query_date2->date();
	QString send_mes = "mode:stu_query\n";

	if (ui.query_date1->date() < ui.query_date2->date())
	{
		ui.query_table->clearContents();//只清除表中数据，不清除表头内容
		ui.query_table->setRowCount(0);//连行也清除掉
		QString date1 = ui.query_date1->date().toString("yyyy-MM-dd");
		QString date2 = ui.query_date2->date().toString("yyyy-MM-dd");
		send_mes += "date1:" + date1 + "\n";
		send_mes += "date2:" + date2 + "\n";
		qDebug() << send_mes;
		tcpSocket->write(send_mes.toStdString().c_str(), strlen(send_mes.toStdString().c_str()));
	}
	else
	{
		QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("日期错误，请重新输入！"));
	}
}

bool mode::newTcpConnect(QString connectIP)
{
	//tcpSocket->abort();
	//Attempts to make a connection to hostName on the given port.
	tcpSocket->connectToHost(connectIP, 50520);
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(recvMessage()), Qt::UniqueConnection);
	connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(returnConnect()), Qt::UniqueConnection);
	bool connected = tcpSocket->waitForConnected();
	return connected;
}

void mode::sendLoginMessage(QString message)
{
	//memset(buffer, 0, 1024);
	//memcpy(buffer, &message, sizeof(message));
	//tcpSocket->write((char *)&message, sizeof(message));
	tcpSocket->write(message.toStdString().c_str(), strlen(message.toStdString().c_str()));
	tcpSocket->waitForBytesWritten(300);
	//connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(recvMessage()));
}

void mode::sendLogoutMessage()
{
	QString send_mes = "mode:logout\n";
	tcpSocket->write(send_mes.toStdString().c_str(), strlen(send_mes.toStdString().c_str()));
}

//接收信息（待修改）
void mode::recvMessage()
{
	QByteArray array = tcpSocket->readAll();
	QString str(array);
	qDebug() << str;
	//qDebug() << isshow;
	QMap<QString, QString> res_Mes;
	QString temp = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '\n')
		{
			QString mapKey = "";
			QString mapValue = "";
			int split = 0;
			for (int j = 0; j < temp.length(); j++)
			{
				if (temp[j] == ':')
				{
					split = j;
					break;
				}
				mapKey += temp[j];
			}
			for (int j = split + 1; j < temp.length(); j++)
			{
				//qDebug() << j << temp[j];
				mapValue += temp[j];
			}
			//char* gbkvalue = new char[mapValue.length() + 1];
			//UTF82GBK(mapValue.c_str(), gbkvalue, mapValue.length());
			res_Mes[mapKey] = mapValue;
			//qDebug() << mapKey << ":" << res_Mes[mapKey];
			char* gbkvalue = new char[mapValue.length()];
			string sgbkvalue = gbkvalue;

			//classname换为gbk
			/*
			if (mapKey == "classname")
			{
			res_Mes[mapKey] = sgbkvalue;
			cout << (sgbkvalue == "15网工") << endl;
			cout << (sgbkvalue == "123") << endl;
			}
			*/
			temp = "";
		}
		else
		{
			temp += str[i];
		}
	}
	if (res_Mes["mode"] == "login")
	{
		if (res_Mes["message"] == "login success")
		{
			info["classname"] = res_Mes["classname"];
			info["name"] = res_Mes["name"];
			info["id"] = res_Mes["id"];
			if (info["character"] == "student")
			{
				ui.class_label->setText(QString::fromLocal8Bit("班级：") + info["classname"]);
				ui.id_label->setText(QString::fromLocal8Bit("学号：") + info["id"]);
			}
			if (res_Mes["signinStatus"] == "not open")
			{
				camopen = false;
				issignin = false;
			}
			else if (res_Mes["signinStatus"] == "has not sign in")
			{
				camopen = true;
				issignin = false;
			}
			else if (res_Mes["signinStatus"] == "has sign in")
			{
				camopen = false;
				issignin = true;
			}
		}
		emit sendlogin(res_Mes["message"]);
	}
	else if (res_Mes["mode"] == "stu_query")
	{
		QString dates = res_Mes["stu_query_signin"];
		QString temp = "";
		QMap<QString, QString> query_dates;
		while (dates.indexOf(" ") != -1)
		{
			temp = dates.mid(0, dates.indexOf(" "));
			int indexofsplit = temp.indexOf("|");
			QString tempdate = temp.mid(0, indexofsplit);
			QString tempnum = temp.mid(indexofsplit + 1);
			if (tempnum == "1")
			{
				tempnum = "Yes";
			}
			else
			{
				tempnum = "No";
			}
			query_dates[tempdate] = tempnum;
			dates = dates.mid(dates.indexOf(" ") + 1);
		}
		QMap<QString, QString>::iterator it = query_dates.begin();
		int cnt = 0;
		while (it != query_dates.end())
		{
			qDebug() << it.key() << it.value();
			int RowCont;
			RowCont = ui.query_table->rowCount();
			ui.query_table->insertRow(RowCont);
			ui.query_table->setItem(RowCont, 0, new QTableWidgetItem(it.key()));
			ui.query_table->setItem(RowCont, 1, new QTableWidgetItem(it.value()));
			ui.query_table->item(cnt, 0)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
			ui.query_table->item(cnt, 1)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
			//ui.query_table->item(cnt, 2)->setTextAlignment(Qt::AlignVCenter);
			cnt++;
			it++;
		}
	}
	else if (res_Mes["mode"] == "teacher_query")
	{
		QString totalcnt = QString::fromLocal8Bit("应签次数:") + res_Mes["totalcount"] + "\n";
		QString cnt = QString::fromLocal8Bit("实际签到次数:") + res_Mes["signincount"] + "\n";
		QMessageBox::information(NULL, QString::fromLocal8Bit("查询结果"), totalcnt + cnt);
	}
	else if (res_Mes["mode"] == "man_signin")
	{
		QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("人工签到完成！"));
	}
	else if (res_Mes["mode"] == "broadcast")
	{
		ui.textEdit->setText(res_Mes["broadcastMes"]);
	}
	else if (res_Mes["mode"] == "normal_signin")
	{
		if (info["character"] == "student")
		{
			if (res_Mes["signinStatus"] == "has not sign in")
			{
				camopen = true;
				issignin = false;
				QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("签到开始！"));
			}
			else if (res_Mes["signinStatus"] == "has sign in")
			{
				camopen = false;
				issignin = true;
				QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("签到开始！你已签到！"));
			}
			if (issignin == false)
			{
				opencamera();
			}
		}
		else
		{
			QString signs = res_Mes["stu_signin_status"];
			QString temp = "";
			QMap<QString, QString> signin_maps;
			while (signs.indexOf(" ") != -1)
			{
				temp = signs.mid(0, signs.indexOf(" "));
				int indexofsplit = temp.indexOf("|");
				QString tempname = temp.mid(0, indexofsplit);
				QString tempnum = temp.mid(indexofsplit + 1);
				if (tempnum == "1")
				{
					tempnum = "Yes";
				}
				else
				{
					tempnum = "No";
				}
				signin_maps[tempname] = tempnum;
				signs = signs.mid(signs.indexOf(" ") + 1);
			}
			QMap<QString, QString>::iterator it = signin_maps.begin();
			int cnt = 0;
			while (it != signin_maps.end())
			{
				qDebug() << it.key() << it.value();
				int RowCont;
				RowCont = ui.signin_table->rowCount();
				ui.signin_table->insertRow(RowCont);
				ui.signin_table->setItem(RowCont, 0, new QTableWidgetItem(it.key()));
				ui.signin_table->setItem(RowCont, 1, new QTableWidgetItem(it.value()));
				ui.signin_table->item(cnt, 0)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
				ui.signin_table->item(cnt, 1)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
				//ui.query_table->item(cnt, 2)->setTextAlignment(Qt::AlignVCenter);
				cnt++;
				it++;
			}
		}


	}
	else if (res_Mes["mode"] == "dynamic_signin")
	{
		if (info["character"] == "student")
		{
			if (res_Mes["signinStatus"] == "has not sign in")
			{
				camopen = true;
				issignin = false;
				QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("动态签到开始！"));
			}
			else if (res_Mes["signinStatus"] == "has sign in")
			{
				camopen = false;
				issignin = true;
				QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("动态签到开始！你已签到！"));
			}
			if (issignin == false)
			{
				opencamera();
			}
		}
		else
		{
			QString signs = res_Mes["stu_signin_status"];
			QString temp = "";
			QMap<QString, QString> signin_maps;
			while (signs.indexOf(" ") != -1)
			{
				temp = signs.mid(0, signs.indexOf(" "));
				int indexofsplit = temp.indexOf("|");
				QString tempname = temp.mid(0, indexofsplit);
				QString tempnum = temp.mid(indexofsplit + 1);
				if (tempnum == "1")
				{
					tempnum = "Yes";
				}
				else
				{
					tempnum = "No";
				}
				signin_maps[tempname] = tempnum;
				signs = signs.mid(signs.indexOf(" ") + 1);
			}
			QMap<QString, QString>::iterator it = signin_maps.begin();
			int cnt = 0;
			while (it != signin_maps.end())
			{
				qDebug() << it.key() << it.value();
				int RowCont;
				RowCont = ui.signin_table->rowCount();
				ui.signin_table->insertRow(RowCont);
				ui.signin_table->setItem(RowCont, 0, new QTableWidgetItem(it.key()));
				ui.signin_table->setItem(RowCont, 1, new QTableWidgetItem(it.value()));
				ui.signin_table->item(cnt, 0)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
				ui.signin_table->item(cnt, 1)->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
				//ui.query_table->item(cnt, 2)->setTextAlignment(Qt::AlignVCenter);
				cnt++;
				it++;
			}
		}

	}
	else if (res_Mes["mode"] == "finish_signin")
	{
		camopen = false;
		cnt++;
		closecamera();
		QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("签到结束！"));
	}
	else if (res_Mes["mode"] == "sendPic")
	{
		if (info["character"] == "student")
		{
			if (res_Mes["stu_signin"] == "finish")
			{
				issignin = true;
				QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("签到成功！"));
				ui.capture_Button->setEnabled(false);
				ui.capture_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
				ui.recap_Button->setEnabled(false);
				ui.recap_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
				ui.upload_Button->setEnabled(false);
				ui.upload_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
				closecamera();
			}
			else
			{
				QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("签到失败！请重新拍摄并上传图片！"));
				ui.capture_Button->setEnabled(true);
				ui.capture_Button->setStyleSheet("QPushButton{color: black;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
				ui.recap_Button->setEnabled(false);
				ui.recap_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
				ui.upload_Button->setEnabled(false);
				ui.upload_Button->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
			}
		}
		else if (info["character"] == "teacher")
		{
			qDebug() << res_Mes["signinname"];
			int RowCont;
			RowCont = ui.signin_table->rowCount();
			for (int i = 0; i < RowCont; i++)
			{
				if (ui.signin_table->item(i, 0)->text() == res_Mes["signinname"])
				{
					ui.signin_table->item(i, 1)->setText("Yes");
				}
			}
		}
	}
}

void mode::closeConnect()
{
	qDebug() << "closeconnect()";
	sendLogoutMessage();
	tcpSocket->disconnectFromHost();
	tcpSocket->waitForDisconnected();
	tcpSocket->close();
}

//教师开启正常签到
void mode::normal_signin()
{
	QString send_mes = "mode:normal_signin\n";
	tcpSocket->write(send_mes.toStdString().c_str(), strlen(send_mes.toStdString().c_str()));
	ui.normal_signin->setEnabled(false);
	ui.normal_signin->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
}

//教师开启动态签到
void mode::dynamic_signin()
{
	QString send_mes = "mode:dynamic_signin\n";
	tcpSocket->write(send_mes.toStdString().c_str(), strlen(send_mes.toStdString().c_str()));
	ui.dynamic_signin->setEnabled(false);
	ui.dynamic_signin->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	ui.finish_signin->setEnabled(true);
	ui.finish_signin->setStyleSheet("QPushButton{color: black;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
}

//教师结束签到
void mode::finish_signin()
{
	ui.signin_table->setRowCount(0);
	ui.signin_table->clearContents();
	QString send_mes = "mode:finish_signin\n";
	tcpSocket->write(send_mes.toStdString().c_str(), strlen(send_mes.toStdString().c_str()));
	ui.finish_signin->setEnabled(false);
	if (cnt == 0)
	{
		ui.dynamic_signin->setEnabled(true);
		ui.dynamic_signin->setStyleSheet("QPushButton{color: black;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
		ui.normal_signin->setEnabled(false);
		ui.normal_signin->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	}
	else
	{
		ui.dynamic_signin->setEnabled(false);
		ui.dynamic_signin->setStyleSheet("QPushButton{color: grey;border:0.1em solid rgb(0, 0, 0);background-color: rgba(200, 200, 200,0);}");
	}
}

void mode::broadcast()
{
	QString send_mes = "mode:broadcast\n";
	QString broadMes = ui.broadcastText->toPlainText();
	send_mes += "broadcastMes:" + broadMes + "\n";
	tcpSocket->write(send_mes.toStdString().c_str(), strlen(send_mes.toStdString().c_str()));
}

//教师查询签到次数
void mode::teacher_query()
{
	QString send_mes = "mode:teacher_query\n";
	if (ui.query_id->text().isEmpty())
	{
		QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("请输入学号！"));
	}
	send_mes += "query_id:" + ui.query_id->text() + "\n";
	if (ui.tea_query_date1->date() < ui.tea_query_date2->date())
	{
		QString date1 = ui.tea_query_date1->date().toString("yyyy-MM-dd");
		QString date2 = ui.tea_query_date2->date().toString("yyyy-MM-dd");
		send_mes += "date1:" + date1 + "\n";
		send_mes += "date2:" + date2 + "\n";
		tcpSocket->write(send_mes.toStdString().c_str(), strlen(send_mes.toStdString().c_str()));
	}
	else
	{
		QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("日期错误，请重新输入！"));
	}

}

//人工签到
void mode::manSignin()
{
	QString send_mes = "mode:man_signin\n";
	if (ui.signin_id->text().isEmpty())
	{
		QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("请输入学号！"));
		return;
	}
	send_mes += "signin_id:" + ui.signin_id->text() + "\n";
	if (ui.signin_ratio->isChecked())
	{
		send_mes += "signin_status:signin\n";
	}
	else if (ui.absence_ratio->isChecked())
	{
		send_mes += "signin_status:absence\n";
	}
	else
	{
		QMessageBox::information(NULL, "Warning", QString::fromLocal8Bit("请选择签到状态！"));
		return;
	}
	tcpSocket->write(send_mes.toStdString().c_str(), strlen(send_mes.toStdString().c_str()));
}
/*
void mode::startThread()
{
socketThread *socketthread = new socketThread(this);
connect(socketthread, SIGNAL(resultReady(int)), this, SLOT(handleResults(int)));
// 线程结束后，自动销毁
connect(socketthread, SIGNAL(finished()), socketthread, SLOT(deleteLater()));
//socketthread->start();
connect(socketthread, SIGNAL(send()), this, SLOT(receiveMes()));
}
*/
