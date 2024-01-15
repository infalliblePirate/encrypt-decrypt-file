cmake_minimum_required(VERSION 3.10)
project(encrypt-decrypt-file)

set(CMAKE_CXX_STANDARD 14)

option(BUILD_TESTS "Buildd tests" ON)

if (BUILD_TESTS)
    add_executable(encryptor src/FileEncryptor.cpp include/FileEncryptor.h
            tests/test_FileEncryptor.cpp)
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    target_link_libraries(encryptor PRIVATE GTest::GTest GTest::Main pthread)
else ()
    add_executable(encryptor src/FileEncryptor.cpp include/FileEncryptor.h
            src/main.cpp)
endif ()

install(TARGETS encryptor DESTINATION build)
