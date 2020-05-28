#include "dialogdelete.h"
#include "ui_dialogdelete.h"
#include <QMessageBox>

DialogDelete::DialogDelete(QWidget *parent, QVector<QPair<QString, types_add>> rows,  QString req_url) :
    QDialog(parent),
    ui(new Ui::DialogDelete)
{
    ui->setupUi(this);
    qreq_url = req_url;
    validate_fields = QVector<bool>(rows.length());
    validate_fields.fill(false);
    warnLabel = new QLabel();
    warnLabel->setText("");
    ui->gridLayout->addWidget(warnLabel,rows.length(), 1);
    ui->groupBox->setTitle("");

    DeleteBtn = new QPushButton;
    DeleteBtn->setText("Delete");
    connect(DeleteBtn,SIGNAL(clicked()), this, SLOT(clickedDeleteBtn()));
    ui->gridLayout->addWidget(DeleteBtn, rows.length() + 1, 1);

    returnBtn = new QPushButton;
    returnBtn->setText("return");
    connect(returnBtn,SIGNAL(clicked()), this, SLOT(clickedReturnBtn()));
    ui->gridLayout->addWidget(returnBtn, rows.length() + 1, 0);

    lines.resize(rows.length());
    types_of_lines.resize(rows.length());
    for (int i = 0; i < rows.length(); i++)
    {
        lines[i].first = new QLabel();
        lines[i].first->setText(rows[i].first);
        lines[i].second = new QLineEdit();
        types_of_lines[i] = rows[i].second;
        if (rows[i].second == Password)
        {
            lines[i].second->setEchoMode(QLineEdit::Password);
        }
        ui->gridLayout->addWidget(lines[i].first,i, 0);
        ui->gridLayout->addWidget(lines[i].second,i, 1);
        connect(lines[i].second, SIGNAL(textChanged(const QString &)), this, SLOT(on_PassLineEdit_textChanged(const QString &)));
    }
}


void DialogDelete::on_PassLineEdit_textChanged(const QString &arg1)
{
    QRegExp reg("^[\\d\\s\\w!?(){},./\\|\\-;\'\"@]*$");
    if ((arg1.length() < 6 || arg1.length() > 30 || !reg.exactMatch(arg1)) && arg1.compare("********") )
    {
        this->warnLabel->setText("wrong type of fields!\n It must be between 6 and 30 symbols.\n permited spec-symbols: !?(){},./\\|-;\'\"@");
    }
    else
    {
        this->warnLabel->setText("");
    }
}

#include <QDebug>
void DialogDelete::clickedDeleteBtn()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl(qreq_url);
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=DELETE&";
    QString buf1= "", buf2 = "";

    this->setWindowTitle("Checking...");
    connect(manager, &QNetworkAccessManager::finished,
            this, &DialogDelete::DeleteResponse); //DeleteResponse - response handler

    for (int i = 0; i < this->types_of_lines.length(); i++)
    {
        switch (this->types_of_lines[i])
        {
            case ((int)id):
                data_str += "id=";
                break;
            case ((int)uid):
                data_str += "uid=";
                break;
            case ((int)name):
                data_str += "name=";
                break;
            case ((int)surname):
                data_str += "surname=";
                break;
            case ((int)email):
                data_str += "email=";
                break;
            case ((int)description):
                data_str += "description=";
                break;
            case ((int)corr_answer):
                data_str += "corr_answer=";
                break;
            case ((int)answer):
                data_str += "answer=";
                break;
            case ((int)Login):
                data_str += "login=";
                break;
            case ((int)Password):
                data_str += "pass=";
                break;
            default:
                return;
        }
        data_str += this->lines[i].second->text() + "&";
    }

    data.append((const QString &)data_str); // bytearray to string
    manager->post(request ,data);
}

void DialogDelete::DeleteResponse(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);
qInfo() << data_str;
    this->setWindowTitle("Reading results");

    if (data_str.startsWith("301\nInvalidJsonValues: no such user"))
    {
        QMessageBox::critical(this, "Failed", "No such user");
    }
    else if (data_str.startsWith("301\nInvalidJsonValues: no such subject"))
    {
        QMessageBox::critical(this, "Failed", "No such subject");
    }
    else if (data_str.startsWith("301\nInvalidJsonValues: no such lesson"))
    {
        QMessageBox::critical(this, "Failed", "No such lesson");
    }
    else if (data_str.startsWith("301\nInvalidJsonValues: no such group"))
    {
        QMessageBox::critical(this, "Failed", "No such  group");
    }
    else if (data_str.startsWith("301\nInvalidJsonValues: Empty JSON\nDELETE"))
    {
        QMessageBox::critical(this, "Failed", "Entered empty values");
    }
    else if (data_str.startsWith("301\nInvalidJsonValues"))
    {
        QMessageBox::critical(this, "Failed", "Invalid entered values");
    }
    else if (data_str.startsWith("200\nSuccess\nDELETE"))
    {
        QMessageBox::information(this, "Success", "You deleted element!");
    }
    else
    {
        QMessageBox::critical(this, "Failed", "Something goes wrong");
    }
    this->close();
}

void DialogDelete::clickedReturnBtn()
{
    this->close();
}


DialogDelete::~DialogDelete()
{
    delete ui;
    for (auto &a : lines)
    {
        delete a.first;
        delete a.second;
    }
    delete warnLabel;
    delete returnBtn;
    delete DeleteBtn;
}
