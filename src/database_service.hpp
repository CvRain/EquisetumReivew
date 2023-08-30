//
// Created by cvrain on 23-8-29.
//

#pragma once

#include <SQLiteCpp/SQLiteCpp.h>
#include <loguru/loguru.hpp>

//这个类是一个单例类
//负责管理SQLite数据库的连接和基本操作

class DatabaseService final {
public:
    static DatabaseService &GetInstance();

private:
    DatabaseService();

    ~DatabaseService();

    SQLite::Database database;
};

