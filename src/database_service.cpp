//
// Created by cvrain on 23-8-29.
//

#include "database_service.hpp"

DatabaseService::DatabaseService() : database(SQLite::Database(".sqlite.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE)){
    LOG_F(INFO, "sqlite3 version: %s(%s)", SQLite::VERSION, SQLite::getLibVersion());
    LOG_F(INFO, "sqliteC++ Version: %s", SQLITECPP_VERSION);
    LOG_F(INFO, "Database created successfully: %s", database.getFilename().c_str());
}

DatabaseService::~DatabaseService() {
    LOG_F(INFO, "Database closed successfully: %s", database.getFilename().c_str());
}

DatabaseService &DatabaseService::GetInstance() {
    static auto getInstance = DatabaseService();
    return getInstance;
}