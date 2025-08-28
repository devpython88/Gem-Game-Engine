#pragma once
#include <string>


namespace gem {
    struct Error {
        bool ok;
        std::string what;
    };
};