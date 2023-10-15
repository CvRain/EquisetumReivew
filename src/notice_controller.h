//
// Created by cvrain on 23-10-15.
//

#pragma once

#include "db_notice_operator.h"
#include <QObject>
#include <QString>


class NoticeController : public QObject{
    Q_OBJECT
public:
    explicit NoticeController(QObject *parent = nullptr);
    void Test();
public slots:

private:
    //DbOperator::DbNoticeOperator& notice_operator;

};
