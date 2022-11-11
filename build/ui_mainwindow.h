/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QListView *listView;
    QPushButton *pushButton_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *le_err;
    QLineEdit *le_bat;
    QLabel *label_3;
    QPushButton *btn_x;
    QPushButton *btn_mx;
    QPushButton *btn_y;
    QPushButton *btn_my;
    QPushButton *btn_th;
    QPushButton *btn_mth;
    QLineEdit *robotx;
    QLineEdit *roboty;
    QLineEdit *robotth;
    QPushButton *btn_Ready;
    QPushButton *btn_Moving;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(489, 344);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 20, 113, 25));
        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setGeometry(QRect(40, 60, 111, 261));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 120, 121, 51));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 20, 141, 89));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        le_err = new QLineEdit(layoutWidget);
        le_err->setObjectName(QString::fromUtf8("le_err"));

        gridLayout->addWidget(le_err, 1, 1, 1, 1);

        le_bat = new QLineEdit(layoutWidget);
        le_bat->setObjectName(QString::fromUtf8("le_bat"));

        gridLayout->addWidget(le_bat, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        btn_x = new QPushButton(centralwidget);
        btn_x->setObjectName(QString::fromUtf8("btn_x"));
        btn_x->setGeometry(QRect(240, 190, 51, 51));
        btn_mx = new QPushButton(centralwidget);
        btn_mx->setObjectName(QString::fromUtf8("btn_mx"));
        btn_mx->setGeometry(QRect(240, 250, 51, 51));
        btn_y = new QPushButton(centralwidget);
        btn_y->setObjectName(QString::fromUtf8("btn_y"));
        btn_y->setGeometry(QRect(180, 250, 51, 51));
        btn_my = new QPushButton(centralwidget);
        btn_my->setObjectName(QString::fromUtf8("btn_my"));
        btn_my->setGeometry(QRect(300, 250, 51, 51));
        btn_th = new QPushButton(centralwidget);
        btn_th->setObjectName(QString::fromUtf8("btn_th"));
        btn_th->setGeometry(QRect(180, 190, 51, 51));
        btn_mth = new QPushButton(centralwidget);
        btn_mth->setObjectName(QString::fromUtf8("btn_mth"));
        btn_mth->setGeometry(QRect(300, 190, 51, 51));
        robotx = new QLineEdit(centralwidget);
        robotx->setObjectName(QString::fromUtf8("robotx"));
        robotx->setGeometry(QRect(360, 200, 113, 25));
        roboty = new QLineEdit(centralwidget);
        roboty->setObjectName(QString::fromUtf8("roboty"));
        roboty->setGeometry(QRect(360, 230, 113, 25));
        robotth = new QLineEdit(centralwidget);
        robotth->setObjectName(QString::fromUtf8("robotth"));
        robotth->setGeometry(QRect(360, 260, 113, 25));
        btn_Ready = new QPushButton(centralwidget);
        btn_Ready->setObjectName(QString::fromUtf8("btn_Ready"));
        btn_Ready->setGeometry(QRect(320, 30, 89, 25));
        btn_Moving = new QPushButton(centralwidget);
        btn_Moving->setObjectName(QString::fromUtf8("btn_Moving"));
        btn_Moving->setGeometry(QRect(320, 60, 89, 25));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "location send", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "bat", nullptr));
        le_err->setText(QApplication::translate("MainWindow", "0", nullptr));
        le_bat->setText(QApplication::translate("MainWindow", "54.2", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "err", nullptr));
        btn_x->setText(QApplication::translate("MainWindow", "+x", nullptr));
        btn_mx->setText(QApplication::translate("MainWindow", "-x", nullptr));
        btn_y->setText(QApplication::translate("MainWindow", "+y", nullptr));
        btn_my->setText(QApplication::translate("MainWindow", "-y", nullptr));
        btn_th->setText(QApplication::translate("MainWindow", "+th", nullptr));
        btn_mth->setText(QApplication::translate("MainWindow", "-th", nullptr));
        btn_Ready->setText(QApplication::translate("MainWindow", "ready", nullptr));
        btn_Moving->setText(QApplication::translate("MainWindow", "moving", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
