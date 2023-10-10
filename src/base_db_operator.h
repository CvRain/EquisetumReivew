//
// Created by cvrain on 23-10-10.
//

#pragma once

#include <filesystem>
#include <leveldb/db.h>
#include <loguru/loguru.hpp>
#include <utility>
#include <string>
#include <string_view>

class BaseDbOperator {
public:
    using DbResult = std::pair<leveldb::Status, const std::string_view>;
    explicit BaseDbOperator(const std::filesystem::path& db_path);
    void Delete();
    virtual DbResult Put(const std::string_view& key, const std::string_view& value);
    virtual DbResult Get(const std::string_view& key);
    ~BaseDbOperator();
protected:
    leveldb::DB *db;
};


