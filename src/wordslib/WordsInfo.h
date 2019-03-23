#pragma once

#include <map>
#include "Common.h"

using words_frequency_t = std::map<std::string /*word*/, size_t /*count*/>;

/*return statistic about set of words*/
class WordsInfo
{
public:
    WordsInfo(const words_container_t& words)
        : m_words(words)
    {}
    ~WordsInfo() = default;

    size_t getCount() const;
    words_container_t getReverse() const;
    std::string getLongestWord() const;
    words_frequency_t getFrequency() const;
    std::string getMostFrequentWord() const;
    std::string getMostFrequentWord(const words_frequency_t& words) const;

private:
    const words_container_t& m_words;
};

