cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SOURCE_DIR}/cmake")
# set(CMAKE_INCLUDE_PATH "${CMAKE_INCLUDE_PATH} ${SOURCE_DIR}/shadow ${SOURCE_DIR}/unhesher")

set(MY_CXX_FLAGS  " -DBOOST_ERROR_CODE_HEADER_ONLY")
set(MY_EXE_LINKER_FLAGS  "-pthread -lcrypt")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MY_EXE_LINKER_FLAGS}")

include(cmake/version.cmake)
include(cmake/third_party.cmake)

# include_directories(${SOURCE_DIR}/common)

add_subdirectory(wordslib)
add_subdirectory(tests)

set (MAIN_SOURCES
    main.cpp
    )

add_executable (${PROJECT} ${MAIN_SOURCES})
target_link_libraries(${PROJECT} ${Boost_LIBRARIES} )
target_link_libraries(${PROJECT} wordslib)

set_target_properties(${PROJECT} PROPERTIES VERSION "${${PROJECT}_VERSION}" SOVERSION "0")
