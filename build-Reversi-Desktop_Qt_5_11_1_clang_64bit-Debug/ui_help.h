/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_help
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *help)
    {
        if (help->objectName().isEmpty())
            help->setObjectName(QStringLiteral("help"));
        help->resize(380, 375);
        widget = new QWidget(help);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(36, 40, 293, 301));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(188, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(help);
        QObject::connect(pushButton, SIGNAL(clicked()), help, SLOT(close()));

        QMetaObject::connectSlotsByName(help);
    } // setupUi

    void retranslateUi(QDialog *help)
    {
        help->setWindowTitle(QApplication::translate("help", "Dialog", nullptr));
        textBrowser->setHtml(QApplication::translate("help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:20pt; font-weight:600;\">\351\273\221\347\231\275\346\243\213(Reversi)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:12pt; font-weight:600;\">\346\270\270\346\210\217\350\247\204\345\210\231</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'SimSun'; font-size"
                        ":12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'sans-serif'; font-size:12pt; color:#000000; background-color:#ffffff;\">1.\345\274\200\345\261\200\357\274\232\351\200\232\345\270\270</span><a href=\"https://zh.wikipedia.org/wiki/%E9%BB%91\"><span style=\" font-family:'sans-serif'; font-size:12pt; text-decoration: underline; color:#000000; background-color:#ffffff;\">\351\273\221</span></a><span style=\" font-family:'sans-serif'; font-size:12pt; color:#000000; background-color:#ffffff;\">\345\255\220\345\205\210\350\241\214\343\200\202\345\217\214\346\226\271\350\275\256\346\265\201\350\220\275\345\255\220\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'sans-serif'; font-size:12pt; color:#000000; background-color:#ffffff;\">2.\350\220\275\345\255\220\357\274\232\345"
                        "\217\252\350\246\201\350\220\275\345\255\220\345\222\214\346\243\213\347\233\230\344\270\212\344\273\273\344\270\200\346\236\232\345\267\261\346\226\271\347\232\204\346\243\213\345\255\220\345\234\250\344\270\200\346\235\241\347\272\277\344\270\212\357\274\210\346\250\252\343\200\201\347\233\264\343\200\201\346\226\234\347\272\277\347\232\206\345\217\257\357\274\211\345\244\271\347\235\200\345\257\271\346\226\271\346\243\213\345\255\220\357\274\214\345\260\261\350\203\275\345\260\206\345\257\271\346\226\271\347\232\204\350\277\231\344\272\233\346\243\213\345\255\220\350\275\254\345\217\230\344\270\272\346\210\221\345\267\261\346\226\271\357\274\210\347\277\273\351\235\242\345\215\263\345\217\257\357\274\211\343\200\202\345\246\202\346\236\234\345\234\250\344\273\273\344\270\200\344\275\215\347\275\256\350\220\275\345\255\220\351\203\275\344\270\215\350\203\275\345\244\271\344\275\217\345\257\271\346\211\213\347\232\204\344\273\273\344\270\200\351\242\227\346\243\213\345\255\220\357\274\214\345\260\261\350\246\201"
                        "\350\256\251\345\257\271\346\211\213\344\270\213\345\255\220\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'sans-serif'; font-size:12pt; color:#000000; background-color:#ffffff;\">3.\350\203\234\350\264\237\357\274\232\345\275\223\345\217\214\346\226\271\347\232\206\344\270\215\350\203\275\344\270\213\345\255\220\346\227\266\357\274\214\346\270\270\346\210\217\345\260\261\347\273\223\346\235\237\357\274\214\345\255\220\345\244\232\347\232\204\344\270\200\346\226\271\350\203\234\343\200\202</span></p></body></html>", nullptr));
        pushButton->setText(QApplication::translate("help", "\346\210\221\347\237\245\351\201\223\344\272\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class help: public Ui_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
