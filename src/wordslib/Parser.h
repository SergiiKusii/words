#pragma once

#include "Common.h"
/*
    parse set of words
*/
class Parser
{
public:
    Parser() = default;
    ~Parser() = default;
    words_container_t parse(const std::string& words);
};
