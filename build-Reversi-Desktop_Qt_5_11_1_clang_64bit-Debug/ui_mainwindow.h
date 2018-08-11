/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart;
    QAction *actionRegret;
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionAbout_us;
    QWidget *centralwidget;
    QLCDNumber *blackCount;
    QLCDNumber *whiteCount;
    QLabel *black;
    QLabel *white;
    QMenuBar *menubar;
    QMenu *menuGame;
    QMenu *menuMore;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionRegret = new QAction(MainWindow);
        actionRegret->setObjectName(QStringLiteral("actionRegret"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout_us = new QAction(MainWindow);
        actionAbout_us->setObjectName(QStringLiteral("actionAbout_us"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        blackCount = new QLCDNumber(centralwidget);
        blackCount->setObjectName(QStringLiteral("blackCount"));
        blackCount->setGeometry(QRect(490, 240, 91, 71));
        whiteCount = new QLCDNumber(centralwidget);
        whiteCount->setObjectName(QStringLiteral("whiteCount"));
        whiteCount->setGeometry(QRect(630, 250, 91, 61));
        black = new QLabel(centralwidget);
        black->setObjectName(QStringLiteral("black"));
        black->setGeometry(QRect(480, 100, 111, 121));
        black->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/black.jpg")));
        white = new QLabel(centralwidget);
        white->setObjectName(QStringLiteral("white"));
        white->setGeometry(QRect(620, 110, 111, 111));
        white->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/white.jpg")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuGame = new QMenu(menubar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        menuMore = new QMenu(menubar);
        menuMore->setObjectName(QStringLiteral("menuMore"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuGame->menuAction());
        menubar->addAction(menuMore->menuAction());
        menuGame->addAction(actionStart);
        menuGame->addAction(actionRegret);
        menuGame->addAction(actionExit);
        menuMore->addAction(actionHelp);
        menuMore->addAction(actionAbout_us);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionStart->setText(QApplication::translate("MainWindow", "Start", nullptr));
        actionRegret->setText(QApplication::translate("MainWindow", "Regret", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", nullptr));
        actionAbout_us->setText(QApplication::translate("MainWindow", "About us", nullptr));
        black->setText(QString());
        white->setText(QString());
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", nullptr));
        menuMore->setTitle(QApplication::translate("MainWindow", "More", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
