#pragma once

#include <string>

namespace ti {

struct Error {
    std::string message;
    std::string code;

    operator bool() const {
        return code != "Ok";
    }
};

}