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

    leveldb::Status DbNoticeOperator::Retrieve(const std::string_view &key) {
        return leveldb::Status::OK();
    }

    leveldb::Status DbNoticeOperator::Update(const std::string_view &key, const std::string_view &value) {
        return leveldb::Status::OK();
    }

    leveldb::Status DbNoticeOperator::Delete(const std::string_view &key) {
        return leveldb::Status::OK();
    }


}
