/********************************************************************************
** Form generated from reading UI file 'vxshipnavigation.ui'
**
** Created: Tue Oct 29 23:09:58 2013
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VXSHIPNAVIGATION_H
#define UI_VXSHIPNAVIGATION_H

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

class Ui_CVxDisplayToolBarClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CVxDisplayToolBarClass)
    {
        if (CVxDisplayToolBarClass->objectName().isEmpty())
            CVxDisplayToolBarClass->setObjectName(QString::fromUtf8("CVxDisplayToolBarClass"));
        CVxDisplayToolBarClass->resize(600, 400);
        menuBar = new QMenuBar(CVxDisplayToolBarClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        CVxDisplayToolBarClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CVxDisplayToolBarClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CVxDisplayToolBarClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(CVxDisplayToolBarClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CVxDisplayToolBarClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CVxDisplayToolBarClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CVxDisplayToolBarClass->setStatusBar(statusBar);

        retranslateUi(CVxDisplayToolBarClass);

        QMetaObject::connectSlotsByName(CVxDisplayToolBarClass);
    } // setupUi

    void retranslateUi(QMainWindow *CVxDisplayToolBarClass)
    {
        CVxDisplayToolBarClass->setWindowTitle(QApplication::translate("CVxDisplayToolBarClass", "CVxDisplayToolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CVxDisplayToolBarClass: public Ui_CVxDisplayToolBarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VXSHIPNAVIGATION_H
