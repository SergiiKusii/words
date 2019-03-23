#include "WordsInfo.h"

#include <algorithm>

size_t WordsInfo::getCount() const
{
    return m_words.size();
}

words_container_t WordsInfo::getReverse() const
{
    words_container_t reserse(m_words.size());
    std::reverse_copy(std::begin(m_words), std::end(m_words), std::begin(reserse));
    return reserse;
}

std::string WordsInfo::getLongestWord() const
{
    auto itMax = std::max_element(std::begin(m_words), std::end(m_words), 
            [](const std::string& ls, const std::string& rs) {
                return ls.size() < rs.size();
            });

    if (itMax == std::end(m_words))
    {
        return "";
    }

    return *itMax;
}

/*return map where key is a word and value is the number of repetitions of that word*/
words_frequency_t WordsInfo::getFrequency() const
{
    words_frequency_t wordsFrequency;
    for (auto& word : m_words)
    {
        auto it = wordsFrequency.find(word);
        if (it == std::end(wordsFrequency))
        {
            wordsFrequency.emplace(word, 1);
        }
        else
        {
            it->second++;
        }
    }
    
    return wordsFrequency;
}

std::string WordsInfo::getMostFrequentWord() const
{
    return getMostFrequentWord(getFrequency());
}
    
std::string WordsInfo::getMostFrequentWord(const words_frequency_t& words) const
{
    auto it = std::max_element(std::begin(words), std::end(words), 
            [](const words_frequency_t::value_type& ls, const words_frequency_t::value_type& rs){
                return ls.second < rs.second;
            });

    if (it == std::end(words))
    {
        return "";
    }

    return it->first;
}