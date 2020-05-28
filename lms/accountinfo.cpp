#include "accountinfo.h"
#include "ui_accountinfo.h"
#include <QMessageBox>
#include <QDebug>

bool    ft_check_bool_vector_acc(QVector<bool> c)
{
    for (auto i : c)
    {
        if (!i)
            return false;
    }
    return true;
}

accountInfo::accountInfo(QWidget *parent, QString *login) :
    QWidget(parent),
    ui(new Ui::accountInfo)
{
    ui->setupUi(this);
    qlogin= login;
    validate_fields = QVector<bool>(4);
    validate_fields.fill(true);
    ui->LoginLineEdit->setDisabled(true);
    ui->PasswordLineEdit->setDisabled(true);
    ui->SurnameLineEdit->setDisabled(true);
    ui->NameLineEdit->setDisabled(true);
    ui->EmailLineEdit->setDisabled(true);
    this->setWindowFlags( Qt::Dialog );
    this->fields = QStringList();
    update_launched = false;
    this->setWindowTitle("Checking...");
    startInit();
}

void accountInfo::startInit(void)
{
    QString login, password;
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl("http://localhost/t_users/CRUD_user.php");
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=GET&";

    connect(manager, &QNetworkAccessManager::finished,
            this, &accountInfo::getResponseReceived); //getResponseReceived - response handler

    data_str += "login=" + *(this->qlogin);
    data.append((const QString &)data_str); // bytearray to string

    manager->post(request ,data);
}

void accountInfo::getResponseReceived(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    this->setWindowTitle("Updating...");
    if (!data_str.startsWith("200"))
    {
        QMessageBox::critical(this, "Not logged in", "wrong password or login");
        return ;
    }

    data_str = data_str.remove("200\nSuccess\nGETALL\n");
    QStringList header = QString(data_str).remove(QRegExp("[\\d\\s\\w!?(){},./\\|\\-;\'\"@]*&")).split(":");
    for (QString col_name: header)
    {
        data_str = data_str.remove(col_name);
    }
    data_str = data_str.remove(": ");
    QStringList person_inf_lst = data_str.split("&");

    ui->LoginLineEdit->setText(person_inf_lst[5]);
    ui->PasswordLineEdit->setText("********");
    ui->SurnameLineEdit->setText(person_inf_lst[1]);
    ui->NameLineEdit->setText(person_inf_lst[2]);
    ui->EmailLineEdit->setText(person_inf_lst[6]);
    this->setWindowTitle("Your account");
}

accountInfo::~accountInfo()
{
    delete ui;
}

void accountInfo::on_ExitBtn_clicked()
{
    exit(0);
}

void accountInfo::on_returnBtn_clicked()
{
    this->close();
}


void accountInfo::patchResponseReceived(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    this->setWindowTitle("Checking...");

    if (data_str.startsWith("200"))
    {
        *(this->qlogin) = ui->LoginLineEdit->text();
        this->startInit();
    }
    else
    {
        QMessageBox::critical(this, "error!", "Something goes wrong");
        this->close();
    }
}

void accountInfo::on_update_clicked()
{
    if (this->update_launched == false)
    {
        this->update_launched = true;
        this->fields.append(ui->PasswordLineEdit->text());
        this->fields.append(ui->SurnameLineEdit->text());
        this->fields.append(ui->NameLineEdit->text());
        this->fields.append(ui->EmailLineEdit->text());
        ui->PasswordLineEdit->setDisabled(false);
        ui->SurnameLineEdit->setDisabled(false);
        ui->NameLineEdit->setDisabled(false);
        ui->EmailLineEdit->setDisabled(false);
        validate_fields.fill(false);
    }
    else if (this->update_launched == true)
    {
        ui->PasswordLineEdit->setDisabled(true);
        ui->SurnameLineEdit->setDisabled(true);
        ui->NameLineEdit->setDisabled(true);
        ui->EmailLineEdit->setDisabled(true);
        this->update_launched = false;

        QNetworkAccessManager * manager = new QNetworkAccessManager(this);
        const QUrl url = QUrl("http://localhost/t_users/CRUD_user.php");
        QNetworkRequest request(url);
        QByteArray data;
        QString data_str = "type=PATCH&";

        this->setWindowTitle("Downloadling...");
        connect(manager, &QNetworkAccessManager::finished,
                this, &accountInfo::patchResponseReceived); //responseReceived - response handler

        data_str += "login=" + *(this->qlogin) + "&";

        if (QString::compare(this->fields[0], ui->PasswordLineEdit->text()))
            data_str += "new_pass=" + ui->PasswordLineEdit->text() + "&";
        if (QString::compare(this->fields[1], ui->SurnameLineEdit->text()))
            data_str += "new_pass=" + ui->SurnameLineEdit->text() + "&";
        if (QString::compare(this->fields[2], ui->NameLineEdit->text()))
            data_str += "name=" + ui->NameLineEdit->text() + "&";
        if (QString::compare(this->fields[3], ui->EmailLineEdit->text()))
            data_str += "email=" + ui->EmailLineEdit->text() + "&";
        data.append((const QString &)data_str); // bytearray to string
        manager->post(request ,data);
    }
}


void accountInfo::on_PasswordLineEdit_textChanged(const QString &arg1)
{
    QRegExp reg("^[\\d\\s\\w!?(){},./\\|\\-;\'\"@]*$");
    if ((arg1.length() < 8 || arg1.length() > 32) && this->update_launched )
    {
        validate_fields[1] = false;
        ui->password_warn->setText("password must be between 8 and 32 symbols");
    }
    else if (!reg.exactMatch(arg1) && arg1.compare("********") && this->update_launched )
    {
        validate_fields[1] = false;
        ui->password_warn->setText("wrong type of password");
    }
    else
    {
        validate_fields[1] = true;
        ui->password_warn->setText("");
    }
    ft_checkEditLines();
}

void accountInfo::on_EmailLineEdit_textChanged(const QString &arg1)
{
    QRegExp reg("^[\\d\\s\\w\\-@]*$");
    if ((arg1.length() < 0 || arg1.length() > 64) && this->update_launched )
    {
        validate_fields[0] = false;
        ui->password_warn->setText("email must be between 0 and 64 symbols");
    }
    else if (!reg.exactMatch(arg1) && this->update_launched)
    {
        validate_fields[0] = false;
        ui->email_warn->setText("wrong email type");
    }
    else
    {
        validate_fields[0] = true;
        ui->email_warn->setText("");
    }

    ft_checkEditLines();
}

void accountInfo::on_SurnameLineEdit_textChanged(const QString &arg1)
{
    QRegExp reg("^[\\d\\s\\w\\-]*$");
    if (arg1.length() < 0 ||arg1.length() > 12)
    {
        validate_fields[3] = false;
        ui->surname_warn->setText("surname must be between 0 and 12 symbols");
    }
    else if (!reg.exactMatch(arg1) && this->update_launched )
    {
        validate_fields[3] = false;
        ui->surname_warn->setText("wrong type of surname");
    }
    else
    {
        validate_fields[3] = true;
        ui->surname_warn->setText("");
    }
    ft_checkEditLines();
}

void accountInfo::on_NameLineEdit_textChanged(const QString &arg1)
{
    QRegExp reg("^[\\d\\s\\w\\-]*$");
    if (arg1.length() < 6 || arg1.length() > 12)
    {
        validate_fields[2] = false;
        ui->name_warn->setText("name must be between 6 and 12 symbols");
    }
    else if (!reg.exactMatch(arg1) && this->update_launched )
    {
        validate_fields[2] = false;
        ui->name_warn->setText("wrong type of name");
    }
    else
    {
        validate_fields[2] = true;
        ui->name_warn->setText("");
    }
}

void accountInfo::ft_checkEditLines(){

    if (ft_check_bool_vector_acc(validate_fields))
    {
        ui->update->setEnabled(true);
    }
    else
        ui->update->setEnabled(false);
}
