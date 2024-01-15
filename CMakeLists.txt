cmake_minimum_required(VERSION 3.10)
project(encrypt-decrypt-file)

set(CMAKE_CXX_STANDARD 14)

option(BUILD_TESTS "Build tests" ON)

if (BUILD_TESTS)
    add_executable(encryptor src/FileEncryptor.cpp include/FileEncryptor.h
            tests/test_Base64Encryption.cpp
            include/Base64Encryption.h
            src/Base64Encryption.cpp)
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    target_link_libraries(encryptor PRIVATE GTest::GTest GTest::Main pthread)
else ()
    add_executable(encryptor src/FileEncryptor.cpp include/FileEncryptor.h
            src/main.cpp
            include/Base64Encryption.h
            src/Base64Encryption.cpp)
endif ()

install(TARGETS encryptor DESTINATION build)
