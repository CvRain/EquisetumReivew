//
// Created by cvrain on 23-10-10.
//

#pragma once

#include "base_db_operator.h"
#include "id_generator.h"
#include "json_maker.h"
#include <filesystem>

namespace DbOperator {
    const std::filesystem::path notice_db = "notice";

    class DbNoticeOperator : public BaseOperator {
    public:
        static DbNoticeOperator& GetInstance();

        DbResult Create(const std::string_view &value) override;

        DbResult Retrieve(const std::string_view &key) override;

        DbResult Update(const std::string_view &key, const std::string_view &value) override;

        DbResult Delete(const std::string_view &key) override;

        DbResultList GetAll() override;

    private:
        explicit DbNoticeOperator();

        ~DbNoticeOperator() = default;

        DbNoticeOperator(const DbNoticeOperator &) = default;

        DbNoticeOperator &operator=(const DbNoticeOperator &) = default;

        BaseDbOperator db_operator;
    };
}

