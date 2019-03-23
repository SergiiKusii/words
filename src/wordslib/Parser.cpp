#include "Parser.h"

static char g_delimiter = ' ';

/*
    split string by g_delimiter
*/
words_container_t Parser::parse(const std::string& words)
{
    words_container_t wordsContainer;
    size_t posBegin = 0;
    while (posBegin != std::string::npos)
    {
        auto posEnd = words.find(posBegin, g_delimiter);
        if (posEnd == std::string::npos)
        {
            posEnd = words.size() - 1;
        }

        if (posBegin < posEnd)
        {
            wordsContainer.push_back(words.substr(posBegin, posEnd - posBegin));
        }

        posBegin = words.find(posEnd, g_delimiter);
    }

    return words_container_t();
}
