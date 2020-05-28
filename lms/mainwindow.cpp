#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "accountinfo.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stud_model = nullptr;
    pedago_model = nullptr;
    subj_model = nullptr;
    lessons_model = nullptr;
    tasks_model = nullptr;
    groups_model = nullptr;
    TTU_model = nullptr;
    tmp_model = nullptr;
    item = nullptr;
    login = "NChernova";
    responseFromChild = "";
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auth_window = new AuthWindow(this, &login);
    auth_window->setModal(true);
    //auth_window->exec();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete auth_window;
    delete stud_model;
    delete pedago_model;
    delete subj_model;
    delete lessons_model;
    delete tasks_model;
}



void MainWindow::on_actionYour_Account_triggered()
{
    account_window = new accountInfo(this, &(this->login));
    account_window->setWindowModality(Qt::ApplicationModal);
    account_window->show();
}


void MainWindow::on_actionShow_all_student_triggered()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl("http://localhost/t_users/CRUD_user.php");
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=GETALL&";

    this->setWindowTitle("Checking");
    connect(manager, &QNetworkAccessManager::finished,
            this, &MainWindow::responseStudReceived); //responseStudReceived - response handler
    data_str += "sOp=true";
    data.append((const QString &)data_str); //string to bytearray
    manager->post(request ,data);
}

void MainWindow::responseStudReceived(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    this->setWindowTitle("");
    if (!data_str.startsWith("200"))
    {
        QMessageBox::critical(this, "Not logged in", "wrong password or login");
        return ;
    }

    if (stud_model == nullptr)
        delete stud_model;
    stud_model = new QStandardItemModel;
    data_str = data_str.remove("200\nSuccess\nGETALL\n");
    data_str = data_str.remove("[");
    QStringList persons_lst = data_str.split("]&");
    QStringList header = QString(persons_lst[0]).remove(QRegExp("\\s[\\d\\w@\\-]*&")).split(":");
    QVector<QStringList> all_info;
    uint64_t counter = 0;


    for (QString &person_inf : persons_lst)
    {
        for (QString col_name: header)
        {
            person_inf = person_inf.remove(col_name);
        }
        person_inf = person_inf.remove(": ");
        QStringList person_inf_lst = person_inf.split("&");
        for (int i = 0; i < person_inf_lst.length(); i++)
        {
            item = new QStandardItem(person_inf_lst[i]);
            stud_model->setItem(counter, i, item);
        }
        counter++;
    }

    stud_model->setHorizontalHeaderLabels(header);
    ui->tableView->show();
    ui->tableView->setModel(stud_model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}


void MainWindow::responsePedagoReceived(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    this->setWindowTitle("");
    if (!data_str.startsWith("200"))
    {
        QMessageBox::critical(this, "Not logged in", "wrong password or login");
        return ;
    }

    if (pedago_model == nullptr)
        delete pedago_model;
    data_str = data_str.remove("200\nSuccess\nGETALL\n");
    data_str = data_str.remove("[");
    QStringList persons_lst = data_str.split("]&");
    QStringList header = QString(persons_lst[0]).remove(QRegExp("\\s[\\d\\w@\\-]*&")).split(":");
    QVector<QStringList> all_info;
    uint64_t counter = 0;

    pedago_model = new QStandardItemModel;
    for (QString &person_inf : persons_lst)
    {
        for (QString col_name: header)
        {
            person_inf = person_inf.remove(col_name);
        }
        person_inf = person_inf.remove(": ");
        QStringList person_inf_lst = person_inf.split("&");
        for (int i = 0; i < person_inf_lst.length(); i++)
        {
            item = new QStandardItem(person_inf_lst[i]);
            pedago_model->setItem(counter, i, item);
        }
        counter++;
    }

    pedago_model->setHorizontalHeaderLabels(header);
    ui->tableView->show();
    ui->tableView->setModel(pedago_model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_actionShow_all_pedagos_triggered()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl("http://localhost/t_users/CRUD_user.php");
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=GETALL&";

    this->setWindowTitle("Checking");
    connect(manager, &QNetworkAccessManager::finished,
            this, &MainWindow::responsePedagoReceived); //responseStudReceived - response handler
    data_str += "sOp=false";
    data.append((const QString &)data_str); //string to bytearray
    manager->post(request ,data);
}


void MainWindow::responseSubjReceived(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    this->setWindowTitle("");
    if (!data_str.startsWith("200"))
    {
        QMessageBox::critical(this, "Not logged in", "wrong password or login");
        return ;
    }

    if (subj_model == nullptr)
        delete subj_model;
    data_str = data_str.remove("200\nSuccess\nGETALL\n");
    data_str = data_str.remove("[");
    QStringList persons_lst = data_str.split("]&");
    QStringList header = QString(persons_lst[0]).remove(QRegExp("[\\d\\s\\w!?(){},./\\|\\-;\'\"]*&")).split(":");
    QVector<QStringList> all_info;
    uint64_t counter = 0;

    subj_model = new QStandardItemModel;
    for (QString &person_inf : persons_lst)
    {
        for (QString col_name: header)
        {
            person_inf = person_inf.remove(col_name);
        }
        person_inf = person_inf.remove(": ");
        QStringList person_inf_lst = person_inf.split("&");
        for (int i = 0; i < person_inf_lst.length(); i++)
        {
            item = new QStandardItem(person_inf_lst[i]);
            subj_model->setItem(counter, i, item);
        }
        counter++;
    }

    subj_model->setHorizontalHeaderLabels(header);
    ui->tableView->show();
    ui->tableView->setModel(subj_model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_actionShow_all_triggered()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl("http://localhost/t_subjects/CRUD_subjects.php");
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=GETALL";

    this->setWindowTitle("Checking");
    connect(manager, &QNetworkAccessManager::finished,
            this, &MainWindow::responseSubjReceived); //responseStudReceived - response handler
    data.append((const QString &)data_str); //string to bytearray
    manager->post(request ,data);
}

void MainWindow::responseLessonsReceived(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    this->setWindowTitle("");
    if (!data_str.startsWith("200"))
    {
        QMessageBox::critical(this, "Not logged in", "wrong password or login");
        return ;
    }

    if (lessons_model == nullptr)
        delete lessons_model;
    data_str = data_str.remove("200\nSuccess\nGETALL\n");
    data_str = data_str.remove("[");
    QStringList persons_lst = data_str.split("]&");
    QStringList header = QString(persons_lst[0]).remove(QRegExp("[\\d\\s\\w!?(){},./\\|\\-;\'\"]*&")).split(":");
    QVector<QStringList> all_info;
    uint64_t counter = 0;

    lessons_model = new QStandardItemModel;
    for (QString &person_inf : persons_lst)
    {
        for (QString col_name: header)
        {
            person_inf = person_inf.remove(col_name);
        }
        person_inf = person_inf.remove(": ");
        QStringList person_inf_lst = person_inf.split("&");
        for (int i = 0; i < person_inf_lst.length(); i++)
        {
            item = new QStandardItem(person_inf_lst[i]);
            lessons_model->setItem(counter, i, item);
        }
        counter++;
    }

    lessons_model->setHorizontalHeaderLabels(header);
    ui->tableView->show();
    ui->tableView->setModel(lessons_model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_actionShow_all_2_triggered()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl("http://localhost/t_lessons/CRUD_lessons.php");
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=GETALL";

    this->setWindowTitle("Checking");
    connect(manager, &QNetworkAccessManager::finished,
            this, &MainWindow::responseLessonsReceived); //responseStudReceived - response handler
    data.append((const QString &)data_str); //string to bytearray
    manager->post(request ,data);
}

void MainWindow::responseTasksReceived(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    this->setWindowTitle("");
    if (!data_str.startsWith("200"))
    {
        QMessageBox::critical(this, "Not logged in", "wrong password or login");
        return ;
    }

    if (tasks_model == nullptr)
        delete tasks_model;
    data_str = data_str.remove("200\nSuccess\nGETALL\n");
    data_str = data_str.remove("[");
    QStringList persons_lst = data_str.split("]&");
    QStringList header = QString(persons_lst[0]).remove(QRegExp("[\\d\\s\\w!?(){},./\\|\\-;\'\"]*&")).split(":");
    QVector<QStringList> all_info;
    uint64_t counter = 0;

    tasks_model = new QStandardItemModel;
    for (QString &person_inf : persons_lst)
    {
        for (QString col_name: header)
        {
            person_inf = person_inf.remove(col_name);
        }
        person_inf = person_inf.remove(": ");
        QStringList person_inf_lst = person_inf.split("&");
        for (int i = 0; i < person_inf_lst.length(); i++)
        {
            item = new QStandardItem(person_inf_lst[i]);
            tasks_model->setItem(counter, i, item);
        }
        counter++;
    }

    tasks_model->setHorizontalHeaderLabels(header);
    ui->tableView->show();
    ui->tableView->setModel(tasks_model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_actionShow_all_4_triggered()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl("http://localhost/t_tasks/CRUD_tasks.php");
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=GETALL";

    this->setWindowTitle("Checking");
    connect(manager, &QNetworkAccessManager::finished,
            this, &MainWindow::responseTasksReceived); //responseStudReceived - response handler
    data.append((const QString &)data_str); //string to bytearray
    manager->post(request ,data);
}

void MainWindow::on_actionexit_triggered()
{
    this->close();
}

void MainWindow::on_actionLog_out_triggered()
{
    ui->tableView->hide();
    this->login = "";
    auth_window->exec();
}

void MainWindow::responseGroupsReceived(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    this->setWindowTitle("");
    if (!data_str.startsWith("200"))
    {
        QMessageBox::critical(this, "Not logged in", "wrong password or login");
        return ;
    }

    if (groups_model == nullptr)
        delete groups_model;
    data_str = data_str.remove("200\nSuccess\nGETALL\n");
    data_str = data_str.remove("[");
    QStringList persons_lst = data_str.split("]&");
    QStringList header = QString(persons_lst[0]).remove(QRegExp("[\\d\\s\\w!?(){},./\\|\\-;\'\"]*&")).split(":");
    QVector<QStringList> all_info;
    uint64_t counter = 0;

    groups_model = new QStandardItemModel;
    for (QString &person_inf : persons_lst)
    {
        for (QString col_name: header)
        {
            person_inf = person_inf.remove(col_name);
        }
        person_inf = person_inf.remove(": ");
        QStringList person_inf_lst = person_inf.split("&");
        for (int i = 0; i < person_inf_lst.length(); i++)
        {
            item = new QStandardItem(person_inf_lst[i]);
            groups_model->setItem(counter, i, item);
        }
        counter++;
    }

    groups_model->setHorizontalHeaderLabels(header);
    ui->tableView->show();
    ui->tableView->setModel(groups_model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_actionShow_all_3_triggered()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl("http://localhost/t_groups/CRUD_groups.php");
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=GETALL";

    this->setWindowTitle("Checking");
    connect(manager, &QNetworkAccessManager::finished,
            this, &MainWindow::responseTasksReceived); //responseStudReceived - response handler
    data.append((const QString &)data_str); //string to bytearray
    manager->post(request ,data);
}


void MainWindow::responseTTUReceived(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    QString data_str(data);

    this->setWindowTitle("");
    if (!data_str.startsWith("200"))
    {
        QMessageBox::critical(this, "Not logged in", "wrong password or login");
        return ;
    }

    if (TTU_model == nullptr)
        delete TTU_model;
    data_str = data_str.remove("200\nSuccess\nGETALL\n");
    data_str = data_str.remove("[");
    QStringList persons_lst = data_str.split("]&");
    QStringList header = QString(persons_lst[0]).remove(QRegExp("[\\d\\s\\w!?(){},./\\|\\-;\'\"]*&")).split(":");
    QVector<QStringList> all_info;
    uint64_t counter = 0;

    TTU_model = new QStandardItemModel;
    for (QString &person_inf : persons_lst)
    {
        for (QString col_name: header)
        {
            person_inf = person_inf.remove(col_name);
        }
        person_inf = person_inf.remove(": ");
        QStringList person_inf_lst = person_inf.split("&");
        for (int i = 0; i < person_inf_lst.length(); i++)
        {
            item = new QStandardItem(person_inf_lst[i]);
            TTU_model->setItem(counter, i, item);
        }
        counter++;
    }

    TTU_model->setHorizontalHeaderLabels(header);
    ui->tableView->show();
    ui->tableView->setModel(TTU_model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_actionShow_all_5_triggered()
{
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    const QUrl url = QUrl("http://localhost/t_tasks_users/CRUD_tasks.php");
    QNetworkRequest request(url);
    QByteArray data;
    QString data_str = "type=GETALL";

    this->setWindowTitle("Checking");
    connect(manager, &QNetworkAccessManager::finished,
            this, &MainWindow::responseTTUReceived); //responseTTUReceived - response handler
    data.append((const QString &)data_str); //string to bytearray
    manager->post(request ,data);
}

void MainWindow::on_actionSearch_triggered()
{
    QVector<QPair<QString, types_add>> rows(2);
    rows[0].first = "Task id";
    rows[0].second = id;
    rows[1].first = "User id";
    rows[1].second = uid;

    if ((this->dialog_window) != nullptr)
    {
        delete (this->dialog_window);
        this->dialog_window = nullptr;
    }
    this->responseFromChild = "";
    this->dialog_window = new DialogSearch(this, rows, &(this->responseFromChild), "http://localhost/t_tasks_users/CRUD_tasks.php");
    this->dialog_window->setWindowTitle("Search task result");
    this->dialog_window->setModal(true);
    this->dialog_window->exec();
    if (QString::compare(this->responseFromChild, ""))
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "", "Show you the result?", QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            if (tmp_model == nullptr)
                delete tmp_model;
            QString data_str = QString(this->responseFromChild).remove("200\nSuccess\nGET\n");
            data_str= data_str.remove("[");
            QStringList persons_lst = data_str.split("]&");
            QStringList header = QString(persons_lst[0]).remove(QRegExp("[\\d\\s\\w!?(){},./\\|\\-;\'\"]*&")).split(":");
            QVector<QStringList> all_info;
            uint64_t counter = 0;

            tmp_model = new QStandardItemModel;
            for (QString &person_inf : persons_lst)
            {
                for (QString col_name: header)
                {
                    person_inf = person_inf.remove(col_name);
                }
                person_inf = person_inf.remove(": ");
                QStringList person_inf_lst = person_inf.split("&");
                for (int i = 0; i < person_inf_lst.length(); i++)
                {
                    item = new QStandardItem(person_inf_lst[i]);
                    tmp_model->setItem(counter, i, item);
                }
                counter++;
            }

            tmp_model->setHorizontalHeaderLabels(header);
            ui->tableView->show();
            ui->tableView->setModel(tmp_model);
            ui->tableView->resizeRowsToContents();
            ui->tableView->resizeColumnsToContents();
        }
    }
    this->responseFromChild = "";
}

void MainWindow::on_actionCreate_new_student_triggered()
{
    QVector<QPair<QString, types_add>> rows(4);
    rows[0].first = "Login";
    rows[0].second = Login;
    rows[1].first = "Password";
    rows[1].second = Password;
    rows[2].first = "Surname";
    rows[2].second = surname;
    rows[3].first = "Name";
    rows[3].second = name;
    rows[3].first = "Email";
    rows[3].second = email;

    if ((this->dialog_window) != nullptr)
    {
        delete (this->dialog_window);
        this->dialog_window = nullptr;
    }
    this->dialog_window = new DialogAdd(this, rows, "http://localhost/t_users/CRUD_user.php");
    this->dialog_window->setWindowTitle("Add student");
    this->dialog_window->setModal(true);
    this->dialog_window->exec();
}

void MainWindow::on_actionDelete_student_triggered()
{
    QVector<QPair<QString, types_add>> rows(1);
    rows[0].first = "Login";
    rows[0].second = Login;

    if ((this->dialog_window) != nullptr)
    {
        delete (this->dialog_window);
        this->dialog_window = nullptr;
    }
    this->dialog_window = new DialogDelete(this, rows, "http://localhost/t_users/CRUD_user.php");
    this->dialog_window->setModal(true);
    this->dialog_window->setWindowTitle("Delete student");
    this->dialog_window->exec();
}

void MainWindow::on_actionCreate_triggered()
{
    QVector<QPair<QString, types_add>> rows(3);
    rows[0].first = "Subject name";
    rows[0].second = name;
    rows[1].first = "Description";
    rows[1].second = description;
    rows[2].first = "Author UID";
    rows[2].second = uid;

    if ((this->dialog_window) != nullptr)
    {
        delete (this->dialog_window);
        this->dialog_window = nullptr;
    }
    this->dialog_window = new DialogAdd(this, rows, "http://localhost/t_subjects/CRUD_subjects.php");
    this->dialog_window->setWindowTitle("Add Subject");
    this->dialog_window->setModal(true);
    this->dialog_window->exec();
}

void MainWindow::on_actionAdd_triggered()
{
    QVector<QPair<QString, types_add>> rows(7);
    rows[0].first = "Lesson name";
    rows[0].second = name;
    rows[1].first = "Description";
    rows[1].second = description;
    rows[2].first = "Author UID";
    rows[2].second = uid;
    rows[3].first = "Subject id";
    rows[3].second = subj_id;
    rows[4].first = "Control type";
    rows[4].second = control_type;
    rows[5].first = "Lessons theory";
    rows[5].second = theory;
    rows[6].first = "Tasks recomendation";
    rows[6].second = recomend;

    if ((this->dialog_window) != nullptr)
    {
        delete (this->dialog_window);
        this->dialog_window = nullptr;
    }
    this->dialog_window = new DialogAdd(this, rows, "http://localhost/t_lessons/CRUD_lessons.php");
    this->dialog_window->setWindowTitle("Add Lesson");
    this->dialog_window->setModal(true);
    this->dialog_window->exec();
}

void MainWindow::on_actionAdd_3_triggered()
{
    QVector<QPair<QString, types_add>> rows(4);
    rows[0].first = "Lesson ID";
    rows[0].second = l_id;
    rows[1].first = "Question";
    rows[1].second = quest;
    rows[2].first = "Correct Answer";
    rows[2].second = corr_answer;
    rows[3].first = "Answers \n(comma-separated)";
    rows[3].second = answer;


    if ((this->dialog_window) != nullptr)
    {
        delete (this->dialog_window);
        this->dialog_window = nullptr;
    }
    this->dialog_window = new DialogAdd(this, rows, "http://localhost/t_tasks/CRUD_tasks.php");
    this->dialog_window->setWindowTitle("Add Task");
    this->dialog_window->setModal(true);
    this->dialog_window->exec();
}

void MainWindow::on_actionAdd_2_triggered()
{
    QVector<QPair<QString, types_add>> rows(4);
    rows[0].first = "Group name";
    rows[0].second = name;
    rows[1].first = "Learning type";
    rows[1].second = learning_type;
    rows[2].first = "Start date";
    rows[2].second = start_date;
    rows[3].first = "End data";
    rows[3].second = end_date;


    if ((this->dialog_window) != nullptr)
    {
        delete (this->dialog_window);
        this->dialog_window = nullptr;
    }
    this->dialog_window = new DialogAdd(this, rows, "http://localhost/t_groups/CRUD_groups.php");
    this->dialog_window->setWindowTitle("Add Group");
    this->dialog_window->setModal(true);
    this->dialog_window->exec();
}

void MainWindow::on_actionDelete_3_triggered()
{
    QVector<QPair<QString, types_add>> rows(1);
    rows[0].first = "Subject id";
    rows[0].second = id;

    if ((this->dialog_window) != nullptr)
    {
        delete (this->dialog_window);
        this->dialog_window = nullptr;
    }
    this->dialog_window = new DialogDelete(this, rows, "http://localhost/t_subjects/CRUD_subjects.php");
    this->dialog_window->setModal(true);
    this->dialog_window->setWindowTitle("Delete Subject");
    this->dialog_window->exec();
}

void MainWindow::on_actionDelte_triggered()
{
    QVector<QPair<QString, types_add>> rows(1);
    rows[0].first = "Lesson id";
    rows[0].second = id;

    if ((this->dialog_window) != nullptr)
    {
        delete (this->dialog_window);
        this->dialog_window = nullptr;
    }
    this->dialog_window = new DialogDelete(this, rows, "http://localhost/t_lessons/CRUD_lessons.php");
    this->dialog_window->setModal(true);
    this->dialog_window->setWindowTitle("Delete Lesson");
    this->dialog_window->exec();
}

void MainWindow::on_actionDelete_triggered()
{
    QVector<QPair<QString, types_add>> rows(1);
    rows[0].first = "Task id";
    rows[0].second = id;

    if ((this->dialog_window) != nullptr)
    {
        delete (this->dialog_window);
        this->dialog_window = nullptr;
    }
    this->dialog_window = new DialogDelete(this, rows, "http://localhost/t_tasks/CRUD_tasks.php");
    this->dialog_window->setModal(true);
    this->dialog_window->setWindowTitle("Delete Task");
    this->dialog_window->exec();
}

void MainWindow::on_actionDelete_4_triggered()
{
    QVector<QPair<QString, types_add>> rows(1);
    rows[0].first = "Group id";
    rows[0].second = id;

    if ((this->dialog_window) != nullptr)
    {
        delete (this->dialog_window);
        this->dialog_window = nullptr;
    }
    this->dialog_window = new DialogDelete(this, rows, "http://localhost/t_groups/CRUD_groups.php");
    this->dialog_window->setModal(true);
    this->dialog_window->setWindowTitle("Delete Group");
    this->dialog_window->exec();
}
