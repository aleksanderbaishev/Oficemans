#include "functions.h"
#include <QString>
#include <QDebug>
#include <QCoreApplication>

QByteArray parsing (QString &data_from_client) {
    QStringList data_from_client_list = data_from_client.split(QLatin1Char('&'));
    QString nameOfFunc = data_from_client_list.front();
    data_from_client_list.pop_front();
    if (nameOfFunc == "auth")
        return auth(data_from_client_list.at(0), data_from_client_list.at(1));
    if (nameOfFunc == "reg")
        return reg(data_from_client_list.at(0), data_from_client_list.at(1), data_from_client_list.at(2));
    else
        return "error1\r\n";
}

QByteArray auth (QString log, QString pass) {
    if (log == "zenia" and pass == "111\r\n")
        return "done\r\n";
    else
        return "error2\r\n";
}

QByteArray reg (QString log, QString pass, QString mail) {
    if (log == "zenia" and pass == "111" and mail == "zenia@gmail.com\r\n")
        return "done\r\n";
    else
        return "error3\r\n";
}
