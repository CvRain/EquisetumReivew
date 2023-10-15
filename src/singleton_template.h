//
// Created by cvrain on 23-10-15.
// 一个单例模式的模板文件，用于通用创建单例模式类
//

#pragma once

namespace DbOperator {
    template<typename T>
    class SingletonTemplate {
    public:
        static T &GetInstance(){
            static T instance;
            return instance;
        }

        SingletonTemplate(const SingletonTemplate &) = delete;

        SingletonTemplate &operator=(const SingletonTemplate &) = delete;

    protected:
        SingletonTemplate() = default;

        ~SingletonTemplate() = default;
    };
}