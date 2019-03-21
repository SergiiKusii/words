cmake_minimum_required(VERSION 2.8)

SET(PROJECT_WORDS_TEST wordsTests)

project(${PROJECT_WORDS_TEST})

add_executable(${PROJECT_WORDS_TEST} wordsTests.cpp)
target_link_libraries(${PROJECT_WORDS_TEST} ${Boost_LIBRARIES})
add_test(NAME ${PROJECT_WORDS_TEST} COMMAND ${PROJECT_WORDS_TEST})


