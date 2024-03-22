#ifndef AUTHREGFORM_H
#define AUTHREGFORM_H

#include <QWidget>
#include "functionsforclient.h"
namespace Ui {
class AuthRegForm;
}

class AuthRegForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthRegForm(QWidget *parent = nullptr);
    ~AuthRegForm();
    //FunctionsForClient* get_funk();

signals:
      void is_auth(QString,QString);

private slots:
    void on_pushButton_clicked();

    void on_pushChange_clicked();

    void on_pushAuth_clicked();

private:
    Ui::AuthRegForm *ui;
    //FunctionsForClient func;

};

#endif // AUTHREGFORM_H
