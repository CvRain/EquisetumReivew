//
// Created by cvrain on 23-10-10.
//

#pragma once

#include <string>
#include <string_view>
#include <chrono>
#include <random>

class IdGenerator {
public:
    static uint32_t GenerateTimestamp();
    static uint32_t GenerateRandomNum();
    static std::string GenerateTimeString(int length = -1);
    static std::string GenerateRandomNumString(int length = -1);
    static std::string GenerateObjectId();
};
