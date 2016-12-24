/********************************************************************************
** Form generated from reading UI file 'myqtplayer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYQTPLAYER_H
#define UI_MYQTPLAYER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyQtPlayerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyQtPlayerClass)
    {
        if (MyQtPlayerClass->objectName().isEmpty())
            MyQtPlayerClass->setObjectName(QString::fromUtf8("MyQtPlayerClass"));
        MyQtPlayerClass->resize(600, 400);
        menuBar = new QMenuBar(MyQtPlayerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MyQtPlayerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyQtPlayerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MyQtPlayerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyQtPlayerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MyQtPlayerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyQtPlayerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MyQtPlayerClass->setStatusBar(statusBar);

        retranslateUi(MyQtPlayerClass);

        QMetaObject::connectSlotsByName(MyQtPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyQtPlayerClass)
    {
        MyQtPlayerClass->setWindowTitle(QApplication::translate("MyQtPlayerClass", "MyQtPlayer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MyQtPlayerClass: public Ui_MyQtPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQTPLAYER_H
