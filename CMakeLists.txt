cmake_minimum_required(VERSION 3.10)
project(encrypt-decrypt-file)

set(CMAKE_CXX_STANDARD 14)

add_executable(encryptor src/main.cpp src/FileEncryptor.cpp include/FileEncryptor.h)