/********************************************************************************
** Form generated from reading UI file 'ariang.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARIANG_H
#define UI_ARIANG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ariangClass
{
public:
    QWidget *centralWidget;
    QWebEngineView *webEngineView;

    void setupUi(QMainWindow *ariangClass)
    {
        if (ariangClass->objectName().isEmpty())
            ariangClass->setObjectName(QStringLiteral("ariangClass"));
        ariangClass->resize(1024, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ariang/Resources/tileicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ariangClass->setWindowIcon(icon);
        centralWidget = new QWidget(ariangClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        webEngineView = new QWebEngineView(centralWidget);
        webEngineView->setObjectName(QStringLiteral("webEngineView"));
        webEngineView->setGeometry(QRect(0, 0, 501, 311));
        webEngineView->setUrl(QUrl(QStringLiteral("qrc:/ariang/GeneratedFiles/AriaNg-0.5.0/index.html")));
        ariangClass->setCentralWidget(centralWidget);

        retranslateUi(ariangClass);

        QMetaObject::connectSlotsByName(ariangClass);
    } // setupUi

    void retranslateUi(QMainWindow *ariangClass)
    {
        ariangClass->setWindowTitle(QApplication::translate("ariangClass", "ariang_ctl", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ariangClass: public Ui_ariangClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARIANG_H
