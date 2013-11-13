/********************************************************************************
** Form generated from reading UI file 'ckinectread.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CKINECTREAD_H
#define UI_CKINECTREAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CKinectReadClass
{
public:
    QAction *actionRecord;
    QAction *actionStop;
    QWidget *centralWidget;
    QGraphicsView *userView;
    QLabel *Grade;
    QPushButton *stop;
    QPushButton *start;
    QScrollArea *Advices;
    QWidget *scrollAreaWidgetContents;
    QGraphicsView *OpenGLView;
    QMenuBar *menuBar;
    QMenu *menuStart;
    QMenu *menuAbout_us;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CKinectReadClass)
    {
        if (CKinectReadClass->objectName().isEmpty())
            CKinectReadClass->setObjectName(QString::fromUtf8("CKinectReadClass"));
        CKinectReadClass->resize(885, 627);
        actionRecord = new QAction(CKinectReadClass);
        actionRecord->setObjectName(QString::fromUtf8("actionRecord"));
        actionStop = new QAction(CKinectReadClass);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        centralWidget = new QWidget(CKinectReadClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        userView = new QGraphicsView(centralWidget);
        userView->setObjectName(QString::fromUtf8("userView"));
        userView->setGeometry(QRect(340, 0, 531, 411));
        Grade = new QLabel(centralWidget);
        Grade->setObjectName(QString::fromUtf8("Grade"));
        Grade->setGeometry(QRect(340, 440, 541, 71));
        stop = new QPushButton(centralWidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(20, 520, 75, 23));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(160, 520, 75, 23));
        Advices = new QScrollArea(centralWidget);
        Advices->setObjectName(QString::fromUtf8("Advices"));
        Advices->setGeometry(QRect(0, 430, 311, 80));
        Advices->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 309, 78));
        Advices->setWidget(scrollAreaWidgetContents);
        OpenGLView = new QGraphicsView(centralWidget);
        OpenGLView->setObjectName(QString::fromUtf8("OpenGLView"));
        OpenGLView->setGeometry(QRect(0, 0, 300, 400));
        CKinectReadClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CKinectReadClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 885, 23));
        menuStart = new QMenu(menuBar);
        menuStart->setObjectName(QString::fromUtf8("menuStart"));
        menuAbout_us = new QMenu(menuBar);
        menuAbout_us->setObjectName(QString::fromUtf8("menuAbout_us"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        CKinectReadClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CKinectReadClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CKinectReadClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CKinectReadClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CKinectReadClass->setStatusBar(statusBar);

        menuBar->addAction(menuStart->menuAction());
        menuBar->addAction(menuAbout_us->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuStart->addAction(actionRecord);
        menuStart->addAction(actionStop);
        menuStart->addSeparator();

        retranslateUi(CKinectReadClass);

        QMetaObject::connectSlotsByName(CKinectReadClass);
    } // setupUi

    void retranslateUi(QMainWindow *CKinectReadClass)
    {
        CKinectReadClass->setWindowTitle(QApplication::translate("CKinectReadClass", "CKinectRead", 0, QApplication::UnicodeUTF8));
        actionRecord->setText(QApplication::translate("CKinectReadClass", "Record", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("CKinectReadClass", "Stop", 0, QApplication::UnicodeUTF8));
        Grade->setText(QApplication::translate("CKinectReadClass", "Display the users' grade", 0, QApplication::UnicodeUTF8));
        stop->setText(QApplication::translate("CKinectReadClass", "Stop", 0, QApplication::UnicodeUTF8));
        start->setText(QApplication::translate("CKinectReadClass", "Start", 0, QApplication::UnicodeUTF8));
        menuStart->setTitle(QApplication::translate("CKinectReadClass", "Start", 0, QApplication::UnicodeUTF8));
        menuAbout_us->setTitle(QApplication::translate("CKinectReadClass", "About us", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("CKinectReadClass", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CKinectReadClass: public Ui_CKinectReadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CKINECTREAD_H
