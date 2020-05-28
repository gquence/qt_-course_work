#ifndef DIALOGSEARCH_H
#define DIALOGSEARCH_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

enum types_add
{
    id = 0,
    uid,
    name,
    surname,
    email,
    description,
    corr_answer,
    answer,
    Login,
    Password,
    control_type,
    learning_type,
    l_id,
    subj_id,
    quest,
    theory,
    recomend,
    start_date,
    end_date
};



namespace Ui {


class DialogSearch;
}

class DialogSearch : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSearch(QWidget *parent = nullptr, QVector<QPair<QString, types_add>> rows = QVector<QPair<QString, types_add>>(), QString *QresponseToParent = nullptr, QString req_url = QString());
    ~DialogSearch();

private slots:

    void on_PassLineEdit_textChanged(const QString &arg1);
    void clickedReturnBtn();
    void clickedSearchBtn();


private:
    void searchResponse(QNetworkReply *reply);
    bool ft_check_bool_vector_acc(QVector<bool> c);
    void ft_checkEditLines();

    Ui::DialogSearch *ui;

    QVector<QPair<QLabel *, QLineEdit *>>   lines;
    QVector<QComboBox *>   Combos;
    QLabel                                  *warnLabel;
    QPushButton                             *returnBtn;
    QPushButton                             *searchBtn;
    QVector<types_add>  types_of_lines;
    QVector<bool>       validate_fields;
    QString             *ResponseToParent;
    QString qreq_url;

    QStringList control_type_arr;
    QStringList learning_type_arr;

};

#endif // DIALOGSEARCH_H
