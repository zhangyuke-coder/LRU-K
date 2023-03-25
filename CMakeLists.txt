cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(LRU_K CXX)
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

enable_testing()

add_executable(lru_test LRU_k_test.cc LRU_K.cc)

target_link_libraries(lru_test gtest_main gtest pthread)