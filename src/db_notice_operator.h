//
// Created by cvrain on 23-10-10.
//

#pragma once

#include "singleton_template.h"
#include "base_db_operator.h"
#include "id_generator.h"
#include "json_maker.h"
#include <filesystem>

namespace DbOperator {
    const std::filesystem::path notice_db = "notice";

    class DbNoticeOperator : public BaseOperator, public SingletonTemplate<DbNoticeOperator> {
    public:
        explicit DbNoticeOperator();

        DbResult Create(const std::string_view &value) override;

        DbResult Retrieve(const std::string_view &key) override;

        DbResult Update(const std::string_view &key, const std::string_view &value) override;

        DbResult Delete(const std::string_view &key) override;

        DbResultList GetAll() override;

    private:

        BaseDbOperator db_operator;
    };
}

