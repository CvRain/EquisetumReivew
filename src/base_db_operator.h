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
#include <vector>
#include <map>

namespace DbOperator {
    const std::filesystem::path default_db_directory = "leveldb";
    using DbResult = std::pair<leveldb::Status, const std::string_view>;
    using DbKeyValue = std::map<std::string_view, std::string_view>;
    using DbResultList = std::pair<leveldb::Status, DbKeyValue>;

    class BaseDbOperator {
    public:
        explicit BaseDbOperator(const std::filesystem::path &db_path);

        void RemoveDb();

        virtual DbResult Put(const std::string_view &key, const std::string_view &value);

        virtual DbResult Get(const std::string_view &key);

        virtual DbResultList GetAll();

        virtual DbResult Delete(const std::string_view &key);

        ~BaseDbOperator();

    protected:
        leveldb::DB *db{};
    };

    class BaseOperator{
    public:
        virtual std::pair<leveldb::Status, const std::string_view> Create(const std::string_view& value) = 0;
        virtual DbResult Retrieve(const std::string_view& key) = 0;
        virtual leveldb::Status Update(const std::string_view& key, const std::string_view& value) = 0;
        virtual leveldb::Status Delete(const std::string_view& key) = 0;
        virtual DbResultList GetAll() = 0;
    };

}

