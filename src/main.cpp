#include <iostream>
#include <algorithm> 
#include <iterator> 
#include <boost/program_options.hpp>

#include "wordslib/Parser.h"
#include "wordslib/WordsInfo.h"

struct Config
{
    std::string words;
};

Config ParseArguments(int argc, char *argv[])
{
    using namespace boost::program_options;
    Config cfg;

    options_description desc{"\
words - application for get info about set of words.\n\
Copyright Sergii Kusii 2019.\n\n\
Options"};
    desc.add_options()
        ("help,h", "Help screen")
        ("words,w", value<std::string>(), "Set of words");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help") || !vm.count("words"))
    {
        std::cout << desc << '\n';
        return cfg;
    }
                
    cfg.words = vm["words"].as<std::string>();
        
    return cfg;
}

int main(int argc, char *argv[])
{
    try
    {
        auto cfg = ParseArguments(argc, argv);
        if (cfg.words.empty())
        {
            return 0;
        }
     
        Parser parser;
        auto words = parser.parse(cfg.words);
        WordsInfo wordsinfo(words);

        std::cout << "Count: " << wordsinfo.getCount() << std::endl;
        
        auto frequency = wordsinfo.getFrequency();
        std::cout << "Words: " <<  std::endl;
        for (auto& pair : frequency)
        {
             std::cout << pair.first << " - " << pair.second <<  std::endl;
        }

        std::cout << "Longest: " << wordsinfo.getMaxWord() << std::endl;
        
        std::cout << "Most frequent: " << wordsinfo.getMostFrequentWord(frequency) << std::endl;

        std::cout << "Reverse: ";
        auto reverse = wordsinfo.getReverse();
        std::copy(std::begin(reverse), std::end(reverse),
              std::ostream_iterator<std::string>(std::cout, " ")); 
        std::cout << std::endl;
    }
    catch (const boost::program_options::error &ex)
    {
        std::cerr << ex.what() << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what();
        return -1;
    }
    
    return 0;
}