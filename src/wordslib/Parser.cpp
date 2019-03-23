#include "Parser.h"

static char g_delimiter = ' ';

/*
    split string by g_delimiter
*/
words_container_t Parser::parse(const std::string& words)
{
    words_container_t wordsContainer;
    size_t posBegin = 0;
    while (posBegin < words.size())
    {
        //ignore all empty words and delimiters
        if (words[posBegin] == g_delimiter)
        {
            posBegin++;
            continue;
        }

        auto posEnd = words.find(g_delimiter, posBegin);
        if (posEnd == std::string::npos)
        {
            posEnd = words.size();
        }

        if (posBegin < posEnd)
        {
            auto word = words.substr(posBegin, posEnd - posBegin);
            wordsContainer.emplace_back(word);
        }

        posBegin = posEnd + 1;
    }

    return wordsContainer;
}
