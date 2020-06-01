#include "dialogadd.h"
#include "ui_dialogadd.h"
#include <QMessageBox>
#include <QDebug>
DialogAdd::DialogAdd(QWidget *parent, QVector<QPair<QString, types_add>> rows,  QString req_url) :
    QDialog(parent),
    ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
    qreq_url = req_url;
    control_type_arr = QStringList({"Homework", "Exam"});
    learning_type_arr = QStringList({"full time", "distance", "evening"});
    validate_fields = QVector<bool>(rows.length());
    validate_fields.fill(false);
    Combos.resize(rows.length());
    Combos.fill(nullptr);
    ui->groupBox->setTitle("");

    warnLabel = new QLabel();
    warnLabel->setText("");
    ui->gridLayout->addWidget(warnLabel,rows.length(), 1);

    AddBtn = new QPushButton;
    AddBtn->setText("Add");
    connect(AddBtn,SIGNAL(clicked()), this, SLOT(clickedAddBtn()));
    ui->gridLayout->addWidget(AddBtn, rows.length() + 1, 1);

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
        if (rows[i].second == control_type || rows[i].second == learning_type)
        {
            QComboBox *ptr = new QComboBox();

            if (rows[i].second == control_type)
            {
                ptr->addItems(control_type_arr);
                ptr->currentTextChanged(control_type_arr[0]);
            }
            else if (rows[i].second == learning_type)
            {
                ptr->addItems(learning_type_arr);
                ptr->currentTextChanged(learning_type_arr[0]);
            }
            Combos[i] = ptr;
            ui->gridLayout->addWidget(ptr,i, 1);
        }
        else
        {
            lines[i].second = new QLineEdit();
            ui->gridLayout->addWidget(lines[i].second,i, 1);
            connect(lines[i].second, SIGNAL(textChanged(const QString &)), this, SLOT(on_PassLineEdit_textChanged(const QString &)));
        }
        types_of_lines[i] = rows[i].second;
        ui->gridLayout->addWidget(lines[i].first,i, 0);
    }
}


void DialogAdd::on_PassLineEdit_textChanged(const QString &arg1)
{
    QRegExp reg("^[\\d\\s\\w!?(){},./\\|\\-;\'\"@]*$");
    if ((arg1.length() < 6 || arg1.length() > 30 || !reg.exactMatch(arg1)) && arg1.compare("********") )
    {
        this->warnLabel->setText("wrong type of fields!\n It must be between 6 and 30 symbols.\n permited spec-symbols: !?(){},./\\|-;\'\"@\nPS except quests, theory, recomendatons and descriptions");
    }
    else
    {
        this->warnLabel->setText("");
    }
}

#include <QDebug>
void DialogAdd::clickedAddBtn()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl(qreq_url);
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=POST&sOp=true&";
    QString buf1= "", buf2 = "";

    this->setWindowTitle("Checking...");
    connect(manager, &QNetworkAccessManager::finished,
            this, &DialogAdd::AddResponse); //AddResponse - response handler

    for (int i = 0; i < this->types_of_lines.length(); i++)
    {
        switch (this->types_of_lines[i])
        {
            case ((int)Login):
                data_str += "login=";
                break;
            case ((int)Password):
                data_str += "pass=";
                break;
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
                data_str += "corr_ans=";
                break;
            case ((int)answer):
                data_str += "ans={";
                break;
            case ((int)control_type):
                data_str += "l_type=";
                break;
            case ((int)learning_type):
                data_str += "l_type=";
                break;
            case ((int)l_id):
                data_str += "l_id=";
                break;
            case ((int)subj_id):
                data_str += "subj_id=";
                break;
            case ((int)quest):
                data_str += "quest=";
                break;
            case ((int)theory):
                data_str += "theory=";
                break;
            case ((int)recomend):
                data_str += "recomend=";
                break;
            case ((int)start_date):
                data_str += "start_date=";
                break;
            case ((int)end_date):
                data_str += "end_date=";
                break;
            default:
                return;
        }
        if (this->types_of_lines[i] == control_type || this->types_of_lines[i] == learning_type)
        {
            data_str += this->Combos[i]->currentText() + "&";
        }
        else
        {
            if (this->types_of_lines[i] == answer)
                data_str += this->lines[i].second->text() + "}&";
            else
                data_str += this->lines[i].second->text() + "&";
        }
    }
    data.append((const QString &)data_str); // bytearray to string
    //qInfo() << data_str;
    manager->post(request ,data);
}

void DialogAdd::AddResponse(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);
    this->setWindowTitle("Reading results");
    //qInfo() << data_str;
    if (data_str.startsWith("301\nInvalidJsonValues: Login must be unique\nPOST"))
    {
        QMessageBox::critical(this, "Failed", "Login is not unique");
    }
    else if (data_str.startsWith("301\nInvalidJsonValues: no such user\nPOST"))
    {
        QMessageBox::critical(this, "Failed", "No such user");
    }
    else if (data_str.startsWith("301\nInvalidJsonValues: no such subject\nPOST"))
    {
        QMessageBox::critical(this, "Failed", "No such subject");
    }
    else if (data_str.startsWith("301\nInvalidJsonValues: No such lesson\nPOST"))
    {
        QMessageBox::critical(this, "Failed", "No such lesson");
    }
    else if (data_str.startsWith("301\nInvalidJsonValues: Empty JSON\nPOST"))
    {
        QMessageBox::critical(this, "Failed", "Entered empty values");
    }
    else if (data_str.startsWith("301\nInvalidJsonValues"))
    {
        QMessageBox::critical(this, "Failed", "Invalid entered values");
    }
    else if (data_str.startsWith("200\nSuccess\nPOST\n"))
    {
        QMessageBox::information(this, "Success", "You added new element!");
    }
    else
    {
        QMessageBox::critical(this, "Failed", "Something goes wrong");
    }
    this->close();
}

void DialogAdd::clickedReturnBtn()
{
    this->close();
}


DialogAdd::~DialogAdd()
{
    delete ui;
    for (auto &a : lines)
    {
        delete a.first;
        delete a.second;
    }
    delete warnLabel;
    delete returnBtn;
    delete AddBtn;
}
