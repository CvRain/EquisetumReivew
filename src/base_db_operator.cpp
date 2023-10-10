//
// Created by cvrain on 23-10-10.
//

#include "base_db_operator.h"

BaseDbOperator::BaseDbOperator(const std::filesystem::path& db_path) {
    leveldb::Options options;
    options.create_if_missing = true;
    const auto status = leveldb::DB::Open(options, db_path, &db);
    if(!status.ok()){
        LOG_F(ERROR, "%s", status.ToString().data());
        assert(status.ok());
    }
    LOG_F(INFO, "Open level db: %s", db_path.string().data());
}

void BaseDbOperator::Delete() {
    delete db;
    db = nullptr;
}

BaseDbOperator::~BaseDbOperator() {
    if(db != nullptr){
        Delete();
    }
}

BaseDbOperator::DbResult BaseDbOperator::Put(const std::string_view &key, const std::string_view &value) {
    const auto result = db->Put(leveldb::WriteOptions(), key.data(), value.data());
    return std::make_pair(result, value);
}

BaseDbOperator::DbResult BaseDbOperator::Get(const std::string_view &key) {
    std::string value;
    const auto result = db->Get(leveldb::ReadOptions(), key.data(), &value);
    return std::make_pair(result, value);
}
