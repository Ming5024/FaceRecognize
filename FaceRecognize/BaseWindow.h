#pragma once

#include "MyTitleBar.h"
#include <Qwidget>

class BaseWindow : public QWidget
{
	Q_OBJECT

public:
	BaseWindow(QWidget *parent);
	~BaseWindow();

private:
	void initTitleBar();
	void paintEvent(QPaintEvent *event);
	void loadStyleSheet(const QString &sheetName);

private slots:
	void onButtonMinClicked();
	void onButtonRestoreClicked();
	void onButtonMaxClicked();
	void onButtonCloseClicked();

protected:
	MyTitleBar* m_titleBar;
};
