cmake_minimum_required(VERSION 2.8)

set (PROJECT_WORDS_LIB wordslib)
project(${PROJECT_WORDS_LIB})

set (PRIVATE_CLASSES
    Parser
    WordsInfo
    )

set (SOURCES)
foreach (class ${PRIVATE_CLASSES})
    LIST (APPEND SOURCES ${class}.cpp)
endforeach ()

add_library (${PROJECT_WORDS_LIB} STATIC ${SOURCES})


