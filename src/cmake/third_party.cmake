
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS unit_test_framework program_options)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
else()
    message(FATAL_ERROR "Boost is not found")
endif()
