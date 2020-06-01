/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionYour_Account;
    QAction *actionexit;
    QAction *actionCreate_new_student;
    QAction *actionShow_all_student;
    QAction *actionShow_all_pedagos;
    QAction *actionCreate;
    QAction *actionShow_all;
    QAction *actionShow_all_2;
    QAction *actionAdd;
    QAction *actionAdd_2;
    QAction *actionShow_all_3;
    QAction *actionAdd_3;
    QAction *actionShow_all_4;
    QAction *actionDelete;
    QAction *actionDelete_student;
    QAction *actionDelete_3;
    QAction *actionDelte;
    QAction *actionDelete_4;
    QAction *actionReload;
    QAction *actionLog_out;
    QAction *actionShow_all_5;
    QAction *actionSearch;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menuSubjects;
    QMenu *menuLessons;
    QMenu *menuTasks;
    QMenu *menuGroups;
    QMenu *menuOther;
    QMenu *menuUsers;
    QMenu *menuTasks_Results;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(0, 112, 70);\n"
"font: 63 bold 12pt \"URW Gothic L\";"));
        actionYour_Account = new QAction(MainWindow);
        actionYour_Account->setObjectName(QString::fromUtf8("actionYour_Account"));
        actionexit = new QAction(MainWindow);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        actionCreate_new_student = new QAction(MainWindow);
        actionCreate_new_student->setObjectName(QString::fromUtf8("actionCreate_new_student"));
        actionShow_all_student = new QAction(MainWindow);
        actionShow_all_student->setObjectName(QString::fromUtf8("actionShow_all_student"));
        actionShow_all_pedagos = new QAction(MainWindow);
        actionShow_all_pedagos->setObjectName(QString::fromUtf8("actionShow_all_pedagos"));
        actionCreate = new QAction(MainWindow);
        actionCreate->setObjectName(QString::fromUtf8("actionCreate"));
        QFont font;
        font.setFamily(QString::fromUtf8("Umpush"));
        actionCreate->setFont(font);
        actionCreate->setIconVisibleInMenu(false);
        actionShow_all = new QAction(MainWindow);
        actionShow_all->setObjectName(QString::fromUtf8("actionShow_all"));
        actionShow_all_2 = new QAction(MainWindow);
        actionShow_all_2->setObjectName(QString::fromUtf8("actionShow_all_2"));
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
        actionAdd_2 = new QAction(MainWindow);
        actionAdd_2->setObjectName(QString::fromUtf8("actionAdd_2"));
        actionShow_all_3 = new QAction(MainWindow);
        actionShow_all_3->setObjectName(QString::fromUtf8("actionShow_all_3"));
        actionAdd_3 = new QAction(MainWindow);
        actionAdd_3->setObjectName(QString::fromUtf8("actionAdd_3"));
        actionShow_all_4 = new QAction(MainWindow);
        actionShow_all_4->setObjectName(QString::fromUtf8("actionShow_all_4"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionDelete_student = new QAction(MainWindow);
        actionDelete_student->setObjectName(QString::fromUtf8("actionDelete_student"));
        actionDelete_3 = new QAction(MainWindow);
        actionDelete_3->setObjectName(QString::fromUtf8("actionDelete_3"));
        actionDelte = new QAction(MainWindow);
        actionDelte->setObjectName(QString::fromUtf8("actionDelte"));
        actionDelete_4 = new QAction(MainWindow);
        actionDelete_4->setObjectName(QString::fromUtf8("actionDelete_4"));
        actionReload = new QAction(MainWindow);
        actionReload->setObjectName(QString::fromUtf8("actionReload"));
        actionLog_out = new QAction(MainWindow);
        actionLog_out->setObjectName(QString::fromUtf8("actionLog_out"));
        actionShow_all_5 = new QAction(MainWindow);
        actionShow_all_5->setObjectName(QString::fromUtf8("actionShow_all_5"));
        actionSearch = new QAction(MainWindow);
        actionSearch->setObjectName(QString::fromUtf8("actionSearch"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(0, 112, 70);\n"
"font: 11pt \"Umpush\";"));

        gridLayout_2->addWidget(tableView, 5, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("URW Gothic L"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        menuBar->setFont(font1);
        menuBar->setStyleSheet(QString::fromUtf8("background:  rgb(169, 127, 220);\n"
"color:   rgb(86, 14, 173);\n"
"font: 10pt \"URW Gothic L\";"));
        menuSubjects = new QMenu(menuBar);
        menuSubjects->setObjectName(QString::fromUtf8("menuSubjects"));
        menuLessons = new QMenu(menuBar);
        menuLessons->setObjectName(QString::fromUtf8("menuLessons"));
        menuTasks = new QMenu(menuBar);
        menuTasks->setObjectName(QString::fromUtf8("menuTasks"));
        menuGroups = new QMenu(menuBar);
        menuGroups->setObjectName(QString::fromUtf8("menuGroups"));
        menuOther = new QMenu(menuBar);
        menuOther->setObjectName(QString::fromUtf8("menuOther"));
        menuUsers = new QMenu(menuBar);
        menuUsers->setObjectName(QString::fromUtf8("menuUsers"));
        menuTasks_Results = new QMenu(menuBar);
        menuTasks_Results->setObjectName(QString::fromUtf8("menuTasks_Results"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuUsers->menuAction());
        menuBar->addAction(menuSubjects->menuAction());
        menuBar->addAction(menuLessons->menuAction());
        menuBar->addAction(menuTasks->menuAction());
        menuBar->addAction(menuGroups->menuAction());
        menuBar->addAction(menuTasks_Results->menuAction());
        menuBar->addAction(menuOther->menuAction());
        menuSubjects->addSeparator();
        menuSubjects->addAction(actionCreate);
        menuSubjects->addAction(actionShow_all);
        menuSubjects->addAction(actionDelete_3);
        menuLessons->addAction(actionAdd);
        menuLessons->addAction(actionShow_all_2);
        menuLessons->addAction(actionDelte);
        menuTasks->addAction(actionAdd_3);
        menuTasks->addAction(actionShow_all_4);
        menuTasks->addAction(actionDelete);
        menuGroups->addAction(actionAdd_2);
        menuGroups->addAction(actionShow_all_3);
        menuGroups->addAction(actionDelete_4);
        menuOther->addAction(actionYour_Account);
        menuOther->addAction(actionexit);
        menuOther->addAction(actionLog_out);
        menuUsers->addAction(actionCreate_new_student);
        menuUsers->addAction(actionShow_all_student);
        menuUsers->addAction(actionShow_all_pedagos);
        menuUsers->addAction(actionDelete_student);
        menuTasks_Results->addAction(actionShow_all_5);
        menuTasks_Results->addAction(actionSearch);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LMS", nullptr));
        actionYour_Account->setText(QCoreApplication::translate("MainWindow", "Your Account", nullptr));
        actionexit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionCreate_new_student->setText(QCoreApplication::translate("MainWindow", "Create new student", nullptr));
        actionShow_all_student->setText(QCoreApplication::translate("MainWindow", "Show all students", nullptr));
        actionShow_all_pedagos->setText(QCoreApplication::translate("MainWindow", "Show all pedagos", nullptr));
        actionCreate->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        actionShow_all->setText(QCoreApplication::translate("MainWindow", "Show all", nullptr));
        actionShow_all_2->setText(QCoreApplication::translate("MainWindow", "Show all", nullptr));
        actionAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        actionAdd_2->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        actionShow_all_3->setText(QCoreApplication::translate("MainWindow", "Show all", nullptr));
        actionAdd_3->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        actionShow_all_4->setText(QCoreApplication::translate("MainWindow", "Show all", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionDelete_student->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionDelete_3->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionDelte->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionDelete_4->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionReload->setText(QCoreApplication::translate("MainWindow", "Reload", nullptr));
        actionLog_out->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        actionShow_all_5->setText(QCoreApplication::translate("MainWindow", "Show all", nullptr));
        actionSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        menuSubjects->setTitle(QCoreApplication::translate("MainWindow", "Subjects", nullptr));
        menuLessons->setTitle(QCoreApplication::translate("MainWindow", "Lessons", nullptr));
        menuTasks->setTitle(QCoreApplication::translate("MainWindow", "Tasks", nullptr));
        menuGroups->setTitle(QCoreApplication::translate("MainWindow", "Groups", nullptr));
        menuOther->setTitle(QCoreApplication::translate("MainWindow", "Other", nullptr));
        menuUsers->setTitle(QCoreApplication::translate("MainWindow", "Users", nullptr));
        menuTasks_Results->setTitle(QCoreApplication::translate("MainWindow", "Tasks Results", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
