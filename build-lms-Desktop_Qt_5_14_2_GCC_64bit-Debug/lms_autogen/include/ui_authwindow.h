/********************************************************************************
** Form generated from reading UI file 'authwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHWINDOW_H
#define UI_AUTHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthWindow
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLineEdit *LoginLineEdit;
    QLabel *label_2;
    QLineEdit *PasswordLineEdit;
    QPushButton *SignInButton;
    QPushButton *SignUpButton;
    QPushButton *pushButton;

    void setupUi(QDialog *AuthWindow)
    {
        if (AuthWindow->objectName().isEmpty())
            AuthWindow->setObjectName(QString::fromUtf8("AuthWindow"));
        AuthWindow->resize(400, 300);
        AuthWindow->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(0, 112, 70);\n"
"font: 63 bold 12pt \"URW Gothic L\";"));
        gridLayout = new QGridLayout(AuthWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(AuthWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 80, 337, 148));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        LoginLineEdit = new QLineEdit(layoutWidget);
        LoginLineEdit->setObjectName(QString::fromUtf8("LoginLineEdit"));
        LoginLineEdit->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));
        LoginLineEdit->setText(QString::fromUtf8(""));
        LoginLineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout_4->addWidget(LoginLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        PasswordLineEdit = new QLineEdit(layoutWidget);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));
        PasswordLineEdit->setText(QString::fromUtf8(""));
        PasswordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout_4->addWidget(PasswordLineEdit, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        SignInButton = new QPushButton(layoutWidget);
        SignInButton->setObjectName(QString::fromUtf8("SignInButton"));
        SignInButton->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        verticalLayout_2->addWidget(SignInButton);

        SignUpButton = new QPushButton(layoutWidget);
        SignUpButton->setObjectName(QString::fromUtf8("SignUpButton"));

        verticalLayout_2->addWidget(SignUpButton);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 240, 51, 30));
        pushButton->setStyleSheet(QString::fromUtf8("Color: rgb(255, 79, 0);"));

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(AuthWindow);

        QMetaObject::connectSlotsByName(AuthWindow);
    } // setupUi

    void retranslateUi(QDialog *AuthWindow)
    {
        AuthWindow->setWindowTitle(QString());
        groupBox->setTitle(QCoreApplication::translate("AuthWindow", "Authorization", nullptr));
        label->setText(QCoreApplication::translate("AuthWindow", "Login:", nullptr));
        label_2->setText(QCoreApplication::translate("AuthWindow", "Password:", nullptr));
        SignInButton->setText(QCoreApplication::translate("AuthWindow", "Sign in", nullptr));
        SignUpButton->setText(QCoreApplication::translate("AuthWindow", "Sign up", nullptr));
        pushButton->setText(QCoreApplication::translate("AuthWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthWindow: public Ui_AuthWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHWINDOW_H
