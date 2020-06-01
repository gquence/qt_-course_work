/********************************************************************************
** Form generated from reading UI file 'dialogsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSEARCH_H
#define UI_DIALOGSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSearch
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;

    void setupUi(QDialog *DialogSearch)
    {
        if (DialogSearch->objectName().isEmpty())
            DialogSearch->setObjectName(QString::fromUtf8("DialogSearch"));
        DialogSearch->resize(392, 358);
        verticalLayout = new QVBoxLayout(DialogSearch);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(DialogSearch);
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


        retranslateUi(DialogSearch);

        QMetaObject::connectSlotsByName(DialogSearch);
    } // setupUi

    void retranslateUi(QDialog *DialogSearch)
    {
        DialogSearch->setWindowTitle(QCoreApplication::translate("DialogSearch", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogSearch", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSearch: public Ui_DialogSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSEARCH_H
