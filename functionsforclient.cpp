#include "functionsforclient.h"

FunctionsForClient::FunctionsForClient()
{
    ui_auth = new AuthRegForm;
    ui_auth->show();
    connect(ui_auth,&AuthRegForm::is_auth, this,&FunctionsForClient::is_auth);

}
void FunctionsForClient::is_auth(QString log, QString pass)
{
    if (log == "user" && pass == "123")
    {
        delete ui_auth;
        //emit on_auth_ok();
        ui_main = new MainWindow;
        ui_main->show();
    }
}
