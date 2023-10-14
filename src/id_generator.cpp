//
// Created by cvrain on 23-10-10.
//

#include "id_generator.h"

uint32_t IdGenerator::GenerateTimestamp() {
    const auto now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(now.time_since_epoch()).count();
}

uint32_t IdGenerator::GenerateRandomNum() {
    const auto timestamp = GenerateTimestamp();
    std::default_random_engine engine(timestamp);
    std::uniform_int_distribution<uint32_t> uniform{};
    return uniform(engine);
}

std::string IdGenerator::GenerateTimeString(const int length) {
    const auto timestamp = GenerateTimestamp();
    if (length == -1)
        return std::to_string(timestamp);
    auto str = std::to_string(timestamp % (uint32_t) pow(10, length));
    return str;
}

std::string IdGenerator::GenerateRandomNumString(const int length) {
    const auto random_number = GenerateRandomNum();
    auto str = std::to_string(random_number);
    if (length == -1)
        return str;
    return str.substr(0, length);
}

std::string IdGenerator::GenerateObjectId() {
    return GenerateRandomNumString() + GenerateTimeString(5);
}
