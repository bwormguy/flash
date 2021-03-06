//
// Created by roman on 05.08.2020.
//

#include "LoggerFormatter.h"

namespace LoggerUtil {
    static inline std::string dateTimeNow() noexcept;
}

std::string LoggerUtil::LoggerFormatter::format(const std::string &data) const noexcept {
    return dateTimeNow() + data + "\n";
}

static inline std::string LoggerUtil::dateTimeNow() noexcept {
    const unsigned int buffchars = 20;
    char buffer[buffchars];
    time_t seconds = time(nullptr);
    tm *timeinfo = localtime(&seconds);
    strftime(buffer, buffchars, "%Y-%I-%d %H:%M", timeinfo);
    return std::string(buffer);
}

