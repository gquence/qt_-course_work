#include "dialogsearch.h"
#include "ui_dialogsearch.h"
#include <QMessageBox>
#include <QComboBox>

DialogSearch::DialogSearch(QWidget *parent, QVector<QPair<QString, types_add>> rows, QString *QresponseToParent, QString req_url) :
    QDialog(parent),
    ui(new Ui::DialogSearch)
{
    ui->setupUi(this);
    qreq_url = req_url;
    ResponseToParent = QresponseToParent;
    control_type_arr = QStringList({"Homework", "Exam"});
    learning_type_arr = QStringList({"full time", "distance", "evening"});
    Combos.resize(rows.length());
    Combos.fill(nullptr);
    ui->groupBox->setTitle("");

    validate_fields = QVector<bool>(rows.length());
    validate_fields.fill(false);
    warnLabel = new QLabel();
    warnLabel->setText("");
    ui->gridLayout->addWidget(warnLabel,rows.length(), 1);

    searchBtn = new QPushButton;
    searchBtn->setText("search");
    connect(searchBtn,SIGNAL(clicked()), this, SLOT(clickedSearchBtn()));
    ui->gridLayout->addWidget(searchBtn, rows.length() + 1, 1);

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


void DialogSearch::on_PassLineEdit_textChanged(const QString &arg1)
{
    QRegExp reg("^[\\d\\s\\w!?(){},./\\|\\-;\'\"@]*$");
    if ((arg1.length() < 1 || arg1.length() > 30 || !reg.exactMatch(arg1)) && arg1.compare("********") )
    {
        this->warnLabel->setText("wrong type of fields!\n It must be between 1 and 30 symbols.\n permited spec-symbols: !?(){},./\\|-;\'\"@");
    }
    else
    {
        this->warnLabel->setText("");
    }
}

#include <QDebug>
void DialogSearch::clickedSearchBtn()
{
    QString login, password;
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl(qreq_url);
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=GET&";
    QString buf1= "", buf2 = "";

    this->setWindowTitle("Checking...");
    connect(manager, &QNetworkAccessManager::finished,
            this, &DialogSearch::searchResponse); //responseReceived - response handler

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
            data_str += this->lines[i].second->text() + "&";
    }
    data.append((const QString &)data_str); // bytearray to string
    qInfo() << data_str;
    manager->post(request ,data);
}

void DialogSearch::searchResponse(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    this->setWindowTitle("Reading results");
    if (data_str.startsWith("200\nSuccess\nGET\nresult:"))
    {
        QMessageBox::about(this, "Failed", "No task with this id or uid");
        this->close();
    }
    else if (data_str.startsWith("301\nInvalidJsonValues: Empty JSON\nGET"))
    {
        QMessageBox::critical(this, "Failed", "Entered empty values");
        this->close();
    }
    else if (data_str.startsWith("200\nSuccess\nGET\n"))
    {
        *(this->ResponseToParent) = QString(data_str);
        this->close();
    }
    else
    {
        QMessageBox::critical(this, "Failed", "Something goes wrong");
        this->close();
    }
}

void DialogSearch::clickedReturnBtn()
{
    this->close();
}

bool    DialogSearch::ft_check_bool_vector_acc(QVector<bool> c)
{
    for (auto i : c)
    {
        if (!i)
            return false;
    }
    return true;
}


void DialogSearch::ft_checkEditLines(){

    if (ft_check_bool_vector_acc(validate_fields))
    {
        this->searchBtn->setEnabled(true);
    }
    else
        this->searchBtn->setEnabled(false);
}

DialogSearch::~DialogSearch()
{
    delete ui;
    for (auto &a : lines)
    {
        delete a.first;
        delete a.second;
    }
    for (auto & a : Combos)
    {
        if (a != nullptr)
            delete a;
    }
    delete warnLabel;
    delete returnBtn;
    delete searchBtn;

}
