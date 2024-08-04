/**
 * @file ConsoleLogger.hpp
 * @author Massinissa Bandou
 * @brief 
 * @version 0.1
 * @date 2024-08-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CONSOLELOGGER_HPP
#define CONSOLELOGGER_HPP_

#include "../Common/Defines.hpp"

#include <iostream>
#include <memory>
#include <mutex>

class ConsoleLogger final
{
    ConsoleLogger() = default;
public:
    ~ConsoleLogger() = default;
    ConsoleLogger(const ConsoleLogger&) = delete;
    ConsoleLogger(ConsoleLogger &&) = delete;
    ConsoleLogger& operator=(const ConsoleLogger&) = delete;
    ConsoleLogger& operator=(ConsoleLogger &&) = delete;
    template <typename DataType, typename ... Args>
    static auto write(const DataType & datatype, const Args&... args) -> void;
    template <typename DataType>
    static auto write(const DataType & data) -> void;
private:
    inline static std::mutex m_mtx;
};

/// @brief write into the terminal
/// @tparam ...Args 
/// @tparam DataType 
/// @param datatype 
/// @param ...args 
/// @return void
template <typename DataType, typename ... Args>
auto ConsoleLogger::write(const DataType & datatype, const Args& ...args) -> void
{
    std::lock_guard<std::mutex> lock(m_mtx);
    std::cout << datatype << SPACING;
    ConsoleLogger::write(args...);
}

/// @brief write into terminal
/// @tparam DataType 
/// @param data 
/// @return void
template <typename DataType>
auto ConsoleLogger::write(const DataType & data) -> void
{
    std::cout << data << std::endl;
}

/// LOG definition:
#define LOG(...) ConsoleLogger::write(__VA_ARGS__);

#endif /// CONSOLELOGGER_HPP_
