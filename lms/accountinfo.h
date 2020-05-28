#ifndef ACCOUNTINFO_H
#define ACCOUNTINFO_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QStandardItemModel>
#include <QStandardItem>

namespace Ui {
class accountInfo;
}

class accountInfo : public QWidget
{
    Q_OBJECT

public:
    explicit accountInfo(QWidget *parent = nullptr,QString *qlogin = nullptr);
    ~accountInfo();

private slots:
    void on_returnBtn_clicked();
    void startInit(void);
    void getResponseReceived(QNetworkReply *reply);

    void on_ExitBtn_clicked();

    void on_update_clicked();
    void patchResponseReceived(QNetworkReply *reply);

    void on_PasswordLineEdit_textChanged(const QString &arg1);

    void on_NameLineEdit_textChanged(const QString &arg1);

    void on_SurnameLineEdit_textChanged(const QString &arg1);

    void on_EmailLineEdit_textChanged(const QString &arg1);
    void ft_checkEditLines();

private:
    Ui::accountInfo     *ui;
    QString             *qlogin;
    QStandardItemModel  *model;
    QStandardItem       *item;
    QStringList         fields;
    bool                update_launched;
    QVector<bool>       validate_fields;
};

#endif // ACCOUNTINFO_H
