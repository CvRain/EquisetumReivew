//
// Created by cvrain on 23-10-10.
//

#pragma once

#include "base_db_operator.h"
#include "id_generator.h"
#include <filesystem>

namespace DbOperator {
    const std::filesystem::path notice_db = "notice";

    class DbNoticeOperator : public BaseOperator {
    public:
        static DbNoticeOperator& GetInstance();

        std::pair<leveldb::Status, const std::string_view> Create(const std::string_view &value) override;

        leveldb::Status Retrieve(const std::string_view &key) override;

        leveldb::Status Update(const std::string_view &key, const std::string_view &value) override;

        leveldb::Status Delete(const std::string_view &key) override;

    private:
        explicit DbNoticeOperator();

        ~DbNoticeOperator() = default;

        DbNoticeOperator(const DbNoticeOperator &) = default;

        DbNoticeOperator &operator=(const DbNoticeOperator &) = default;

        BaseDbOperator db_operator;
    };
}

