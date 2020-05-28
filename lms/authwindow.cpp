#include "authwindow.h"
#include "ui_authwindow.h"

#include <QMessageBox>


AuthWindow::AuthWindow(QWidget *parent, QString *login) :
    QDialog(parent),
    ui(new Ui::AuthWindow)
{
    this->setWindowFlags( Qt::Dialog
                          | Qt::WindowMinimizeButtonHint
                          | Qt::WindowMaximizeButtonHint
                          );
    qlogin = login;
    ui->setupUi(this);
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::responseReceived(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    this->setWindowTitle("");

    if (data_str.startsWith("true"))
    {
        *(this->qlogin) = ui->LoginLineEdit->text();
        QMessageBox::about(this, "Logged in", "You are logged in!\nHello");
        this->close();
    }
    else
    {
        QMessageBox::critical(this, "Not logged in", "wrong password or login");
    }
    ui->LoginLineEdit->setText("");
    ui->PasswordLineEdit->setText("");
}

void AuthWindow::on_SignInButton_clicked()
{
    QString login, password;
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl(req_url);
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=AUTH&";

    this->setWindowTitle("Checking");
    connect(manager, &QNetworkAccessManager::finished,
            this, &AuthWindow::responseReceived); //responseReceived - response handler

    data_str += "login=" + ui->LoginLineEdit->text() + "&";
    data_str += "pass=" + ui->PasswordLineEdit->text() + "&";
    data_str += "sOp=false";
    data.append((const QString &)data_str); // bytearray to string

    manager->post(request ,data);
}

void AuthWindow::on_SignUpButton_clicked()
{
    w_registration = new registr(this);
    w_registration->setWindowModality(Qt::ApplicationModal);
    w_registration->show();
}

void AuthWindow::on_pushButton_clicked()
{
    exit(0);
}
