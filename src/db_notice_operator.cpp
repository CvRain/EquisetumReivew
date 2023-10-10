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

    leveldb::Status DbNoticeOperator::Create(const std::string_view &value) {
        return leveldb::Status::OK();
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
