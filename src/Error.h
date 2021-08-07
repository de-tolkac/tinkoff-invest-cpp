#pragma once

#include <string>

struct Error {
    std::string message;
    std::string code;

    operator bool() const {
        return code != "Ok";
    }
};