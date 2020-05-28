#ifndef DIALOGADD_H
#define DIALOGADD_H

#include <QDialog>
#include "dialogsearch.h"
#include <QComboBox>

namespace Ui {
class DialogAdd;
}

class DialogAdd : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAdd(QWidget *parent = nullptr, QVector<QPair<QString, types_add>> rows = QVector<QPair<QString, types_add>>(), QString req_url = QString());
    ~DialogAdd();
private slots:

    void on_PassLineEdit_textChanged(const QString &arg1);
    void clickedReturnBtn();
    void clickedAddBtn();


private:
    void AddResponse(QNetworkReply *reply);
private:
    Ui::DialogAdd *ui;
    QVector<QPair<QLabel *, QLineEdit *>>   lines;
    QVector<QComboBox *>                    Combos;
    QLabel                                  *warnLabel;
    QPushButton                             *returnBtn;
    QPushButton                             *AddBtn;
    QVector<types_add>  types_of_lines;
    QVector<bool>       validate_fields;
    QString             *ResponseToParent;
    QString qreq_url;

    QStringList control_type_arr;
    QStringList learning_type_arr;
};

#endif // DIALOGADD_H
