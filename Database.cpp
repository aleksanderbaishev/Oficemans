#include "Database.h"

Database* Database::p_instance = nullptr;
DatabaseDestroyer Database::destroyer;

Database::Database(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Database.db");
    if (!db.open()) {
        qDebug() << "Error: failed to open database";
    }
}

bool Database::createTable(){
    QSqlQuery query(db);
    return query.exec("create table users(id integer primary key not null, login text not null unique, password text not null, email text not null unique);");
}

Database::~Database(){
    db.close();
}

Database& Database::getInstance(){
    if(!p_instance){
        p_instance = new Database();
        p_instance->createTable();
    }
    return *p_instance;
}

QSqlDatabase& Database::getDatabase(){
    return db;
}

DatabaseDestroyer::~DatabaseDestroyer() {
    delete p_instance;
}

void DatabaseDestroyer::initialize(Database *p) {
    p_instance = p;
}

QStringList Database::queryToDatabase(QStringList src){
    QSqlQuery query(db);
    query.prepare(src[0]);
    int i = 1;
    while(i < src.size())
    {
        query.bindValue(src[i], src[i+1]);
        i+=2;
    }

    QStringList res;
    if(src[0].contains("SELECT")){
        // qDebug() << query.exec();
        // qDebug() << query.first();
        if(query.exec() && query.first()){
            res.append("found");
            return res;
        }
    }
    else{
        if(query.exec()){
            res.append("ok");
            return res;
        }
    }
    return res;
}
