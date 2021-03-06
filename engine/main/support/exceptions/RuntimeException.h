//
// Created by roman on 04.08.2020.
//

#ifndef FLASH_RUNTIMEEXCEPTION_H
#define FLASH_RUNTIMEEXCEPTION_H

#include "Exception.h"
#include "ExceptionCodes.h"

namespace Exceptions {

    class RuntimeException : public Exception {
    public:
        explicit RuntimeException(const char *message, int code = ExceptionCodes::RUNTIME_EXCEPTION) : Exception(message, code) {}

        explicit RuntimeException(const std::string &message, int code = ExceptionCodes::RUNTIME_EXCEPTION) : Exception(message, code) {}
    };

}
#endif //FLASH_RUNTIMEEXCEPTION_H
