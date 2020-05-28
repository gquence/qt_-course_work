#ifndef REGISTR_H
#define REGISTR_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

namespace Ui {
class registr;
}

class registr : public QWidget
{
    Q_OBJECT

public:
    explicit registr(QWidget *parent = nullptr);
    ~registr();

private slots:
    void on_SignUpButton_clicked();

    void on_PasswordLineEdit_textChanged(const QString &arg1);

    void on_LoginLineEdit_textChanged(const QString &arg1);

    void on_SurnameLineEdit_textChanged(const QString &arg1);

    void on_NameLineEdit_textChanged(const QString &arg1);

    void responseReceived(QNetworkReply *reply);

private:
    QString req_url = "http://localhost/t_users/CRUD_user.php";
    Ui::registr *ui;
    QVector<bool> validate_fields;
};

#endif // REGISTR_H
