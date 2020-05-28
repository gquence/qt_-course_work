#include "registr.h"
#include "ui_registr.h"
#include <QLabel>
#include <QDebug>
#include <QMessageBox>

bool    ft_check_bool_vector(QVector<bool> c)
{
    for (auto i : c)
    {
        if (!i)
            return false;
    }
    return true;
}

registr::registr(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registr)
{
    ui->setupUi(this);
    validate_fields = QVector<bool>(4);
    validate_fields.fill(false);
    this->setWindowFlags( Qt::Dialog );
    ui->SignUpButton->setEnabled(false);
}

registr::~registr()
{
    delete ui;
    this->setWindowFlags( Qt::Dialog
                          | Qt::WindowMinimizeButtonHint
                          | Qt::WindowMaximizeButtonHint
                          );
}

void registr::on_SignUpButton_clicked()
{
    QString login, password;
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl(req_url);
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=POST&";
    QString buf1= "", buf2 = "";

    this->setWindowTitle("Checking");
    connect(manager, &QNetworkAccessManager::finished,
            this, &registr::responseReceived); //responseReceived - response handler

    data_str += "login=" + ui->LoginLineEdit->text() + "&";
    data_str += "pass=" + ui->PasswordLineEdit->text() + "&";
    data_str += "name=" + ui->NameLineEdit->text() + "&";
    data_str += "surname=" + ui->SurnameLineEdit->text() + "&";

    buf1 = (QString)(ui->comboBox->currentText());
    if (QString::compare(buf1, "Student", Qt::CaseInsensitive))
        data_str += "sOp=false";
    else
        data_str += "sOp=true";
    data.append((const QString &)data_str); // bytearray to string
    manager->post(request ,data);
}

void registr::responseReceived(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    if (data_str.startsWith("200"))
    {
        QMessageBox::about(this, "Signed up", "You are signed up!");
        this->close();
    }
    else
    {
        QMessageBox::critical(this, "Error", "wrong value of the fields");
    }
}

void registr::on_PasswordLineEdit_textChanged(const QString &arg1)
{
    if (arg1.length() < 8 || arg1.length() > 32)
    {
        validate_fields[1] = false;
        ui->password_warn->setText("password must be between 8 and 32 symbols");
    }
    else
    {
        validate_fields[1] = true;
        ui->password_warn->setText("");
    }
    if (ft_check_bool_vector(validate_fields))
    {
        ui->SignUpButton->setEnabled(true);
    }
    else
        ui->SignUpButton->setEnabled(false);
}

void registr::on_LoginLineEdit_textChanged(const QString &arg1)
{
    if (arg1.length() < 6 || arg1.length() > 12)
    {
        validate_fields[0] = false;
        ui->login_warn->setText("login must be between 6 and 12 symbols");
    }
    else
    {
        validate_fields[0] = true;
        ui->login_warn->setText("");
    }
    if (ft_check_bool_vector(validate_fields))
    {
        ui->SignUpButton->setEnabled(true);
    }
    else
        ui->SignUpButton->setEnabled(false);
}

void registr::on_SurnameLineEdit_textChanged(const QString &arg1)
{
    if (arg1.length() > 12)
    {
        validate_fields[3] = false;
        ui->surname_warn->setText("surname must be less then 12 symbols");
    }
    else
    {
        validate_fields[3] = true;
        ui->surname_warn->setText("");
    }
    if (ft_check_bool_vector(validate_fields))
    {
        ui->SignUpButton->setEnabled(true);
    }
    else
    {
        ui->SignUpButton->setEnabled(false);
    }
}

void registr::on_NameLineEdit_textChanged(const QString &arg1)
{
    if (arg1.length() < 6 || arg1.length() > 12)
    {
        validate_fields[2] = false;
        ui->name_warn->setText("name must be between 6 and 12 symbols");
    }
    else
    {
        validate_fields[2] = true;
        ui->name_warn->setText("");
    }
    if (ft_check_bool_vector(validate_fields))
    {
        ui->SignUpButton->setEnabled(true);
    }
    else
        ui->SignUpButton->setEnabled(false);
}
