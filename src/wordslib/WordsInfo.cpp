#include "WordsInfo.h"

#include <algorithm>

size_t WordsInfo::getCount() const
{
    return m_words.size();
}

words_container_t WordsInfo::getReverse() const
{
    words_container_t reserse;
    std::reverse_copy(std::begin(m_words), std::end(m_words), std::begin(reserse));
    return reserse;
}
    
std::string WordsInfo::getMaxWord() const
{
    auto itMax = std::max_element(std::begin(m_words), std::end(m_words));
    if (itMax == std::end(m_words))
    {
        return "";
    }

    return *itMax;
}

words_frequency_t WordsInfo::getFrequency() const
{
    words_frequency_t wordsFrequency;
    return wordsFrequency;
}