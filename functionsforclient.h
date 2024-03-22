#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QObject>
#include "mainwindow.h"
#include "authregform.h"
class FunctionsForClient: public QObject
{
    Q_OBJECT
public:
    FunctionsForClient();

signals:
    void on_auth_ok();
private:
    MainWindow * ui_main;
    AuthRegForm * ui_auth;
public slots:
    void is_auth(QString, QString);
};

#endif // FUNCTIONSFORCLIENT_H
