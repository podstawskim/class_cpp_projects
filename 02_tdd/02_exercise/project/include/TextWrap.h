#pragma once

#include <string>
#include <sstream>

class TextWrap {
public:

    explicit TextWrap(int columns = 1);

    std::string wrap(const char* line) const;

private:
    int columns;
};