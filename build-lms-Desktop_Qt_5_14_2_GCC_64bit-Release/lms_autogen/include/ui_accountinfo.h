/********************************************************************************
** Form generated from reading UI file 'accountinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTINFO_H
#define UI_ACCOUNTINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accountInfo
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *LoginLineEdit;
    QLabel *label_2;
    QLineEdit *PasswordLineEdit;
    QLabel *label_3;
    QLineEdit *SurnameLineEdit;
    QLabel *label_4;
    QLineEdit *NameLineEdit;
    QLabel *label_5;
    QLineEdit *EmailLineEdit;
    QLabel *password_warn;
    QLabel *surname_warn;
    QLabel *name_warn;
    QLabel *email_warn;
    QPushButton *update;
    QGridLayout *gridLayout_2;
    QPushButton *ExitBtn;
    QPushButton *returnBtn;

    void setupUi(QWidget *accountInfo)
    {
        if (accountInfo->objectName().isEmpty())
            accountInfo->setObjectName(QString::fromUtf8("accountInfo"));
        accountInfo->resize(536, 419);
        accountInfo->setStyleSheet(QString::fromUtf8("background:rgb(255, 255, 255);\n"
"Color: rgb(0, 112, 70);\n"
"font: 63 bold 12pt \"URW Gothic L\";\n"
""));
        gridLayout = new QGridLayout(accountInfo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(accountInfo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("Color: rgb(0, 112, 70)"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        LoginLineEdit = new QLineEdit(groupBox);
        LoginLineEdit->setObjectName(QString::fromUtf8("LoginLineEdit"));
        LoginLineEdit->setStyleSheet(QString::fromUtf8("Color: rgb(0, 112, 70)"));
        LoginLineEdit->setText(QString::fromUtf8(""));
        LoginLineEdit->setEchoMode(QLineEdit::Normal);

        formLayout->setWidget(0, QFormLayout::FieldRole, LoginLineEdit);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("\n"
"Color: rgb(0, 112, 70)"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        PasswordLineEdit = new QLineEdit(groupBox);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setStyleSheet(QString::fromUtf8("Color: rgb(0, 112, 70)"));
        PasswordLineEdit->setText(QString::fromUtf8(""));
        PasswordLineEdit->setEchoMode(QLineEdit::Normal);

        formLayout->setWidget(2, QFormLayout::FieldRole, PasswordLineEdit);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("\n"
"Color: rgb(0, 112, 70)"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        SurnameLineEdit = new QLineEdit(groupBox);
        SurnameLineEdit->setObjectName(QString::fromUtf8("SurnameLineEdit"));
        SurnameLineEdit->setStyleSheet(QString::fromUtf8("Color: rgb(0, 112, 70)"));
        SurnameLineEdit->setText(QString::fromUtf8(""));
        SurnameLineEdit->setEchoMode(QLineEdit::Normal);

        formLayout->setWidget(4, QFormLayout::FieldRole, SurnameLineEdit);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"Color: rgb(0, 112, 70)"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        NameLineEdit = new QLineEdit(groupBox);
        NameLineEdit->setObjectName(QString::fromUtf8("NameLineEdit"));
        NameLineEdit->setStyleSheet(QString::fromUtf8("Color: rgb(0, 112, 70)"));
        NameLineEdit->setText(QString::fromUtf8(""));
        NameLineEdit->setEchoMode(QLineEdit::Normal);

        formLayout->setWidget(6, QFormLayout::FieldRole, NameLineEdit);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("\n"
"Color: rgb(0, 112, 70)"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_5);

        EmailLineEdit = new QLineEdit(groupBox);
        EmailLineEdit->setObjectName(QString::fromUtf8("EmailLineEdit"));
        EmailLineEdit->setStyleSheet(QString::fromUtf8("Color: rgb(0, 112, 70)"));
        EmailLineEdit->setText(QString::fromUtf8(""));
        EmailLineEdit->setEchoMode(QLineEdit::Normal);

        formLayout->setWidget(8, QFormLayout::FieldRole, EmailLineEdit);

        password_warn = new QLabel(groupBox);
        password_warn->setObjectName(QString::fromUtf8("password_warn"));
        password_warn->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(255, 79, 0);\n"
"font: 63 bold 10pt \"URW Gothic L\";"));

        formLayout->setWidget(3, QFormLayout::FieldRole, password_warn);

        surname_warn = new QLabel(groupBox);
        surname_warn->setObjectName(QString::fromUtf8("surname_warn"));
        surname_warn->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(255, 79, 0);\n"
"font: 63 bold 10pt \"URW Gothic L\";"));

        formLayout->setWidget(5, QFormLayout::FieldRole, surname_warn);

        name_warn = new QLabel(groupBox);
        name_warn->setObjectName(QString::fromUtf8("name_warn"));
        name_warn->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(255, 79, 0);\n"
"font: 63 bold 10pt \"URW Gothic L\";"));

        formLayout->setWidget(7, QFormLayout::FieldRole, name_warn);

        email_warn = new QLabel(groupBox);
        email_warn->setObjectName(QString::fromUtf8("email_warn"));
        email_warn->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(255, 79, 0);\n"
"font: 63 bold 10pt \"URW Gothic L\";"));

        formLayout->setWidget(9, QFormLayout::FieldRole, email_warn);


        verticalLayout->addLayout(formLayout);

        update = new QPushButton(groupBox);
        update->setObjectName(QString::fromUtf8("update"));

        verticalLayout->addWidget(update);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        ExitBtn = new QPushButton(groupBox);
        ExitBtn->setObjectName(QString::fromUtf8("ExitBtn"));
        ExitBtn->setStyleSheet(QString::fromUtf8("Color: rgb(255, 79, 0);"));

        gridLayout_2->addWidget(ExitBtn, 0, 0, 1, 1);

        returnBtn = new QPushButton(groupBox);
        returnBtn->setObjectName(QString::fromUtf8("returnBtn"));

        gridLayout_2->addWidget(returnBtn, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(accountInfo);

        QMetaObject::connectSlotsByName(accountInfo);
    } // setupUi

    void retranslateUi(QWidget *accountInfo)
    {
        accountInfo->setWindowTitle(QCoreApplication::translate("accountInfo", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("accountInfo", "Your account", nullptr));
        label->setText(QCoreApplication::translate("accountInfo", "Login:", nullptr));
        label_2->setText(QCoreApplication::translate("accountInfo", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("accountInfo", "Surname:", nullptr));
        label_4->setText(QCoreApplication::translate("accountInfo", "Name:", nullptr));
        label_5->setText(QCoreApplication::translate("accountInfo", "E-mail:", nullptr));
        password_warn->setText(QString());
        surname_warn->setText(QString());
        name_warn->setText(QString());
        email_warn->setText(QString());
        update->setText(QCoreApplication::translate("accountInfo", "Change something", nullptr));
        ExitBtn->setText(QCoreApplication::translate("accountInfo", "Exit", nullptr));
        returnBtn->setText(QCoreApplication::translate("accountInfo", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accountInfo: public Ui_accountInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTINFO_H
