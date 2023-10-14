//
// Created by cvrain on 23-10-10.
//

#pragma once

#include <json/json.h>
#include <string>
#include <optional>

//模板接受整型，浮点型，字符串, 布尔型
template<class T>
concept CommonJsonType = std::is_integral_v<T> || std::is_floating_point_v<T> || std::is_same_v<T, std::string> || std::is_same_v<T, bool>;

class JsonMaker {
public:
    template<class T>
    static std::optional<std::string> GetItem(const Json::Value& json_text, const std::string &key);

    template<CommonJsonType T>
    JsonMaker& Append(const std::string& key, const T& value);

    [[nodiscard]] std::string GetStdString() const;

    void Clear();

private:
    Json::Value json_root{};
};

template<CommonJsonType T>
JsonMaker &JsonMaker::Append(const std::string &key, const T &value) {
    json_root[key] = value;
    return *this;
}


template<class T>
std::optional<std::string> JsonMaker::GetItem(const Json::Value& json_text, const std::string &key) {
    if(!json_text[key].is<T>()){
        return std::nullopt;
    }
    return json_text[key].as<T>();
}


