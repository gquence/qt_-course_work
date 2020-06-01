/********************************************************************************
** Form generated from reading UI file 'registr.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTR_H
#define UI_REGISTR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registr
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    QLabel *name;
    QLineEdit *PasswordLineEdit;
    QLabel *login_warn;
    QLineEdit *NameLineEdit;
    QLineEdit *SurnameLineEdit;
    QLineEdit *LoginLineEdit;
    QLabel *password;
    QLabel *Login;
    QLabel *surname;
    QLabel *password_warn;
    QComboBox *comboBox;
    QLabel *surname_warn;
    QLabel *surname1;
    QLabel *name_warn;
    QPushButton *SignUpButton;

    void setupUi(QWidget *registr)
    {
        if (registr->objectName().isEmpty())
            registr->setObjectName(QString::fromUtf8("registr"));
        registr->resize(495, 373);
        registr->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(0, 112, 70);\n"
"font: 63 bold 12pt \"URW Gothic L\";"));
        gridLayout = new QGridLayout(registr);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(registr);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        name = new QLabel(groupBox);
        name->setObjectName(QString::fromUtf8("name"));
        name->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        gridLayout_4->addWidget(name, 6, 0, 1, 1);

        PasswordLineEdit = new QLineEdit(groupBox);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));
        PasswordLineEdit->setText(QString::fromUtf8(""));
        PasswordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout_4->addWidget(PasswordLineEdit, 2, 1, 1, 1);

        login_warn = new QLabel(groupBox);
        login_warn->setObjectName(QString::fromUtf8("login_warn"));
        login_warn->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(255, 79, 0);\n"
"font: 63 bold 10pt \"URW Gothic L\";"));

        gridLayout_4->addWidget(login_warn, 1, 1, 1, 1);

        NameLineEdit = new QLineEdit(groupBox);
        NameLineEdit->setObjectName(QString::fromUtf8("NameLineEdit"));
        NameLineEdit->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));
        NameLineEdit->setText(QString::fromUtf8(""));
        NameLineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout_4->addWidget(NameLineEdit, 6, 1, 1, 1);

        SurnameLineEdit = new QLineEdit(groupBox);
        SurnameLineEdit->setObjectName(QString::fromUtf8("SurnameLineEdit"));
        SurnameLineEdit->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));
        SurnameLineEdit->setText(QString::fromUtf8(""));
        SurnameLineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout_4->addWidget(SurnameLineEdit, 4, 1, 1, 1);

        LoginLineEdit = new QLineEdit(groupBox);
        LoginLineEdit->setObjectName(QString::fromUtf8("LoginLineEdit"));
        LoginLineEdit->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));
        LoginLineEdit->setText(QString::fromUtf8(""));
        LoginLineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout_4->addWidget(LoginLineEdit, 0, 1, 1, 1);

        password = new QLabel(groupBox);
        password->setObjectName(QString::fromUtf8("password"));
        password->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        gridLayout_4->addWidget(password, 2, 0, 1, 1);

        Login = new QLabel(groupBox);
        Login->setObjectName(QString::fromUtf8("Login"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        Login->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        gridLayout_4->addWidget(Login, 0, 0, 1, 1);

        surname = new QLabel(groupBox);
        surname->setObjectName(QString::fromUtf8("surname"));
        surname->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        gridLayout_4->addWidget(surname, 8, 0, 1, 1);

        password_warn = new QLabel(groupBox);
        password_warn->setObjectName(QString::fromUtf8("password_warn"));
        password_warn->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(255, 79, 0);\n"
"font: 63 bold 10pt \"URW Gothic L\";"));

        gridLayout_4->addWidget(password_warn, 3, 1, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_4->addWidget(comboBox, 8, 1, 1, 1);

        surname_warn = new QLabel(groupBox);
        surname_warn->setObjectName(QString::fromUtf8("surname_warn"));
        surname_warn->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(255, 79, 0);\n"
"font: 63 bold 10pt \"URW Gothic L\";"));

        gridLayout_4->addWidget(surname_warn, 5, 1, 1, 1);

        surname1 = new QLabel(groupBox);
        surname1->setObjectName(QString::fromUtf8("surname1"));
        surname1->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        gridLayout_4->addWidget(surname1, 4, 0, 1, 1);

        name_warn = new QLabel(groupBox);
        name_warn->setObjectName(QString::fromUtf8("name_warn"));
        name_warn->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(255, 79, 0);\n"
"font: 63 bold 10pt \"URW Gothic L\";"));

        gridLayout_4->addWidget(name_warn, 7, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        SignUpButton = new QPushButton(groupBox);
        SignUpButton->setObjectName(QString::fromUtf8("SignUpButton"));
        SignUpButton->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        verticalLayout_2->addWidget(SignUpButton);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(registr);

        QMetaObject::connectSlotsByName(registr);
    } // setupUi

    void retranslateUi(QWidget *registr)
    {
        registr->setWindowTitle(QCoreApplication::translate("registr", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("registr", "Registration", nullptr));
        name->setText(QCoreApplication::translate("registr", "Name", nullptr));
        login_warn->setText(QString());
        password->setText(QCoreApplication::translate("registr", "Password:", nullptr));
        Login->setText(QCoreApplication::translate("registr", "Login:", nullptr));
        surname->setText(QCoreApplication::translate("registr", "Member type", nullptr));
        password_warn->setText(QString());
        comboBox->setItemText(0, QCoreApplication::translate("registr", "Student", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("registr", "Pedago", nullptr));

        surname_warn->setText(QString());
        surname1->setText(QCoreApplication::translate("registr", "Surname", nullptr));
        name_warn->setText(QString());
        SignUpButton->setText(QCoreApplication::translate("registr", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registr: public Ui_registr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTR_H
