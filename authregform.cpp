#include "authregform.h"
#include "ui_authregform.h"

AuthRegForm::AuthRegForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AuthRegForm)
{
    ui->setupUi(this);
    ui->labelEmail->setVisible(false);
    ui->lineEmail->setVisible(false);
    ui->pushRegister->setVisible(false);
}

AuthRegForm::~AuthRegForm()
{
    delete ui;
}

void AuthRegForm::on_pushAuth_clicked()
{
    emit is_auth(ui->lineLogin->text(),ui->linePassword->text());
}


void AuthRegForm::on_pushChange_clicked()
{
    bool flag = ui->labelEmail->isVisible();

    ui->labelEmail->setVisible(!flag);
    ui->lineEmail->setVisible(!flag);
    ui->pushRegister->setVisible(!flag);
    ui->pushAuth->setVisible(flag);

}

void AuthRegForm::on_pushButton_clicked(){}
/*
FunctionsForClient* AuthRegForm:: get_funk()
{
    return &(this->func);
}
*/
