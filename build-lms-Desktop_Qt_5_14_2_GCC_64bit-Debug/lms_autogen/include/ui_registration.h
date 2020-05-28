/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_registration
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_4;
    QLineEdit *PasswordLineEdit;
    QLabel *label_4;
    QLineEdit *LoginLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *NameLineEdit;
    QLineEdit *SurnameLineEdit;
    QPushButton *SignUpButton;

    void setupUi(QDialog *registration)
    {
        if (registration->objectName().isEmpty())
            registration->setObjectName(QString::fromUtf8("registration"));
        registration->resize(480, 305);
        gridLayout = new QGridLayout(registration);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(registration);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        PasswordLineEdit = new QLineEdit(groupBox);
        PasswordLineEdit->setObjectName(QString::fromUtf8("PasswordLineEdit"));
        PasswordLineEdit->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));
        PasswordLineEdit->setText(QString::fromUtf8(""));
        PasswordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout_4->addWidget(PasswordLineEdit, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        gridLayout_4->addWidget(label_4, 3, 0, 1, 1);

        LoginLineEdit = new QLineEdit(groupBox);
        LoginLineEdit->setObjectName(QString::fromUtf8("LoginLineEdit"));
        LoginLineEdit->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));
        LoginLineEdit->setText(QString::fromUtf8(""));
        LoginLineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout_4->addWidget(LoginLineEdit, 0, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        gridLayout_4->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        gridLayout_4->addWidget(label_3, 2, 0, 1, 1);

        NameLineEdit = new QLineEdit(groupBox);
        NameLineEdit->setObjectName(QString::fromUtf8("NameLineEdit"));
        NameLineEdit->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));
        NameLineEdit->setText(QString::fromUtf8(""));
        NameLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout_4->addWidget(NameLineEdit, 3, 2, 1, 1);

        SurnameLineEdit = new QLineEdit(groupBox);
        SurnameLineEdit->setObjectName(QString::fromUtf8("SurnameLineEdit"));
        SurnameLineEdit->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));
        SurnameLineEdit->setText(QString::fromUtf8(""));
        SurnameLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout_4->addWidget(SurnameLineEdit, 2, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        SignUpButton = new QPushButton(groupBox);
        SignUpButton->setObjectName(QString::fromUtf8("SignUpButton"));
        SignUpButton->setStyleSheet(QString::fromUtf8("Background:rgb(96, 214, 169);\n"
"Color: rgb(0, 112, 70)"));

        verticalLayout_2->addWidget(SignUpButton);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(registration);

        QMetaObject::connectSlotsByName(registration);
    } // setupUi

    void retranslateUi(QDialog *registration)
    {
        registration->setWindowTitle(QCoreApplication::translate("registration", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("registration", "Registration", nullptr));
        label_4->setText(QCoreApplication::translate("registration", "Name", nullptr));
        label->setText(QCoreApplication::translate("registration", "Login:", nullptr));
        label_2->setText(QCoreApplication::translate("registration", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("registration", "Surname", nullptr));
        SignUpButton->setText(QCoreApplication::translate("registration", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registration: public Ui_registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
