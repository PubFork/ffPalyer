/********************************************************************************
** Form generated from reading UI file 'controlbtn.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLBTN_H
#define UI_CONTROLBTN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlBtn
{
public:
    QPushButton *btnPlay;
    QPushButton *btnNext;
    QWidget *viewPlay;
    QPushButton *btnStop;
    QSlider *ctlSlider;
    QPushButton *btnPause;

    void setupUi(QWidget *ControlBtn)
    {
        if (ControlBtn->objectName().isEmpty())
            ControlBtn->setObjectName(QString::fromUtf8("ControlBtn"));
        ControlBtn->resize(590, 296);
        btnPlay = new QPushButton(ControlBtn);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        btnPlay->setGeometry(QRect(10, 260, 75, 23));
        btnNext = new QPushButton(ControlBtn);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        btnNext->setGeometry(QRect(100, 260, 75, 23));
        viewPlay = new QWidget(ControlBtn);
        viewPlay->setObjectName(QString::fromUtf8("viewPlay"));
        viewPlay->setGeometry(QRect(9, 9, 341, 201));
        btnStop = new QPushButton(ControlBtn);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setGeometry(QRect(180, 260, 75, 23));
        ctlSlider = new QSlider(ControlBtn);
        ctlSlider->setObjectName(QString::fromUtf8("ctlSlider"));
        ctlSlider->setGeometry(QRect(370, 260, 160, 19));
        ctlSlider->setMaximum(999);
        ctlSlider->setOrientation(Qt::Horizontal);
        btnPause = new QPushButton(ControlBtn);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setGeometry(QRect(270, 260, 75, 23));

        retranslateUi(ControlBtn);

        QMetaObject::connectSlotsByName(ControlBtn);
    } // setupUi

    void retranslateUi(QWidget *ControlBtn)
    {
        ControlBtn->setWindowTitle(QApplication::translate("ControlBtn", "ControlBtn", 0, QApplication::UnicodeUTF8));
        btnPlay->setText(QApplication::translate("ControlBtn", "Play1", 0, QApplication::UnicodeUTF8));
        btnNext->setText(QApplication::translate("ControlBtn", "Play2", 0, QApplication::UnicodeUTF8));
        btnStop->setText(QApplication::translate("ControlBtn", "Stop", 0, QApplication::UnicodeUTF8));
        btnPause->setText(QApplication::translate("ControlBtn", "Pause", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ControlBtn: public Ui_ControlBtn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLBTN_H
