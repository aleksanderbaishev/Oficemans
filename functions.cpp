#include "function.h"
#include <QStringList>
#include <QDebug>
#include <regex>
#include "database.h"

bool isValidEmail(QString email)
{
    std::string email2 = email.trimmed().toUtf8().constData();
    qDebug() << email2;
    const std::regex emailPattern(
        "(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$)");

    return std::regex_match(email2, emailPattern);
}

QByteArray parsing(QString &data_from_client){
    QStringList client_data_list = data_from_client.split("&");
    QString func_name = client_data_list.front();

    if (func_name.compare("auth") == 0)
    {
        client_data_list.pop_front();
        return auth(client_data_list.at(0), client_data_list.at(1));
    }
    else if (func_name.compare("reg") == 0)
    {
        client_data_list.pop_front();
        return reg(client_data_list.at(0), client_data_list.at(1), client_data_list.at(2));
    }
    else
    {
        return "error\n";
    }
}

QByteArray auth(QString log, QString pass)
{
    pass = pass.trimmed();
    QStringList querySrc;
    querySrc.append("SELECT login, password FROM users WHERE login == :login and password == :password;");
    querySrc.append(":login");
    querySrc.append(log);
    querySrc.append(":password");
    querySrc.append(pass);
    qDebug()<<querySrc;
    querySrc = Database::getInstance().queryToDatabase(querySrc);
    if (querySrc.size() > 0)
    {
        return (QString("auth+&") + log + "\n").toUtf8();
    }
    else
    {
        return "auth-\n";
    }
}

QByteArray reg(QString log, QString pass, QString mail)
{
    if (isValidEmail(mail))
    {
        QStringList querySrc;
        querySrc.append("SELECT login, password FROM users WHERE login == :login");
        querySrc.append(":login");
        querySrc.append(log);
        querySrc.append(":password");
        querySrc.append(pass);
        querySrc = Database::getInstance().queryToDatabase(querySrc);
        if (querySrc.size() > 0)
        {
            return "reg-\n";
        }
        else
        {
            querySrc.append("INSERT INTO users (login, password, email) VALUES (:login, :password, :email);");
            querySrc.append(":login");
            querySrc.append(log);
            querySrc.append(":password");
            querySrc.append(pass);
            querySrc.append(":email");
            querySrc.append(mail);
            querySrc = Database::getInstance().queryToDatabase(querySrc);
            if (querySrc.size() > 0)
            {
                return (QString("reg+&") + log + "\n").toUtf8();
            }
            else
            {
                return "failed to register user\n";
            }
        }
    }
    else
    {
        return "wrong email\n";
    }
}
