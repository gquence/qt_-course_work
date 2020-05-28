/********************************************************************************
** Form generated from reading UI file 'dialogdelete.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDELETE_H
#define UI_DIALOGDELETE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogDelete
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;

    void setupUi(QDialog *DialogDelete)
    {
        if (DialogDelete->objectName().isEmpty())
            DialogDelete->setObjectName(QString::fromUtf8("DialogDelete"));
        DialogDelete->resize(480, 640);
        verticalLayout = new QVBoxLayout(DialogDelete);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(DialogDelete);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("Background:rgb(255,255,255);\n"
"Color: rgb(0, 112, 70);\n"
"font: 63 bold 12pt \"URW Gothic L\";"));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout_2->addLayout(gridLayout);


        verticalLayout->addWidget(groupBox);


        retranslateUi(DialogDelete);

        QMetaObject::connectSlotsByName(DialogDelete);
    } // setupUi

    void retranslateUi(QDialog *DialogDelete)
    {
        DialogDelete->setWindowTitle(QCoreApplication::translate("DialogDelete", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogDelete", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogDelete: public Ui_DialogDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDELETE_H
