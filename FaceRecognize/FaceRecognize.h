#pragma once

#include <QtWidgets/QWidget>
#include "ui_FaceRecognize.h"	
#include "login.h"
#include "BaseWindow.h"

//class FaceRecognize : public QWidget
class FaceRecognize : public BaseWindow
{
	Q_OBJECT

public:
	FaceRecognize(QWidget *parent = Q_NULLPTR);
	bool isshow;

private:
	Ui::FaceRecognizeClass ui;
	login* loginWin = new login;

	void loadStyleSheet(const QString &sheetName);

private slots:
	void openlogin();
};
