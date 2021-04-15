cmake_minimum_required(VERSION 3.5)
project(KeyLocker VERSION 1.0.0 LANGUAGES CXX)

set(SOURCE_FILES
src/crypto/SHA256.cpp
src/crypto/AES.cpp
src/key.cpp
src/password.cpp)

add_library(key_locker ${SOURCE_FILES})

add_executable(keylocker src/main.cpp)

target_include_directories(key_locker PUBLIC include)

target_link_libraries(keylocker LINK_PUBLIC key_locker)
