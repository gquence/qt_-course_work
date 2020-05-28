#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include "authwindow.h"
#include "accountinfo.h"
#include "dialogsearch.h"
#include "dialogadd.h"
#include "dialogdelete.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionYour_Account_triggered();

    void on_actionShow_all_student_triggered();
    void responseStudReceived(QNetworkReply *reply);

    void on_actionShow_all_pedagos_triggered();
    void responsePedagoReceived(QNetworkReply *reply);

    void on_actionShow_all_triggered();
    void responseSubjReceived(QNetworkReply *reply);

    void on_actionShow_all_2_triggered();
    void responseLessonsReceived(QNetworkReply *reply);

    void on_actionShow_all_4_triggered();
    void responseTasksReceived(QNetworkReply *reply);

    void on_actionexit_triggered();

    void on_actionLog_out_triggered();

    void on_actionShow_all_3_triggered();
    void responseGroupsReceived(QNetworkReply *reply);

    void on_actionShow_all_5_triggered();
    void responseTTUReceived(QNetworkReply *reply);

    void on_actionSearch_triggered();

    void on_actionCreate_new_student_triggered();

    void on_actionDelete_student_triggered();

    void on_actionCreate_triggered();

    void on_actionAdd_triggered();

    void on_actionAdd_3_triggered();

    void on_actionAdd_2_triggered();

    void on_actionDelete_3_triggered();

    void on_actionDelte_triggered();

    void on_actionDelete_triggered();

    void on_actionDelete_4_triggered();

private:
    Ui::MainWindow      *ui;
    AuthWindow          *auth_window;
    accountInfo         *account_window;
    QDialog             *dialog_window;
    QStandardItemModel  *stud_model;
    QStandardItemModel  *pedago_model;
    QStandardItemModel  *subj_model;
    QStandardItemModel  *lessons_model;
    QStandardItemModel  *tasks_model;
    QStandardItemModel  *groups_model;
    QStandardItemModel  *TTU_model;
    QStandardItemModel  *tmp_model;
    QStandardItem       *item;
    QString             login;
    QString             responseFromChild;
};
#endif // MAINWINDOW_H
