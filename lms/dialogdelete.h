#ifndef DIALOGDELETE_H
#define DIALOGDELETE_H

#include <QDialog>
#include "dialogsearch.h"

namespace Ui {
class DialogDelete;
}

class DialogDelete : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDelete(QWidget *parent = nullptr, QVector<QPair<QString, types_add>> rows = QVector<QPair<QString, types_add>>(), QString req_url = QString());
    ~DialogDelete();
private slots:

    void on_PassLineEdit_textChanged(const QString &arg1);
    void clickedReturnBtn();
    void clickedDeleteBtn();


private:
    void DeleteResponse(QNetworkReply *reply);
private:
    Ui::DialogDelete *ui;
    QVector<QPair<QLabel *, QLineEdit *>>   lines;
    QLabel                                  *warnLabel;
    QPushButton                             *returnBtn;
    QPushButton                             *DeleteBtn;
    QVector<types_add>  types_of_lines;
    QVector<bool>       validate_fields;
    QString qreq_url;
};

#endif // DIALOGDELETE_H
