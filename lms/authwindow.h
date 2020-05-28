#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include "registr.h"

namespace Ui {
class AuthWindow;
}

class AuthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr, QString *login = nullptr);
    ~AuthWindow();
private slots:
    void on_SignInButton_clicked();
    void responseReceived(QNetworkReply *reply);

    void on_SignUpButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::AuthWindow *ui;
    QString         req_url = "http://localhost/t_users/CRUD_user.php";
    registr         *w_registration;
    QString         *qlogin;
};


#endif // AUTHWINDOW_H
