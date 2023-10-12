//
// Created by cvrain on 23-10-10.
//

#include "db_notice_operator.h"

namespace DbOperator{

    DbNoticeOperator::DbNoticeOperator(): db_operator(default_db_directory/notice_db){
    }

    DbNoticeOperator &DbNoticeOperator::GetInstance() {
        static auto db_operator = DbNoticeOperator();
        return db_operator;
    }

    std::pair<leveldb::Status, const std::string_view> DbNoticeOperator::Create(const std::string_view &value) {
        auto uuid = IdGenerator::GenerateObjectId();
        const auto status = db_operator.Put(uuid, value);
        return std::make_pair(status.first, uuid);
    }

    DbResult DbNoticeOperator::Retrieve(const std::string_view &key) {
        const auto result = db_operator.Get(key);
        return result;
    }

    leveldb::Status DbNoticeOperator::Update(const std::string_view &key, const std::string_view &value) {
        const auto result = db_operator.Get(key);
        return db_operator.Put(key, value).first;

    }

    leveldb::Status DbNoticeOperator::Delete(const std::string_view &key) {
        const auto result = db_operator.Delete(key);
        return result.first;
    }

    DbResultList DbNoticeOperator::GetAll() {
        const auto result = db_operator.GetAll();
        return result;
    }


}
