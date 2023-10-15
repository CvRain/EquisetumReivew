//
// Created by cvrain on 23-10-15.
//

#include "notice_controller.h"

NoticeController::NoticeController(QObject *parent) : QObject(parent){
    DbOperator::SingletonTemplate<DbOperator::DbNoticeOperator>::GetInstance();
}

void NoticeController::Test() {
}
