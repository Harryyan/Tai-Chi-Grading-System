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
    QAction *grade;
    QAction *exit;
    QWidget *centralWidget;
    QGraphicsView *userView;
    QLabel *Grade;
    QPushButton *stop;
    QPushButton *start;
    QScrollArea *Advices;
    QWidget *scrollAreaWidgetContents;
    QGraphicsView *OpenGLView;
    QPushButton *breakpoint;
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
        CKinectReadClass->resize(999, 689);
        grade = new QAction(CKinectReadClass);
        grade->setObjectName(QString::fromUtf8("grade"));
        exit = new QAction(CKinectReadClass);
        exit->setObjectName(QString::fromUtf8("exit"));
        centralWidget = new QWidget(CKinectReadClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        userView = new QGraphicsView(centralWidget);
        userView->setObjectName(QString::fromUtf8("userView"));
        userView->setGeometry(QRect(340, 0, 651, 481));
        Grade = new QLabel(centralWidget);
        Grade->setObjectName(QString::fromUtf8("Grade"));
        Grade->setGeometry(QRect(343, 500, 841, 101));
        stop = new QPushButton(centralWidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(3, 610, 75, 23));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(228, 610, 75, 23));
        Advices = new QScrollArea(centralWidget);
        Advices->setObjectName(QString::fromUtf8("Advices"));
        Advices->setGeometry(QRect(2, 500, 331, 80));
        Advices->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 329, 78));
        Advices->setWidget(scrollAreaWidgetContents);
        OpenGLView = new QGraphicsView(centralWidget);
        OpenGLView->setObjectName(QString::fromUtf8("OpenGLView"));
        OpenGLView->setGeometry(QRect(1, -1, 331, 481));
        breakpoint = new QPushButton(centralWidget);
        breakpoint->setObjectName(QString::fromUtf8("breakpoint"));
        breakpoint->setGeometry(QRect(113, 610, 75, 23));
        CKinectReadClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CKinectReadClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 999, 23));
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
        menuStart->addAction(grade);
        menuStart->addAction(exit);
        menuStart->addSeparator();

        retranslateUi(CKinectReadClass);
        QObject::connect(start, SIGNAL(clicked()), CKinectReadClass, SLOT(startRecord()));
        QObject::connect(stop, SIGNAL(clicked()), CKinectReadClass, SLOT(stopRecord()));
        QObject::connect(breakpoint, SIGNAL(pressed()), CKinectReadClass, SLOT(insert()));
        QObject::connect(grade, SIGNAL(triggered()), CKinectReadClass, SLOT(showGrade()));
        QObject::connect(exit, SIGNAL(triggered()), CKinectReadClass, SLOT(close()));

        QMetaObject::connectSlotsByName(CKinectReadClass);
    } // setupUi

    void retranslateUi(QMainWindow *CKinectReadClass)
    {
        CKinectReadClass->setWindowTitle(QApplication::translate("CKinectReadClass", "CKinectRead", 0, QApplication::UnicodeUTF8));
        grade->setText(QApplication::translate("CKinectReadClass", "Show Grade", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("CKinectReadClass", "Exit", 0, QApplication::UnicodeUTF8));
        Grade->setText(QApplication::translate("CKinectReadClass", "Display the users' grade", 0, QApplication::UnicodeUTF8));
        stop->setText(QApplication::translate("CKinectReadClass", "Stop", 0, QApplication::UnicodeUTF8));
        start->setText(QApplication::translate("CKinectReadClass", "Start", 0, QApplication::UnicodeUTF8));
        breakpoint->setText(QApplication::translate("CKinectReadClass", "Insert", 0, QApplication::UnicodeUTF8));
        menuStart->setTitle(QApplication::translate("CKinectReadClass", "Grading", 0, QApplication::UnicodeUTF8));
        menuAbout_us->setTitle(QApplication::translate("CKinectReadClass", "About us", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("CKinectReadClass", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CKinectReadClass: public Ui_CKinectReadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CKINECTREAD_H
