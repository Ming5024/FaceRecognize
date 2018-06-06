/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label;
    QPushButton *login_2;
    QLineEdit *tea_class;
    QPushButton *exit;
    QLineEdit *stu_name;
    QLineEdit *tea_password;
    QRadioButton *stuRadio;
    QLineEdit *stu_class;
    QLabel *label_2;
    QLineEdit *tea_name;
    QRadioButton *teacherRadio;
    QLineEdit *stu_id;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QFrame *line;
    QLabel *label_3;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(512, 386);
        login->setStyleSheet(QStringLiteral("background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255))"));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 130, 41, 31));
        label->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        login_2 = new QPushButton(login);
        login_2->setObjectName(QStringLiteral("login_2"));
        login_2->setGeometry(QRect(110, 310, 93, 41));
        login_2->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);\n"
"border-style: outset;"));
        tea_class = new QLineEdit(login);
        tea_class->setObjectName(QStringLiteral("tea_class"));
        tea_class->setGeometry(QRect(330, 130, 101, 31));
        tea_class->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:2px solid rgb(200, 200, 200);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);"));
        exit = new QPushButton(login);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(310, 310, 93, 41));
        exit->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        stu_name = new QLineEdit(login);
        stu_name->setObjectName(QStringLiteral("stu_name"));
        stu_name->setGeometry(QRect(120, 230, 101, 31));
        stu_name->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:2px solid rgb(200, 200, 200);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);"));
        tea_password = new QLineEdit(login);
        tea_password->setObjectName(QStringLiteral("tea_password"));
        tea_password->setGeometry(QRect(330, 230, 101, 31));
        tea_password->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:2px solid rgb(200, 200, 200);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);"));
        stuRadio = new QRadioButton(login);
        stuRadio->setObjectName(QStringLiteral("stuRadio"));
        stuRadio->setGeometry(QRect(100, 70, 101, 31));
        stuRadio->setStyleSheet(QLatin1String("font-size:15px;\n"
"color:rgb(255, 255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);\n"
""));
        stu_class = new QLineEdit(login);
        stu_class->setObjectName(QStringLiteral("stu_class"));
        stu_class->setGeometry(QRect(120, 130, 101, 31));
        stu_class->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:2px solid rgb(200, 200, 200);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 180, 41, 31));
        label_2->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        tea_name = new QLineEdit(login);
        tea_name->setObjectName(QStringLiteral("tea_name"));
        tea_name->setGeometry(QRect(330, 180, 101, 31));
        tea_name->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:2px solid rgb(200, 200, 200);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);"));
        teacherRadio = new QRadioButton(login);
        teacherRadio->setObjectName(QStringLiteral("teacherRadio"));
        teacherRadio->setGeometry(QRect(310, 70, 101, 31));
        teacherRadio->setStyleSheet(QLatin1String("font-size:15px;\n"
"color:rgb(255, 255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);\n"
""));
        stu_id = new QLineEdit(login);
        stu_id->setObjectName(QStringLiteral("stu_id"));
        stu_id->setGeometry(QRect(120, 180, 101, 31));
        stu_id->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:2px solid rgb(200, 200, 200);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(login);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(280, 130, 41, 31));
        label_4->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        label_6 = new QLabel(login);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(280, 180, 41, 31));
        label_6->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        label_5 = new QLabel(login);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(280, 230, 41, 31));
        label_5->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));
        line = new QFrame(login);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(240, 60, 20, 231));
        line->setStyleSheet(QLatin1String("color: rgb(255,255,255);\n"
"background-color: rgba(0%,0%,0%,30%);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 230, 41, 31));
        label_3->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);"));

        retranslateUi(login);
        QObject::connect(login_2, SIGNAL(clicked()), login, SLOT(sendmessage()));
        QObject::connect(exit, SIGNAL(clicked()), login, SLOT(returnConnect()));

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "login", 0));
        label->setText(QApplication::translate("login", "\347\217\255\347\272\247", 0));
        login_2->setText(QApplication::translate("login", "\347\231\273\345\275\225", 0));
        exit->setText(QApplication::translate("login", "\351\200\200\345\207\272", 0));
        stuRadio->setText(QApplication::translate("login", "\346\210\221\346\230\257\345\255\246\347\224\237", 0));
        label_2->setText(QApplication::translate("login", "\345\255\246\345\217\267", 0));
        teacherRadio->setText(QApplication::translate("login", "\346\210\221\346\230\257\346\225\231\345\270\210", 0));
        label_4->setText(QApplication::translate("login", "\347\217\255\347\272\247", 0));
        label_6->setText(QApplication::translate("login", "\345\247\223\345\220\215", 0));
        label_5->setText(QApplication::translate("login", "\345\257\206\347\240\201", 0));
        label_3->setText(QApplication::translate("login", "\345\247\223\345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
