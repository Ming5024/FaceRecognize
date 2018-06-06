/********************************************************************************
** Form generated from reading UI file 'mode.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_H
#define UI_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mode
{
public:
    QStackedWidget *stackedWidget;
    QWidget *student;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *class_label;
    QPushButton *recap_Button;
    QLabel *label;
    QPushButton *capture_Button;
    QLabel *id_label;
    QPushButton *upload_Button;
    QLabel *camlabel;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QPushButton *query_button;
    QTableWidget *query_table;
    QLabel *label_5;
    QDateEdit *query_date1;
    QDateEdit *query_date2;
    QWidget *teacher;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QTableWidget *signin_table;
    QPushButton *dynamic_signin;
    QPushButton *normal_signin;
    QTextEdit *broadcastText;
    QPushButton *finish_signin;
    QPushButton *pushButton_2;
    QWidget *tab_4;
    QLineEdit *query_id;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *tea_query;
    QDateEdit *tea_query_date1;
    QDateEdit *tea_query_date2;
    QWidget *tab_5;
    QLabel *label_9;
    QLineEdit *signin_id;
    QRadioButton *signin_ratio;
    QRadioButton *absence_ratio;
    QLabel *label_10;
    QPushButton *man_signin;

    void setupUi(QWidget *mode)
    {
        if (mode->objectName().isEmpty())
            mode->setObjectName(QStringLiteral("mode"));
        mode->resize(686, 561);
        mode->setStyleSheet(QStringLiteral("background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.761194 rgba(255, 255, 255, 255))"));
        stackedWidget = new QStackedWidget(mode);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 40, 691, 521));
        stackedWidget->setStyleSheet(QLatin1String("QStackedWidget{\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}"));
        student = new QWidget();
        student->setObjectName(QStringLiteral("student"));
        student->setStyleSheet(QStringLiteral(""));
        tabWidget = new QTabWidget(student);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 0, 691, 531));
        tabWidget->setSizeIncrement(QSize(0, 0));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setStyleSheet(QLatin1String("QTabBar::tab{ min-height: 80px; min-width:30px;border:2px solid rgb(0, 0, 0)}\n"
"QTabBar::tab:second{margin-bottom:5px}\n"
"QTabBar::tab:selected{background-color:rgb(255, 255, 255)}\n"
"QTabBar::tab:!selected{background-color:rgba(0, 0, 0,0)}\n"
"background-color:rgba(0,0,0,0)\n"
"\n"
""));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(20, 20));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setStyleSheet(QStringLiteral(""));
        class_label = new QLabel(tab);
        class_label->setObjectName(QStringLiteral("class_label"));
        class_label->setGeometry(QRect(30, 20, 111, 31));
        class_label->setStyleSheet(QLatin1String("color:rgb(255,255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        recap_Button = new QPushButton(tab);
        recap_Button->setObjectName(QStringLiteral("recap_Button"));
        recap_Button->setGeometry(QRect(220, 430, 91, 31));
        recap_Button->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 90, 161, 191));
        label->setStyleSheet(QLatin1String("color:rgb(255,255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        capture_Button = new QPushButton(tab);
        capture_Button->setObjectName(QStringLiteral("capture_Button"));
        capture_Button->setGeometry(QRect(370, 430, 91, 31));
        capture_Button->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        id_label = new QLabel(tab);
        id_label->setObjectName(QStringLiteral("id_label"));
        id_label->setGeometry(QRect(30, 50, 111, 31));
        id_label->setStyleSheet(QLatin1String("color:rgb(255,255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        upload_Button = new QPushButton(tab);
        upload_Button->setObjectName(QStringLiteral("upload_Button"));
        upload_Button->setGeometry(QRect(540, 430, 91, 31));
        upload_Button->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        camlabel = new QLabel(tab);
        camlabel->setObjectName(QStringLiteral("camlabel"));
        camlabel->setGeometry(QRect(210, 20, 421, 361));
        camlabel->setStyleSheet(QStringLiteral("background-color:black;"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 430, 93, 28));
        pushButton->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 320, 151, 61));
        textEdit->setStyleSheet(QLatin1String("color:rgb(255,255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(255, 255, 255,255);"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        query_button = new QPushButton(tab_2);
        query_button->setObjectName(QStringLiteral("query_button"));
        query_button->setGeometry(QRect(510, 60, 93, 28));
        query_button->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        query_table = new QTableWidget(tab_2);
        if (query_table->columnCount() < 2)
            query_table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        query_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        query_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        query_table->setObjectName(QStringLiteral("query_table"));
        query_table->setGeometry(QRect(120, 140, 406, 281));
        query_table->setStyleSheet(QLatin1String("color:rgb(79, 79, 79);\n"
"border-radius:5px;\n"
"background-color: white;"));
        query_table->horizontalHeader()->setDefaultSectionSize(180);
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(290, 65, 16, 21));
        label_5->setStyleSheet(QLatin1String("color:rgb(255,255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        query_date1 = new QDateEdit(tab_2);
        query_date1->setObjectName(QStringLiteral("query_date1"));
        query_date1->setGeometry(QRect(130, 60, 141, 31));
        query_date1->setStyleSheet(QLatin1String("color:rgb(0, 0, 127);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"border-radius:5px;\n"
"background-color: rgba(255, 255, 255,200);"));
        query_date1->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));
        query_date2 = new QDateEdit(tab_2);
        query_date2->setObjectName(QStringLiteral("query_date2"));
        query_date2->setGeometry(QRect(320, 60, 141, 31));
        query_date2->setStyleSheet(QLatin1String("color:rgb(0, 0, 127);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"border-radius:5px;\n"
"background-color: rgba(255, 255, 255,200);"));
        query_date2->setDateTime(QDateTime(QDate(2018, 12, 31), QTime(0, 0, 0)));
        tabWidget->addTab(tab_2, QString());
        stackedWidget->addWidget(student);
        teacher = new QWidget();
        teacher->setObjectName(QStringLiteral("teacher"));
        tabWidget_2 = new QTabWidget(teacher);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 711, 521));
        tabWidget_2->setStyleSheet(QLatin1String("QTabBar::tab{ min-height: 80px; min-width:30px;border:2px solid rgb(0, 0, 0)}\n"
"QTabBar::tab:second{margin-bottom:5px}\n"
"QTabBar::tab:selected{background-color:rgb(255, 255, 255)}\n"
"QTabBar::tab:!selected{background-color:rgba(0, 0, 0,0)}\n"
"background-color:rgba(0,0,0,0)\n"
"\n"
""));
        tabWidget_2->setTabPosition(QTabWidget::West);
        tabWidget_2->setTabShape(QTabWidget::Triangular);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        signin_table = new QTableWidget(tab_3);
        if (signin_table->columnCount() < 2)
            signin_table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        signin_table->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        signin_table->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        signin_table->setObjectName(QStringLiteral("signin_table"));
        signin_table->setGeometry(QRect(80, 150, 451, 201));
        signin_table->setStyleSheet(QLatin1String("color:rgb(79, 79, 79);\n"
"border-radius:5px;\n"
"background-color: white;"));
        signin_table->setLineWidth(4);
        signin_table->horizontalHeader()->setDefaultSectionSize(213);
        signin_table->horizontalHeader()->setMinimumSectionSize(36);
        signin_table->verticalHeader()->setDefaultSectionSize(39);
        signin_table->verticalHeader()->setMinimumSectionSize(34);
        dynamic_signin = new QPushButton(tab_3);
        dynamic_signin->setObjectName(QStringLiteral("dynamic_signin"));
        dynamic_signin->setGeometry(QRect(250, 390, 91, 41));
        dynamic_signin->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        normal_signin = new QPushButton(tab_3);
        normal_signin->setObjectName(QStringLiteral("normal_signin"));
        normal_signin->setGeometry(QRect(80, 390, 91, 41));
        normal_signin->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        broadcastText = new QTextEdit(tab_3);
        broadcastText->setObjectName(QStringLiteral("broadcastText"));
        broadcastText->setGeometry(QRect(80, 20, 351, 101));
        broadcastText->setStyleSheet(QLatin1String("color:rgb(255,255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(255, 255, 255,255);"));
        finish_signin = new QPushButton(tab_3);
        finish_signin->setObjectName(QStringLiteral("finish_signin"));
        finish_signin->setGeometry(QRect(430, 390, 91, 41));
        finish_signin->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(460, 50, 61, 31));
        pushButton_2->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        query_id = new QLineEdit(tab_4);
        query_id->setObjectName(QStringLiteral("query_id"));
        query_id->setGeometry(QRect(280, 80, 141, 41));
        query_id->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"border:2px solid rgb(200, 200, 200);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(210, 80, 51, 41));
        QFont font;
        font.setPointSize(12);
        label_6->setFont(font);
        label_6->setStyleSheet(QLatin1String("color:rgb(255,255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 160, 91, 41));
        label_7->setFont(font);
        label_7->setStyleSheet(QLatin1String("color:rgb(255,255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        label_8 = new QLabel(tab_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(190, 230, 91, 41));
        label_8->setFont(font);
        label_8->setStyleSheet(QLatin1String("color:rgb(255,255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        tea_query = new QPushButton(tab_4);
        tea_query->setObjectName(QStringLiteral("tea_query"));
        tea_query->setGeometry(QRect(280, 320, 91, 61));
        tea_query->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        tea_query_date1 = new QDateEdit(tab_4);
        tea_query_date1->setObjectName(QStringLiteral("tea_query_date1"));
        tea_query_date1->setGeometry(QRect(280, 160, 141, 41));
        tea_query_date1->setStyleSheet(QLatin1String("color:rgb(0, 0, 127);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"border-radius:5px;\n"
"background-color: rgba(255, 255, 255,200);"));
        tea_query_date1->setDateTime(QDateTime(QDate(2018, 1, 1), QTime(0, 0, 0)));
        tea_query_date2 = new QDateEdit(tab_4);
        tea_query_date2->setObjectName(QStringLiteral("tea_query_date2"));
        tea_query_date2->setGeometry(QRect(280, 230, 141, 41));
        tea_query_date2->setStyleSheet(QLatin1String("color:rgb(0, 0, 127);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"border-radius:5px;\n"
"background-color: rgba(255, 255, 255,200);"));
        tea_query_date2->setDateTime(QDateTime(QDate(2018, 12, 31), QTime(0, 0, 0)));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 110, 51, 41));
        label_9->setFont(font);
        label_9->setStyleSheet(QLatin1String("color:rgb(255,255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        signin_id = new QLineEdit(tab_5);
        signin_id->setObjectName(QStringLiteral("signin_id"));
        signin_id->setGeometry(QRect(250, 110, 171, 41));
        signin_id->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"border:2px solid rgb(200, 200, 200);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);"));
        signin_ratio = new QRadioButton(tab_5);
        signin_ratio->setObjectName(QStringLiteral("signin_ratio"));
        signin_ratio->setGeometry(QRect(290, 210, 71, 41));
        QFont font1;
        signin_ratio->setFont(font1);
        signin_ratio->setStyleSheet(QLatin1String("font-size:20px;\n"
"color:rgb(255, 255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);\n"
""));
        absence_ratio = new QRadioButton(tab_5);
        absence_ratio->setObjectName(QStringLiteral("absence_ratio"));
        absence_ratio->setGeometry(QRect(390, 210, 71, 41));
        absence_ratio->setFont(font1);
        absence_ratio->setStyleSheet(QLatin1String("font-size:20px;\n"
"color:rgb(255, 255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);\n"
""));
        label_10 = new QLabel(tab_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(190, 210, 101, 41));
        label_10->setFont(font);
        label_10->setStyleSheet(QLatin1String("color:rgb(255,255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        man_signin = new QPushButton(tab_5);
        man_signin->setObjectName(QStringLiteral("man_signin"));
        man_signin->setGeometry(QRect(270, 290, 91, 61));
        man_signin->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        tabWidget_2->addTab(tab_5, QString());
        stackedWidget->addWidget(teacher);

        retranslateUi(mode);
        QObject::connect(pushButton, SIGNAL(clicked()), mode, SLOT(exit()));
        QObject::connect(recap_Button, SIGNAL(clicked()), mode, SLOT(recap()));
        QObject::connect(capture_Button, SIGNAL(clicked()), mode, SLOT(capture()));
        QObject::connect(upload_Button, SIGNAL(clicked()), mode, SLOT(upload()));
        QObject::connect(query_button, SIGNAL(clicked()), mode, SLOT(query()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), mode, SLOT(broadcast()));
        QObject::connect(normal_signin, SIGNAL(clicked()), mode, SLOT(normal_signin()));
        QObject::connect(dynamic_signin, SIGNAL(clicked()), mode, SLOT(dynamic_signin()));
        QObject::connect(finish_signin, SIGNAL(clicked()), mode, SLOT(finish_signin()));
        QObject::connect(tea_query, SIGNAL(clicked()), mode, SLOT(teacher_query()));
        QObject::connect(man_signin, SIGNAL(clicked()), mode, SLOT(manSignin()));

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mode);
    } // setupUi

    void retranslateUi(QWidget *mode)
    {
        mode->setWindowTitle(QApplication::translate("mode", "mode", 0));
        class_label->setText(QApplication::translate("mode", "\347\217\255\347\272\247\357\274\2321001", 0));
        recap_Button->setText(QApplication::translate("mode", "\351\207\215\346\213\215", 0));
        label->setText(QApplication::translate("mode", "\344\275\240\345\245\275\357\274\214\346\254\242\350\277\216\344\275\277\347\224\250\344\272\272\350\204\270\350\257\206\n"
"\345\210\253\347\255\276\345\210\260\347\263\273\347\273\237\345\217\263\344\276\247\345\214\272\345\237\237\345\260\206\n"
"\346\230\276\347\244\272\345\275\223\345\211\215\346\221\204\345\203\217\345\244\264\346\213\215\346\221\204\345\210\260\n"
"\347\232\204\347\224\273\351\235\242\357\274\214\350\257\267\347\202\271\345\207\273\346\213\215\347\205\247\346\214\211\n"
"\351\222\256\350\277\233\350\241\214\346\213\215\346\221\204\343\200\202\347\241\256\350\256\244\346\227\240\350\257\257\n"
"\345\220\216\350\257\267\347\202\271\345\207\273\344\270\212\344\274\240\346\214\211\351\222\256\350\277\233\350\241\214\n"
"\344\270\212\344\274\240\357\274\214\345\271\266\347\255\211\345\276\205\346\234\215\345\212\241\345\231\250\350\277\224\n"
"\345\233\236\347\273\223\346\236\234\343\200\202\n"
"\345\246\202\346\236\234\345\257\271\346\213\215\346\221\204\347\273\223\346\236\234\344\270\215\346"
                        "\273\241\346\204\217\357\274\214\n"
"\345\217\257\344\273\245\347\202\271\345\207\273\351\207\215\346\213\215\346\214\211\351\222\256\350\277\233\350\241\214\n"
"\351\207\215\346\226\260\346\213\215\346\221\204\343\200\202", 0));
        capture_Button->setText(QApplication::translate("mode", "\346\213\215\347\205\247", 0));
        id_label->setText(QApplication::translate("mode", "\345\255\246\345\217\267\357\274\232153300xx", 0));
        upload_Button->setText(QApplication::translate("mode", "\344\270\212\344\274\240", 0));
        camlabel->setText(QString());
        pushButton->setText(QApplication::translate("mode", "exit", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("mode", "\347\255\276\345\210\260", 0));
        query_button->setText(QApplication::translate("mode", "\346\237\245\350\257\242", 0));
        QTableWidgetItem *___qtablewidgetitem = query_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("mode", "\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem1 = query_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("mode", "\346\230\257\345\220\246\347\255\276\345\210\260", 0));
        label_5->setText(QApplication::translate("mode", "-", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("mode", "\346\237\245\350\257\242", 0));
        QTableWidgetItem *___qtablewidgetitem2 = signin_table->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("mode", "\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem3 = signin_table->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("mode", "\347\255\276\345\210\260\346\203\205\345\206\265", 0));
        dynamic_signin->setText(QApplication::translate("mode", "\345\212\250\346\200\201\347\255\276\345\210\260", 0));
        normal_signin->setText(QApplication::translate("mode", "\350\257\276\345\211\215\347\255\276\345\210\260", 0));
        finish_signin->setText(QApplication::translate("mode", "\347\273\223\346\235\237\347\255\276\345\210\260", 0));
        pushButton_2->setText(QApplication::translate("mode", "\345\217\221\351\200\201", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("mode", "\347\255\276\345\210\260\347\225\214\351\235\242", 0));
        label_6->setText(QApplication::translate("mode", "\345\255\246\345\217\267\357\274\232", 0));
        label_7->setText(QApplication::translate("mode", "\350\265\267\345\247\213\346\227\245\346\234\237\357\274\232", 0));
        label_8->setText(QApplication::translate("mode", "\347\273\223\346\235\237\346\227\245\346\234\237\357\274\232", 0));
        tea_query->setText(QApplication::translate("mode", "\346\237\245\350\257\242", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("mode", "\346\237\245\350\257\242", 0));
        label_9->setText(QApplication::translate("mode", "\345\255\246\345\217\267\357\274\232", 0));
        signin_ratio->setText(QApplication::translate("mode", "\347\255\276\345\210\260", 0));
        absence_ratio->setText(QApplication::translate("mode", "\347\274\272\345\270\255", 0));
        label_10->setText(QApplication::translate("mode", "\347\255\276\345\210\260\346\203\205\345\206\265\357\274\232", 0));
        man_signin->setText(QApplication::translate("mode", "\346\217\220\344\272\244", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("mode", "\344\272\272\345\267\245\347\255\276\345\210\260", 0));
    } // retranslateUi

};

namespace Ui {
    class mode: public Ui_mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_H
