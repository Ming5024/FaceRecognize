/********************************************************************************
** Form generated from reading UI file 'FaceRecognize.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACERECOGNIZE_H
#define UI_FACERECOGNIZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceRecognizeClass
{
public:
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *connectIP;

    void setupUi(QWidget *FaceRecognizeClass)
    {
        if (FaceRecognizeClass->objectName().isEmpty())
            FaceRecognizeClass->setObjectName(QStringLiteral("FaceRecognizeClass"));
        FaceRecognizeClass->resize(367, 240);
        FaceRecognizeClass->setStyleSheet(QStringLiteral("background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255))"));
        label_2 = new QLabel(FaceRecognizeClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 50, 261, 51));
        label_2->setSizeIncrement(QSize(0, 3));
        label_2->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"/*border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;*/\n"
"background-color: rgba(32, 125, 255,0);\n"
""));
        label_2->setLineWidth(5);
        pushButton = new QPushButton(FaceRecognizeClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(112, 180, 111, 41));
        pushButton->setStyleSheet(QLatin1String("color:rgb(0, 0, 0);\n"
"border:0.1em solid rgb(0, 0, 0);\n"
"/*\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(200, 200, 200,0);"));
        label = new QLabel(FaceRecognizeClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 120, 51, 31));
        label->setStyleSheet(QLatin1String("color:rgb(255, 255, 255);\n"
"/*\n"
"border:0.1em solid rgb(158, 149, 255);\n"
"border-radius:5px;\n"
"*/\n"
"background-color: rgba(32, 125, 255,0);\n"
""));
        connectIP = new QLineEdit(FaceRecognizeClass);
        connectIP->setObjectName(QStringLiteral("connectIP"));
        connectIP->setGeometry(QRect(130, 120, 151, 31));
        connectIP->setStyleSheet(QLatin1String("color:rgb(79, 79, 79);\n"
"border:0.1em solid rgb(180, 180, 180);\n"
"border-radius:5px;\n"
"background-color:white;"));

        retranslateUi(FaceRecognizeClass);
        QObject::connect(pushButton, SIGNAL(clicked()), FaceRecognizeClass, SLOT(openlogin()));

        QMetaObject::connectSlotsByName(FaceRecognizeClass);
    } // setupUi

    void retranslateUi(QWidget *FaceRecognizeClass)
    {
        FaceRecognizeClass->setWindowTitle(QApplication::translate("FaceRecognizeClass", "FaceRecognize", 0));
        label_2->setText(QApplication::translate("FaceRecognizeClass", "\346\254\242\350\277\216\344\275\277\347\224\250\350\257\245\344\272\272\350\204\270\350\257\206\345\210\253\347\263\273\347\273\237\357\274\214\350\257\267\345\234\250\344\270\213\346\226\271\350\276\223\n"
"\345\205\245\346\241\206\350\276\223\345\205\245\344\275\240\346\203\263\350\246\201\350\277\233\350\241\214\350\277\236\346\216\245\347\232\204\346\234\215\345\212\241\345\231\250\347\232\204IP\n"
"\345\234\260\345\235\200\345\271\266\347\202\271\345\207\273\346\214\211\351\222\256\350\277\233\350\241\214\350\277\236\346\216\245\343\200\202", 0));
        pushButton->setText(QApplication::translate("FaceRecognizeClass", "\350\277\236\346\216\245", 0));
        label->setText(QApplication::translate("FaceRecognizeClass", "IP\345\234\260\345\235\200", 0));
        connectIP->setText(QApplication::translate("FaceRecognizeClass", "172.18.157.216", 0));
    } // retranslateUi

};

namespace Ui {
    class FaceRecognizeClass: public Ui_FaceRecognizeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACERECOGNIZE_H
