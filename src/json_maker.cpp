//
// Created by cvrain on 23-10-10.
//

#include "json_maker.h"

std::string JsonMaker::GetStdString() const {
    return json_root.toStyledString();
}

void JsonMaker::Clear() {
    json_root = Json::Value{};
}
