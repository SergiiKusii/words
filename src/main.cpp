#include <iostream>
#include <algorithm> 
#include <iterator> 
#include <boost/program_options.hpp>

struct Config
{
    std::string words;
    bool debug = false; 
};

Config ParseArguments(int argc, char *argv[])
{
    using namespace boost::program_options;
    Config cfg;
    try
    {
        options_description desc{"\
words - application for get info about set of words.\n\
Copyright Sergii Kusii 2019.\n\n\
Options"};
        desc.add_options()
            ("help,h", "Help screen")
            ("words,w", value<std::string>(), "Set of words")
            ("debug,d", "Show debug output");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        if (vm.count("help") || !vm.count("words"))
        {
            std::cout << desc << '\n';
            return cfg;
        }
                    
        cfg.words = vm["words"].as<std::string>();
        
        cfg.debug = vm.count("debug") > 0;

        return cfg;
    }
    catch (const error &ex)
    {
        std::cerr << ex.what() << '\n';
    }

    return cfg;
}

int main(int argc, char *argv[])
{
    try
    {
        auto cfg = ParseArguments(argc, argv);
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