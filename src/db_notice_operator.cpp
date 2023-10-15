//
// Created by cvrain on 23-10-10.
//

#include "db_notice_operator.h"

namespace DbOperator {

    DbNoticeOperator::DbNoticeOperator()
    : db_operator(default_db_directory / notice_db),  SingletonTemplate<DbNoticeOperator>(){
    }

    DbResult DbNoticeOperator::Create(const std::string_view &value) {
        auto uuid = IdGenerator::GenerateObjectId();

        JsonMaker maker{};
        const auto result = maker.Append<std::string>("create", IdGenerator::GenerateRandomNumString())
                .Append<std::string>("uuid", uuid)
                .Append<std::string>("content", value.data())
                .GetStdString();

        const auto status = db_operator.Put(uuid, result);
        return std::make_pair(status.first, uuid);
    }

    DbResult DbNoticeOperator::Retrieve(const std::string_view &key) {
        const auto result = db_operator.Get(key);
        return result;
    }

    DbResult DbNoticeOperator::Update(const std::string_view &key, const std::string_view &value) {
        const auto result = db_operator.Get(key);
        return result;

    }

    DbResult DbNoticeOperator::Delete(const std::string_view &key) {
        const auto result = db_operator.Delete(key);
        return result;
    }

    DbResultList DbNoticeOperator::GetAll() {
        const auto result = db_operator.GetAll();
        return result;
    }


}
